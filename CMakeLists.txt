cmake_minimum_required(VERSION 3.5)

project(dumpobj LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB dumpobj_SRC
     "dumpobj/dumpobj.cpp"
)

add_executable(dumpobj ${dumpobj_SRC})

project(link11 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

execute_process(COMMAND git rev-list HEAD --count
                OUTPUT_VARIABLE GIT_REV
                ERROR_QUIET
                OUTPUT_STRIP_TRAILING_WHITESPACE
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)

execute_process(COMMAND git log --pretty=format:%h -n 1
                OUTPUT_VARIABLE GIT_COMMIT
                ERROR_QUIET
                OUTPUT_STRIP_TRAILING_WHITESPACE
                WORKING_DIRECTORY ${CMAKE_SOURCE_DIR}
)


set(VERSION "#define APP_REVISION_STRING \"${GIT_COMMIT}\"\n"
            "#define APP_VERSION ${GIT_REV}\n"
            "#define APP_VERSION_STRING \"V0.${GIT_REV}\"\n"
)


# generate version.h
include_directories(${CMAKE_BINARY_DIR})
file(WRITE ${CMAKE_BINARY_DIR}/version.h ${VERSION})

file(GLOB link11_SRC
     "main.cpp"
     "process.cpp"
     "tables.cpp"
     "util.cpp"
     "main.h"
)

add_executable(link11 ${link11_SRC} ${CMAKE_BINARY_DIR}/version.h)
