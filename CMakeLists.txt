# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.

cmake_minimum_required(VERSION 3.16)



# Project

project(SA_Serializer)

message("SA_Serializer Main directory: ${CMAKE_CURRENT_SOURCE_DIR}")



# Outputs

### Setup output directory
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)		# .exe
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .lib / .a
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)		# .dll / .so



# Input

file(GLOB_RECURSE SA_SERIALIZER_SOURCES "Source/*")



# Library


## Static library.
add_library(SA_Serializer STATIC ${SA_SERIALIZER_SOURCES})


## Include directories
target_include_directories(SA_Serializer PUBLIC Include)
target_include_directories(SA_Serializer PRIVATE Include/SA/Serializer)


## Compile features

### Standard
target_compile_features(SA_Serializer PUBLIC c_std_11)
target_compile_features(SA_Serializer PUBLIC cxx_std_20)

### SA_Serializer module implementation preprocessor.
target_compile_definitions(SA_Serializer PUBLIC SA_SERIALIZER_IMPL)



# Options

## Add SA_Serializer's tests to build tree.
option(SA_SERIALIZER_BUILD_TESTS_OPT "Should build SA_Serializer tests" OFF)



# Entrypoints

add_subdirectory(ThirdParty)

if(SA_SERIALIZER_BUILD_TESTS_OPT)

	### Enable testing for this directory and below.
	enable_testing()

	add_subdirectory(Tests)
endif()
