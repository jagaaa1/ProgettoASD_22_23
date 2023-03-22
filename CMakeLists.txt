cmake_minimum_required(VERSION 3.23)
project(Progetto C)

set(CMAKE_C_STANDARD 99)
set(GCC_COVERAGE_COMPILE_FLAGS "-Wall -Wextra -Werror -O0")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )

add_executable(Progetto main.c period.h period.c utils.c utils.h exec_time.c exec_time.h string_gen.c string_gen.h)

target_link_libraries(Progetto xlsxwriter z)