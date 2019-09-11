cmake_minimum_required (VERSION "3.7.1")
SET (CMAKE_C_COMPILER_WORKS 1)
SET (CMAKE_CXX_COMPILER_WORKS 1)


project ("example3")


file(GLOB_RECURSE  SOURCES "src/*.cpp")


include_directories(${CMAKE_SOURCE_DIR}/includes)
 
add_executable(${PROJECT_NAME} ${SOURCES})
