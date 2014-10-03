# Google Test C++ library.
# Taken from: https://github.com/snikulov/google-test-examples
project(gtest_builder C CXX)
include(ExternalProject)

ExternalProject_Add(googletest
    SVN_REPOSITORY "http://googletest.googlecode.com/svn/trunk"
    PREFIX "${CMAKE_CURRENT_BINARY_DIR}"
    UPDATE_COMMAND ""
    INSTALL_COMMAND ""
)

# Specify include directory.
ExternalProject_Get_Property(googletest source_dir)
set(GTEST_INCLUDE_DIRS ${source_dir}/include PARENT_SCOPE)

# Specify MainTest link libraries.
ExternalProject_Get_Property(googletest binary_dir)
set(GTEST_LIBS_DIR ${binary_dir} PARENT_SCOPE)
