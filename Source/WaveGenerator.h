/*
  ==============================================================================

    WaveGenerator.h
    Created: 11 Oct 2016 12:38:13pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
/*Ceci est un generateur d'onde, autrement dit, un oscillateur capable de generer 
un saw ou un square ou un autre type d'onde qui se trouve dans waves
Il doit connaître le type d'onde à générer, la fréquence, la phase le nombre de sampleFrames, le sampleRate
*/
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

	void getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
	void setFrequency(float newFrequency);//used to change the frequency
	void setWaveType(int newWaveType);//used to change the waveType
    void setPan(float newPan);//used to change the pan
    void setVolume(float newVolume);//used to change the volume
    void setPhase(float newPhase);
    //void setPhase(float newPhase);//sets phase value, between 0 - 1
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

