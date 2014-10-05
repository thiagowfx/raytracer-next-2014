#include <cstdio>
#include <iostream>
#include "ViewPlane.hpp"
using namespace std;
using namespace Raytracer;

int main() {
  ViewPlane vp;
  vp.set_hres(101);
  cout << vp.get_hres() << endl;
  cout << "Hello World!" << endl;
  return 0;
}
