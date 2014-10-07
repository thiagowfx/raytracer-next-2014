#include "gtest/gtest.h"
#include "GlossySpecularBRDF.hpp"
using Raytracer::GlossySpecular;
using Raytracer::RGBColor;

TEST(GlossySpecularTest, GetterSetterTest) {
	GlossySpecular g;

    g.set_ks(0.1);
    g.set_exp(0.1);
    g.set_cs(RGBColor(0.1, 0.1, 0.1));

	EXPECT_DOUBLE_EQ(0.1, g.get_ks());
	EXPECT_DOUBLE_EQ(0.1, g.get_exp());
	EXPECT_EQ(RGBColor(0.1, 0.1, 0.1), g.get_cs());
}

class GlossySpecularTestClass : public ::testing::Test {
 protected:
  virtual void SetUp() {
    x = new GlossySpecular();
    x_test = new GlossySpecular();

    x->set_ks(0.1);
    x->set_exp(0.1);
    x->set_cs(RGBColor(0.1, 0.1, 0.1));
  }

  virtual void TearDown() {
    delete x;
    delete x_test;
  }

  GlossySpecular* x;
  GlossySpecular* x_test;
};

TEST_F(GlossySpecularTestClass, XmlSerializationTest) {
  const char* filename = "GlossySpecular.xml";
  save_xml<GlossySpecular>(*x, filename);
  load_xml<GlossySpecular>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

TEST_F(GlossySpecularTestClass, BinarySerializationTest) {
  const char* filename = "GlossySpecular.bin";
  save_binary<GlossySpecular>(*x, filename);
  load_binary<GlossySpecular>(*x_test, filename);
  EXPECT_EQ(*x, *x_test);
}

