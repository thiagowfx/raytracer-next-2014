#include "gtest/gtest.h"
#include "NRooksSampler.hpp"
using Raytracer::NRooks;

class NRooksTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new NRooks(10);
    x_test = new NRooks();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  NRooks* x;
  NRooks* x_test;
};

TEST_F(NRooksTestClass, XmlSerializationTest) {
  const char* filename = "NRooks.xml";
  save_xml<NRooks>(*x, filename);
  load_xml<NRooks>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(NRooksTestClass, BinarySerializationTest) {
  const char* filename = "NRooks.bin";
  save_binary<NRooks>(*x, filename);
  load_binary<NRooks>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
