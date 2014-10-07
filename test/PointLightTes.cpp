#include "gtest/gtest.h"
#include "PointLight.hpp"
using Raytracer::PointLight;
using Raytracer::RGBColor;

TEST(PointLightTest, GetterSetterTest) {
  PointLight p;

  p.set_radiance(0.1);
  p.set_color(RGBColor(0.1, 0.1, 0.1));
  p.set_location(Vector3d(0.1, 0.1, 0.1));

  EXPECT_DOUBLE_EQ(0.1, p.get_radiance());
  EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), p.get_color());
  EXPECT_EQ(Vector3d(0.1, 0.1, 0.1), p.get_location());
}

class PointLightTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new PointLight();
    x_test = new PointLight();

    x->set_radiance(0.1);
    x->set_color(RGBColor(0.1, 0.1, 0.1));
    x->set_location(Vector3d(0.1, 0.1, 0.1));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  PointLight* x;
  PointLight* x_test;
};

TEST_F(PointLightTestClass, XmlSerializationTest) {
  const char* filename = "PointLight.xml";
  save_xml<PointLight>(*x, filename);
  load_xml<PointLight>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(PointLightTestClass, BinarySerializationTest) {
  const char* filename = "PointLight.bin";
  save_binary<PointLight>(*x, filename);
  load_binary<PointLight>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
