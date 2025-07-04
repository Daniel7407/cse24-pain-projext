#ifndef COLOR_SELECTOR_H
#define COLOR_SELECTOR_H

#include <bobcat_ui/all.h>
#include "Color.h"
#include "Enums.h"

class ColorSelector : public bobcat::Group {
    int red; 
    int green; 
    int blue; 

    Fl_Slider* redSlider; 
    Fl_Slider* greenSlider; 
    Fl_Slider* blueSlider; 

    bobcat::TextBox* redDisplay; 
    bobcat::TextBox* greenDisplay; 
    bobcat::TextBox* blueDisplay; 
    bobcat::Button* displayButton; 

    static void onSliderChanged_cb(Fl_Widget* widget, void* userData); 
    void onSliderChange(); 

public:
    ColorSelector(int x, int y, int w, int h);

    Color getColor() const;
};

#endif