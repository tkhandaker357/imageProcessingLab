#include <iostream>
#include <string>

#include "funcs.hpp"

auto main(int argc, const char** argv) -> int {
    if (argc < 3 && argv[1] != "help") {
        std::cout << "Not enough arguments. Type \"help\" to learn commands.\n";
        return 0;
    }

    if (argv[1] == "help") {
        std::cout << "main [FILE NAME] [COMMAND] -o [OUTPUT NAME]\n";
        std::cout << "File in [FILE NAME] must be in .pgm format.\n \
                      Output name is optional. Default is \"outImage.pgm\"";
        std::cout << "Commands (case sensitive) include:\n";
        std::cout << "\tinvert_image_color\n\tinvert_right_half\n\tadd_white_box\n\tadd_frame \
                      \n\tscale_twice\n\tpixelate";
        return 0;
    }

    std::string filename{ argv[1] }, command{ argv[2] }, outputFile{ "outImage.pgm" };
    if (argc > 3) {
        std::string command2 { argv[3] };
        if (command2 == "-o") {
            outputFile = argv[4];
        }
    }

    if (command == "invert_image_color") {
        invertImageColor(filename, outputFile);
    } else if (command == "invert_right_half") {
        invertRightHalf(filename, outputFile);
    } else if (command == "add_white_box") {
        addWhiteBox(filename, outputFile);
    } else if (command == "add_frame") {
        addBoxFrame(filename, outputFile);
    } else if (command == "scale_twice") {
        scaleTwice(filename, outputFile);
    } else if (command == "pixelate") {
        pixelate(filename, outputFile);
    } else if (command == "all") {
        invertImageColor(filename, outputFile);
        invertRightHalf(filename, outputFile);
        addWhiteBox(filename, outputFile);
        addBoxFrame(filename, outputFile);
        scaleTwice(filename, outputFile);
        pixelate(filename, outputFile);
    }

    return 0;
}