#include "gtest/gtest.h"
#include "DirectionalLight.hpp"
using Raytracer::DirectionalLight;
using Raytracer::RGBColor;

TEST(DirectionalLightTest, GetterSetterTest) {
  DirectionalLight x;

  x->set_radiance(0.1);
  x->set_color(RGBColor(0.1, 0.1, 0.1));
  x->set_direction(Vector3d(0.1, 0.1, 0.1));

  EXPECT_DOUBLE_EQ(0.1, x->get_radiance());
  EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), x->get_color());
  EXPECT_EQ(Vector3d(0.1, 0.1, 0.1), x->get_direction());
}

class DirectionalLightTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new DirectionalLight();
    x_test = new DirectionalLight();

    x->set_radiance(0.1);
    x->set_color(RGBColor(0.1, 0.1, 0.1));
    x->set_direction(Vector3d(0.1, 0.1, 0.1));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  DirectionalLight* x;
  DirectionalLight* x_test;
};

TEST_F(DirectionalLightTestClass, XmlSerializationTest) {
  const char* filename = "DirectionalLight.xml";
  save_xml<DirectionalLight>(*x, filename);
  load_xml<DirectionalLight>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(DirectionalLightTestClass, BinarySerializationTest) {
  const char* filename = "DirectionalLight.bin";
  save_binary<DirectionalLight>(*x, filename);
  load_binary<DirectionalLight>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
