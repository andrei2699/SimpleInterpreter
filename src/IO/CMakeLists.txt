add_library(IO
    src/FileReader.cpp
    src/FileReader.hpp
)

target_include_directories(IO PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
