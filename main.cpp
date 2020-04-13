#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>


#include "imagehelpers.h"
#include "shapes.cpp"
int main() {
  nothing("inImage.pgm");
  invert("walter.pgm");
  invertHalf("walter.pgm");
  box("walter.pgm");
  frame("inImage.pgm");
  scale("walter.pgm");
  pixelate("inImage.pgm");
}
