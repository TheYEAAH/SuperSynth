/*
  ==============================================================================

    WaveGenerator.cpp
    Created: 11 Oct 2016 12:38:13pm
    Author:  dell

  ==============================================================================
*/

#include "WaveGenerator.h"

//constructeurs et destructeurs
//Constructeur par défault et surchargé
WaveGenerator::WaveGenerator(
float frequency,
int waveType,
float phase,
float pulseWidth,
float pan,
float volume)
: frequency(frequency),
waveType(waveType),
phase(phase),
pulseWidth(pulseWidth),
sampleRate(44100.0),//I need to change this
pan(pan),
volume(volume)//updateSampleRate();
{
}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

WaveGenerator::~WaveGenerator()
{
}

void WaveGenerator::getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) //il faut que l'oscillateur envoie un pointeur vers une valeur qui sera modifiée par la fonction
{
/*    switch (waveType) {
        case 1: sineWave(frequency,numSamples); break;
        case 2: sawtoothWave(frequency,numSamples); break;
        case 3: squareWave(frequency,numSamples); break;
        case 4: whiteNoise(frequency,numSamples); break;
        default: sawtoothWave(frequency,numSamples); break;
        }*/
    
    float tempVar;//variable temporaire qui permet de faire une fois un calcul qui prend beaucoup de ressources
    while (--numSamples >= 0){
        tempVar = volume * (1 - 2 * phase);
        const float currentSample = tempVar;
        outputBuffer.addSample (0, startSample, pan * tempVar);
        outputBuffer.addSample (1, startSample, (1 - pan) * tempVar);
        /*for (int i = outputBuffer.getNumChannels(); --i >= 0;)
        outputBuffer.addSample (i, startSample, currentSample);*/

        phase += frequency / sampleRate;
        if (phase >= 1.0){
            phase = phase - 1.0f;
        }
        ++startSample;
    }
}

void WaveGenerator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
}
    
void WaveGenerator::setWaveType(int newWaveType)
{
    waveType= newWaveType;
}

void WaveGenerator::setPan(float newPan)
{
    pan=newPan;//doit prendre en compte le pan de l'oscillateur et le pan global du synthé ou du waveGenerator
}

void WaveGenerator::setVolume(float newVolume)
{
    volume = newVolume;//doit prendre en compte le volume de l'oscillateur et le volume global du synthé ou du waveGenerator
}

void WaveGenerator::setPhase(float newPhase)
{
    phase = newPhase;
}