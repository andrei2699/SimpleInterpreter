cmake_minimum_required(VERSION 3.0)

project("SimpleInterpreter" VERSION 1.3.0)

add_subdirectory(src)

add_executable("${PROJECT_NAME}" main.cpp)

target_link_libraries("${PROJECT_NAME}" PRIVATE List Stack IO Parser Runner)

add_definitions(-DAPP_NAME="${PROJECT_NAME} - ${PROJECT_VERSION}")