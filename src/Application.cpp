#include "Application.h"
#include "Enums.h"
#include <bobcat_ui/bobcat_ui.h>

using namespace bobcat;
using namespace std;

void Application::onCanvasMouseDown(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->startScribble();
        canvas->updateScribble(mx, my, 1, 1, 1, 14);
        canvas->redraw();
    }
    else if (tool == RECTANGLE) {
        canvas->addRectangle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    }
    else if (tool == CIRCLE) { 
        canvas->addCircle(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw();
    } else if (tool == TRIANGLE) { 
        canvas->addTriangle(mx, my, color.getR(), color.getG(), color.getB()); 
        canvas->redraw(); 
    } else if (tool == POLYGON){
        canvas->addPolygon(mx, my, color.getR(), color.getG(), color.getB());
        canvas->redraw(); 
    } else if (tool == SELECTOR){
        selectedShape = canvas->selectShape(mx, my);
    }

    if (tool != SELECTOR){
        selectedShape = nullptr; 
    }

}

void Application::onCanvasMouseUp(bobcat::Widget* sender, float mx, float my) {
    canvas->endScribble();
}

void Application::onCanvasDrag(bobcat::Widget* sender, float mx, float my) {
    TOOL tool = toolbar->getTool();
    Color color = colorSelector->getColor();

    if (tool == PENCIL) {
        canvas->updateScribble(mx, my, color.getR(), color.getG(), color.getB(), 7);
        canvas->redraw();
    }
    else if (tool == ERASER) {
        canvas->updateScribble(mx, my, 1.0, 1.0, 1.0, 14);
        canvas->redraw();
    } else if (tool == SELECTOR && selectedShape) { 
        selectedShape->changePos(mx, my);
        canvas->redraw();
    }
}


void Application::onToolbarChange(bobcat::Widget* sender) {
    ACTION action = toolbar->getAction();
    TOOL tool = toolbar->getTool(); 

    if (tool != SELECTOR){
        selectedShape = nullptr; 
    }

    if (action == CLEAR) {
        canvas->clear();
        canvas->redraw();
    }
    else if (action == UNDO) {
        canvas->undo();
        canvas->redraw();
    }
}

void Application::onColorSelectorChange(bobcat::Widget* sender){
    Color color = colorSelector->getColor();

    if (selectedShape){
        selectedShape->setColor(color.getR(), color.getG(), color.getB()); 
        canvas->redraw(); 
    }
}

Application::Application() {
    window = new Window(25, 75, 450, 400, "Pain Application");

    toolbar = new Toolbar(0, 0, 100, 400);
    canvas = new Canvas(100, 0, 350, 350);
    colorSelector = new ColorSelector(100, 350, 350, 50);
    colorSelector->box(FL_BORDER_BOX);

    window->add(toolbar);
    window->add(canvas);
    window->add(colorSelector);

    ON_MOUSE_DOWN(canvas, Application::onCanvasMouseDown);
    ON_DRAG(canvas, Application::onCanvasDrag);
    ON_CHANGE(toolbar, Application::onToolbarChange);
    ON_MOUSE_UP(canvas, Application::onCanvasMouseUp);
    ON_CHANGE(colorSelector, Application::onColorSelectorChange); 
    window->show();
}