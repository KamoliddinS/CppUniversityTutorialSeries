cmake_minimum_required(VERSION 3.10)

# This is project name 
project(CarRentalManagmentSystem)



set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)
#Specifies the C++ standard to use (you can change this according to your needs).



include_directories(includes)
#above line: This line tells CMake to include the include directory where your header files are located.
# in our case it is the "includes" directory.


file(GLOB SOURCES "src/*.cpp")
#above line: Gathers all source files from the src directory.

add_executable(CarRentalManagmentSystem ${SOURCES})
# above the line: Creates an executable named LibraryManagementSystem from the specified source files.
