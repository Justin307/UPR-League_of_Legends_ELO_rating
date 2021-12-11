cmake_minimum_required(VERSION 3.0)
project(UPR_projekt C)

set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -fsanitize=address -lm")

set(CMAKE_C_STANDARD 99)

add_executable(UPR_projekt main.c lol.c lol.h htmlwriter.c htmlwriter.h generalhelper.c generalhelper.h)

target_link_libraries(UPR_projekt PRIVATE m)
