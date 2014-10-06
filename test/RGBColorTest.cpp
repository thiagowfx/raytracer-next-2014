#include "gtest/gtest.h"
#include "RGBColor.hpp"
using Raytracer::RGBColor;

TEST(RGBColorTest, clampToRedTest) {
  RGBColor c(0.5, 0.5, 0.5);
  EXPECT_EQ(c, c.clamp_to_red());

  RGBColor d(2.0, 1.0, 1.0);
  EXPECT_EQ(RGBColor(1.0, 0.0, 0.0), d.clamp_to_red());
}

TEST(RGBColorTest, normalizeTest) {
  RGBColor c(0.5, 0.5, 0.5);
  EXPECT_EQ(c, c.normalize());

  RGBColor d(2.0, 1.0, 1.0);
  EXPECT_EQ(RGBColor(1.0, 0.5, 0.5), d.normalize());
}

TEST(RGBColorTest, averageTest) {
  RGBColor c(0.3, 0.3, 0.3);
  EXPECT_FLOAT_EQ(0.3, c.average());
}

TEST(RGBColorTest, powcTest) {
  RGBColor c(0.5, 0.5, 0.5);
  EXPECT_TRUE(c.powc(2) == RGBColor(0.25, 0.25, 0.25));
}

TEST(RGBColorTest, operatorEqualTest) {
  RGBColor c(0.1, 0.1, 0.1);
  RGBColor d, e;
  e = d = c;
  EXPECT_TRUE(d == c);
  EXPECT_TRUE(e == d);
}

TEST(RGBColorTest, operatorCompareTest) {
  RGBColor c(0.1, 0.1, 0.1);
  RGBColor d(0.1, 0.1, 0.1);
  EXPECT_TRUE(c == d);
}

TEST(RGBColorTest, operatorTimesTest) {
  RGBColor c(0.1, 0.1, 0.1);
  RGBColor d = 3 * c;
  EXPECT_FLOAT_EQ(0.3, d.get_r());
  EXPECT_FLOAT_EQ(0.3, d.get_g());
  EXPECT_FLOAT_EQ(0.3, d.get_b());
}

TEST(RGBColorTest, operatorPlusTest) {
  RGBColor c(0.1, 0.1, 0.1);
  c += RGBColor(0.2, 0.2, 0.2);
  EXPECT_FLOAT_EQ(0.3, c.get_r());
  EXPECT_FLOAT_EQ(0.3, c.get_g());
  EXPECT_FLOAT_EQ(0.3, c.get_b());
}

TEST(RGBColorTest, operatorPlusEqualTest) {
  RGBColor c(0.1, 0.1, 0.1);
  RGBColor d(0.2, 0.2, 0.2);
  d += c;
  EXPECT_FLOAT_EQ(0.3, d.get_r());
  EXPECT_FLOAT_EQ(0.3, d.get_g());
  EXPECT_FLOAT_EQ(0.3, d.get_b());
}

TEST(RGBColorTest, GetterSetterTest) {
  RGBColor c;

  c.set_r(0.1);
  c.set_g(0.1);
  c.set_b(0.1);

  EXPECT_FLOAT_EQ(0.1, c.get_r());
  EXPECT_FLOAT_EQ(0.1, c.get_g());
  EXPECT_FLOAT_EQ(0.1, c.get_b());
}

class RGBColorTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new RGBColor();
    x_test = new RGBColor();

    x->set_r(0.1);
    x->set_g(0.1);
    x->set_b(0.1);
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  RGBColor* x;
  RGBColor* x_test;
};

TEST_F(RGBColorTestClass, XmlSerializationTest) {
  const char* filename = "RGBColor.xml";
  save_xml<RGBColor>(*x, filename);
  load_xml<RGBColor>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(RGBColorTestClass, BinarySerializationTest) {
  const char* filename = "RGBColor.bin";
  save_binary<RGBColor>(*x, filename);
  load_binary<RGBColor>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}
