#include "gtest/gtest.h"
#include "PureRandomSampler.hpp"
using Raytracer::PureRandom;

class PureRandomTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new PureRandom(10);
    x_test = new PureRandom();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  PureRandom* x;
  PureRandom* x_test;
};

TEST_F(PureRandomTestClass, XmlSerializationTest) {
  const char* filename = "PureRandom.xml";
  save_xml<PureRandom>(*x, filename);
  load_xml<PureRandom>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(PureRandomTestClass, BinarySerializationTest) {
  const char* filename = "PureRandom.bin";
  save_binary<PureRandom>(*x, filename);
  load_binary<PureRandom>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
