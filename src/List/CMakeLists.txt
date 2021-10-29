add_library(List 
    src/List.hpp
    src/List.cpp
)

target_include_directories(List PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
