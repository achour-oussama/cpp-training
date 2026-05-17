cmake_minimum_required(VERSION 3.16)
project(ConcurrentProject)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -pthread")

add_executable(main src/main.cpp src/ThreadPool.cpp src/producer.cpp src/Task.cpp)
target_include_directories(main PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(test src/Task.cpp)