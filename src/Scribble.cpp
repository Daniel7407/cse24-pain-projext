#include "Scribble.h"

void Scribble::addPoint(float x, float y, float r, float g, float b, int size){
    points.push_back(new Point(x, y, r, g, b, size));
}

void Scribble::draw(){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->draw();
    }
}

bool Scribble::wasClicked(float x, float y){
    for(unsigned int i = 0; i < points.size(); i++){
        if (points[i]->wasClicked(x, y)){
            return true; 
        }
    }

    return false; 
}

void Scribble::changePos(float x, float y){ 
    for (unsigned int i = points.size() - 1; i > 0; i--){
        if (points[i]->wasClicked(x, y)){
            Point* temp = points[i]; 
            points.erase(points.begin() + i); 
            points.push_back(temp); 
            break; 
        }
    }
    float changeInX = x - points[points.size() - 1]->getX(); 
    float changeInY = y - points[points.size() - 1]->getY(); 

    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->changePos(points[i]->getX() + changeInX, points[i]->getY() + changeInY);
    }
}

void Scribble::setColor(float r, float g, float b){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->setColor(r, g, b); 
    }
}

void Scribble::changeSize(int delta){
    for (unsigned int i = 0; i < points.size(); i++){
        points[i]->changeSize(delta); 
    }
}

Scribble::~Scribble(){
    for (unsigned int i = 0; i < points.size(); i++){
        delete points[i];
    }
    points.clear();
}


