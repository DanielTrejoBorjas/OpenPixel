cmake_minimum_required(VERSION 3.22)

project(OpenPixel LANGUAGES C CXX)

set(CMAKE_C_STANDARD 99)         
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CXX_STANDARD 17)        
set(CMAKE_CXX_STANDARD_REQUIRED ON)



file(GLOB_RECURSE SOURCES "src/*.cpp" "src/*.c")

add_executable(OpenPixel ${SOURCES})


#----------------------------PKG-ZONE----------------------------

#NLOHMANN_JSON
find_package(nlohmann_json REQUIRED)
target_link_libraries(OpenPixel PRIVATE nlohmann_json::nlohmann_json)