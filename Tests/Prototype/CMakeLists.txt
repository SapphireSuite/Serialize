# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SerializerProto)



# Executable

## Add executable target.
add_executable(SA_SerializerProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SerializerProto PRIVATE SA_Serializer)



# Tests

add_test(NAME CSA_MathsProto COMMAND SA_SerializerProto)
