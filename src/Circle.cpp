#include "Circle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <cmath>

Circle::Circle() {
    x = 0.0;
    y = 0.0;
    radius = 0.2;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Circle::Circle(float x, float y, float r, float g, float b) {
    this->x = x; 
    this->y = y; 
    radius = 0.2;
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Circle::draw() {
    glColor3f(r, g, b);

    float inc = M_PI / 32;
    glBegin(GL_POLYGON);
        for (float theta = 0; theta <= 2 * M_PI; theta += inc){
            glVertex2d(x + cos(theta) * radius, y + sin(theta) * radius);
        }
    glEnd();
}

bool Circle::wasClicked(float x, float y){
    if (sqrt(pow(x - this->x, 2) + pow(y - this->y, 2)) <= this->radius){
        return true; 
    }

    return false; 
}

void Circle::changePos(float x, float y){ 
    this->x = x; 
    this->y = y; 
}

void Circle::setColor(float r, float g, float b){
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Circle::changeSize(int delta){
    if (radius > 0.04){
        radius += delta * .02; 
    } else if (radius <= 0.04 && delta == 1) { 
        radius += delta * .02; 
    }
}   

