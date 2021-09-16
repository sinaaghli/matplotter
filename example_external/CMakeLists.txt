cmake_minimum_required(VERSION 3.5)
project(plotterexample)

# set default build to debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Release or Debug" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall" CACHE INTERNAL "")

# find package 
find_package(matplotter REQUIRED)

# I shouldnt need to find python2 since it was a dep of matplotter but can't resolve the dependency related issues for now
find_package (Python2 COMPONENTS Interpreter NumPy REQUIRED)

include_directories(${MATPLOTTER_INCLUDE_DIRS})

# build type
set(CMAKE_BUILD_TYPE Release CACHE STRING "Choose the type of build." FORCE)
set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS
             "Debug"
             "Release"
             "MinSizeRel"
             "RelWithDebInfo"
)

# add binary
add_executable(plotter plotter.cpp)

# add library
target_link_libraries(plotter ${MATPLOTTER_LIBRARIES})

