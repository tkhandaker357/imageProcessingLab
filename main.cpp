#include <iostream>
#include <string>

#include "invert.hpp"

auto main() -> int {
    invertImageColor("inImage.pgm");
    invertRightHalf("inImage.pgm");
    addWhiteBox("inImage.pgm");
    addBoxFrame("inImage.pgm");
    scaleTwice("inImage.pgm");
    pixelate("inImage.pgm");

    return 0;
}