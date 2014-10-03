#!/bin/bash
# Scaffold a new test file.

[[ "$1" == "" ]] && echo "No arguments provided. Usage: $0 ClassName" && exit

cat << EOF > "$1Test.cpp"
#include "gtest/gtest.h"
#include "$1.hpp"
using Raytracer::$1;

TEST($1Test, Test0) {
    EXPECT_EQ(true, true);
}

class $1TestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new $1();
    x_test = new $1();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  $1* x;
  $1* x_test;
};

TEST_F($1TestClass, XmlSerializationTest) {
  const char* filename = "$1.xml";
  save_xml<$1>(*x, filename);
  load_xml<$1>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F($1TestClass, BinarySerializationTest) {
  const char* filename = "$1.bin";
  save_binary<$1>(*x, filename);
  load_binary<$1>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

EOF

