cmake_minimum_required(VERSION 3.17)

project(executor VERSION 0.1 LANGUAGES C)

set(CMAKE_THREAD_PREFER_PTHREAD TRUE)
set(THREADS_PREFER_PTHREAD_FLAG TRUE)
find_package(Threads REQUIRED)
find_package(libactors REQUIRED)

set(CMAKE_C_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS on)
add_compile_definitions(_GNU_SOURCE)
add_compile_definitions(_FORTIFY_SOURCE=2)
add_compile_options(
  -O1 -Wall -Wextra -pedantic -Werror
  -g -fno-omit-frame-pointer -fsanitize=address
  -Wno-unused-const-variable)

add_link_options(-lurcu -lurcu-cds -lurcu-common)
add_link_options(-fsanitize=address)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

add_custom_command(
  OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/parser.c
  COMMAND ragel -G2 -o ${CMAKE_CURRENT_SOURCE_DIR}/parser.c ${CMAKE_CURRENT_SOURCE_DIR}/parser.rl
  DEPENDS parser.rl)

add_executable(
  executor executor.c ${CMAKE_CURRENT_SOURCE_DIR}/parser.c)
target_link_libraries(executor actors)
target_compile_definitions(executor
  PRIVATE executor_VERSION_MAJOR=${executor_VERSION_MAJOR}
  PRIVATE executor_VERSION_MINOR=${executor_VERSION_MINOR})

enable_testing()

function(exp_test name)
	add_test(${name}
		 expect ${CMAKE_CURRENT_SOURCE_DIR}/test/${name}.exp)
endfunction(exp_test)

exp_test(ping)
exp_test(ping-exit)
exp_test(tester-allc)
exp_test(tester-cmds)
exp_test(tester-exec)
exp_test(tester-concurrent)
