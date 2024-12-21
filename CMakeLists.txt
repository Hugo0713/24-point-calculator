cmake_minimum_required(VERSION 3.10)

project(24PointCalculator)

set(CMAKE_CXX_STANDARD 11)

# 添加选项来选择要编译的源文件
option(USE_GUI "Build with GUI" OFF)

if(USE_GUI)
    set(SOURCES
        src/graph.cpp
        src/calculator.cpp
    )
else()
    set(SOURCES
        src/main.cpp
        src/calculator.cpp
    )
endif()

# 查找 FLTK 库
find_package(FLTK REQUIRED)

# 创建可执行文件
add_executable(24PointCalculator ${SOURCES})

# 链接 FLTK 库
target_link_libraries(24PointCalculator ${FLTK_LIBRARIES})