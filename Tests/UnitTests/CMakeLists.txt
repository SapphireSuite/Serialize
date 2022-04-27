# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SerializerUT)

SA_FetchGoogleTest()



# Executable

## Inputs

file(GLOB_RECURSE SA_SERIALIZER_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_SerializerUT ${SA_SERIALIZER_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SerializerUT PRIVATE SA_Serializer)

### Google test module dependency.
target_link_libraries(SA_SerializerUT PRIVATE gtest)



# Tests

add_test(NAME CSA_SerializerUT COMMAND SA_SerializerUT)
