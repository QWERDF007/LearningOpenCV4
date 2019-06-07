# cmake needs this line
cmake_minimum_required(VERSION 3.5)

# 自定义变量，方便修改
set(PROJECT_NAME basic_image_container)

# 定义项目
project(${PROJECT_NAME})

# 设置可执行文件输出目录
# PROJECT_BINARY_DIR cmakelist.txt 的同级目录
# PROJECT_SOURCE_DIR cmake命令执行的目录
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/bin)

# STATUS 对应输出前缀为 --
# message(STATUS "PROJECT_SOURCE_DIR: ${PROJECT_SOURCE_DIR}")
# message(STATUS "PROJECT_BINARY_DIR: ${PROJECT_BINARY_DIR}")

# 寻找 OpenCV 4，OpenCVConfig.cmake 所在目录的绝对路径
find_package(OpenCV 4 REQUIRED)

# 如果找到 OpenCV，打印一些信息
message(STATUS "OpenCV library status:")
message(STATUS "    version: ${OpenCV_VERSION}")
message(STATUS "    libraries: ${OpenCV_LIBS}")
message(STATUS "    include path: ${OpenCV_INCLUDE_DIRS}")

# 声明可执行文件
add_executable(${PROJECT_NAME} src/main.cpp)

# 链接至 OpenCV 库
target_link_libraries(${PROJECT_NAME} ${OpenCV_LIBS})