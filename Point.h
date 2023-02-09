#ifndef ASSIGNMENT2_POINT_H
#define ASSIGNMENT2_POINT_H


class Point {
public:
    // Constructor which initialises x and y to 0
    Point();

    // Constructor to initialise x and y to the given values
    Point(int _x, int _y);

    // Return the value of x
    int getX() const;

    // Set the value of x to the given parameter
    void setX(int _x);

    // Return the value of y
    int getY() const;

    // Set the value of y to the given parameter
    void setY(int _y);

private:
    // x and y variables set to private, and only used through the getters and setters function for encapuslation
    int x;
    int y;
};


#endif //ASSIGNMENT2_POINT_H
