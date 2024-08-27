#pragma once

#include <iostream>
#include <string>
#include "imageio.h"

auto invertValue(int value) -> int;
auto invertImageColor(std::string imageName) -> void;
auto invertRightHalf(std::string imageName) -> void;
auto addWhiteBox(std::string imageName) -> void;
auto addBoxFrame(std::string imageName) -> void;
auto scaleTwice(std::string imageName) -> void;
auto pixelate(std::string imageName) -> void;
