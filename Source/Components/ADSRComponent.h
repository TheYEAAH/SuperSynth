#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ADSRComponent    : public Component
{
public:
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    
    ADSRComponent(AudioProcessorValueTreeState& vts);
    ~ADSRComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    /*creates a Label with the given text and textValueSuffix.*/
    void createLabel(Label *label, const String &text);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID, const String &suffix);
    
    ScopedPointer<GroupComponent> envelopeGroup;
    
    ScopedPointer<Slider> attackSlider;
    ScopedPointer<Slider> decaySlider;
    ScopedPointer<Slider> sustainSlider;
    ScopedPointer<Slider> releaseSlider;

    ScopedPointer<Label> attackLabel;
    ScopedPointer<Label> decayLabel;
    ScopedPointer<Label> sustainLabel;
    ScopedPointer<Label> releaseLabel;


    ScopedPointer<SliderAttachment> attackAttachment;
    ScopedPointer<SliderAttachment> decayAttachment;
    ScopedPointer<SliderAttachment> sustainAttachment;
    ScopedPointer<SliderAttachment> releaseAttachment;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
