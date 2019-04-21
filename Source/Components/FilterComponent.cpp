/*
  ==============================================================================

    FilterComponent.cpp
    Created: 17 Oct 2016 4:41:32pm
    Author:  dell

  ==============================================================================
*/

#include "FilterComponent.h"

//==============================================================================
FilterComponent::FilterComponent(AudioProcessorValueTreeState& vts)
: valueTreeState (vts)
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    ///IL faut que j'utilise la IIRFilter class il y a une video sur youtube a ce propos
    
    filterGroup = new GroupComponent;
    cutoffLabel = new Label;
    cutoffSlider = new Slider;
    resonanceLabel = new Label;
    resonance = new Slider;   
    filterTypeLabel = new Label;
    filterType = new ComboBox;    

    
    setSize (168, 104);
    
    
    //oscillatorGroup
    filterGroup->setText("Filter");
    addAndMakeVisible (filterGroup);
    
    //cutoff
    createLabel(cutoffLabel, "cutoff");
    createSlider(cutoffSlider, "cutoff"," Hz");
    cutoffAttachment = new SliderAttachment (valueTreeState, "cutoff", *cutoffSlider);
    
    //resonance
    createLabel(resonanceLabel, "res");
    createSlider(cutoffSlider, "resonance");

    
    //filterType
    //Label
    createLabel(filterTypeLabel, "Type");
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
    cutoffAttachment = nullptr;
    filterGroup = nullptr;
    cutoffLabel = nullptr;
    cutoffSlider = nullptr;
    resonanceLabel = nullptr;
    resonance = nullptr;   
    filterTypeLabel = nullptr;
    filterType = nullptr;
}

void FilterComponent::paint (Graphics& g)
{
}

void FilterComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    filterGroup->setBounds(0, 0, 168, 104);
    
    cutoffLabel->setBounds (3, 13, 40, 12);//x,y,width,height
    cutoffSlider->setBounds(8,26,30,30);
    resonanceLabel->setBounds (43, 13, 40, 12);//x,y,width,height
    resonance->setBounds(48,26,30,30);
    filterTypeLabel->setBounds (83, 13, 40, 12);//x,y,width,height
    filterType->setBounds(88, 33, 70, 16);
    
    /*keyTrackLabel.setBounds (3, 57, 40, 12);//x,y,width,height
    keyTrack.setBounds(8,69,30,30);
    velocityLabel.setBounds (43, 57, 40, 12);//x,y,width,height
    velocity.setBounds(48,69,30,30);*/
}

void FilterComponent::createLabel(Label *label, const String &newText)
{
    label->setFont (Font (12.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label->setText (newText, dontSendNotification);
    addAndMakeVisible (label);
}

void FilterComponent::createSlider(Slider *slider, const String &newID)
{
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setRange (0.0, 1.0, 0.0);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    slider->setPopupDisplayEnabled (false, true, this);
    slider->setValue (1.0);
    slider->setComponentID(newID);
    addAndMakeVisible (slider);
}
void FilterComponent::createSlider(Slider *slider, const String &newID, const String &suffix)
{
    createSlider(slider, newID);
    slider->setTextValueSuffix (suffix);
}