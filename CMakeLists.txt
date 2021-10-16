cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME dhcpcli)
set(DHCP_LEASE_GENERATED_FAKE_DATA ${CMAKE_CURRENT_BINARY_DIR}/dhcp-lease/tests/databases/dhcpd.db)

option(DEBUG "debug mode" OFF)

if(DEBUG)
    set(DHCP_LEASE_DEST_FAKE_DATA ${CMAKE_CURRENT_BINARY_DIR}/dhcp-lease/tests/databases)

    if(NOT EXISTS ${DHCP_LEASE_DEST_FAKE_DATA})
        message(STATUS "Fuck you!!! i can't find db file!")
    endif()
    
else()
    set(DHCP_LEASE_DEST_FAKE_DATA /var/lib/dhcp)       
endif()

add_definitions(-DDHCP_DATABASE_PATH="${DHCP_LEASE_DEST_FAKE_DATA}/dhcpd.db")

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/dhcpcli.c
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(dhcp-lease)