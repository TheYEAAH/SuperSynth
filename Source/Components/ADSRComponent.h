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

    void resized() override;

private:
    /*creates a Label with the given text and textValueSuffix.*/
    void createLabel(Label &label, const String &text);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider &slider, const String &newID);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider &slider, const String &newID, const String &suffix);
    
    GroupComponent envelopeGroup;
    
    Slider attackSlider;
    Slider decaySlider;
    Slider sustainSlider;
    Slider releaseSlider;

    Label attackLabel;
    Label decayLabel;
    Label sustainLabel;
    Label releaseLabel;


    std::unique_ptr<SliderAttachment> attackAttachment;
    std::unique_ptr<SliderAttachment> decayAttachment;
    std::unique_ptr<SliderAttachment> sustainAttachment;
    std::unique_ptr<SliderAttachment> releaseAttachment;
    
    AudioProcessorValueTreeState& valueTreeState;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
