#include "Rectangle.h"
#include <GL/freeglut.h>

Rectangle::Rectangle() {
    x = 0.0;
    y = 0.0;
    width = 0.4;
    height = 0.4;
    r = 0.0;
    g = 0.0;
    b = 0.0;
}

Rectangle::Rectangle(float x, float y, float r, float g, float b) {
    this->x = x;
    this->y = y;
    width = 0.4;
    height = 0.4;
    this->r = r;
    this->g = g;
    this->b = b;
}

void Rectangle::draw() {
    glColor3f(r, g, b);

    glBegin(GL_POLYGON);
        glVertex2f(x - width/2, y + height/2);
        glVertex2f(x + width/2, y + height/2);
        glVertex2f(x + width/2, y - height/2);
        glVertex2f(x - width/2, y - height/2);
    glEnd();
}

bool Rectangle::wasClicked(float x, float y){
    if ((x < this->x + width/2) && (x > this->x - width / 2) && (y < this->y + width/2) && (y > this->y - width / 2)){
        return true; 
    }
    return false; ; 
}

void Rectangle::changePos(float x, float y){ 
    this->x = x; 
    this->y = y; 
}

void Rectangle::setColor(float r, float g, float b){
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Rectangle::changeSize(int delta){ 
    if (height > 0.04){
        height += delta * .04; 
        width += delta * .04;
    } else if (height == 0.04 && delta == 1) { 
        height += delta * .04; 
        width += delta * .04;
    } else if (height == .04 && delta == -1){

    }
}