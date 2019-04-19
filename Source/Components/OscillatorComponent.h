/*
  ==============================================================================

    OscillatorComponent.h
    Created: 13 Dec 2015 11:26:19pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/** This class is the component which is made to act as the GUI of a SuperWaveGenerator.
It is added as a subComponent of the SuperSynthAudioProcessorEditor.
*/
class OscillatorComponent : public Component
{
public:
    enum
    {
        paramControlHeight = 64,
        paramLabelHeight   = 12,
        paramLabelWidth    = 52,
        paramSliderWidth   = 52,
        paramSliderHeight  = 52
    };
    
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    typedef AudioProcessorValueTreeState::ButtonAttachment ButtonAttachment;
    
    /** Creates an OscillatorComponent. It is an editor specially made for the SuperWaveGenerator Class. */
    OscillatorComponent(AudioProcessorValueTreeState& vts);    
    ~OscillatorComponent();

    void paint (Graphics&);
    void resized();

private:
    /*amp, wave, pitch, voices, detune
  pan, phase, fine, pw,     Spread*/
  
    GroupComponent oscillatorGroup;
    
    Slider amplitudeSlider;
    Slider panSlider;
    
    Slider waveTypeSlider;
    Slider phaseSlider;
    
    Slider pitchSlider;
    Slider fineSlider;
    
    Slider voiceNumberSlider;
    Slider pulseWidthSlider;
    
    Slider detuneSlider;
    Slider spreadSlider;
    
    ToggleButton retrigButton;
    ToggleButton fixedButton;


    Label amplitudeLabel;
    Label panLabel;
    
    Label waveTypeLabel;
    Label phaseLabel;
    
    Label pitchLabel;
    Label fineLabel;
    
    Label voiceNumberLabel;
    Label pulseWidthLabel;
    
    Label detuneLabel;
    Label spreadLabel;

    Label retrigLabel;
    Label fixedLabel;
    
    ScopedPointer<SliderAttachment> amplitudeAttachment;
    ScopedPointer<SliderAttachment> panAttachment;
    
    ScopedPointer<SliderAttachment> waveTypeAttachment;
    ScopedPointer<SliderAttachment> phaseAttachment;
    
    ScopedPointer<SliderAttachment> pitchAttachment;
    ScopedPointer<SliderAttachment> fineAttachment;

    ScopedPointer<SliderAttachment> voiceNumberAttachment;
    ScopedPointer<SliderAttachment> pulseWidthAttachment;
    
    ScopedPointer<SliderAttachment> detuneAttachment;
    ScopedPointer<SliderAttachment> spreadAttachment;
    
    ScopedPointer<ButtonAttachment> retrigAttachment;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};