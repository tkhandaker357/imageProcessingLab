#include <iostream>
#include <cassert>
#include <cstdlib>
#include <fstream>

#include "funcs.hpp"

void readImage(std::string filename, int image[MAX_H][MAX_W], int &height, int &width) {
	char c;
	int x;
	std::ifstream instr;
	instr.open(filename);

	// read the header P2
	instr >> c;
	assert(c == 'P');
	instr >> c;
	assert(c == '2');

	// skip the comments (if any)
	while ((instr>>std::ws).peek() == '#') {
		instr.ignore(4096, '\n');
	}

	instr >> width;
	instr >> height;

	assert(width <= MAX_W);
	assert(height <= MAX_H);
	int max;
	instr >> max;
	assert(max == 255);

	for (int row = 0; row < height; row++)
		for (int col = 0; col < width; col++)
			instr >> image[row][col];
	instr.close();
	return;
}


// Writes a PGM file
// Need to provide the array data and the image dimensions
void writeImage(std::string filename, int image[MAX_H][MAX_W], int height, int width) {
	std::ofstream ostr;
	ostr.open(filename);
	if (ostr.fail()) {
		std::cout << "Unable to write file\n";
		exit(1);
	};

	// print the header
	ostr << "P2" << std::endl;
	// width, height
	ostr << width << ' ';
	ostr << height << std::endl;
	ostr << 255 << std::endl;

	for (int row = 0; row < height; row++) {
		for (int col = 0; col < width; col++) {
		    assert(image[row][col] < 256);
			assert(image[row][col] >= 0);
			ostr << image[row][col] << ' ';
			ostr << std::endl;
		}
	}
	ostr.close();
	return;
}

auto invertValue(int value) -> int {
    if (value < 0 || value > 255) {
        return -1;
    }

    return 255 - value;
}

auto invertImageColor(std::string imageName, std::string outputName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height; ++i) {
        for (size_t j{ 0 }; j < width; ++j) {
            outputImage[i][j] = 255 - image[i][j];
        }
    }

    writeImage(outputName, outputImage, height, width);
}

auto invertRightHalf(std::string imageName, std::string outputName) -> void {
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

    writeImage(outputName, outputImage, height, width);
}

auto addWhiteBox(std::string imageName, std::string outputName) -> void {
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

    writeImage(outputName, outputImage, height, width);
}

auto addBoxFrame(std::string imageName, std::string outputName) -> void {
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

    writeImage(outputName, outputImage, height, width);
}

auto scaleTwice(std::string imageName, std::string outputName) -> void {
    int height, width;
    int image[MAX_H][MAX_W];
    readImage(imageName, image, height, width);

    int outputImage[MAX_H][MAX_W];
    for (size_t i{ 0 }; i < height * 2; ++i) {
        for (size_t j{ 0 }; j < width * 2; ++j) {
            outputImage[i][j] = image[i / 2][j / 2];
        }
    }

    writeImage(outputName, outputImage, height * 2, width * 2);
}

auto pixelate(std::string imageName, std::string outputName) -> void {
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
    writeImage(outputName, outputImage, height, width);
}
