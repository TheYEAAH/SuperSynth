/*
  ==============================================================================

    LFOComponent.cpp
    Created: 29 Oct 2016 11:35:18pm
    Author:  dell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "LFOComponent.h"

//==============================================================================
LFOComponent::LFOComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    LFOGroup = new GroupComponent;
    waveTypeLabel = new Label;
    waveType = new Slider;
    offsetLabel = new Label;
    offset = new Slider;   
    rateLabel = new Label;
    rate = new Slider;
    retrigLabel = new Label;
    retrig = new ToggleButton;

    
    setSize (96, 104);
    
    
    //LFOGroup
    LFOGroup->setText("LFO");
    addAndMakeVisible (LFOGroup);
    
    //waveType
    //Label
    waveTypeLabel->setFont (Font (12.00f, Font::plain));
    waveTypeLabel->setJustificationType (Justification::centred);
    waveTypeLabel->setEditable (false, false, false);
    waveTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    waveTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    waveTypeLabel->setText ("wave", dontSendNotification);
    addAndMakeVisible (waveTypeLabel);
    //Slider
    waveType->setSliderStyle (Slider::RotaryVerticalDrag);
    waveType->setRange (0.0, 127.0, 1.0);
    waveType->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    waveType->setPopupDisplayEnabled (true, this);
    waveType->setTextValueSuffix (" Hz");
    waveType->setValue (1.0);
    waveType->setComponentID("waveType");
    addAndMakeVisible (waveType);
    
    //offset
    //Label
    offsetLabel->setFont (Font (12.00f, Font::plain));
    offsetLabel->setJustificationType (Justification::centred);
    offsetLabel->setEditable (false, false, false);
    offsetLabel->setColour (TextEditor::textColourId, Colours::black);
    offsetLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    offsetLabel->setText ("offset", dontSendNotification);
    addAndMakeVisible (offsetLabel);
    //Slider
    offset->setSliderStyle (Slider::RotaryVerticalDrag);
    offset->setRange (0.0, 127.0, 1.0);
    offset->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    offset->setPopupDisplayEnabled (true, this);
    offset->setTextValueSuffix (" %");
    offset->setValue (1.0);
    offset->setComponentID("offset");
    addAndMakeVisible (offset);
    
    //rate
    //Label
    rateLabel->setFont (Font (12.00f, Font::plain));
    rateLabel->setJustificationType (Justification::centred);
    rateLabel->setEditable (false, false, false);
    rateLabel->setColour (TextEditor::textColourId, Colours::black);
    rateLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    rateLabel->setText ("rate", dontSendNotification);
    addAndMakeVisible (rateLabel);
    //Slider
    rate->setSliderStyle (Slider::RotaryVerticalDrag);
    rate->setRange (0.0, 127.0, 1.0);
    rate->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    rate->setPopupDisplayEnabled (true, this);
    rate->setTextValueSuffix (" Hz");
    rate->setValue (1.0);
    rate->setComponentID("rate");
    addAndMakeVisible (rate);
    
    //retrig
    //Label
    retrigLabel->setFont (Font (12.00f, Font::plain));
    retrigLabel->setJustificationType (Justification::centred);
    retrigLabel->setEditable (false, false, false);
    retrigLabel->setColour (TextEditor::textColourId, Colours::black);
    retrigLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    retrigLabel->setText ("retrig", dontSendNotification);
    addAndMakeVisible (retrigLabel);
    //Slider
    addAndMakeVisible (retrig);
}

LFOComponent::~LFOComponent()
{
    delete LFOGroup;
    delete waveTypeLabel;
    delete waveType;
    delete offsetLabel;
    delete offset;   
    delete rateLabel;
    delete rate;
    delete retrigLabel;
    delete retrig;
}

void LFOComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
/*
    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("FilterComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder tex*/
}

void LFOComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    LFOGroup->setBounds(0, 0, 96, 104);
    
    waveTypeLabel->setBounds (3, 13, 40, 12);//x,y,width,height
    waveType->setBounds(8,26,30,30);
    offsetLabel->setBounds (43, 13, 40, 12);//x,y,width,height
    offset->setBounds(48,26,30,30);
    rateLabel->setBounds (3, 57, 40, 12);//x,y,width,height
    rate->setBounds(8,69,30,30);
    retrigLabel->setBounds (43, 57, 40, 12);//x,y,width,height
    retrig->setBounds(48,69,30,30);
}
