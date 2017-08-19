/*
  ==============================================================================

    WaveGenerator.h
    Created: 11 Oct 2016 12:38:13pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

/** A wave generator, an oscillator able to generate various types of waves
(although in this case it can just play saw waves).
It has  to know the type of wave to generate, the frequency, the phase,
the sampleFrames number, the sampleRate. */

class WaveGenerator
{
public:
    WaveGenerator(
    float frequency=440.0,
    int waveType = 2,
    float phase = 0.0f,
    float pulseWidth = 0.0,
    float pan = 0.5,
    float amplitude = 1.0);
    
	~WaveGenerator();
	
 /** Renders the next block of data.
    The output audio data must be added to the current contents of the buffer provided. 
    Only the region of the buffer between startSample and (startSample + numSamples) 
    should be altered by this method. */
	void getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples);

	/** Sets the oscillator frequency in Hertz. */
	void setFrequency(float newFrequency);
	
	/** Sets the type of wave used by the oscillator. */
	void setWaveType(int newWaveType);
	
	/**Sets the pan of the oscillator. Value between 0 and 1. */
    void setPan(float newPan);
    
    /**Sets the oscillator amplitude, from 0 to 1. */
    void setVolume(float newVolume);
    
    /** Sets the oscillator phase value, between 0 and 1. */
    void setPhase(float newPhase);

    //void setPulseWidth

private:
	float frequency;
    int waveType;//waveType 1=sineWave, 2=sawtoothWave, 3=squareWave, 4=whiteNoise
    float phase; //position in the wave phase ratio between 0-1
    float pulseWidth;//ratio between 0-1
    float sampleRate;
    float pan;//ratio between 0-1
    float volume;//volume
};

