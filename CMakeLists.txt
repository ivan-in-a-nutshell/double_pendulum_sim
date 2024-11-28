cmake_minimum_required(VERSION 3.29)
project(cpp_rendering LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
option(BUILD_SHARED_LIBS "Build shared libraries" OFF)


add_executable(${PROJECT_NAME}
        src/main.cpp
        src/events.cpp
        src/configurations.hpp
        src/physics.cpp
        src/physics.hpp
)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-graphics)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-window)
target_link_libraries(${PROJECT_NAME} PRIVATE sfml-system)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_23)
