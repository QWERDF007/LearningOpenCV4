cmake_minimum_required(VERSION 3.5)

# 自定义变量，方便修改
set(PROJECT_NAME mask_operations)

project(${PROJECT_NAME})

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# 寻找 OpenCV 4，OpenCVConfig.cmake 所在目录的绝对路径
find_package(OpenCV 4 REQUIRED)

add_executable(${PROJECT_NAME} src/main.cpp)

target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})