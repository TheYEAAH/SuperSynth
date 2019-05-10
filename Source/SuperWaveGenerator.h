/*
  ==============================================================================

    superwavegenerator.h
    Created: 11 Oct 2016 12:31:06pm
    Author:  Philippe SICABAIG

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "wavegenerator.h"
//#include "PolyBLEPOscillator.h"
#include "math.h"

/** A superwave generator, a group of oscillators that creates a superwave together.
The superwave generator has the same parameters as a wave generator, with the addition
of the number of internal oscillators, the detune amount between the oscillators,
the stereo spread wich is the panning of the oscillators relative to the others.

For the moment it only generates supersaws.
In the future it has to be able to use other wave types.

It creates internally listeners for the parameters created in the SuperSynthAudioProcessor class.
(unless phase and puseWidth parameters which are not supported yet)
The listeners for the following parameters are created internally :
    retrig
    voiceNumber
    detune
    spread
    amplitude

Listeners to add in the future :
    phase
    pulseWidth

So basically this class listens to the plugin editor.
This is wrong because this means that the parameter of SuperWaveGeneratorAudioProcessor are actually created by SuperSynthAudioProcessor.
We want to improve that so that the parameters are created within the SuperWaveGeneratorAudioProcessor class
(and more generally within any AudioProcessor used internally).

The SuperWaveGeneratorAudioProcessor should have its own editor and pass its parameters and editor to the SuperSynthAudioProcessor
which should care about including the SuperWaveGeneratorAudioProcessorEditor into the SuperSynthAudioProcessorEditor class.

@See SuperSynthAudioProcessor, SuperSynthAudioProcessorEditor
*/

//------------------------------------------------------------------------------------------

class SuperWaveGenerator : public AudioProcessorValueTreeState::Listener
{
public:
    /** Creates a SuperWaveGenerator. */
    SuperWaveGenerator(AudioProcessorValueTreeState& parameters, float frequency = 440.);
    
    /** Destructor. */
	~SuperWaveGenerator();
	
    /** Renders the next block of data.
    The output audio data must be added to the current contents of the buffer provided. 
    Only the region of the buffer between startSample and (startSample + numSamples) should be altered by this method. */
	void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const;
	
	/**Sets the SuperwaveGenerator base frequency. */
	void setFrequency(float newFrequency);//used to change the frequency
	
	/** Sets the detune amount between the oscillators. Ratio between 0 and 1. */
    void setDetune(float newDetune);
    
    /** Returns the detune amount between the oscillators. Ratio between 0 and 1. */
    float getDetune() const;// ratio 0-1
    
    /** Sets the number of WaveGenerator that will be used by the SuperWaveGeneratorAudioProcessor.
    Integer included in [0;8], so a maximum of 8 voices. */
    void setVoiceNumber(int newVoiceNumber);
    
    /** Sets the stereo spread ratio (between 0 and 1) */
    void setSpread(float newSpread);
    
    /** Sets the amplitude (between 0 and 1). */
    void setAmplitude(float newAmplitude);
    
    /** Sets the wave type of the superwave generators. @See WaveGenerator  */
    void setWaveType(int newWaveType);
    
    /** Implements the AudioProcessorValueTreeState::Listener method.
    This callback method is called by the AudioProcessorValueTreeState when a parameter changes.
    @See AudioProcessorValueTreeState::Listener
    */
    void parameterChanged(const String &parameterID, float newValue) override;
    //void setPhase(float newPhase);//sets phase value, between 0 - 1
    //void setPulseWidth
    
private:
    WaveGenerator * oscillators[8];
    AudioProcessorValueTreeState& parameters;
    float frequency;
    Random random;
};
