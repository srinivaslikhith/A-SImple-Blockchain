cmake_minimum_required(VERSION 3.10)
project(Blockchain)

find_package(OpenSSL REQUIRED)
find_package(gRPC REQUIRED)
find_package(Protobuf REQUIRED)


# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(${Protobuf_INCLUDE_DIRS} ${gRPC_INCLUDE_DIRS} headers)

set(PROTO_SRC 
    src/blockchain.grpc.pb.cc
    src/blockchain.pb.cc
)
# Source files
set(SOURCES 
    src/blockchain.cc 
    src/utils.cc
)

#Create client the executable
add_executable(client src/client.cc src/utils.cc ${PROTO_SRC})
target_link_libraries(client ${Protobuf_LIBRARIES} gRPC::grpc++ OpenSSL::Crypto)

# Create server the executable
add_executable(server src/server.cc ${SOURCES} ${PROTO_SRC})
target_link_libraries(server ${Protobuf_LIBRARIES} gRPC::grpc++ OpenSSL::Crypto)

#copy files to build directory
add_custom_command(TARGET client POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/files
    ${CMAKE_BINARY_DIR}/files
)
add_custom_command(TARGET server POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
    ${CMAKE_SOURCE_DIR}/files
    ${CMAKE_BINARY_DIR}/files
)