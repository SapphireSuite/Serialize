# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)



# Project

project(SA_Serialize)

message("SA_Serialize Main directory: ${CMAKE_CURRENT_SOURCE_DIR}")



# Outputs

### Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)		# .exe
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .lib / .a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .dll / .so



# Input

file(GLOB_RECURSE SA_SERIALIZE_SOURCES "Source/*")



# Library


## Static library.
add_library(SA_Serialize STATIC ${SA_SERIALIZE_SOURCES})


## Include directories
target_include_directories(SA_Serialize PUBLIC Include)
target_include_directories(SA_Serialize PRIVATE Include/SA/Serialize)


## Link libraries
target_link_libraries(SA_Serialize PUBLIC JSON)


## Compile features

### Standard
target_compile_features(SA_Serialize PUBLIC c_std_11)
target_compile_features(SA_Serialize PUBLIC cxx_std_20)

### SA_Serialize module implementation preprocessor.
target_compile_definitions(SA_Serialize PUBLIC SA_SERIALIZER_IMPL)



# Options

## Add SA_Serialize's tests to build tree.
option(SA_SERIALIZE_BUILD_TESTS_OPT "Should build SA_Serialize tests" OFF)



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_SERIALIZE_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
