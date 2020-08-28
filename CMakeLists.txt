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
string(LENGTH "${CMAKE_SOURCE_DIR}/" SOURCE_PATH_SIZE)
add_definitions("-DSOURCE_PATH_SIZE=${SOURCE_PATH_SIZE}")

add_link_options(-lurcu -lurcu-cds -lurcu-common)
add_link_options(-fsanitize=address)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})

function(ragelc name)
  add_custom_command(
    OUTPUT ${CMAKE_CURRENT_SOURCE_DIR}/${name}.c
    COMMAND ragel -G1 -o ${CMAKE_CURRENT_SOURCE_DIR}/${name}.c ${CMAKE_CURRENT_SOURCE_DIR}/${name}.rl
    DEPENDS ${name}.rl parser-common.rl)
endfunction(ragelc)

ragelc(parser)
ragelc(driver-parser)

add_executable(executor executor.c parser.c)
target_link_libraries(executor actors)
target_compile_definitions(executor
  PRIVATE executor_VERSION_MAJOR=${executor_VERSION_MAJOR}
  PRIVATE executor_VERSION_MINOR=${executor_VERSION_MINOR})

add_executable(driver driver.c driver-parser.c)
target_link_libraries(driver actors)
target_compile_definitions(driver
  PRIVATE driver_VERSION_MAJOR=${executor_VERSION_MAJOR}
  PRIVATE driver_VERSION_MINOR=${executor_VERSION_MINOR})

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

function(sh_test name)
	add_test(${name} ${CMAKE_CURRENT_SOURCE_DIR}/test/${name}.sh)
endfunction(sh_test)

sh_test(driver-nop)
sh_test(driver-all-pass)
sh_test(driver-some-fail)
sh_test(driver-continuation)
sh_test(local-integration)
