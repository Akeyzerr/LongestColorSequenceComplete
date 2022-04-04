cmake_minimum_required(VERSION 3.5.1)

include(${CMAKE_CURRENT_SOURCE_DIR}/cmake_helpers/helpers_c.cmake)

project(longestSequence)

find_package(PythonLibs REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS})

set(BLD_DIR ${CMAKE_CURRENT_SOURCE_DIR}/ctest_build())
set(INC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lcs/lib)
set(SRC_DIR ${CMAKE_CURRENT_SOURCE_DIR}/lcs/src)

#generate project LIBRARY
add_library(
    ${PROJECT_NAME}
    SHARED
        ${INC_DIR}
    ${SRC_DIR}/main.c
    ${SRC_DIR}/helpers.c
    ${SRC_DIR}/runDFS.c
    ${SRC_DIR}/Vector.c
    )

#generate project binary
# add_executable(
#     ${PROJECT_NAME}
#     ${SRC_DIR}/main.c
#     ${SRC_DIR}/Vector.c
#     ${SRC_DIR}/helpers.c
#     ${SRC_DIR}/runDFS.c
#     )

target_link_libraries(${PROJECT_NAME} ${PYTHON_LIBRARIES})

target_include_directories(
    ${PROJECT_NAME} 
        PRIVATE 
            ${INC_DIR}
)  


set_target_c_standard(${PROJECT_NAME} 99)
enable_target_c_warnings(${PROJECT_NAME})
