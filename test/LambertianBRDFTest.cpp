#include "gtest/gtest.h"
#include "LambertianBRDF.hpp"
using Raytracer::Lambertian;
using Raytracer::RGBColor;

TEST(LambertianTest, GetterSetterTest) {
  Lambertian l;

  l.set_kd(0.1);
  l.set_cd(RGBColor(0.1, 0.1, 0.1));

  EXPECT_DOUBLE_EQ(0.1, l.get_kd());
  EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), l.get_cd());
}

class LambertianTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new Lambertian();
    x_test = new Lambertian();

    x->set_kd(0.1);
    x->set_cd(RGBColor(0.1, 0.1, 0.1));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  Lambertian* x;
  Lambertian* x_test;
};

TEST_F(LambertianTestClass, XmlSerializationTest) {
  const char* filename = "Lambertian.xml";
  save_xml<Lambertian>(*x, filename);
  load_xml<Lambertian>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(LambertianTestClass, BinarySerializationTest) {
  const char* filename = "Lambertian.bin";
  save_binary<Lambertian>(*x, filename);
  load_binary<Lambertian>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
