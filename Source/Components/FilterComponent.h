/*
  ==============================================================================

    FilterComponent.h
    Created: 17 Oct 2016 4:41:32pm
    Author:  dell

  ==============================================================================
*/
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class FilterComponent    : public Component
{
public:
    typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;

    
    
    FilterComponent(AudioProcessorValueTreeState& vts);
    ~FilterComponent();
    
    void resized() override;

private:
    /*creates a Label with the given text and textValueSuffix.*/
    void createLabel(Label *label, const String &text);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID, const String &suffix);
    
    ScopedPointer<GroupComponent> filterGroup;
    
    ScopedPointer<Slider> cutoffSlider;
    ScopedPointer<Slider> resonance;
    //Slider keyTrack;
    //Slider velocity;
    ScopedPointer<ComboBox> filterType;
    
    ScopedPointer<Label> cutoffLabel;
    ScopedPointer<Label> resonanceLabel;
    ScopedPointer<Label> filterTypeLabel;
    //Label keyTrackLabel;
    //Label velocityLabel;
    
    ScopedPointer<SliderAttachment> cutoffAttachment;
    AudioProcessorValueTreeState& valueTreeState;    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
