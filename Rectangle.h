#ifndef ASSIGNMENT2_RECTANGLE_H
#define ASSIGNMENT2_RECTANGLE_H

#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Rectangle : public Shape, public Movable {
public:
    // Constructor to initialise the top left point, and the height (h) and the width (w)
    Rectangle(int x, int y, int h, int w);

    // Destructor to release the memory of the rectangle
    virtual ~Rectangle();

    void toString() override;

    void move(int newX, int newY) override;

    void scale(float scaleX, float scaleY) override;

    void addToPoints() override;

    bool isIsotropic() override {return false;};

    std::ostream& print(std::ostream& out) const override;

private:
    // Height of the rectangle
    int height;
    // Width of the rectangle
    int width;
    // Right top coordinate
    Point rightTop;
    // Right bottom coordinate
    Point rightBottom;
    // Left bottom coordinate
    Point leftBottom;

    void calculateArea() override;

    void calculatePerimeter() override;

    void calculatePoints() override;

    void updatePoints() override;
};



#endif //ASSIGNMENT2_RECTANGLE_H
