#pragma once

#include <iostream>
#include <string>

const int MAX_H{ 512 };
const int MAX_W{ 512 };

auto readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) -> void;
auto writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width) -> void;
auto invertValue(int value) -> int;
auto invertImageColor(std::string imageName, std::string outputName = "outImage.pgm") -> void;
auto invertRightHalf(std::string imageName, std::string outputName = "outImage.pgm") -> void;
auto addWhiteBox(std::string imageName, std::string outputName = "outImage.pgm") -> void;
auto addBoxFrame(std::string imageName, std::string outputName = "outImage.pgm") -> void;
auto scaleTwice(std::string imageName, std::string outputName = "outImage.pgm") -> void;
auto pixelate(std::string imageName, std::string outputName = "outImage.pgm") -> void;
