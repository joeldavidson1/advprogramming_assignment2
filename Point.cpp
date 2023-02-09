#include "Point.h"
#include <iostream>

Point::Point() : x{0}, y{0} {}

// Member initialisation list
Point::Point(int _x, int _y) : x{_x}, y{_y} {}

int Point::getX() const { return x; }

void Point::setX(int _x) { x = _x; }

int Point::getY() const { return y; }

void Point::setY(int _y) { y = _y; }

