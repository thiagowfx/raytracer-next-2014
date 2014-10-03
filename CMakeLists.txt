# Master CMake file for the project.
cmake_minimum_required(VERSION 2.8.12)

set(PROJECT_NAME_STR "raytracer")
project(${PROJECT_NAME_STR} C CXX)

######################################################

set(BUILD_DIR "{PROJECT_SOURCE_DIR}/build")
set(EXT_PROJECTS_DIR "${PROJECT_SOURCE_DIR}/ext")
set(INCLUDE_DIR_ARRAY "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

include_directories(${INCLUDE_DIR_ARRAY})

#######################################################

find_package(Boost REQUIRED COMPONENTS serialization)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(/usr/include/eigen3)

#######################################################

set(
	RAYTRACER_SOURCES
	"${SRC_DIR}/Globals.cpp"
	"${SRC_DIR}/ViewPlane.cpp"
	)
add_library(RAYTRACER_LIBRARY OBJECT ${RAYTRACER_SOURCES})

add_executable(
	main
	"${SRC_DIR}/main.cpp"
	$<TARGET_OBJECTS:RAYTRACER_LIBRARY>
	)

########################################################

option(test "Build all tests." ON)
if (test)
  enable_testing()
  add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
  include_directories(${GTEST_INCLUDE_DIRS})
  set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}UnitTests)
  file(GLOB TEST_SRC_FILES ${TEST_DIR}/*.cpp)
  add_executable(
	  ${PROJECT_TEST_NAME}
	  ${TEST_SRC_FILES}
	  $<TARGET_OBJECTS:RAYTRACER_LIBRARY>
	  )
  add_dependencies(${PROJECT_TEST_NAME} googletest)
  target_link_libraries(
	  ${PROJECT_TEST_NAME}
	  ${GTEST_LIBS_DIR}/libgtest.a
	  ${GTEST_LIBS_DIR}/libgtest_main.a
	  ${Boost_LIBRARIES}
	  pthread
	  )
  add_test(${PROJECT_TEST_NAME} ${PROJECT_TEST_NAME})
endif()
