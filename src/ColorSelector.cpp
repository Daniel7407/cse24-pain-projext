#include "ColorSelector.h"
#include <cstdlib>
#include <iostream>

using namespace bobcat;

void ColorSelector::onSliderChanged_cb(Fl_Widget* widget, void* userData){
    ColorSelector* self = static_cast<ColorSelector*>(userData); 
    self->onChange();
}

void ColorSelector::onChange(){
    red = static_cast<int>(redSlider->value()); 
    blue = static_cast<int>(blueSlider->value()); 
    green = static_cast<int>(greenSlider->value()); 

}

Color ColorSelector::getColor() const { 
    return Color(red/255.0, green/255.0, blue/255.0); 
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    redSlider = new Fl_Slider(x + 10, y + 20, 80, 10); 
    redSlider->type(FL_HOR_NICE_SLIDER); 
    redSlider->bounds(0, 255); 
    redSlider->value(255); 
    redSlider->step(1); 
    redSlider->callback(onSliderChanged_cb, this); 

    greenSlider = new Fl_Slider(x + 100, y + 20, 80, 10); 
    greenSlider->type(FL_HOR_NICE_SLIDER); 
    greenSlider->bounds(0, 255); 
    greenSlider->step(1); 
    greenSlider->callback(onSliderChanged_cb, this); 

    blueSlider = new Fl_Slider(x + 190, y + 20, 80, 10); 
    blueSlider->type(FL_HOR_NICE_SLIDER); 
    blueSlider->bounds(0, 255); 
    blueSlider->step(1); 
    blueSlider->callback(onSliderChanged_cb, this); 

}