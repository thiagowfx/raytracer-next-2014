#include "gtest/gtest.h"
#include "Ray.hpp"
using Raytracer::Ray;

TEST(RayTest, GetterSetterTest) {
  Ray r;

  r.set_origin(Vector3d(0.1, 0.1, 0.1));
  r.set_direction(Vector3d(0.1, 0.1, 0.1));

  EXPECT_EQ(r.get_origin(), Vector3d(0.1, 0.1, 0.1));
  EXPECT_EQ(r.get_direction(), Vector3d(0.1, 0.1, 0.1));
}

class RayTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new Ray();
    x_test = new Ray();

    x->set_origin(Vector3d(0.0, 0.1, 0.2));
    x->set_direction(Vector3d(0.3, 0.4, 0.5));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  Ray* x;
  Ray* x_test;
};

TEST_F(RayTestClass, XmlSerializationTest) {
  const char* filename = "Ray.xml";
  save_xml<Ray>(*x, filename);
  load_xml<Ray>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(RayTestClass, BinarySerializationTest) {
  const char* filename = "Ray.bin";
  save_binary<Ray>(*x, filename);
  load_binary<Ray>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
