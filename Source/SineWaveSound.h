/*
  ==============================================================================

    SineWaveSound.h
    Created: 6 Feb 2016 11:58:41pm
    Author:  dell

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"

/** A demo synth sound that's just a basic sine wave.. */
class SineWaveSound : public SynthesiserSound
{
public:
    SineWaveSound() {}

    bool appliesToNote (int /*midiNoteNumber*/) override   { return true; }
    bool appliesToChannel (int /*midiChannel*/) override   { return true; }
};