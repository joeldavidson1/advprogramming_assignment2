#include "Rectangle.h"
#include <iostream>
#include <iomanip>

Rectangle::Rectangle(int x, int y, int h, int w) :
        Shape{x, y},
        height{h},
        width{w},
        rightTop{},
        rightBottom{},
        leftBottom{} {}

Rectangle::~Rectangle() {
    std::cout << "--- Deleting rectangle ---" << std::endl;
}


void Rectangle::calculateArea() {
    area = height * width;
}

void Rectangle::calculatePerimeter() {
    perimeter = (height * 2) + (width * 2);
}

void Rectangle::calculatePoints() {
    rightTop.setX(leftTop.getX() + width);
    rightTop.setY(leftTop.getY());

    rightBottom.setX(leftTop.getX() + width);
    rightBottom.setY(leftTop.getY() + height);

    leftBottom.setX(leftTop.getX());
    leftBottom.setY(leftTop.getY() + height);
}

void Rectangle::toString() {
    std::cout << "Rectangle [" << "height = " << height << ", " << "width = " << width << "]" << std::endl;
    std::cout << "Points [";
    for (auto &point: points) {
        std::cout << "(" << point.getX() << "," << point.getY() << ")";
    }
    std::cout << "]" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "Area = " << area << "   " << "Perimeter = " << perimeter
              << std::endl;
}

void Rectangle::move(int newX, int newY) {
    leftTop.setX(newX);
    leftTop.setY(newY);

    calculatePoints();
    updatePoints();
}

void Rectangle::addToPoints() {
    points.push_back(leftTop);
    points.push_back(rightTop);
    points.push_back(rightBottom);
    points.push_back(leftBottom);
}

void Rectangle::updatePoints() {
    points[0] = leftTop;
    points[1] = rightTop;
    points[2] = rightBottom;
    points[3] = leftBottom;
}

std::ostream &Rectangle::print(std::ostream &out) const {
    out << "Rectangle [" << "height = " << this->height << ", width = " << this->width << "]\n";
    out << "Points [";
    for (auto &point: this->points) {
        out << "(" << point.getX() << "," << point.getY() << ")";
    }
    out << "]" << std::endl;
    out << std::fixed << std::setprecision(1) << "Area = " << this->area << "   " << "Perimeter = " << this->perimeter
        << std::endl;

    return out;
}

void Rectangle::scale(float scaleX, float scaleY) {
    height = scaleX * height;
    width = scaleY * width;

    calculateArea();
    calculatePerimeter();
    calculatePoints();
    updatePoints();
}
