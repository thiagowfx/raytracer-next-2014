#include "gtest/gtest.h"
#include "RegularSampler.hpp"
using Raytracer::Regular;

class RegularTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new Regular(10);
    x_test = new Regular();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  Regular* x;
  Regular* x_test;
};

TEST_F(RegularTestClass, XmlSerializationTest) {
  const char* filename = "Regular.xml";
  save_xml<Regular>(*x, filename);
  load_xml<Regular>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(RegularTestClass, BinarySerializationTest) {
  const char* filename = "Regular.bin";
  save_binary<Regular>(*x, filename);
  load_binary<Regular>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

