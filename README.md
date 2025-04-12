# QtMineSweeper
基于Qt实现的扫雷游戏

[参考项目](https://gitcode.com/open-source-toolkit/84972)

使用cmake构建项目。

文件夹目录为：
```bash
project_root/
│
├── AdvanceCpp/        <- 这是源代码目录，包含 AdvanceCpp 项目的 CMakeLists.txt
│    ├── CMakeLists.txt
│    └── ...
│
├── QtMineSweeper/    <- 这是源代码目录，包含 QtMineSweeper 项目的 CMakeLists.txt
│    ├── CMakeLists.txt
│    └── ...
│
├── Debug/            <- 这是构建目录的父目录
│    ├── advanceCppBuild/  <- 这是 AdvanceCpp 项目的构建目录
│    └── qtMineSweeperBuild/  <- 这是 QtMineSweeper 项目的构建目录
├── start.bat         <- 批处理文件
└── ...
```

start.bat脚本内容：
主要是编译了两个项目，第一个项目在仓库AdvanceCpp中，第二个项目在仓库QtMineSweeper中。
```bash
@echo off
call "D:\vs2022\vs2022_app\VC\Auxiliary\Build\vcvarsamd64_x86.bat"

:: 编译 advanceCpp 项目
cd Debug\AdvanceCpp
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Debug ..\..\AdvanceCpp
if errorlevel 1 (
    echo "CMake failed for advanceCpp"
    pause
    exit /b 1
)

msbuild /m advanceCpp.sln /p:Platform=x64 /p:Configuration=Debug
if errorlevel 1 (
    echo "Build failed for advanceCpp"
    pause
    exit /b 1
)

:: 编译 QtMineSweeper 项目
cd ..\QtMineSweeper
cmake -G "Visual Studio 17 2022" -A x64 -DCMAKE_BUILD_TYPE=Debug ..\..\QtMineSweeper
if errorlevel 1 (
    echo "CMake failed for QtMineSweeper"
    pause
    exit /b 1
)

msbuild /m QtMineSweeper.sln /p:Platform=x64 /p:Configuration=Debug
if errorlevel 1 (
    echo "Build failed for QtMineSweeper"
    pause
    exit /b 1
)

cd ..\..
pause
```

注意`cd`目录只能跳转已经有的文件夹，不能跳转到一个不存在的文件夹。