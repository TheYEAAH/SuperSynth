/*
  ==============================================================================

    LFO.cpp
    Created: 31 Oct 2016 3:57:27pm
    Author:  dell

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#include "LFO.h"
//constructeurs et destructeurs
//Constructeur par défault et surchargé

LFO::LFO(
float waveType,
float offset,
float rate,
bool retrig,
bool sync
)
: sampleRate(41000.0),//updateSampleRate();
waveType(waveType),
offset(offset),
rate(rate),
retrig(retrig),
sync(sync)
{
}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

LFO::~LFO()
{
}

void LFO::getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) //il faut que l'oscillateur envoie un pointeur vers une valeur qui sera modifiée par la fonction
{
    
}


void LFO::setWaveType(float newWaveType)
{
    waveType = newWaveType;
}
void LFO::setOffset(float newOffset)
{
    offset = newOffset;
}
void LFO::setRate(float newRate)
{
    rate = newRate;
}

void LFO::setRetrig(bool newRetrig)
{
    retrig = newRetrig;
}
void LFO::setSync(bool newSync)
{
    sync = newSync;
}