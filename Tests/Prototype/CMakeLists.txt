# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SerializeProto)



# Executable

## Add executable target.
add_executable(SA_SerializeProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SerializeProto PUBLIC SA_Serialize)



# Tests

add_test(NAME CSA_SerializeProto COMMAND SA_SerializeProto)
