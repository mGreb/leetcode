get_filename_component(NAME ${CMAKE_CURRENT_SOURCE_DIR} NAME)
project(${NAME})
add_executable(${NAME} ${NAME}.cpp)
