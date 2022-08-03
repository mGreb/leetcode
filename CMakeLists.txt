cmake_minimum_required(VERSION 3.17)
project(leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_VERBOSE_MAKEFILE ON)

add_compile_options(-Wall)
add_compile_options(-Wextra)
add_compile_options(-Werror)
add_compile_options(-Wpedantic)
add_compile_options(--pedantic-errors)
add_compile_options(-Waddress)
add_compile_options(-fsanitize=address)
add_link_options(-fsanitize=address)

file(GLOB source_files "*.cpp")

# Loop through each source file
foreach(source_file IN LISTS source_files)
    # Get the name of the file without the extension (e.g. 'a' from src/a.cpp'
    get_filename_component(target_name ${source_file} NAME_WE)

    # Create an executable with the above name, building the above source
    add_executable("${target_name}" "${source_file}")
endforeach()
