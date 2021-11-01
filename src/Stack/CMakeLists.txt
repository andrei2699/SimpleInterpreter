add_library(Stack
    src/Stack.cpp
    src/Stack.hpp
)

target_link_libraries(Stack PRIVATE List)

target_include_directories(Stack PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
