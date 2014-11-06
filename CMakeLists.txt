cmake_minimum_required(VERSION 2.8.12)
set(PROJECT_NAME "raytracer")
project(${PROJECT_NAME} C CXX)

set(BUILD_DIR "${PROJECT_SOURCE_DIR}/build")
set(EXT_PROJECTS_DIR "${PROJECT_SOURCE_DIR}/ext")
set(INCLUDE_DIR_ARRAY "${PROJECT_SOURCE_DIR}/include")
set(SRC_DIR "${PROJECT_SOURCE_DIR}/src")
set(TEST_DIR "${PROJECT_SOURCE_DIR}/test")

include_directories(${INCLUDE_DIR_ARRAY})

find_package(Boost REQUIRED COMPONENTS serialization)
include_directories(${Boost_INCLUDE_DIRS})

include_directories(/usr/include/eigen3)

set(
	RAYTRACER_SOURCES
	# "${SRC_DIR}/AmbientLight.cpp"
	"${SRC_DIR}/BBox.cpp"
	"${SRC_DIR}/BRDF.cpp"
	# "${SRC_DIR}/DirectionalLight.cpp"
	"${SRC_DIR}/Globals.cpp"
	"${SRC_DIR}/GlossySpecularBRDF.cpp"
	"${SRC_DIR}/HammersleySampler.cpp"
	"${SRC_DIR}/JitteredSampler.cpp"
	"${SRC_DIR}/LambertianBRDF.cpp"
	# "${SRC_DIR}/Light.cpp"
	# "${SRC_DIR}/Material.cpp"
	# "${SRC_DIR}/Matte.cpp"
	"${SRC_DIR}/MultiJitteredSampler.cpp"
	"${SRC_DIR}/NRooksSampler.cpp"
	"${SRC_DIR}/PerfectSpecularBRDF.cpp"
	# "${SRC_DIR}/PointLight.cpp"
	"${SRC_DIR}/PureRandomSampler.cpp"
	"${SRC_DIR}/Ray.cpp"
	"${SRC_DIR}/RegularSampler.cpp"
	"${SRC_DIR}/RGBColor.cpp"
	"${SRC_DIR}/Sampler.cpp"
	"${SRC_DIR}/ShadeRec.cpp"
	"${SRC_DIR}/ViewPlane.cpp"
	)
add_library(RAYTRACER_LIBRARY OBJECT ${RAYTRACER_SOURCES})

add_executable(
	raytracer
	"${SRC_DIR}/main.cpp"
	$<TARGET_OBJECTS:RAYTRACER_LIBRARY>
	)

########################################################

option(test "Build all tests." ON)
if (test)
  enable_testing()
  set(PROJECT_TEST_NAME ${PROJECT_NAME}UnitTests)
  file(GLOB TEST_SRC_FILES ${TEST_DIR}/*Test.cpp)
  add_subdirectory(${EXT_PROJECTS_DIR}/gtest)
  include_directories(${GTEST_INCLUDE_DIRS})
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
  GTEST_ADD_TESTS(${PROJECT_TEST_NAME} "" ${TEST_SRC_FILES})
endif()
