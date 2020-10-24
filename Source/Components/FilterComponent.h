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
    /*creates a Label with the given text.*/
    void createLabel(Label &label, const String &text);
    
    /*creates a slider with the given text.*/
    void createSlider(Slider &slider, const String &newID);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider &slider, const String &newID, const String &suffix);
    
    GroupComponent filterGroup;
    
    Slider cutoffSlider;
    Slider resonance;
    //Slider keyTrack;
    //Slider velocity;
    ComboBox filterType;
    
    Label cutoffLabel;
    Label resonanceLabel;
    Label filterTypeLabel;
    //Label keyTrackLabel;
    //Label velocityLabel;
    
    std::unique_ptr<SliderAttachment> cutoffAttachment;
    AudioProcessorValueTreeState& valueTreeState;    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
