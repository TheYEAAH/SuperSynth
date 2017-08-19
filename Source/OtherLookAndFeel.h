/*
  ==============================================================================

    OtherLookAndFeel.h
    Created: 19 Aug 2017 12:50:52am
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

/** This class is intended to be the default look and feel for the application. */
class OtherLookAndFeel : public LookAndFeel_V4
{
public:
   
    OtherLookAndFeel();
    
    /** Implementation of the LookAndFeelV2 method. */
    void drawLabel (Graphics &, Label &) override;
    
    /** Implementation of the LookAndFeelV4 method. */
    void drawRotarySlider (Graphics &, int x, int y, int width, int height, float sliderPosProportional, float rotaryStartAngle, float rotaryEndAngle, Slider &) override;
};