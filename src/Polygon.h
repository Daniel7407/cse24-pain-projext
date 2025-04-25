#ifndef POLYGON_H
#define RECTANGLE_H

#include "Shape.h"

class Polygon : public Shape { 
    float x; 
    float y; 
    float width; 
    float height; 
    float r; 
    float g; 
    float b; 

public: 
    Polygon(); 
    Polygon(float x, float y, float r, float g, float b); 
    void draw(); 
};

#endif