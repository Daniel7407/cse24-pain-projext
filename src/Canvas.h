#ifndef CANVAS_H
#define CANVAS_H

#include <bobcat_ui/all.h>
#include <vector>
#include "Point.h"
#include "Rectangle.h"
#include "Triangle.h"
#include "Circle.h"
#include "Polygon.h"
#include "Shape.h"
#include "Scribble.h"

class Canvas : public bobcat::Canvas_ {
    std::vector<Shape*> shapes;

    Scribble* curr;

public:
    Canvas(int x, int y, int w, int h);

    Shape* selectShape(float x, float y); 

    void addPoint(float x, float y, float r, float g, float b, int size);

    void addRectangle(float x, float y, float r, float g, float b);

    void addTriangle(float x, float y, float r, float g, float b); 

    void addCircle(float x, float y, float r, float g, float b);

    void addPolygon(float x, float y, float r, float g, float b); 

    void clear();

    void startScribble();

    void updateScribble(float x, float y, float r, float g, float b, int size);

    void endScribble();

    void render();

    void sendToBack(Shape* shape); 

    void sendToFront(Shape* shape); 

    void erase(Shape* shape); 

};

#endif