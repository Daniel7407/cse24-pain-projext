#include "ColorSelector.h"
#include <FL/Enumerations.H>
#include <bobcat_ui/button.h>
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
    
    redDisplay->label("Red: " + std::to_string(red)); 
    blueDisplay->label("Blue: " + std::to_string(blue)); 
    greenDisplay->label("Green: " + std::to_string(green)); 

    displayButton->color(fl_rgb_color(red, green, blue));

    redraw(); 
}

Color ColorSelector::getColor() const { 
    return Color(red/255.0, green/255.0, blue/255.0); 
}

ColorSelector::ColorSelector(int x, int y, int w, int h) : Group(x, y, w, h) {
    red = 255; 
    blue = 0;
    green = 0; 

    redSlider = new Fl_Slider(x + 10, y + 30, 80, 10); 
    redSlider->type(FL_HOR_NICE_SLIDER); 
    redSlider->color(FL_RED);
    redSlider->bounds(0, 255); 
    redSlider->value(255); 
    redSlider->step(1); 
    redSlider->callback(onSliderChanged_cb, this); 

    redDisplay = new TextBox(x + 10, y + 10, 20, 20, "Red: " + std::to_string(red)); 

    greenSlider = new Fl_Slider(x + 100, y + 30, 80, 10); 
    greenSlider->type(FL_HOR_NICE_SLIDER); 
    greenSlider->color(FL_GREEN); 
    greenSlider->bounds(0, 255); 
    greenSlider->step(1); 
    greenSlider->callback(onSliderChanged_cb, this); 

    greenDisplay = new TextBox(x + 100, y + 10, 20, 20, "Green: " + std::to_string(green)); 

    blueSlider = new Fl_Slider(x + 190, y + 30, 80, 10); 
    blueSlider->type(FL_HOR_NICE_SLIDER); 
    blueSlider->color(FL_BLUE); 
    blueSlider->bounds(0, 255); 
    blueSlider->step(1); 
    blueSlider->callback(onSliderChanged_cb, this); 

    blueDisplay = new TextBox(x + 190, y + 10, 20, 20, "Blue: " + std::to_string(blue)); 

    displayButton = new Button(x + 290, y + 10, 35, 35, ""); 
    displayButton->color(fl_rgb_color(red, green, blue));

}