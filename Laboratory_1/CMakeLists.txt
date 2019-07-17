cmake_minimum_required(VERSION 2.8)

project(ksamp)

set(SOURCES
	src/main.c
	src/ksmap.c
)
set(HEADERS
    ${PROJECT_SOURCE_DIR}/include
    )
add_executable(${PROJECT_NAME} ${SOURCES})
TARGET_INCLUDE_DIRECTORIES(${PROJECT_NAME} PRIVATE ${HEADERS})

