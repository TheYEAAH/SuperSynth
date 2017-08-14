#include "voice.h"
//constructeurs et destructeurs
//Constructeur par défault et surchargé
Voice::Voice(float frequency,bool state) : frequency(frequency),state(state)
{
}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

Voice::~Voice()
{
}

bool Voice::getState() const
{
    return state;
}

void Voice::setState(bool newState)
{
    if (newState != state){//on vérifie qu'il y a modification
        state=newState;
        if (state){//si la voix est activée on crée un SuperWaveGenerator
            oscillator = new SuperWaveGenerator(frequency);
        }
        else{//si la voix est désactivée on supprime le WaveGenerator
            delete oscillator;
        }
    }
}

void Voice::getWave(float **outputs, VstInt32 sampleFrames) const
{
    if (state){
        oscillator->getWave(outputs,sampleFrames);
    }
}

void Voice::setFrequency(float newFrequency)
{
    frequency = newFrequency;
}

void Voice::setVolume(float &newVolume) const
{
    if (state){//si la voix a un oscillateur, elle change le volume, sinon rien
            oscillator->setVolume(newVolume);
    }
}
void Voice::setDetune(float &newDetune) const
{
    if (state){//si la voix a un oscillateur, elle change le volume, sinon rien
            oscillator->setDetune(newDetune);
    }
}

void Voice::setSpread(float &newSpread) const
{
    if (state){//si la voix a un oscillateur, elle change le volume, sinon rien
            oscillator->setSpread(newSpread);
    }
}
