cmake_minimum_required(VERSION 3.10)

project(SessionManagement VERSION 1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(session-management
    src/main.cpp
    src/SessionManager.cpp
)

# Include directories
target_include_directories(session-management PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
