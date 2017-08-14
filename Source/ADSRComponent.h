/*
  ==============================================================================

    ADSRComponent.h
    Created: 31 Oct 2016 9:30:20pm
    Author:  dell

  ==============================================================================
*/

#ifndef ADSRCOMPONENT_H_INCLUDED
#define ADSRCOMPONENT_H_INCLUDED

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
    GroupComponent * ADSRGroup;
    
    Slider * attack;
    Slider * decay;
    Slider * sustain;
    Slider * release;

    Label * attackLabel;
    Label * decayLabel;
    Label * sustainLabel;
    Label * releaseLabel;


    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ADSRComponent)
};


#endif  // ADSRCOMPONENT_H_INCLUDED
