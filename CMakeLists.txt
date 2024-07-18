cmake_minimum_required(VERSION 3.10)
project(REST_API_TEST)

# Find cpprestsdk package
find_package(cpprestsdk REQUIRED)

# Find OpenSSL package
find_package(OpenSSL REQUIRED)

# Find spdlog package
find_package(spdlog REQUIRED)

# Add executable and link cpprestsdk, OpenSSL, and spdlog
add_executable(REST_API_TEST src/main.cpp src/MyController.cpp)

# Include directories for cpprestsdk
target_include_directories(REST_API_TEST PRIVATE /usr/include/cpprest)

# Link against cpprestsdk, OpenSSL, and spdlog
target_link_libraries(REST_API_TEST PRIVATE cpprestsdk::cpprest OpenSSL::Crypto OpenSSL::SSL spdlog::spdlog)

# Ensure OpenSSL libraries are found
find_package(OpenSSL REQUIRED)

