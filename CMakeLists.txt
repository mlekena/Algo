# Specify the minimum version for CMake

cmake_minimum_required(VERSION 2.8)

#Project's name

project(algo)

# Set default build Type
if(NOT CMAKE_BUILD_TYPE)
  message(STATUS "Setting build type to 'RelWithDebInfo' as non was specified.")
  set(CMAKE_BUILD_TYPE "RelWithDebInfo" CACHE STRING
    "Choose the type of build, options are: Debug Release RelWithDebInfo MinSizeRel."
    FORCE)
endif()

set(CMAKE_CXX_FLAGS "-std=c++11 -W -Wall -Wno-sign-compare")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O2")
set(CMAKE_CXX_FLAGS_RELWITHDEBINFO "-O2 -g")

if(DEFINED ENV{CXXFLAGS})
  set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} $ENV{CXXFLAGS}")
endif()

# Check out Git submodules.
if (EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.gitmodules")
  execute_process (COMMAND git submodule update --init --recursive
                   WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif()

# Set output folders where program will be created
set(CMAKE_BINARY_DIR ${CMAKE_SOURCE_DIR}/bin)
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(LIBRARY_OUTPUT_PATH ${CMAKE_BINARY_DIR})
set(SRC_DIR ${CMAKE_SOURCE_DIR}/src)

add_library(libalgo
  ${SRC_DIR}/linked_list.cc
  )

set(LIBALGO libalgo)

include_directories("${SRC_DIR}")

add_executable(hello ${SRC_DIR}/helloworld.cc)

add_executable(main ${SRC_DIR}/main.cc)
target_link_libraries(main "${LIBALGO}")


# TESTING 
include(CTest)

enable_testing()

if(BUILD_TESTING)
  add_subdirectory(thirdparty/googletest)
  include_directories(thirdparty/googletest/googletest/include)
  include_directories(thirdparty/googletest/googlemock/include)

    # algotest
  set(TEST_TARGETS
    linked_list_test
    )

  foreach(target ${TEST_TARGETS})
    add_executable(${target} tests/${target}.cc)
    target_link_libraries(${target} "${LIBALGO}" gtest_main gmock)
  endforeach(target)

  # add_test(NAME range_map_test COMMAND range_map_test)
  #   add_test(NAME bloaty_test_x86-64 COMMAND bloaty_test WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/tests/testdata/linux-x86_64)
  add_test(NAME linked_list_test COMMAND linked_list_test)
endif()