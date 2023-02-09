#ifndef ASSIGNMENT2_CIRCLE_H
#define ASSIGNMENT2_CIRCLE_H

#include "Shape.h"
#include "Movable.h"
#include <string>

class Circle : public Shape, public Movable {
public:
    // Constructor to initialise the top left point and the radius of the circle
    Circle(int x, int y, int r);

    // Destructor to release the memory of the circle
    virtual ~Circle();

    void toString() override;

    void move(int newX, int newY) override;

    void addToPoints() override;

    bool isIsotropic() override {return true;};

    std::ostream& print(std::ostream& out) const override;

    void scale(float scaleX, float scaleY) override;

private:
    // Radius of the circle
    int radius;
    // Right bottom coordinate
    Point rightBottom;

    void calculateArea() override;

    void calculatePerimeter() override;

    void calculatePoints() override;

    void updatePoints() override;
};



#endif //ASSIGNMENT2_CIRCLE_H
