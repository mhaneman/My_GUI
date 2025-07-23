# Enable testing
enable_testing()

# Find Catch2 package (works with vcpkg or installed Catch2)
find_package(Catch2 3 REQUIRED)

add_executable(tests test_example.cpp)

# Link Catch2 to the test executable
target_link_libraries(tests PRIVATE Catch2::Catch2WithMain)

# This registers tests with CTest
include(CTest)
include(Catch)
catch_discover_tests(tests)
