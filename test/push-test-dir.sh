echo "Using Test dir" ${TEST_DIR:=$(pwd)/test}

mkdir $TEST_DIR || true
cd $TEST_DIR
