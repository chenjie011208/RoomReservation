cmake_minimum_required(VERSION 3.10)

project(RoomReservation)

include_directories(${PROJECT_SOURCE_DIR}/include)

add_executable(main_run src/main.cpp src/student.cpp src/teacher.cpp)
