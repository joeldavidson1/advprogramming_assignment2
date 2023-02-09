#include "Circle.h"
#include <iostream>
#include <cmath>
#include <iomanip>

Circle::Circle(int _x, int _y, int r) :
        Shape{_x, _y},
        radius{r},
        rightBottom{0, 0} {
    isCircular = true;
}

Circle::~Circle() {
    std::cout << "--- Deleting circle ---" << std::endl;
}

void ::Circle::calculatePoints() {
    rightBottom.setX(leftTop.getX() + 2 * radius);
    rightBottom.setY(leftTop.getY() + 2 * radius);
}

void Circle::toString() {
    std::cout << "Circle [" << "radius = " << radius << std::endl;
    std::cout << "Points [";
    for (auto &point: points) {
        std::cout << "(" << point.getX() << ", " << point.getY() << ")";
        std::cout << std::endl;
    }
    std::cout << "]" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "Area = " << area << "   " << "Perimeter = " << perimeter
              << std::endl;

}

void Circle::calculateArea() {
    area = M_PI * (radius * radius);
}

void Circle::calculatePerimeter() {
    perimeter = 2 * M_PI * radius;
}


void Circle::updatePoints() {
    points[0] = leftTop;
    points[1] = rightBottom;
}

void Circle::addToPoints() {
    points.push_back(leftTop);
    points.push_back(rightBottom);
}

void Circle::move(int newX, int newY) {
    leftTop.setX(newX);
    leftTop.setY(newY);

    calculatePoints();
    updatePoints();
}

std::ostream &Circle::print(std::ostream &out) const {
    out << "Circle [" << "radius = " << this->radius << "]" << std::endl;
    out << "Points [";
    for (auto &point: this->points) {
        out << "(" << point.getX() << "," << point.getY() << ")";
    }
    out << "]" << std::endl;
    out << std::fixed << std::setprecision(1) << "Area = " << this->area << "   " << "Perimeter = " << this->perimeter
        << std::endl;

    return out;
}

void Circle::scale(float scaleX, float scaleY) {
    // Calculate the new scaled radius with the x value.
    // x and y values should be equal as checked with the other helper functions
    radius = scaleX * radius;

    calculateArea();
    calculatePerimeter();
    calculatePoints();
    updatePoints();
}




