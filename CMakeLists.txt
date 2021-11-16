cmake_policy(SET CMP0048 NEW)
project(random_walk)
cmake_minimum_required(VERSION 3.18)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14 -O3")

set(BOOST_PYTHONLIB python39)
find_package(PythonLibs 3.9 REQUIRED)
include_directories(${PYTHON_INCLUDE_DIRS} ${Boost_INCLUDE_DIRS})

find_package(Boost 1.65.0 COMPONENTS ${BOOST_PYTHONLIB} python REQUIRED)
find_package(OpenMP REQUIRED)
OPTION (USE_OpenMP "Use OpenMP" ON)
IF(USE_OpenMP)
  FIND_PACKAGE(OpenMP)
  IF(OPENMP_FOUND)
    SET(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} ${OpenMP_C_FLAGS}")
    SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} ${OpenMP_CXX_FLAGS}")
  ENDIF()
ENDIF()

include_directories(include
                    include/pcg-cpp-0.98/include)
set(
    SRC_FILES
    src/walk.cpp
    src/stat.cpp
)

add_library(pywalk SHARED src/pywalk.cpp ${SRC_FILES})
set_target_properties(pywalk PROPERTIES PREFIX "")
set_target_properties(pywalk PROPERTIES SUFFIX ".so")
target_link_libraries(pywalk ${Boost_LIBRARIES} ${PYTHON_LIBRARIES})

add_subdirectory(tests)