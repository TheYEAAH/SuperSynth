/*
  ==============================================================================

    FilterComponent.cpp
    Created: 17 Oct 2016 4:41:32pm
    Author:  dell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    ///IL faut que j'utilise la IIRFilter class il y a une video sur youtube a ce propos
    
    filterGroup = new GroupComponent;
    cutoffLabel = new Label;
    cutoff = new Slider;
    resonanceLabel = new Label;
    resonance = new Slider;   
    filterTypeLabel = new Label;
    filterType = new ComboBox;    

    
    setSize (168, 104);
    
    
    //oscillatorGroup
    filterGroup->setText("Filter");
    addAndMakeVisible (filterGroup);
    
    //cutoff
    //Label
    cutoffLabel->setFont (Font (12.00f, Font::plain));
    cutoffLabel->setJustificationType (Justification::centred);
    cutoffLabel->setEditable (false, false, false);
    cutoffLabel->setColour (TextEditor::textColourId, Colours::black);
    cutoffLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    cutoffLabel->setText ("cutoff", dontSendNotification);
    addAndMakeVisible (cutoffLabel);
    //Slider
    cutoff->setSliderStyle (Slider::RotaryVerticalDrag);
    cutoff->setRange (0.0, 127.0, 1.0);
    cutoff->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    cutoff->setPopupDisplayEnabled (true, this);
    cutoff->setTextValueSuffix (" Hz");
    cutoff->setValue (1.0);
    cutoff->setComponentID("cutoff");
    addAndMakeVisible (cutoff);
    
    //resonance
    //Label
    resonanceLabel->setFont (Font (12.00f, Font::plain));
    resonanceLabel->setJustificationType (Justification::centred);
    resonanceLabel->setEditable (false, false, false);
    resonanceLabel->setColour (TextEditor::textColourId, Colours::black);
    resonanceLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    resonanceLabel->setText ("res", dontSendNotification);
    addAndMakeVisible (resonanceLabel);
    //Slider
    resonance->setSliderStyle (Slider::RotaryVerticalDrag);
    resonance->setRange (0.0, 127.0, 1.0);
    resonance->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    resonance->setPopupDisplayEnabled (true, this);
    resonance->setTextValueSuffix (" Hz");
    resonance->setValue (1.0);
    resonance->setComponentID("resonance");
    addAndMakeVisible (resonance);
    
    //filterType
    //Label
    filterTypeLabel->setFont (Font (12.00f, Font::plain));
    filterTypeLabel->setJustificationType (Justification::centred);
    filterTypeLabel->setEditable (false, false, false);
    filterTypeLabel->setColour (TextEditor::textColourId, Colours::black);
    filterTypeLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    filterTypeLabel->setText ("Type", dontSendNotification);
    addAndMakeVisible (filterTypeLabel);
    //ComboBox
    filterType->setEditableText (false);
    filterType->setJustificationType (Justification::centredLeft);
    filterType->setTextWhenNothingSelected (TRANS("Low24dB"));
    filterType->setTextWhenNoChoicesAvailable (TRANS("Low12dB, High12dB, High24dB"));
    filterType->setComponentID("filterType");
    addAndMakeVisible (filterType);
}

FilterComponent::~FilterComponent()
{
    delete filterGroup;
    delete cutoffLabel;
    delete cutoff;
    delete resonanceLabel;
    delete resonance;   
    delete filterTypeLabel;
    delete filterType;
}

void FilterComponent::paint (Graphics& g)
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

void FilterComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    filterGroup->setBounds(0, 0, 168, 104);
    
    cutoffLabel->setBounds (3, 13, 40, 12);//x,y,width,height
    cutoff->setBounds(8,26,30,30);
    resonanceLabel->setBounds (43, 13, 40, 12);//x,y,width,height
    resonance->setBounds(48,26,30,30);
    filterTypeLabel->setBounds (83, 13, 40, 12);//x,y,width,height
    filterType->setBounds(88, 33, 70, 16);
    
    /*keyTrackLabel.setBounds (3, 57, 40, 12);//x,y,width,height
    keyTrack.setBounds(8,69,30,30);
    velocityLabel.setBounds (43, 57, 40, 12);//x,y,width,height
    velocity.setBounds(48,69,30,30);*/
}
