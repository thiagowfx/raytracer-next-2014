#include "gtest/gtest.h"
#include "JitteredSampler.hpp"
using Raytracer::Jittered;

class JitteredTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new Jittered(10);
    x_test = new Jittered();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  Jittered* x;
  Jittered* x_test;
};

TEST_F(JitteredTestClass, XmlSerializationTest) {
  const char* filename = "Jittered.xml";
  save_xml<Jittered>(*x, filename);
  load_xml<Jittered>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(JitteredTestClass, BinarySerializationTest) {
  const char* filename = "Jittered.bin";
  save_binary<Jittered>(*x, filename);
  load_binary<Jittered>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

