/*
  ==============================================================================

    superwavegenerator.h
    Created: 11 Oct 2016 12:31:06pm
    Author:  dell

  ==============================================================================
*/

#pragma once

/* Ceci est un generateur de superwave, autrement dit, un groupe d'oscillateurs
le SuperWaveGenerator possède les mêmes paramètres que le WaveGenerator avec en plus, 
le nombre d'oscillateurs internes, le detune et le spread
Pour l'instant le WaveGenerator n'est capable que de générer du saw
Il faut dans le futur qu'il soit capable de manipuler
différents types d'ondes qui se trouvent dans le dossier waves
Paramètres du SuperwaveGenerator:
    float frequency;
    int waveType;//waveType 1=sineWave, 2=sawtoothWave, 3=squareWave, 4=whiteNoise
    bool retrig; //1 on 0 off
    float phase; //position in the wave phase ratio between 0-1
    float pulseWidth;//ratio between 0-1
    float sampleRate;
    int voiceNumber;
    float& detune;//detune ratio 0-1
    float spread;//stereo spread ratio 0-1
    float volume;//volume propre du wave generator (prend en compte le volume que l'utilisateur voit du superwave generator et le volume global du synthé
    */

//------------------------------------------------------------------------------------------
#include "wavegenerator.h"
#include "../JuceLibraryCode/JuceHeader.h"
class SuperWaveGenerator : public AudioProcessorValueTreeState::Listener
{
public:
    SuperWaveGenerator(AudioProcessorValueTreeState& parameters, float frequency = 440.);
	~SuperWaveGenerator();

	void getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const;
	//float getFrequency() const;
	void setFrequency(float newFrequency);//used to change the frequency
	//void setWaveType(int newWaveType);//used to change the waveType
    void setDetune(float newDetune);
    float getDetune() const;// ratio 0-1
    void setVoiceNumber(int newVoiceNumber);//[0;8]
    void setSpread(float newSpread);// ratio 0-1
    void setAmplitude(float newAmplitude);// used to change the volume
    void parameterChanged(const String &parameterID, float newValue) override;
    //void setPhase(float newPhase);//sets phase value, between 0 - 1
    //void setPulseWidth
    /*    enum WaveType
    {
        SAW,
        PULSE,
        TRIANGLE,
        SIN,
        NOISE
    };*/

private:
    WaveGenerator * oscillators[8];
    AudioProcessorValueTreeState& parameters;
    float frequency;
    Random random;
};
