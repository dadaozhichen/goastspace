cmake_minimum_required(VERSION 3.20)
project(goastspace VERSION 0.0.1 LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 20)

file(GLOB_RECURSE SOURCE "src/*.cpp")
set(Target goastspace_${CMAKE_SYSTEM_NAME})
find_package(SDL3 REQUIRED)
find_package(SDL3_image REQUIRED)
find_package(SDL3_ttf REQUIRED)
find_package(SDL3_mixer REQUIRED) 
find_package(glm REQUIRED)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/)

add_executable(${Target} ${SOURCE})

target_link_libraries(${Target} SDL3::SDL3
                        SDL3_image::SDL3_image
                        SDL3_ttf::SDL3_ttf
                        SDL3_mixer::SDL3_mixer) 