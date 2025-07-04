#ifndef SHAPE_H
#define SHAPE_H

#include <GL/freeglut.h>
#include <GL/gl.h>

// Abstract Data Type
class Shape{

public:
    // This function is now pure virtual
    virtual void draw() = 0;

    // Since Shape contains at least one pure virtual function
    // Shape is an Abstract Data Type

    // This forces every child of Shape to have a draw
    // function implemented
    virtual void setColor(float r, float g, float b) = 0;
    virtual bool wasClicked(float x, float y) = 0; 
    virtual void changePos(float x, float y) = 0; 
    virtual void changeSize(int delta) = 0; 

    // Any ADT must have a virtual destructor
    virtual ~Shape(){}
};

#endif