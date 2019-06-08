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

    void resized();

private:
    /*creates a Label with the given text and textValueSuffix.*/
    void createLabel(Label *label, const String &text);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID, const String &suffix);
    
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
    
    std::unique_ptr<SliderAttachment> amplitudeAttachment;
    std::unique_ptr<SliderAttachment> panAttachment;    
    std::unique_ptr<SliderAttachment> waveTypeAttachment;
    std::unique_ptr<SliderAttachment> phaseAttachment;    
    std::unique_ptr<SliderAttachment> pitchAttachment;
    std::unique_ptr<SliderAttachment> fineAttachment;
    std::unique_ptr<SliderAttachment> voiceNumberAttachment;
    std::unique_ptr<SliderAttachment> pulseWidthAttachment;    
    std::unique_ptr<SliderAttachment> detuneAttachment;
    std::unique_ptr<SliderAttachment> spreadAttachment;    
    std::unique_ptr<ButtonAttachment> retrigAttachment;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (OscillatorComponent)
};