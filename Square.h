#ifndef ASSIGNMENT2_SQUARE_H
#define ASSIGNMENT2_SQUARE_H

#include "Shape.h"
#include "Movable.h"
#include <iostream>

class Square : public Shape, public Movable {
public:
    // Constructor to initialise the top left coordinate and the edges
    Square(int x, int y, int _edge);

    // Destructor to release the memory of the square object
    virtual ~Square();

    void toString() override;

    void move(int newX, int newY) override;

    std::ostream& print(std::ostream& out) const override;

    void scale(float scaleX, float scaleY) override;

    void addToPoints() override;

    bool isIsotropic() override {return true;};

private:
    // Length of the sides of the square
    int edge;
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


#endif //ASSIGNMENT2_SQUARE_H
