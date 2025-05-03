#ifndef SCRIBBLE_H
#define SCRIBBLE_H

#include "Shape.h"
#include "Point.h"
#include <vector>

class Scribble: public Shape {
    std::vector<Point*> points;

public:

    void addPoint(float x, float y, float r, float g, float b, int size);

    void draw();
    bool wasClicked(float x, float y); 
    void changePos(float x, float y); 
    void setColor(float r, float g, float b); 
    void changeSize(int delta); 

    ~Scribble();
};
#endif