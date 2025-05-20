cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Add sources here
set(SOURCES
    src/Engine.cpp
    src/Vec2.cpp
    src/main.cpp
)

# Add the executable from src/main.cpp
add_executable(PhysicsEngine ${SOURCES})
