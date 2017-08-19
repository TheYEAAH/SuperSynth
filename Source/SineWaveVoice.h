/*
  ==============================================================================

    SineWaveVoice.h
    Created: 6 Feb 2016 11:58:58pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "SineWaveSound.h"
#include "superwavegenerator.h"
//==============================================================================
/** The program creates 127 on the initialization which will be present till the end.
When a note is played, the program changes the voice state using setState()
The voice creates everything it needs (oscillators, filters...) when the note starts to play.
When the voice is no longer used, it deletes the oscillators etc to free memory.
*/
class SineWaveVoice   : public SynthesiserVoice
{
public:
    /** Creates a SineWaveVoice. */
    SineWaveVoice(AudioProcessorValueTreeState& parameters, double currentAngle=0, double angleDelta=0, double tailOff=0);

    /** Implementation of the SynthesiserVoice method. */
    bool canPlaySound (SynthesiserSound* sound) override;

    /** Implementation of the SynthesiserVoice method. */
    void startNote (int midiNoteNumber, float velocity, SynthesiserSound* /*sound*/, int /*currentPitchWheelPosition*/) override;
    
    /** Implementation of the SynthesiserVoice method. */
    void stopNote (float /*velocity*/, bool allowTailOff) override;
    
    /** Implementation of the SynthesiserVoice method. */
    void pitchWheelMoved (int /*newValue*/) override;
    
    /** Implementation of the SynthesiserVoice method. */
    void controllerMoved (int /*controllerNumber*/, int /*newValue*/) override;
    
    /** Implementation of the SynthesiserVoice method. */
    void renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples) override;

private:
    double currentAngle, angleDelta, tailOff;
    bool state;//1 note is on 0 note is off
    SuperWaveGenerator * oscillator;
    IIRFilter leftFilter;
    IIRFilter rightFilter;
    //IIRFilterAudioSource filter;
    AudioProcessorValueTreeState& parameters;
};