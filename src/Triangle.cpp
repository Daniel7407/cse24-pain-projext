#include "Triangle.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Triangle::Triangle() { 
    x = 0.0; 
    y = 0.0; 
    width = 0.4; 
    height = 0.4;
    r = 0.0; 
    g = 0.0; 
    b = 0.0; 
}

Triangle::Triangle(float x, float y, float r, float g, float b){
    this->x = x; 
    this->y = y; 
    width = 0.4; 
    height = 0.4; 
    this->r = r; 
    this->g = g; 
    this->b = b; 
}

void Triangle::draw() { 
    glColor3f(r, g, b); 

    glBegin(GL_POLYGON); 
        glVertex2f(x, y + height / 2);
        glVertex2f(x + width / 2, y - height / 2); 
        glVertex2f(x - width / 2, y - height / 2); 
    glEnd(); 
    
}

bool Triangle::wasClicked(float x, float y){
    if ((y < (-2*x + (this->y + width/2 + 2 * this->x))) && (y < (2*x + (this->y + width/2 - 2*this->x))) && (y > (this->y - width/2))){
        return true; 
    }
    return false;  
}