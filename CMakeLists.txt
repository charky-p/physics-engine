cmake_minimum_required(VERSION 3.10)
project(Physics Engine)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Add sources here
set(SOURCES
    src/main.cpp
)

# Add the executable from src/main.cpp
add_executable(Physics Engine ${SOURCES})
