/*
  ==============================================================================

    LFOComponent.h
    Created: 29 Oct 2016 11:35:18pm
    Author:  dell

  ==============================================================================
*/
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class LFOComponent    : public Component
{
public:
    LFOComponent();
    ~LFOComponent();

    void paint (Graphics&) override;
    void resized() override;

private:

    GroupComponent * LFOGroup;
    
    Slider * waveType;
    Slider * offset;
    Slider * rate;
    ToggleButton * retrig;

    Label * waveTypeLabel;
    Label * offsetLabel;
    Label * rateLabel;
    Label * retrigLabel;
    
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (LFOComponent)
};