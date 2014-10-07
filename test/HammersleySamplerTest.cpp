#include "gtest/gtest.h"
#include "HammersleySampler.hpp"
using Raytracer::Hammersley;

class HammersleyTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new Hammersley(10);
    x_test = new Hammersley();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  Hammersley* x;
  Hammersley* x_test;
};

TEST_F(HammersleyTestClass, XmlSerializationTest) {
  const char* filename = "Hammersley.xml";
  save_xml<Hammersley>(*x, filename);
  load_xml<Hammersley>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(HammersleyTestClass, BinarySerializationTest) {
  const char* filename = "Hammersley.bin";
  save_binary<Hammersley>(*x, filename);
  load_binary<Hammersley>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

