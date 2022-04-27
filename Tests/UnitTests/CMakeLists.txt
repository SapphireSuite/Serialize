# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SerializeUT)

SA_FetchGoogleTest()



# Executable

## Inputs

file(GLOB_RECURSE SA_SERIALIZE_UT_SOURCES "*.cpp")

## Add executable target.
add_executable(SA_SerializeUT ${SA_SERIALIZE_UT_SOURCES})



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SerializeUT PRIVATE SA_Serialize)

### Google test module dependency.
target_link_libraries(SA_SerializeUT PRIVATE gtest)



# Tests

add_test(NAME CSA_SerializeUT COMMAND SA_SerializeUT)
