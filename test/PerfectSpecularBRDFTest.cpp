#include "gtest/gtest.h"
#include "PerfectSpecularBRDF.hpp"
using Raytracer::PerfectSpecular;
using Raytracer::RGBColor;

TEST(PerfectSpecularTest, GetterSetterTest) {
  PerfectSpecular p;

  p.set_kr(0.1);
  p.set_cr(RGBColor(0.1, 0.1, 0.1));

  EXPECT_DOUBLE_EQ(0.1, p.get_kr());
  EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), p.get_cr());
}

class PerfectSpecularTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new PerfectSpecular();
    x_test = new PerfectSpecular();

    x->set_kr(0.1);
    x->set_cr(RGBColor(0.1, 0.1, 0.1));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  PerfectSpecular* x;
  PerfectSpecular* x_test;
};

TEST_F(PerfectSpecularTestClass, XmlSerializationTest) {
  const char* filename = "PerfectSpecular.xml";
  save_xml<PerfectSpecular>(*x, filename);
  load_xml<PerfectSpecular>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(PerfectSpecularTestClass, BinarySerializationTest) {
  const char* filename = "PerfectSpecular.bin";
  save_binary<PerfectSpecular>(*x, filename);
  load_binary<PerfectSpecular>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
