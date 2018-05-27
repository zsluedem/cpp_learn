cmake_minimum_required(VERSION 3.7)
project(event_boost)

set(CMAKE_CXX_STANDARD 11)
FIND_PACKAGE(PythonInterp)
find_package(PythonLibs 3 REQUIRED)
if(${PYTHONLIBS_FOUND})
    message(STATUS "Python libraries ${PYTHON_LIBRARIES}")
    message(STATUS "Python include dir ${PYTHON_INCLUDE_DIRS}")
    include_directories(${PYTHON_INCLUDE_DIRS})
endif()

find_package(Boost 1.65 REQUIRED python)
if(Boost_FOUND)
    include_directories(${Boost_INCLUDE_DIRS})
endif()

PYTHON_ADD_MODULE(order order.cpp)

#set(SOURCE_FILES library.cpp library.h b.cpp)

#add_library(event_boost ${SOURCE_FILES})

