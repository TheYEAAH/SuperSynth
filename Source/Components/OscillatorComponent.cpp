/*
  ==============================================================================

    OscillatorComponent.cpp
    Created: 13 Dec 2015 11:26:19pm
    Author:  dell

  ==============================================================================
*/

#include "OscillatorComponent.h"

//==============================================================================
OscillatorComponent::OscillatorComponent(AudioProcessorValueTreeState& vts)
: valueTreeState (vts)
{


    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    /*oscillatorGroup = new GroupComponent;
    amplitudeSlider = new Slider;
    amplitudeLabel = new Label;*/
    
    setSize (5 * paramLabelWidth + 6, 3 * paramControlHeight + 13);

    //oscillatorGroup
    oscillatorGroup.setText("Oscillator");
    addAndMakeVisible (oscillatorGroup);
    
    //amplitude
    //Label
    amplitudeLabel.setFont (Font (12.00f, Font::plain));   
    amplitudeLabel.setText ("amplitude", dontSendNotification);
    
	amplitudeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
	amplitudeSlider.setTextBoxStyle(Slider::TextBoxAbove, true, paramSliderWidth, paramLabelHeight);
	addAndMakeVisible(amplitudeSlider);
    

    addAndMakeVisible (amplitudeLabel);

   
    //addAndMakeVisible (amplitudeSlider);
    amplitudeAttachment.reset(new SliderAttachment (valueTreeState, "amplitude", amplitudeSlider));
    
   //pan  
    panLabel.setText ("pan", dontSendNotification);
    addAndMakeVisible (panLabel);
    
    panSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    panSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (panSlider);
    panAttachment.reset(new SliderAttachment (valueTreeState, "pan", panSlider));
        
    waveTypeLabel.setText ("waveType", dontSendNotification);
    addAndMakeVisible (waveTypeLabel);
    
    waveTypeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    waveTypeSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (waveTypeSlider);
    waveTypeAttachment.reset(new SliderAttachment (valueTreeState, "waveType", waveTypeSlider));
    
    phaseLabel.setText ("phase", dontSendNotification);
    addAndMakeVisible (phaseLabel);
    
    phaseSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    phaseSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (phaseSlider);
    phaseAttachment.reset(new SliderAttachment (valueTreeState, "phase", phaseSlider));
    
    pitchLabel.setText ("pitch", dontSendNotification);
    addAndMakeVisible (pitchLabel);
        
    pitchSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    pitchSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (pitchSlider);
    pitchAttachment.reset(new SliderAttachment (valueTreeState, "pitch", pitchSlider));
    
    fineLabel.setText ("fine", dontSendNotification);
    addAndMakeVisible (fineLabel);
    
    fineSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    fineSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (fineSlider);
    fineAttachment.reset(new SliderAttachment (valueTreeState, "fine", fineSlider));
    
    voiceNumberLabel.setText ("voiceNumber", dontSendNotification);
    addAndMakeVisible (voiceNumberLabel);
    
    voiceNumberSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    voiceNumberSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);    
    addAndMakeVisible (voiceNumberSlider);
    voiceNumberAttachment.reset(new SliderAttachment (valueTreeState, "voiceNumber", voiceNumberSlider));

    pulseWidthLabel.setText ("pulseWidth", dontSendNotification);
    addAndMakeVisible (pulseWidthLabel);
    
    pulseWidthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    pulseWidthSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);        
    addAndMakeVisible (pulseWidthSlider);
    pulseWidthAttachment.reset(new SliderAttachment (valueTreeState, "pulseWidth", pulseWidthSlider));
    
    
    detuneLabel.setText ("detune", dontSendNotification);
    addAndMakeVisible (detuneLabel);
    
    detuneSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    detuneSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);      
    addAndMakeVisible (detuneSlider);
    detuneAttachment.reset(new SliderAttachment (valueTreeState, "detune", detuneSlider));
    
    spreadLabel.setText ("spread", dontSendNotification);
    addAndMakeVisible (spreadLabel);
    
    spreadSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    spreadSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);           
    addAndMakeVisible (spreadSlider);
    spreadAttachment.reset(new SliderAttachment (valueTreeState, "spread", spreadSlider));
    
    //retrig
    retrigLabel.setEditable (false, false, false);
    retrigLabel.setColour (TextEditor::textColourId, Colours::black);
    retrigLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    retrigLabel.setText ("Retrig", dontSendNotification);
    addAndMakeVisible (retrigLabel);

    addAndMakeVisible (retrigButton);
    retrigAttachment.reset(new ButtonAttachment (valueTreeState, "retrig", retrigButton));
    
    //fixed
    fixedLabel.setEditable (false, false, false);
    fixedLabel.setColour (TextEditor::textColourId, Colours::black);
    fixedLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    fixedLabel.setText ("Fixed", dontSendNotification);
    addAndMakeVisible (fixedLabel);

    addAndMakeVisible (fixedButton);
    

    
}

OscillatorComponent::~OscillatorComponent()
{
}


void OscillatorComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    //component.getLocalBounds() always returns a rectangle that is at position (0, 0) with the same width and height as the component

    Rectangle<int> r = getLocalBounds();
    
    //oscillatorGroup
    oscillatorGroup.setBounds(r);
    
    r.removeFromTop(13);
    r.removeFromLeft(3);
    Rectangle<int> slidersArea = r.removeFromTop((paramSliderHeight + paramLabelHeight) *2);
    {
    //amplitude
    Rectangle<int> amplitudeRect = slidersArea.removeFromLeft (paramSliderWidth);
    amplitudeLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    amplitudeSlider.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
            
    //pan
    panLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    panSlider.setBounds (amplitudeRect);   
    
    //waveType
    amplitudeRect = slidersArea.removeFromLeft (paramSliderWidth);
    waveTypeLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    waveTypeSlider.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
   
    //phase
    phaseLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    phaseSlider.setBounds (amplitudeRect);
    
    //pitch
    amplitudeRect = slidersArea.removeFromLeft (paramSliderWidth);
    pitchLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    pitchSlider.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
    
    //fine
    fineLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    fineSlider.setBounds (amplitudeRect);

    //voiceNumber
    amplitudeRect = slidersArea.removeFromLeft (paramSliderWidth);
    voiceNumberLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    voiceNumberSlider.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
    
    //pulseWidth
    pulseWidthLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    pulseWidthSlider.setBounds (amplitudeRect);
   
    //detune
    amplitudeRect = slidersArea.removeFromLeft (paramSliderWidth);
    detuneLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    detuneSlider.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
    
    //spread
    spreadLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    spreadSlider.setBounds (amplitudeRect);
    
    //retrig
    amplitudeRect = r.removeFromLeft (paramLabelWidth);
    retrigLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    retrigButton.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
    
    //fixed
    amplitudeRect = r.removeFromLeft (paramLabelWidth);
    fixedLabel.setBounds (amplitudeRect.removeFromTop (paramLabelHeight));
    fixedButton.setBounds (amplitudeRect.removeFromTop(paramSliderHeight));
    }
}

void OscillatorComponent::createLabel(Label *label, const String &newText)
{
    label->setFont (Font (12.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label->setText (newText, dontSendNotification);
    addAndMakeVisible (label);
}

void OscillatorComponent::createSlider(Slider *slider, const String &newID)
{
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setRange (0.0, 1.0, 0.0);
    slider->setTextBoxStyle (Slider::TextBoxAbove, true, paramSliderWidth,paramLabelHeight);
    slider->setPopupDisplayEnabled (false, true, this);
    slider->setValue (1.0);
    slider->setComponentID(newID);
    addAndMakeVisible (slider);
}
void OscillatorComponent::createSlider(Slider *slider, const String &newID, const String &suffix)
{
    createSlider(slider, newID);
    slider->setTextValueSuffix (suffix);
}
