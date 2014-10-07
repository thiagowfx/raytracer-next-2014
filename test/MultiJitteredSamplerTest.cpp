#include "gtest/gtest.h"
#include "MultiJitteredSampler.hpp"
using Raytracer::MultiJittered;

class MultiJitteredTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new MultiJittered(10);
    x_test = new MultiJittered();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  MultiJittered* x;
  MultiJittered* x_test;
};

TEST_F(MultiJitteredTestClass, XmlSerializationTest) {
  const char* filename = "MultiJittered.xml";
  save_xml<MultiJittered>(*x, filename);
  load_xml<MultiJittered>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(MultiJitteredTestClass, BinarySerializationTest) {
  const char* filename = "MultiJittered.bin";
  save_binary<MultiJittered>(*x, filename);
  load_binary<MultiJittered>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

