/* ------------------------------------------------------
CMP2801M: Advanced Programming
Driver program for assignment
Fall 2019

Written by Ayse Kucukyilmaz

This file is a representative test file.
During marking, we will use the exact same notation
as provided in the brief, so make sure
you follow that guideline. Also make sure that you don't
change the main body provided to you here.
Otherwise, your code may not pass the test cases...

GOOD LUCK!

------------------------------------------------------ */

#include "Shape.h"
#include "Circle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Movable.h"
#include "Helper.h"

#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    string userCommand;
    vector<Shape *> shapes;     // this one will hold your shapes
    vector<string> parameters; // this one will hold parameters for the commands

    Helper::welcomeMessage();

    while (userCommand.compare("exit") != 0) {
        while (true) {
            cout << "Enter the command: ";

            getline(cin, userCommand);

            char *cstr = new char[userCommand.length() + 1];

            // C style string copy
            strncpy(cstr, userCommand.c_str(), userCommand.length() + 1);


            // implement a string tokenizer to populate the parameters vector
            char *section = strtok(cstr, " ");

            while (section != nullptr) {
                parameters.emplace_back(section);
                section = strtok(nullptr, " ");
            }

            // Exit out the if user enters 0 parameters
            if (parameters.empty()) {
                break;
            }

            // First command dictates the rest of the program
            string command = Helper::changeFirstCommand(parameters[0]);

            // Allows helper functions to use the correctly formatted command
            parameters[0] = command;

            // Validate input which the user has entered
            bool validInput = Helper::verifyInput(parameters);

            if (!validInput) {
                break;
            }

            bool validInts = Helper::verifyInt(parameters);

            if (!validInts) {
                break;
            }

            // in the following code, consider checking for the arguments.
            // in case of too few arguments, you may remind the user the correct format
            if (command.compare("addR") == 0) {

                // get parameters in the correct order
                // The following four lines have a type mismatch error
                // note that  the parameters vector contains ascii values
                // HINT: stoi function converts from string to int

                //--x = parameters[1].c_str(); // fix me! also note that x is not previously defined :(
                int x = stoi(parameters[1]);
                int y = stoi(parameters[2]);
                int h = stoi(parameters[3]);
                int w = stoi(parameters[4]);

                Rectangle *r = new Rectangle(x, y, h, w);
                r->calculateAll();
                r->addToPoints();
                shapes.push_back(r);
                cout << *r;

            } else if (command.compare("addS") == 0) {
                int x = stoi(parameters[1]);
                int y = stoi(parameters[2]);
                int e = stoi(parameters[3]);
                Square *s = new Square(x, y, e);
                s->calculateAll();
                s->addToPoints();
                shapes.push_back(s);
                cout << *s;

            } else if (command.compare("addC") == 0) {
                int x = stoi(parameters[1]);
                int y = stoi(parameters[2]);
                int r = stoi(parameters[3]);
                Circle *c = new Circle(x, y, r);
                c->calculateAll();
                c->addToPoints();
                shapes.push_back(c);
                cout << *c;

            } else if (command.compare("scale") == 0) {
                // scale object at index... the scaling needs to be isotropic in case of circle and square
                // you may want to check if the index exists or not!

                // Multiple inheritance is tricky! The Shape class does nto have a scale function, the Movable does!
                // As a result all your derived classes have scale functions...
                // You may need to use type casting wisely to use polymorphic functionality!

                // Obtain the shape number the user requests
                int shapeNo = stoi(parameters[1]); // read from parameters

                bool validIndex = Helper::verifyIndex(shapes, shapeNo);

                // Check if the given index is valid
                if (!validIndex) {
                    break;
                }

                // Downcast shape to Moveable
                Movable *m = dynamic_cast<Movable *>(shapes[shapeNo - 1]);

                bool validFloats = Helper::verifyScaling(parameters, shapes[shapeNo - 1]);

                // Check if the floats are valid
                if (!validFloats) {
                    break;
                }

                // Convert parameters to floats using stof
                float x = stof(parameters[2]);
                float y = stof(parameters[3]);

                m->scale(x, y);
                cout << *shapes[shapeNo - 1];

            } else if (command.compare("move") == 0) {
                // Obtain the shape number the user requests
                int shapeNo = stoi(parameters[1]);

                bool validIndex = Helper::verifyIndex(shapes, shapeNo);

                // Check if the given index is valid
                if (!validIndex) {
                    break;
                }

                // Convert parameters to integers using stoi
                int x = stoi(parameters[2]);
                int y = stoi(parameters[3]);

                // Study the following code. A Shape object is not Movable, but all derived classes are...
                // you can't automatically type cast from a Shape to a Movable, but you can force a downcasting
                Movable *m = dynamic_cast<Movable *>(shapes[shapeNo - 1]);
                m->move(x, y);

                cout << *shapes[shapeNo - 1];
            } else if (command.compare("display") == 0) {
                Helper::showAllShapes(shapes);
            } else if (command.compare("clear") == 0) {
                Helper::deleteAllShapes(shapes);
            } else {
                cerr << "\nEnter a valid 1st command." << endl;
            }

            cout << endl;
            parameters.clear();
        }

        // do any necessary postprocessing at the end of each loop...
        // yes, there is some necessary postprocessing...
        parameters.clear();
        cout << endl;
    }

    cout << "Press any key to continue...";
    std::getchar();

    return 0;
}
