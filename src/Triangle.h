#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Shape.h"

class Triangle : public Shape { 
    float x; 
    float y; 
    float width; 
    float height; 
    float r; 
    float g; 
    float b; 

    public: 
        Triangle(); 
        Triangle(float x, float y, float r, float g, float b); 
        void draw(); 
        bool wasClicked(float x, float y); 
        void changePos(float x, float y); 
        void setColor(float r, float g, float b); 
        void changeSize(int delta); 
};

#endif