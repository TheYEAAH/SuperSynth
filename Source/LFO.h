/*
  ==============================================================================

    LFO.h
    Created: 31 Oct 2016 3:57:27pm
    Author:  dell

  ==============================================================================
*/

#ifndef LFO_H_INCLUDED
#define LFO_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
/*A ModulationGenerator which is an simple oscillator
Needs to know the host tempo to be able to sync
*/
class LFO
{
public:
    LFO(
    float waveType = 0.0,
    float offset = 0.0,//ratio betwenn 0.0-1.0
    float rate = 20.0,//rate in Hz
    bool retrig = false,
    bool sync = false
    );

    
	~LFO();

	void getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples);
    void setWaveType(float newWaveType);
    void setOffset(float newOffset);
    void setRate(float newRate);
    void setRetrig(bool newRetrig);
    void setSync(bool newSync);


private:
    float sampleRate;
    
    float waveType;
    float offset;
    float rate;
    bool retrig;
    bool sync;
};



#endif  // LFO_H_INCLUDED
