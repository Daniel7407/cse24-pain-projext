#include "Point.h"
#include <GL/freeglut.h>
#include <cmath>

Point::Point() {
    x = 0.0;
    y = 0.0;
    r = 0.0;
    g = 0.0;
    b = 0.0;
    size = 7;
}

Point::Point(float x, float y) : Point() {
    this->x = x;
    this->y = y;
}

Point::Point(float x, float y, float r, float g, float b) : Point(x, y) {
    this->r = r;
    this->g = g;
    this->b = b;
}

Point::Point(float x, float y, float r, float g, float b, int size) : Point(x, y, r, g, b) {
    this->size = size;
}

void Point::draw() {
    glColor3f(r, g, b);
    glPointSize(size);

    glBegin(GL_POINTS);
        glVertex2f(x, y);
    glEnd();
}

bool Point::wasClicked(float x, float y){
    if (sqrt(pow(x - this->x, 2) + pow(y - this->y, 2)) <= this->size/200.0){
        return true; 
    }

    return false; 
}

float Point::getX() const {
    return x;
}

float Point::getY() const {
    return y;
}

float Point::getR() const {
    return r;
}

float Point::getG() const {
    return g;
}

float Point::getB() const {
    return b;
}

int Point::getSize() const {
    return size;
}

void Point::changePos(float x, float y){ 
    this->x = x; 
    this->y = y; 
}

void Point::setColor(float r, float g, float b){
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Point::changeSize(int delta){
    if (size > 2){
        size += delta * 1; 
    } else if (size <= 2 && delta == 1) { 
        size += delta * 1; 
    } 
}
