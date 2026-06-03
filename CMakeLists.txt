cmake_minimum_required(VERSION 3.12)
project(llm_inference_engine VERSION 0.1.0 LANGUAGES CXX)

# Configure C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Create executable
add_executable(llm_inference_engine src/main.cpp)

# Include directories
target_include_directories(llm_inference_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)
