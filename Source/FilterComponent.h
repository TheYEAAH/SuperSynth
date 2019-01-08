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
    FilterComponent();
    ~FilterComponent();

    void paint (Graphics&) override;
    void resized() override;

private:

    GroupComponent * filterGroup;
    
    Slider * cutoff;
    Slider * resonance;
    //Slider keyTrack;
    //Slider velocity;
    ComboBox * filterType;
    
    Label * cutoffLabel;
    Label * resonanceLabel;
    Label * filterTypeLabel;
    //Label keyTrackLabel;
    //Label velocityLabel;
    

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (FilterComponent)
};
