add_library(Runner
    src/Runner.hpp
    src/Runner.cpp
)


target_link_libraries(Runner PRIVATE Parser)

target_include_directories(Runner PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
