cmake_minimum_required(VERSION 2.38)
project(My_Tools)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tools main.cpp
        Headers/ToolBox.h
        Sources/ToolBox/ToolBox.cpp
        Sources/ToolBox/Folders.cpp
        Sources/ToolBox/Files.cpp
        Sources/ToolBox/Texts.cpp)
# E:/Work Space/Programing/C++/My_Tools/Headers/ToolBox.h
# E:/Work Space/Programing/C++/My_Tools/Sources/ToolBox/ToolBox.cpp
# E:/Work Space/Programing/C++/My_Tools/Sources/ToolBox/Folders.cpp
# E:/Work Space/Programing/C++/My_Tools/Sources/ToolBox/Files.cpp
# E:/Work Space/Programing/C++/My_Tools/Sources/ToolBox/Texts.cpp