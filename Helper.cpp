#include "Helper.h"
#include <string>
#include <vector>
#include <iostream>
#include <iomanip>

void Helper::welcomeMessage() {
    std::cout << "Welcome. These are the commands of this program:" << std::endl;
    std::cout << "-- addR  x  y  height  width: adds a circle with the given parameters to the vector." << std::endl;
    std::cout << "-- addS  x  y  edge: adds a square with the given parameters to the vector." << std::endl;
    std::cout << "-- addC  x  y  radius: adds a circle with the given parameters to the vector." << std::endl;
    std::cout << "-- move  shapeindex  x  y: moves the shape at the given index to the new x and y values."
              << std::endl;
    std::cout << "-- scale  shapeindex  x  y: scales the shape at the given index to the x and y values." << std::endl;
    std::cout << "-- display: displays the details of all the shapes currently in the vector." << std::endl;
    std::cout << "-- clear: deletes all the shapes currently in the vector and releases the memory.\n" << std::endl;
}


bool Helper::verifyInput(std::vector<std::string> &userInput) {
    bool valid = true;

    if (userInput[0] == "exit") {
        return false;
    } else if (userInput[0] == "addR") {
        // Checks to see if more or less of the required parameters are given
        if (userInput.size() > 5 || userInput.size() < 5) {
            valid = false;
            std::cerr << "\nPlease enter 5 arguments." << std::endl;
        }
    } else if (userInput[0] == "addS" || userInput[0] == "addC" || userInput[0] == "move" || userInput[0] == "scale") {
        // Checks to see if more or less of the required parameters are given
        if (userInput.size() > 4 || userInput.size() < 4) {
            valid = false;
            std::cerr << "\nPlease enter 4 arguments." << std::endl;
        }
    } else if (userInput[0] == "display" || userInput[0] == "clear") {
        return true;
    }

    return valid;
}

void Helper::showAllShapes(const std::vector<Shape *> &shapes) {
    std::cout << "\n" << shapes.size() << " shape(s) currently stored in the container." << std::endl;

    if (!shapes.empty()) {
        std::cout << "Current shapes: " << std::endl;
        for (auto i: shapes) {
            std::cout << *i;
            std::cout << "---------------------------------" << std::endl;
        }
    }
}

bool Helper::verifyScaling(std::vector<std::string> &userInput, Shape *shape) {
    bool valid = true;

    try {
        // Convert the user input to floats
        float x = stof(userInput[2]);
        float y = stof(userInput[3]);

        if (shape->isIsotropic()) {
            // Using an epsilon number to check if the floats are equal
            bool isEqual = abs(x - y) <= 0.000001;

            if (!isEqual) {
                throw "Numbers must be equal to scale square or circle shapes.";
            }

            valid = checkNegative(x);
            valid = checkNegative(y);

            if (!valid) {
                throw "Integer cannot be negative.";
            }

        }
    }
    catch (std::invalid_argument const &e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        std::cerr << "Please enter either integers or floats as your secondary arguments." << std::endl;
        valid = false;
    }
    catch (const char *e) {
        std::cerr << "\nError: " << e << std::endl;
        valid = false;
    }


    return valid;
}

bool Helper::verifyInt(std::vector<std::string> &userInput) {
    bool valid = true;

    try {
        // Allow user to enter a float value for scale command only
        if (userInput[0] != "scale") {
            for (int i = 1; i < userInput.size(); i++) {
                // Iterate through each char
                for (int j = 0; j < userInput[i].size(); j++) {
                    // Check see if the argument contains '.', if so then it's not an integer
                    if (userInput[i][j] == '.') {
                        valid = false;
                        throw "Argument must be an integer.";
                    }
                }

                // Convert the char to string, so it can be used with stoi
                int newI = stoi(std::string(userInput[i]));

                valid = checkNegative(newI);

                if (!valid) {
                    valid = false;
                    throw "Integer cannot be negative.";
                }
            }

            // Just check scale command uses non-negative numbers, but allow floats
        } else {
            for (int i = 1; i < userInput.size(); i++) {
                int newI = stoi(std::string(userInput[i]));

                valid = checkNegative(newI);

                if (!valid) {
                    valid = false;
                    throw "Integer cannot be negative.";
                }
            }
        }
    }
    catch (std::invalid_argument const &e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        std::cerr << "Please enter only integers as your secondary arguments." << std::endl;
        valid = false;
    }
    catch (const char *e) {
        std::cerr << "\nError: " << e << std::endl;
    }

    return valid;
}

void Helper::deleteAllShapes(std::vector<Shape *> &shapes) {
    std::cout << "\nDeleting all shapes in the shape container:" << std::endl;
    for (auto i: shapes) {
        delete i;
    }

    // Shapes is passed by reference so can be cleared inside this function when called
    shapes.clear();
}

bool Helper::verifyIndex(std::vector<Shape *> &shapes, int index) {
    bool valid = true;

    try {
        if (index < 1 || index > shapes.size()) {
            throw std::out_of_range("Index given does not exist in the container.");
        }
    }
    catch (std::out_of_range const &e) {
        std::cerr << "\nError: " << e.what() << std::endl;
        std::cerr << "Please enter a valid index." << std::endl;
        valid = false;
    }

    return valid;
}

std::string Helper::changeFirstCommand(std::string command) {
    // Using STL transform with a lambda to change the command string to lowercase
    std::transform(command.begin(), command.end(), command.begin(),
                   [](unsigned char c) {
                       return std::tolower(c);
                   });

    if (command == "addr" || command == "addc" || command == "adds") {
        // Changes last letter of command to uppercase
        command.back() = toupper(command.back());
    }

    return command;
}


