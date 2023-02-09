#ifndef ASSIGNMENT2_HELPER_H
#define ASSIGNMENT2_HELPER_H

#include <string>
#include <vector>
#include "Shape.h"

class Helper {
public:
    // Explicitly declared default constructor
    Helper() = default;

    // Displays a welcome message to the console
    static void welcomeMessage();

    // Verifies the user input and returns true if it's valid, false if not
    static bool verifyInput(std::vector<std::string> &userInput);

    // Display all shapes currently in the shape vector
    static void showAllShapes(const std::vector<Shape *> &shapes);

    // Deletes all the shapes in the shape vector
    static void deleteAllShapes(std::vector<Shape *> &shapes);

    // Verifies the user input for the scale function
    // Returns true if valid, false if not
    static bool verifyScaling(std::vector<std::string> &userInput, Shape *shape);

    // Verifies whether the user has entered only positive integers depending on the command
    // Returns true if valid, false if not
    static bool verifyInt(std::vector<std::string> &userInput);

    // Verifies whether the index exists in the vector of shapes
    // Returns true if valid, false if not
    static bool verifyIndex(std::vector<Shape *> &shapes, int index);

    // Uses STL functions with a lambda to correctly format the first command
    // Returns the correctly formatted command
    static std::string changeFirstCommand(std::string command);

    // Function template to check for negative numbers
    template <typename T>
    static T checkNegative(T x) {
        if (x < 0) {
            return false;
        }

        return true;
    }
};


#endif //ASSIGNMENT2_HELPER_H
