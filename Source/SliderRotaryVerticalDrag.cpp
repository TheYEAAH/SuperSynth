/*
  ==============================================================================

    SliderRotaryVerticalDrag.cpp
    Created: 16 Jan 2016 10:14:07pm
    Author:  dell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "SliderRotaryVerticalDrag.h"

//==============================================================================
SliderRotaryVerticalDrag::SliderRotaryVerticalDrag()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    setSize (40, 44);
    
    sliderRotaryVerticalDrag.setSliderStyle (Slider::RotaryVerticalDrag);
    sliderRotaryVerticalDrag.setRange (0.0, 127.0, 1.0);
    sliderRotaryVerticalDrag.setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    sliderRotaryVerticalDrag.setPopupDisplayEnabled (true, this);
    sliderRotaryVerticalDrag.setValue (1.0);
    addAndMakeVisible (&sliderRotaryVerticalDrag);

}

SliderRotaryVerticalDrag::~SliderRotaryVerticalDrag()
{
}

void SliderRotaryVerticalDrag::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("SliderRotaryVerticalDrag", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder text
}

void SliderRotaryVerticalDrag::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    sliderRotaryVerticalDrag.setBounds (13, 0, 30, 30);//x,y,width,height

}
