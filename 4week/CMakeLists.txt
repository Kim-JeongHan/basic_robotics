cmake_minimum_required(VERSION 3.11)

project(

    LANGUAGE C
)

add_executable(review1 review1.c)
target_compile_options(review1 PUBLIC -Wall -Werror)

add_executable(review2 review2.c)
target_compile_options(review2 PUBLIC -Wall -Werror)

add_executable(review3 review3.c)
target_compile_options(review3 PUBLIC -Wall -Werror)

add_executable(review4 review4.c)
target_compile_options(review4 PUBLIC -Wall -Werror)

add_executable(assignment1 assignment1.c)
target_compile_options(assignment1 PUBLIC -Wall -Werror)

add_executable(assignment2 assignment2.c)
target_compile_options(assignment2 PUBLIC -Wall -Werror)