cmake_minimum_required(VERSION 3.10)
project(PhysicsEngine LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(${PROJECT_SOURCE_DIR}/include)

# Add sources here
set(SOURCES
    src/Engine.cpp
    src/Vec2.cpp
    src/Body.cpp
    src/main.cpp
)

# Find SFML package
find_package(SFML 2.5 COMPONENTS graphics window system REQUIRED)

# Add the executable from src/main.cpp
add_executable(PhysicsEngine ${SOURCES})

# Link SFML libraries
target_link_libraries(PhysicsEngine sfml-graphics sfml-window sfml-system)

# Catch Library
find_package(Catch2 REQUIRED)

add_executable(tests_run
  tests/test_main.cpp
)

# Catch linking
target_link_libraries(tests_run Catch2::Catch2)

# Use ctest in build to run tests
include(CTest)
enable_testing()

# Optional: Add test results output
set_property(DIRECTORY ${CMAKE_SOURCE_DIR} PROPERTY VS_STARTUP_PROJECT tests_run)

# Register tests with CTest
add_test(NAME PhysicsEngineTests COMMAND tests_run -s)
