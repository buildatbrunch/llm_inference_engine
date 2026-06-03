cmake_minimum_required(VERSION 3.12)
project(llm_inference_engine VERSION 0.1.0 LANGUAGES CXX)

# Configure C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)

# Asio
FetchContent_Declare(
    asio
    GIT_REPOSITORY https://github.com/chriskohlhoff/asio.git
    GIT_TAG        asio-1-30-2
)
FetchContent_MakeAvailable(asio)

# Explicitly set the ASIO include directory for Crow's Findasio module
set(ASIO_INCLUDE_DIR "${asio_SOURCE_DIR}/asio/include" CACHE PATH "Path to Asio headers" FORCE)

# Crow
FetchContent_Declare(
    Crow
    GIT_REPOSITORY https://github.com/CrowCpp/Crow
    GIT_TAG        v1.2.0
)
FetchContent_MakeAvailable(Crow)

# Create executable
add_executable(llm_inference_engine src/main.cpp)

# Include directories
target_include_directories(llm_inference_engine PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/include)

# Link libraries
target_link_libraries(llm_inference_engine Crow::Crow)