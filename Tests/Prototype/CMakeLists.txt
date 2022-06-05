# Copyright (c) 2022 Sapphire's Suite. All Rights Reserved.



# Project

project(SA_SerializeProto)



# Executable

## Add executable target.
add_executable(SA_SerializeProto "main.cpp")



# Dependencies

### Add library dependencies.
target_link_libraries(SA_SerializeProto PUBLIC SA_Serialize)


target_include_directories(SA_SerializeProto PUBLIC Include)


## Refureku Dependency

add_custom_target(RunRefurekuGenerator
					WORKING_DIRECTORY "${PROJECT_SOURCE_DIR}"
					COMMAND RefurekuGenerator "${PROJECT_SOURCE_DIR}/Proto_RefurekuSettings.toml") 

add_dependencies(SA_SerializeProto RunRefurekuGenerator)



# Tests

add_test(NAME CSA_SerializeProto COMMAND SA_SerializeProto)
