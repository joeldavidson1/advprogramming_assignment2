#include "Square.h"
#include <iostream>
#include <iomanip>

Square::Square(int x, int y, int _edge) :
        Shape{x, y},
        edge{_edge},
        rightTop{},
        rightBottom{},
        leftBottom{} {}

Square::~Square() {
    std::cout << "--- Deleting square ---" << std::endl;
}

void Square::calculateArea() {
    area = edge * edge;

}

void Square::calculatePerimeter() {
    perimeter = edge * 4;
}

void Square::addToPoints() {
    points.push_back(leftTop);
    points.push_back(rightTop);
    points.push_back(rightBottom);
    points.push_back(leftBottom);
}


void Square::calculatePoints() {
    rightTop.setX(leftTop.getX() + edge);
    rightTop.setY(leftTop.getY());

    rightBottom.setX(leftTop.getX() + edge);
    rightBottom.setY(leftTop.getY() + edge);

    leftBottom.setX(leftTop.getX());
    leftBottom.setY(leftTop.getY() + edge);
}

void Square::toString() {
    std::cout << "Square [" << "edge = " << edge << "]" << std::endl;
    std::cout << "Points [";
    for (auto &point: points) {
        std::cout << "(" << point.getX() << "," << point.getY() << ")";
    }
    std::cout << "]" << std::endl;
    std::cout << std::fixed << std::setprecision(1) << "Area = " << area << "   " << "Perimeter = " << perimeter
              << std::endl;
}

void Square::move(int newX, int newY) {
    leftTop.setX(newX);
    leftTop.setY(newY);

    calculatePoints();
    updatePoints();
}

void Square::updatePoints() {
    points[0] = leftTop;
    points[1] = rightTop;
    points[2] = rightBottom;
    points[3] = leftBottom;
}

std::ostream &Square::print(std::ostream &out) const {
    out << "Square [" << "edge = " << this->edge << "]\n";
    out << "Points [";
    for (auto &point: this->points) {
        out << "(" << point.getX() << "," << point.getY() << ")";
    }
    out << "]" << std::endl;
    out << std::fixed << std::setprecision(1) << "Area = " << this->area << "   " << "Perimeter = " << this->perimeter
        << std::endl;

    return out;
}

void Square::scale(float scaleX, float scaleY) {
    // Calculate the new scaled edge with the x value.
    // x and y values should be equal as checked with the other helper functions
    edge = scaleX * edge;

    calculateArea();
    calculatePerimeter();
    calculatePoints();
    updatePoints();
}

