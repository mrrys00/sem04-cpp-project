cmake_minimum_required(VERSION 3.20)
project(pong_50th_anniversary VERSION 1.0.1)

include(FetchContent)
set(BUILD_SHARED_LIBS OFF)
FetchContent_Declare(
    SFML
    GIT_REPOSITORY https://github.com/SFML/SFML.git
    GIT_TAG 2.5.1
)

file(COPY ${CMAKE_CURRENT_SOURCE_DIR}/Resources/ DESTINATION ${CMAKE_CURRENT_BINARY_DIR}/Resources/)

FetchContent_MakeAvailable(SFML)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED true)

file(GLOB SOURCES Actors/*.cpp Game/*.cpp Resources/*.cpp Utils/*.cpp)
file(GLOB HEADERS Actors/*.hpp Game/*.hpp Resources/*.hpp Utils/*.hpp)
set(SOURCES_WITHOUT_MAIN ${SOURCES})
list(REMOVE_ITEM SOURCES_WITHOUT_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/pong.cpp)

add_executable(
    ${PROJECT_NAME} ${HEADERS} ${SOURCES}
    pong.cpp
)
target_link_libraries(
    ${PROJECT_NAME}
    sfml-graphics
)
