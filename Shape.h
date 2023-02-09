#ifndef ASSIGNMENT2_SHAPE_H
#define ASSIGNMENT2_SHAPE_H

#include <string>
#include "Point.h"
#include <vector>

// Abstract class
class Shape {
public:
    // Constructor to initialise x and y to the leftTop Point
    Shape(int x, int y);

    // Destructor to release the memory of the shape
    virtual ~Shape() = default;

    // Returns a boolean to check if shape is isotropic
    virtual bool isIsotropic() = 0;

    // Calls calculateArea, calculatePerimeter and calculatePoints
    void calculateAll();

    // Displays the details of the shape to the console
    virtual void toString() = 0;

    // Adds each Point object into the points vector;
    virtual void addToPoints() = 0;

    // Friend function to allow Shape and derived classes to use the print function
    friend std::ostream &operator<<(std::ostream &out, const Shape &shape) { return shape.print(out); }


// Protected access modifier used so only derived classes have access
protected:
    // Area of the shape
    float area;
    // Perimeter of the shape
    float perimeter;
    // Boolean to check whether shape is circular
    bool isCircular;
    // Left top coordinate of the shape
    Point leftTop;
    // Vector to hold each point of the shape
    std::vector<Point> points;

    // Calculates the area of the shape
    virtual void calculateArea() = 0;

    // Calculates the perimeter of the shape
    virtual void calculatePerimeter() = 0;

    // Calculates each point in the vector of points
    virtual void calculatePoints() = 0;

    // Updates the points vector with the newly calculated coordinates
    virtual void updatePoints() = 0;

    // Overrides the << operator as this cannot be virtualised explicitly
    virtual std::ostream &print(std::ostream &out) const = 0;
};


#endif //ASSIGNMENT2_SHAPE_H
