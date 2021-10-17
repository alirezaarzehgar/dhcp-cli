cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME dhcpcli)
set(SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set(DHCP_LEASE_GENERATED_FAKE_DATA ${CMAKE_CURRENT_BINARY_DIR}/dhcp-lease/tests/databases/dhcpd.db)

option(DEBUG "debug mode" OFF)

if(DEBUG)
    set(DHCP_LEASE_DEST_FAKE_DATA ${CMAKE_CURRENT_BINARY_DIR}/dhcp-lease/tests/databases)

    if(NOT EXISTS ${DHCP_LEASE_DEST_FAKE_DATA})
        execute_process(COMMAND ${SCRIPTS}/findb.sh ${SOURCE_DIR}
        RESULT_VARIABLE FINDB_RESULT
        OUTPUT_VARIABLE FINDB_OUT)

        if(NOT FINDB_OUT)
            message(FATAL_ERROR "dbfile not found")
        endif()

        set(DHCP_LEASE_DEST_FAKE_DATA ${FINDB_OUT})
    endif()
    
else()
    set(DHCP_LEASE_DEST_FAKE_DATA /var/lib/dhcp)       
endif()

add_definitions(-DDHCP_DATABASE_PATH="${DHCP_LEASE_DEST_FAKE_DATA}/dhcpd.db")

project(${PROJECT_NAME})

add_executable(${PROJECT_NAME}
    src/dhcpcli_handler.c
    src/file.c
    src/dhcpcli.c
)

target_link_libraries(${PROJECT_NAME}
    lib::lease
)

target_include_directories(${PROJECT_NAME}
    PUBLIC ${PROJECT_SOURCE_DIR}/include
)

add_subdirectory(dhcp-lease)