cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME dhcpcli)

add_executable(${PROJECT_NAME}
    src/dhcpcli.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)