cmake_minimum_required(VERSION 3.15)
project(My_GUI)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Use local vcpkg toolchain file path
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_SOURCE_DIR}/vcpkg/scripts/buildsystems/vcpkg.cmake")

find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(Catch2 CONFIG REQUIRED)


add_executable(${PROJECT_NAME} src/main.cpp src/window.cpp)

target_include_directories(${PROJECT_NAME} PUBLIC src/window.hpp)

target_link_libraries(${PROJECT_NAME} PRIVATE glfw glad::glad)

if (APPLE)
    target_link_libraries(${PROJECT_NAME} PRIVATE "-framework Cocoa" "-framework OpenGL" "-framework IOKit" "-framework CoreVideo")
elseif(UNIX)
    target_link_libraries(${PROJECT_NAME} PRIVATE dl pthread X11)
endif()

option(ENABLE_TESTING "Enable test builds" ON)

if(ENABLE_TESTING)
    enable_testing()
    add_subdirectory(tests)
endif()
