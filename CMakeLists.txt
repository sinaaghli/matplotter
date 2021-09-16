cmake_minimum_required(VERSION 3.5)
project(matplotter)

# set default build to debug
if(NOT CMAKE_BUILD_TYPE)
  set(CMAKE_BUILD_TYPE "Release" CACHE STRING "Release or Debug" FORCE)
endif(NOT CMAKE_BUILD_TYPE)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -Wall" CACHE INTERNAL "")

# find library dependencies 
find_package( PythonLibs 2.7 REQUIRED )
find_package (Python2 COMPONENTS Interpreter NumPy REQUIRED)

SET(DEP_INCLUDE_DIRS 
  ${PYTHON_INCLUDE_DIRS}
)

SET(DEP_LIBS 
  Python2::NumPy
  ${PYTHON_LIBRARIES}
)

# Set variables
include(${CMAKE_SOURCE_DIR}/cmake/SetEnv.cmake)

# Library sources
add_subdirectory(${LIBRARY_FOLDER})

# Library examples
add_subdirectory(example_internal)

# Install targets
include(${CMAKE_SOURCE_DIR}/cmake/InstallConfig.cmake)
