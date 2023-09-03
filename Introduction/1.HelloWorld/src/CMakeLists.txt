cmake_minimum_required(VERSION 3.24) 
# This line specifies the minimum required version of CMake for this project.
# In this case, the project requires at least version 3.24 of CMake to be configured and built correctly.
# If a user tries to configure the project with an older version of CMake, they will receive an error.

project(helloworld)
# This line declares the name of the project, which is "untitled" in this case.
# The project name can be used in various places within the CMake configuration, and it also sets several variables (like PROJECT_NAME, PROJECT_SOURCE_DIR, etc.) that can be used later in the CMakeLists.txt.

set(CMAKE_CXX_STANDARD 17)
# This line sets the C++ standard for the project to C++17. This means that the compiler will use the C++17 standard when compiling the project's source files. 
# If the compiler doesn't support C++17, the configuration process will fail.

add_executable(helloworld main.cpp)
# This line tells CMake to create an executable target named "untitled" from the source file main.cpp. 
# When the project is built, this will produce an executable file named "untitled" (or "untitled.exe" on Windows) from the main.cpp source file.
