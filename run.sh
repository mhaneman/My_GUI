PROJ="My_GUI"
TESTS="tests"

if [[ $1 = "init" ]]; then
    echo "Init Project"
    ./vcpkg/bootstrap-vcpkg.sh -disableMetrics
    ./vcpkg/vcpkg install
fi

if [[ $1 = "build" ]]; then
    echo "Building Project"
    mkdir build
    cmake -B build -S . -DCMAKE_TOOLCHAIN_FILE=../vcpkg/scripts/buildsystems/vcpkg.cmake
    cmake --build ./build
    ./build/$PROJ
fi

if [[ $1 = "run" ]]; then
    echo "Running Project"
    ./build/$PROJ
fi

if [[ $1 = "tests" ]]; then
    echo "Running Tests"
    ./build/$TESTS/$TESTS
fi

if [[ $1 = "clean" ]]; then
    echo "Cleaning Project"
    rm -rf ./build
fi
