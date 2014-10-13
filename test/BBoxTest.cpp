#include "gtest/gtest.h"
#include "BBox.hpp"
using Raytracer::BBox;
using Eigen::Vector3d;

TEST(BBoxTest, hitTest) {
  BBox b(Vector3d(0.0, 0.0, 0.0), Vector3d(1.0, 1.0, 1.0));
  EXPECT_FALSE(
      b.hit(Raytracer::Ray(Vector3d(-2.0, 0.0, 0.0), Vector3d(1.0, 0.0, 0.0))));
  EXPECT_TRUE(
      b.hit(Raytracer::Ray(Vector3d(-2.0, 0.1, 0.1), Vector3d(1.0, 0.0, 0.0))));
  EXPECT_FALSE(b.hit(
      Raytracer::Ray(Vector3d(-2.0, 0.1, 0.1), Vector3d(-1.0, 0.0, 0.0))));
}

TEST(BBoxTest, insideTest) {
  BBox b(Vector3d(0.0, 0.0, 0.0), Vector3d(1.0, 1.0, 1.0));
  EXPECT_TRUE(b.inside(Vector3d(0.5, 0.5, 0.5)));
  EXPECT_TRUE(b.inside(Vector3d(0.9, 0.9, 0.1)));
  EXPECT_FALSE(b.inside(Vector3d(2.0, 2.0, 2.0)));
  EXPECT_FALSE(b.inside(Vector3d(1.0, 0.0, 0.0)));
  EXPECT_FALSE(b.inside(Vector3d(1.0, 1.0, 1.0)));
}

class BBoxTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new BBox(0.0, 0.1, 0.2, 0.3, 0.4, 0.5);
    x_test = new BBox();
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  BBox* x;
  BBox* x_test;
};

TEST_F(BBoxTestClass, XmlSerializationTest) {
  const char* filename = "BBox.xml";
  save_xml<BBox>(*x, filename);
  load_xml<BBox>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(BBoxTestClass, BinarySerializationTest) {
  const char* filename = "BBox.bin";
  save_binary<BBox>(*x, filename);
  load_binary<BBox>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
