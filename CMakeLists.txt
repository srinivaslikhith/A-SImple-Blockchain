cmake_minimum_required(VERSION 3.10)
project(Blockchain)

find_package(OpenSSL REQUIRED)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(headers)

# Source files
set(SOURCES 
    src/blockchain.cc 
    src/utils.cc
)

# Create the executable
# add_executable(blockchain ${SOURCES})

# Link libraries (if needed, e.g., OpenSSL for hashing)
# target_link_libraries(blockchain OpenSSL::Crypto)
