#include "gtest/gtest.h"
#include "Matte.hpp"
using Raytracer::Matte;
using Raytracer::RGBColor;

TEST(MatteTest, GetterSetterTest) {
	Matte m;

    m.set_ka(0.1);
    m.set_kd(0.1);
    m.set_cd(RGBColor(0.1, 0.1, 0.1);

	EXPECT_DOUBLE_EQ(0.1, m.get_ka());
	EXPECT_DOUBLE_EQ(0.1, m.get_kd());
	EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), m.get)cd());
}

class MatteTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new Matte();
    x_test = new Matte();

    x->set_ka(0.1);
    x->set_kd(0.1);
    x->set_cd(RGBColor(0.1, 0.1, 0.1);
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  Matte* x;
  Matte* x_test;
};

TEST_F(MatteTestClass, XmlSerializationTest) {
  const char* filename = "Matte.xml";
  save_xml<Matte>(*x, filename);
  load_xml<Matte>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(MatteTestClass, BinarySerializationTest) {
  const char* filename = "Matte.bin";
  save_binary<Matte>(*x, filename);
  load_binary<Matte>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

