#include "gtest/gtest.h"
#include "ViewPlane.hpp"
using Raytracer::ViewPlane;

TEST(ViewPlaneTest, GetterSetterTest) {
  ViewPlane v;

  v.set_hres(10);
  v.set_vres(10);
  v.set_pixel_size(10.0);
  v.set_gamma(0.5);
  v.set_out_of_gamut(false);
  v.set_max_depth(10);

  EXPECT_EQ(10, v.get_hres());
  EXPECT_EQ(10, v.get_vres());
  EXPECT_FLOAT_EQ(10.0, v.get_pixel_size());
  EXPECT_EQ(0.5, v.get_gamma());
  EXPECT_FALSE(v.get_out_of_gamut());
  EXPECT_EQ(10, v.get_max_depth());
}

class ViewPlaneTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new ViewPlane();
    x_test = new ViewPlane();

    x->set_hres(10);
    x->set_vres(10);
    x->set_pixel_size(10.0);
    x->set_gamma(0.5);
    x->set_out_of_gamut(false);
    x->set_max_depth(10);
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  ViewPlane* x;
  ViewPlane* x_test;
};

TEST_F(ViewPlaneTestClass, XmlSerializationTest) {
  const char* filename = "ViewPlane.xml";
  save_xml<ViewPlane>(*x, filename);
  load_xml<ViewPlane>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(ViewPlaneTestClass, BinarySerializationTest) {
  const char* filename = "ViewPlane.bin";
  save_binary<ViewPlane>(*x, filename);
  load_binary<ViewPlane>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
