#include "gtest/gtest.h"
#include "AmbientLight.hpp"
using Raytracer::AmbientLight;
using Raytracer::Light;
using Raytracer::RGBColor;

TEST(AmbientLightTest, GetterSetterTest) {
	AmbientLight x;

	x.set_radiance(0.1);
	x.set_color(RGBColor(0.1, 0.1, 0.1));
	x.set_shadows(true);

	EXPECT_DOUBLE_EQ(0.1, x.get_radiance());
	EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), x.get_color());
	EXPECT_FALSE(x.get_shadows());

	Light* y = new AmbientLight();
	y->set_shadows(true);
	EXPECT_FALSE(y->get_shadows());
}

class AmbientLightTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new AmbientLight();
    x_test = new AmbientLight();

    x->set_radiance(0.1);
    x->set_color(RGBColor(0.1, 0.1, 0.1));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  AmbientLight* x;
  AmbientLight* x_test;
};

TEST_F(AmbientLightTestClass, XmlSerializationTest) {
  const char* filename = "AmbientLight.xml";
  save_xml<AmbientLight>(*x, filename);
  load_xml<AmbientLight>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(AmbientLightTestClass, BinarySerializationTest) {
  const char* filename = "AmbientLight.bin";
  save_binary<AmbientLight>(*x, filename);
  load_binary<AmbientLight>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

