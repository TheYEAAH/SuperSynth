/*
  ==============================================================================

    OscillatorComponent.cpp
    Created: 13 Dec 2015 11:26:19pm
    Author:  dell

  ==============================================================================
*/

#include "../JuceLibraryCode/JuceHeader.h"
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
    /*oscillatorGroup.setText("Oscillator");
    addAndMakeVisible (oscillatorGroup);*/
    
    //amplitude
    //Label
    amplitudeLabel.setFont (Font (12.00f, Font::plain));   
    amplitudeLabel.setText ("amplitude", dontSendNotification);
    
    amplitudeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    amplitudeSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (amplitudeLabel);
        

    //Slider
    /*amplitudeSlider.setSliderStyle (Slider::RotaryVerticalDrag);
    amplitudeSlider.setRange (0.0, 127.0, 1.0);
    amplitudeSlider.setTextBoxStyle (Slider::NoTextBox, true, paramSliderWidth,paramLabelHeight);
    amplitudeSlider.setPopupDisplayEnabled (true, this);
    amplitudeSlider.setTextValueSuffix (" dB");
    amplitudeSlider.setValue (1.0);
    amplitudeSlider.setComponentID("amplitude");*/
    addAndMakeVisible (amplitudeSlider);
    amplitudeAttachment = new SliderAttachment (valueTreeState, "amplitude", amplitudeSlider);
    
   //pan
    panLabel.setFont (Font (12.00f, Font::plain));     
    panLabel.setText ("pan", dontSendNotification);
    addAndMakeVisible (panLabel);
    
    panSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    panSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (panSlider);
    panAttachment = new SliderAttachment (valueTreeState, "pan", panSlider);
        
    waveTypeLabel.setFont (Font (12.00f, Font::plain));     
    waveTypeLabel.setText ("waveType", dontSendNotification);
    addAndMakeVisible (waveTypeLabel);
    
    waveTypeSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    waveTypeSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (waveTypeSlider);
    waveTypeAttachment = new SliderAttachment (valueTreeState, "waveType", waveTypeSlider);
    
    phaseLabel.setFont (Font (12.00f, Font::plain));     
    phaseLabel.setText ("phase", dontSendNotification);
    addAndMakeVisible (phaseLabel);
    
    phaseSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    phaseSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (phaseSlider);
    phaseAttachment = new SliderAttachment (valueTreeState, "phase", phaseSlider);
    
    pitchLabel.setFont (Font (12.00f, Font::plain));     
    pitchLabel.setText ("pitch", dontSendNotification);
    addAndMakeVisible (pitchLabel);
        
    pitchSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    pitchSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (pitchSlider);
    pitchAttachment = new SliderAttachment (valueTreeState, "pitch", pitchSlider);
    
    fineLabel.setFont (Font (12.00f, Font::plain));     
    fineLabel.setText ("fine", dontSendNotification);
    addAndMakeVisible (fineLabel);
    
    fineSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    fineSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);
    addAndMakeVisible (fineSlider);
    fineAttachment = new SliderAttachment (valueTreeState, "fine", pitchSlider);
    
    voiceNumberLabel.setFont (Font (12.00f, Font::plain));     
    voiceNumberLabel.setText ("voiceNumber", dontSendNotification);
    addAndMakeVisible (voiceNumberLabel);
    
    voiceNumberSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    voiceNumberSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);    
    addAndMakeVisible (voiceNumberSlider);
    voiceNumberAttachment = new SliderAttachment (valueTreeState, "voiceNumber", voiceNumberSlider);
    
    pulseWidthLabel.setFont (Font (12.00f, Font::plain));     
    pulseWidthLabel.setText ("pulseWidth", dontSendNotification);
    addAndMakeVisible (pulseWidthLabel);
    
    pulseWidthSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    pulseWidthSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);        
    addAndMakeVisible (pulseWidthSlider);
    pulseWidthAttachment = new SliderAttachment (valueTreeState, "pulseWidth", pulseWidthSlider);
    
    
    detuneLabel.setFont (Font (12.00f, Font::plain));     
    detuneLabel.setText ("detune", dontSendNotification);
    addAndMakeVisible (detuneLabel);
    
    detuneSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    detuneSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);      
    addAndMakeVisible (detuneSlider);
    detuneAttachment = new SliderAttachment (valueTreeState, "detune", detuneSlider);
        
    spreadLabel.setFont (Font (12.00f, Font::plain));         
    spreadLabel.setText ("spread", dontSendNotification);
    addAndMakeVisible (spreadLabel);
    
    spreadSlider.setSliderStyle(Slider::RotaryVerticalDrag);
    spreadSlider.setTextBoxStyle(Slider::TextBoxAbove,true,paramSliderWidth,paramLabelHeight);           
    addAndMakeVisible (spreadSlider);
    spreadAttachment = new SliderAttachment (valueTreeState, "spread", spreadSlider);
    
    //retrig
    retrigLabel.setFont (Font (12.00f, Font::plain));
    retrigLabel.setJustificationType (Justification::centred);
    retrigLabel.setEditable (false, false, false);
    retrigLabel.setColour (TextEditor::textColourId, Colours::black);
    retrigLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    retrigLabel.setText ("Retrig", dontSendNotification);
    addAndMakeVisible (retrigLabel);

    addAndMakeVisible (retrigButton);
    retrigAttachment = new ButtonAttachment (valueTreeState, "retrig", retrigButton);
    
    //fixed
    fixedLabel.setFont (Font (12.00f, Font::plain));
    fixedLabel.setJustificationType (Justification::centred);
    fixedLabel.setEditable (false, false, false);
    fixedLabel.setColour (TextEditor::textColourId, Colours::black);
    fixedLabel.setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    fixedLabel.setText ("Fixed", dontSendNotification);
    addAndMakeVisible (fixedLabel);

    addAndMakeVisible (fixedButton);
    

    
}

OscillatorComponent::~OscillatorComponent()
{
    /*delete oscillatorGroup;

    delete amplitude;*/

}

void OscillatorComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */

    
    /*g.setColour (Colours::yellow);
    
    const float lineThickness = 3.0f;
    g.drawEllipse (lineThickness * 0.5f,
                   lineThickness * 0.5f,
                   getWidth() - lineThickness,
                   getHeight() - lineThickness,
                   lineThickness);*/
}

void OscillatorComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    

    /*oscillatorGroup.setBounds(getLocalBounds());*///pour avoir les bounds donnés par le parent
    Rectangle<int> r = getLocalBounds();
    r.removeFromTop(13);
    r.removeFromLeft(3);
    Rectangle<int> slidersArea = r.removeFromTop((paramControlHeight + paramLabelHeight) *2);
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
    /*
    Rectangle<int> retrigRect = r.removeFromLeft (paramSliderWidth);
    retrigLabel.setBounds (retrigRect.removeFromTop (paramLabelHeight));
    retrigSlider.setBounds (retrigRect);*/
            

    }

}