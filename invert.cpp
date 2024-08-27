#include <iostream>
#include <string>
#include "imageio.h"

auto invertValue(int value) -> int {
    if (value < 0 || value > 255) {
        return -1;
    }

    return 255 - value;
}

auto invertImageColor(std::string imageName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height; ++i) {
        for (size_t j{ 0 }; j < width; ++j) {
            outputImage[i][j] = 255 - image[i][j];
        }
    }

    writeImage("taskA.pgm", outputImage, height, width);
}

auto invertRightHalf(std::string imageName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height; ++i) {
        for (size_t j{ 0 }; j < width; ++j) {
            if (j >= (width / 2)) {
                outputImage[i][j] = invertValue(image[i][j]);    
            }
            else {
                outputImage[i][j] = image[i][j];
            }
        }
    }

    writeImage("taskB.pgm", outputImage, height, width);
}

auto addWhiteBox(std::string imageName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int boxStart[4] { (height / 2) - height / 4, (width / 2) - width / 4, (height / 2) + height / 4, (width / 2) + width / 4  };
    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height; ++i) {
        for (size_t j{ 0 }; j < width; ++j) {
            if ((i >= boxStart[0] && j >= boxStart[1]) && (i <= boxStart[2] && j <= boxStart[3])) {
                outputImage[i][j] = 255;
            }
            else {
                outputImage[i][j] = image[i][j];
            }
        }
    }

    writeImage("taskC.pgm", outputImage, height, width);
}

auto addBoxFrame(std::string imageName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int boxStart[4] { (height / 2) - height / 4, (width / 2) - width / 4, (height / 2) + height / 4, (width / 2) + width / 4  };
    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height; ++i) {
        for (size_t j{ 0 }; j < width; ++j) {
            if (((i == boxStart[0] || i == boxStart[2]) && (j >= boxStart[1] && j <= boxStart[3])) ||
                ((j == boxStart[1] || j == boxStart[3]) && (i >= boxStart[0] && i <= boxStart[2]))) {
                outputImage[i][j] = 255;
            }
            else {
                outputImage[i][j] = image[i][j];
            }
        }
    }

    writeImage("taskD.pgm", outputImage, height, width);
}

auto scaleTwice(std::string imageName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height * 2; ++i) {
        for (size_t j{ 0 }; j < width * 2; ++j) {
            outputImage[i][j] = image[i / 2][j / 2];
        }
    }

    writeImage("taskE.pgm", outputImage, height * 2, width * 2);
}

auto pixelate(std::string imageName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int outputImage[MAX_H][MAX_W];
    int avg{ 0 }, count{ 0 };
    for (size_t i{ 0 }; i < height; ++i) {
        for (size_t j{ 0 }; j < width; ++j) {
            if (count % 2 == 0) 
                avg = ((image[i][j] + image[i + 1][j] + image[i + 1][j + 1] + image[i + 1][j]) / 4);
            outputImage[i][j] = avg;
            ++count;
        }
    }
    writeImage("taskF.pgm", outputImage, height, width);
}