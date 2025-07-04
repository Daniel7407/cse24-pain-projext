#include "Toolbar.h"
#include "Enums.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/textbox.h>
using namespace bobcat;

void Toolbar::deselectAllTools() {
    pencilButton->color(FL_BACKGROUND_COLOR);
    eraserButton->color(FL_BACKGROUND_COLOR);
    circleButton->color(FL_BACKGROUND_COLOR);
    triangleButton->color(FL_BACKGROUND_COLOR);
    rectangleButton->color(FL_BACKGROUND_COLOR);
    polygonButton->color(FL_BACKGROUND_COLOR); 
    selectorButton->color(FL_BACKGROUND_COLOR); 
    sendToBackButton->color(FL_BACKGROUND_COLOR); 
    sendToFrontButton->color(FL_BACKGROUND_COLOR); 
    plusButton->color(FL_BACKGROUND_COLOR); 
    minusButton->color(FL_BACKGROUND_COLOR); 
}

void Toolbar::visualizeSelectedTool() {
    if (tool == PENCIL) {
        pencilButton->color(FL_WHITE);
    }
    else if (tool == ERASER) {
        eraserButton->color(FL_WHITE);
    }
    else if (tool == CIRCLE) {
        circleButton->color(FL_WHITE);
    }
    else if (tool == TRIANGLE) {
        triangleButton->color(FL_WHITE);
    }
    else if (tool == RECTANGLE) {
        rectangleButton->color(FL_WHITE);
    } else if (tool == POLYGON) { 
        polygonButton->color(FL_WHITE); 
    } else if (tool == SELECTOR) { 
        selectorButton->color(FL_WHITE); 
    }
}

void Toolbar::onClick(bobcat::Widget* sender) {
    deselectAllTools();

    action = NONE;

    if (sender == pencilButton) {
        tool = PENCIL;
    }
    else if (sender == eraserButton) {
        tool = ERASER;
    }
    else if (sender == circleButton) {
        tool = CIRCLE;
    }
    else if (sender == triangleButton) {
        tool = TRIANGLE;
    }
    else if (sender == rectangleButton) {
        tool = RECTANGLE;
    } else if (sender == polygonButton) { 
        tool = POLYGON; 
    } else if (sender == clearButton) {
        action = CLEAR;
    } else if (sender == selectorButton){
        tool = SELECTOR; 
    } else if (sender == sendToBackButton){
        action = SEND_TO_BACK; 
    } else if (sender == sendToFrontButton){
        action = SEND_TO_FRONT; 
    } else if (sender == minusButton){
        action = DECREASE_SIZE; 
    } else if (sender == plusButton){
        action = INCREASE_SIZE; 
    }

    if (onChangeCb) {
        onChangeCb(this);
    }

    visualizeSelectedTool();
    redraw();
}

TOOL Toolbar::getTool() const {
    return tool;
}

ACTION Toolbar::getAction() const {
    return action;
}

Toolbar::Toolbar(int x, int y, int w, int h) : Group(x, y, w, h) {
    pencilButton = new Image(x, y, 50, 50, "./assets/pencil.png");
    eraserButton = new Image(x, y + 50, 50, 50, "./assets/eraser.png");
    circleButton = new Image(x, y + 100, 50, 50, "./assets/circle.png");
    triangleButton = new Image(x, y + 150, 50, 50, "./assets/triangle.png");
    rectangleButton = new Image(x, y + 200, 50, 50, "./assets/rectangle.png");
    polygonButton = new Image(x, y + 250, 50, 50, "./assets/polygon.png"); 
    clearButton = new Image(x + 50, y + 250, 50, 50, "./assets/clear.png");
    selectorButton = new Image(x + 50, y, 50, 50, "./assets/mouse.png"); 
    sendToBackButton = new Image(x + 50, y + 50, 50, 50, "./assets/send-to-back.png"); 
    sendToFrontButton = new Image(x + 50, y + 100, 50, 50, "./assets/bring-to-front.png"); 
    plusButton = new Image(x + 50, y + 150, 50, 50, "./assets/plus.png"); 
    minusButton = new Image(x + 50, y + 200, 50, 50, "./assets/minus.png"); 

    tool = PENCIL;
    action = NONE;

    pencilButton->box(FL_BORDER_BOX);
    eraserButton->box(FL_BORDER_BOX);
    circleButton->box(FL_BORDER_BOX);
    triangleButton->box(FL_BORDER_BOX);
    rectangleButton->box(FL_BORDER_BOX);
    polygonButton->box(FL_BORDER_BOX);
    clearButton->box(FL_BORDER_BOX);
    selectorButton->box(FL_BORDER_BOX);
    sendToBackButton->box(FL_BORDER_BOX);
    sendToFrontButton->box(FL_BORDER_BOX);
    plusButton->box(FL_BORDER_BOX);
    minusButton->box(FL_BORDER_BOX);

    visualizeSelectedTool();

    ON_CLICK(pencilButton, Toolbar::onClick);
    ON_CLICK(eraserButton, Toolbar::onClick);
    ON_CLICK(circleButton, Toolbar::onClick);
    ON_CLICK(triangleButton, Toolbar::onClick);
    ON_CLICK(rectangleButton, Toolbar::onClick);
    ON_CLICK(polygonButton, Toolbar::onClick); 
    ON_CLICK(clearButton, Toolbar::onClick);
    ON_CLICK(selectorButton, Toolbar::onClick); 
    ON_CLICK(sendToBackButton, Toolbar::onClick); 
    ON_CLICK(sendToFrontButton, Toolbar::onClick); 
    ON_CLICK(plusButton, Toolbar::onClick); 
    ON_CLICK(minusButton, Toolbar::onClick); 
}