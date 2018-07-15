cmake_minimum_required(VERSION 2.8)
project(QR_Code)
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR})

#SDL2 Setup
find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIR})

#binary tree
include_directories("${PROJECT_BINARY_DIR}")

#executable
add_executable(qrcodegenerator qrgen.cpp)

#linking
target_link_libraries(qrcodegenerator ${SDL2_LIBRARIES})
