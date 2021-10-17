cmake_minimum_required(VERSION 3.6)

set(PROJECT_NAME dhcpcli)
set(SCRIPTS ${CMAKE_CURRENT_SOURCE_DIR}/scripts)
set(DHCP_LEASE_GENERATED_FAKE_DATA ${CMAKE_CURRENT_BINARY_DIR}/dhcp-lease/tests/databases/dhcpd.db)

find_package(Git QUIET)

message("\n--------------------------------\n")
message("PROJECT NAME:\t\t${PROJECT_NAME}")
message("CMAKE_SYSTEM_NAME:\t${CMAKE_SYSTEM_NAME}")
message("CMAKE_C_COMPILER:\t${CMAKE_C_COMPILER}")
message("CMAKE_CXX_COMPILER:\t${CMAKE_CXX_COMPILER}")
message("CMAKE_BINARY_DIR:\t${CMAKE_BINARY_DIR}")
message("CUNIT_LIBRARY:\t\t${CUNIT_LIBRARY}")
message("DEST_FAKE_DATA:\t\t${DHCP_LEASE_DEST_FAKE_DATA}")
message("\n--------------------------------\n")

if(GIT_FOUND AND EXISTS "../.git")
    option(GIT_SUBMODULE "Check submodules during build" ON)

    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")

        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)

        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()    
endif()

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