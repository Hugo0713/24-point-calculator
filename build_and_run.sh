#!/bin/bash

# 检查输入参数
if [ "$#" -ne 1 ]; then
    echo "Usage: $0 [gui|text]"
    exit 1
fi

# 设置选项
if [ "$1" == "gui" ]; then
    USE_GUI=ON
elif [ "$1" == "text" ]; then
    USE_GUI=OFF
else
    echo "Invalid option: $1"
    echo "Usage: $0 [gui|text]"
    exit 1
fi

# 创建并进入 build 目录
mkdir -p build
cd build

# 运行 CMake 生成构建文件
cmake -DUSE_GUI=$USE_GUI ..

# 编译项目
make

# 运行生成的可执行文件
if [ $? -eq 0 ]; then
    echo "Build succeeded. Running the program..."
    ./24PointCalculator
else
    echo "Build failed."
fi