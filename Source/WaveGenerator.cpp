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
WaveGeneratorWaveType waveType,
float phase,
float pulseWidth,
float pan,
float amplitude)
: frequency(frequency),
waveType(waveType),
phase((double) phase),
pulseWidth(pulseWidth),
sampleRate((double) 44100.0),//I need to change this
pan(pan),
amplitude (amplitude),
mPI(2.*acos(0.0)),
twoPI(2. * mPI),
lastOutput(0.0)
{
    updatePhaseIncrement();
}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

WaveGenerator::~WaveGenerator()
{
}

void WaveGenerator::getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) //il faut que l'oscillateur envoie un pointeur vers une valeur qui sera modifiée par la fonction
{
    double tempVar;//variable temporaire qui permet de faire une fois un calcul qui prend beaucoup de ressources
    
    
    switch (waveType) {
        case WAVEGENERATOR_WAVETYPE_SINE:
            while (--numSamples >= 0) {

                tempVar = sin(phase);
                tempVar *= amplitude;
                outputBuffer.addSample (0, startSample, pan * tempVar);
                outputBuffer.addSample (1, startSample, (1 - pan) * tempVar);
                
                phase += phaseIncrement;
                while (phase >= twoPI) {
                    phase -= twoPI;
                }
                
                ++startSample;
            }
            break;
            
        case WAVEGENERATOR_WAVETYPE_SAW:
            while (--numSamples >= 0) {
                double t = phase / twoPI; 
                //tempVar = 1.0 - (2.0 * phase / twoPI);
                tempVar = (2.0 * phase / twoPI) - 1.0;
                tempVar -= poly_blep(t);
                tempVar *= amplitude;
                outputBuffer.addSample (0, startSample, pan * tempVar);
                outputBuffer.addSample (1, startSample, (1 - pan) * tempVar);
                
                phase += phaseIncrement;
                while (phase >= twoPI) {
                    phase -= twoPI;
                }
                
                ++startSample;
            }
            
            break;
            
        case WAVEGENERATOR_WAVETYPE_SQUARE:
            while (--numSamples >= 0) {
                double t = phase / twoPI; 
                if (phase <= mPI) {
                    tempVar = 1.0;
                } else{
                    tempVar = -1.0;
                }
                
                tempVar += poly_blep(t);
                tempVar -= poly_blep(fmod(t + 0.5, 1.0));
                
                tempVar *= amplitude;
                outputBuffer.addSample (0, startSample, pan * tempVar);
                outputBuffer.addSample (1, startSample, (1 - pan) * tempVar);

                phase += phaseIncrement;
                while (phase >= twoPI) {
                    phase -= twoPI;
                }
                
                ++startSample;
            }
            break;
            
        case WAVEGENERATOR_WAVETYPE_TRIANGLE:
            while (--numSamples >= 0) {
                
                //Same thing as square wave
                double t = phase / twoPI; 
                if (phase <= mPI) {
                    tempVar = 1.0;
                } else{
                    tempVar = -1.0;
                }
                tempVar += poly_blep(t);
                tempVar -= poly_blep(fmod(t + 0.5, 1.0));
            
                //here special for triangle
                // Leaky integrator: y[n] = A * x[n] + (1 - A) * y[n-1]
                tempVar = phaseIncrement * tempVar + (1 - phaseIncrement) * lastOutput;
                
                
                lastOutput = tempVar;
                tempVar *= amplitude;
                outputBuffer.addSample (0, startSample, pan * tempVar);
                outputBuffer.addSample (1, startSample, (1 - pan) * tempVar);
                
                phase += phaseIncrement;
                while (phase >= twoPI) {
                    phase -= twoPI;
                }
                
                ++startSample;
            }
            break;
    }
}

void WaveGenerator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
    updatePhaseIncrement();
}
    
void WaveGenerator::setWaveType(WaveGeneratorWaveType newWaveType)
{
    waveType= newWaveType;
}

void WaveGenerator::setPan(float newPan)
{
    pan=newPan;//doit prendre en compte le pan de l'oscillateur et le pan global du synthé ou du waveGenerator
}

void WaveGenerator::setAmplitude(float newAmplitude)
{
    amplitude = newAmplitude;//doit prendre en compte le volume de l'oscillateur et le volume global du synthé ou du waveGenerator
}

void WaveGenerator::setPhase(float newPhase)
{
    phase = (double) newPhase;
}

void WaveGenerator::updatePhaseIncrement() {
    double calculatedFrequency = fmin(fmax(frequency,0), sampleRate/2.0);
    phaseIncrement = calculatedFrequency * twoPI / sampleRate;
}

double WaveGenerator::poly_blep(double t)
{
    double dt = phaseIncrement / twoPI;
    // 0 <= t < 1
    if (t < dt) {
        t /= dt;
        return t+t - t*t - 1.0;
    }
    // -1 < t < 0
    else if (t > 1.0 - dt) {
        t = (t - 1.0) / dt;
        return t*t + t+t + 1.0;
    }
    // 0 otherwise
    else return 0.0;
}
