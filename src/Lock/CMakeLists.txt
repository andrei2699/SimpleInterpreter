add_library(Lock
    src/Lock.cpp
    src/Lock.hpp    
)

target_include_directories(Lock PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")
