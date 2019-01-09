#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

//==============================================================================
/*
*/
class ADSRComponent    : public Component
{
public:
    ADSRComponent();
    ~ADSRComponent();

    void paint (Graphics&) override;
    void resized() override;

private:
    ScopedPointer<GroupComponent> ADSRGroup;
    
    ScopedPointer<Slider> attack;
    ScopedPointer<Slider> decay;
    ScopedPointer<Slider> sustain;
    ScopedPointer<Slider> release;

    ScopedPointer<Label> attackLabel;
    ScopedPointer<Label> decayLabel;
    ScopedPointer<Label> sustainLabel;
    ScopedPointer<Label> releaseLabel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};
