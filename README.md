# 24点计算器

## 项目简介
该项目是一个快速计算24点的程序，支持从命令行、文件输入和图形化界面输入四个数字，并输出计算结果。程序实现了判断四个数字是否能计算出24点的算法，并生成所有可能的运算组合。

## 文件结构
```
24-point-calculator
├── src
│   ├── main.cpp          // 程序入口点，处理命令行和文件输入
│   ├── graph.cpp         // 图形化界面入口点，使用FLTK库
│   ├── calculator.cpp    // 实现计算器类的逻辑
│   └── calculator.h      // 定义计算器类的接口
├── input.txt             // 存储待计算的数字
├── CMakeLists.txt        // CMake构建配置文件
├── build_and_run.sh      // 构建和运行脚本
└── README.md             // 项目文档
```

## 使用说明

### 构建项目
首先，确保你已经安装了CMake和FLTK库。然后，你可以使用以下命令构建项目：
```sh
mkdir build
cd build
cmake ..
make
```

### 安装FLTK库
在构建项目之前，请确保已安装FLTK库。以下是安装FLTK库的指南：

#### 在Ubuntu上安装FLTK
```sh
sudo apt-get update
sudo apt-get install libfltk1.3-dev
```

#### 在MacOS上安装FLTK
使用Homebrew安装：
```sh
brew install fltk
```

#### 在Windows上安装FLTK
1. 下载FLTK库的Windows安装包：[FLTK下载页面](https://www.fltk.org/software.php)
2. 解压下载的文件，并按照其中的README文件进行安装。

### 命令行输入
可以通过命令行输入四个数字，程序将计算这些数字是否能得到24点。例如：
```sh
./24PointCalculator 3 8 3 8
```

### 文件输入
可以通过文件输入四个数字，程序将计算这些数字是否能得到24点，并将结果输出到`output.txt`文件。例如：
```sh
./24PointCalculator
```
确保`input.txt`文件位于项目根目录，并包含待计算的数字。

### 图形化界面
你可以使用以下命令构建和运行图形化界面版本：
```sh
./build_and_run.sh gui
```
在图形化界面中输入四个数字，点击“Calculate”按钮，程序将计算这些数字是否能得到24点，并显示结果。

### 文本输入
你可以使用以下命令构建和运行文本输入版本：
```sh
./build_and_run.sh text
```
在命令行中输入四个数字，程序将计算这些数字是否能得到24点，并显示结果。

### 添加执行权限
如果遇到 `./build_and_run.sh` 没有权限的问题，可以使用以下命令为脚本文件添加执行权限：
```sh
chmod +x build_and_run.sh
```

## 示例
### 命令行输入示例
```sh
./24PointCalculator 3 8 3 8
```

### 文件输入示例
确保`input.txt`文件内容如下：
```
6   Q   K   6
7   10  1   J
J   4   5   7
```
运行程序：
```sh
./24PointCalculator
```
结果将输出到`output.txt`文件。

### 图形化界面示例
运行图形化界面版本：
```sh
./build_and_run.sh gui
```
在图形化界面中输入四个数字，点击“Calculate”按钮，程序将计算这些数字是否能得到24点，并显示结果。

## 依赖
- CMake 3.10或更高版本
- FLTK库

