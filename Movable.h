#ifndef ASSIGNMENT2_MOVABLE_H
#define ASSIGNMENT2_MOVABLE_H

// Interface class
class Movable {
public:
    // Explicitly declared default constructor
    Movable() = default;

    // Moves the shape to the new x and y coordinates at the top left point
    virtual void move(int newX, int newY) = 0;

    // Scales the shape to the x and y values
    virtual void scale(float scaleX, float scaleY) = 0;
};


#endif //ASSIGNMENT2_MOVABLE_H
