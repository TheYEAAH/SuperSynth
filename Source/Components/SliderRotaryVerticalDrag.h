/*
  ==============================================================================

    SliderRotaryVerticalDrag.h
    Created: 16 Jan 2016 10:14:07pm
    Author:  dell

  ==============================================================================
*/
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class SliderRotaryVerticalDrag    : public Component
{
public:
    SliderRotaryVerticalDrag();
    ~SliderRotaryVerticalDrag();

    void paint (Graphics&);
    void resized();
    void setTextValueSuffix(String );

private:
    Slider sliderRotaryVerticalDrag;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderRotaryVerticalDrag)
};
