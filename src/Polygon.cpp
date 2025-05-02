#include "Polygon.h"
#include <GL/freeglut.h>
#include <GL/gl.h>

Polygon::Polygon() { 
    x = 0.0; 
    y = 0.0; 
    width = 0.4; 
    height = 0.4; 
    r = 0.0; 
    g = 0.0; 
    b = 0.0; 
}

Polygon::Polygon(float x, float y, float r, float g, float b){
    this-> x = x; 
    this-> y = y; 
    width = 0.4; 
    height = 0.4; 
    this-> r = r; 
    this->g = g; 
    this->b = b; 
}

void Polygon::draw() { 
    glColor3f(r, g, b); 

    glBegin(GL_POLYGON); 
        glVertex2f(x, y + height / 2); 
        glVertex2f(x + width / 2, y); 
        glVertex2f(x + width / 2 * .7, y - height / 2); 
        glVertex2f(x - width / 2 * .7, y - height / 2); 
        glVertex2f(x - width / 2, y);
    glEnd(); 
}

bool Polygon::wasClicked(float x, float y){
    if((x > this->x - width/2 * .7) && (x < this->x + width/2 * .7) && (y < this->y + height / 2) && (y > this->y - height/2)){
        return true; 
    }
    return false; 
}

void Polygon::changePos(float x, float y){ 
    this->x = x; 
    this->y = y; 
}

void Polygon::setColor(float r, float g, float b){
    this->r = r; 
    this->g = g; 
    this->b = b; 
}