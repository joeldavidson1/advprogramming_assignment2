#include "Shape.h"

Shape::Shape(int x, int y) :
        leftTop{x, y},
        area{0},
        isCircular{false},
        perimeter{0},
        points{} {}

void Shape::calculateAll() {
    calculatePerimeter();
    calculateArea();
    calculatePoints();
}
