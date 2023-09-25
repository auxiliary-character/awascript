cmake_minimum_required(VERSION 3.11) # FetchContent is available in 3.11+
project(awascript)

# Generate compile_commands.json
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)


# Our Project

add_executable(${PROJECT_NAME} src/awascript.c)

install(TARGETS ${PROJECT_NAME}
        CONFIGURATIONS Release
        RUNTIME DESTINATION /bin)