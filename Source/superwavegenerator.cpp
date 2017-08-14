/*
  ==============================================================================

    superwavegenerator.cpp
    Created: 11 Oct 2016 12:31:07pm
    Author:  dell

  ==============================================================================
*/

#include "superwavegenerator.h"
#include "../JuceLibraryCode/JuceHeader.h"
#include "math.h"
//Constructeur par défault et surchargé
SuperWaveGenerator::SuperWaveGenerator(AudioProcessorValueTreeState& parameters, float frequency)
: parameters(parameters), frequency(frequency)
{   
    /*parameters.addParameterListener	("frequency", this);
    parameters.addParameterListener	("waveType", this);

    parameters.addParameterListener	("phase", this);
    parameters.addParameterListener	("pulseWidth", this);*/
    parameters.addParameterListener	("retrig", this);
    parameters.addParameterListener	("voiceNumber", this);
    parameters.addParameterListener	("detune", this);
    parameters.addParameterListener	("spread", this);
    parameters.addParameterListener	("amplitude", this);

    /*
    création des oscillateurs. chaque oscillateur a une fréquence qui dépend du detune
    Si le nombre d'oscillateurs est pair, les impairs seront detunés au dessus, les pairs en dessous
    Si le nombre d'oscillateurs est impair, le 1er sera au centre, les impairs au dessus, les pairs en dessous
    En binaire, les nombres pairs finissent par 0. Ici on teste si n fini par 1
    */

    int voiceNumber = 8;//(int) *parameters.getRawParameterValue ("voiceNumber");
    float detune = *parameters.getRawParameterValue ("detune");
    float spread = *parameters.getRawParameterValue ("spread");
    bool retrig = (bool) *parameters.getRawParameterValue ("retrig");
    if(voiceNumber & 1)// voiceNumber est impair
    {
        oscillators[0] = new WaveGenerator(frequency);
        for (int i=1; i < voiceNumber; i++)
        {
            //oscillators[i] = new WaveGenerator(frequency - pow(-1,i)* n*(frequency*pow(2,detune/12)-frequency));

            if(i & 1)//oscillateur impair
            {
                oscillators[i] = new WaveGenerator(frequency * pow(2,2 * detune/(12*(voiceNumber-(i/2)))));//frequence oscillateur=frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
            }
            else
            {
                oscillators[i] = new WaveGenerator(frequency * pow(2,-2 * detune /(12*(voiceNumber-((i-1)/2)))));
            }
        }
    }
    else//voiceNumber est pair
    {
        for (int i=0; i < voiceNumber; i++)
        {
            //oscillators[i] = new WaveGenerator(frequency - pow(-1,i)* n*(frequency*pow(2,detune/12)-frequency));

            if(i & 1)//oscillateur impair
            {
                oscillators[i] = new WaveGenerator(frequency * pow(2,2 * detune / (12*(voiceNumber-(i/2)))));//frequence oscillateur=frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
            }
            else
            {
                oscillators[i] = new WaveGenerator(frequency * pow(2,-2 * detune/(12*(voiceNumber-((i-1)/2)))));
            }
        }
    }
    if (!retrig)
    {
        for (int i=0; i < 8; i++)
        {
            oscillators[i]->setPhase(random.nextFloat());
        }
    }
    //on vérifie le spread
    setSpread(spread);
    setDetune(detune);
    setAmplitude(*parameters.getRawParameterValue ("amplitude"));

}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

SuperWaveGenerator::~SuperWaveGenerator()
{//delete oscillators; //Libère la zone pointée par le pointeur
//ici il faut effacer le pointeur
    int voiceNumber = 8;
    for (int i=0; i < voiceNumber; i++)
    {
        delete oscillators[i];
        oscillators[i] = NULL;
    }

/*
    parameters.removeParameterListener	("waveType", this);
    
    parameters.removeParameterListener	("phase", this);
    parameters.removeParameterListener	("pulseWidth", this);*/
    parameters.removeParameterListener	("retrig", this);
    parameters.removeParameterListener	("voiceNumber", this);
    parameters.removeParameterListener	("detune", this);
    parameters.removeParameterListener	("spread", this);
    parameters.removeParameterListener	("amplitude", this);
}

void SuperWaveGenerator::getWave(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const
{
    for (int i=0; i < (int) *parameters.getRawParameterValue ("voiceNumber"); i++)

    {
        oscillators[i]->getWave(outputBuffer, startSample, numSamples);
    }

}

void SuperWaveGenerator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
}


void SuperWaveGenerator::setAmplitude(float newAmplitude)
{
    for (int i(0); i < (int) *parameters.getRawParameterValue ("voiceNumber"); i++)
    {
        oscillators[i]->setVolume(newAmplitude);
    }
}

void SuperWaveGenerator::setDetune(float newDetune)
{
    
    int voiceNumber = (int) *parameters.getRawParameterValue ("voiceNumber");
    float detune = *parameters.getRawParameterValue ("detune");
    
    if(voiceNumber & 1)// voiceNumber est impair
    {
        oscillators[0]->setFrequency(frequency);
        for (int i=1; i < voiceNumber; i++)
        {
            if(i & 1)//oscillateur impair
            {
                oscillators[i]->setFrequency(frequency * pow(2,2 * detune/(12 * (voiceNumber-i))));//frequence oscillateur=frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
            }
            else
            {
                oscillators[i]->setFrequency(frequency * pow(2,-2 * detune/(12 * (voiceNumber - (i - 1)))));
            }
        }
    }
    else//voiceNumber est pair
    {
        for (int i=0; i < voiceNumber; i++)
        {
            //oscillators[i] = new WaveGenerator(frequency - pow(-1,i)* n*(frequency*pow(2,detune/12)-frequency));

            if(i & 1)//oscillateur impair
            {
                oscillators[i]->setFrequency(frequency * pow(2,2 * detune/(12 * (voiceNumber-i))));//frequence oscillateur=frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
            }
            else
            {
                oscillators[i]->setFrequency(frequency * pow(2,-2*detune/(12*(voiceNumber-(i-1)))));
            }
        }
    }
}

float SuperWaveGenerator::getDetune() const
{
    return *parameters.getRawParameterValue ("detune");
}

void SuperWaveGenerator::setVoiceNumber(int newVoiceNumber)
{
    /*for (int i=0; i < (int) *parameters.getRawParameterValue ("voiceNumber"); i++)
    {
        if (oscillators[i])
        {
        }
        else//the oscillator doesn't exist
        {
            oscillators[i] = new WaveGenerator();
        }
    }
    
    for (int i= (int) *parameters.getRawParameterValue ("voiceNumber"); i < 8; i++)
    {
        if (oscillators[i])
        {
            delete oscillators[i];
            oscillators[i] = NULL;
        }
    }*/
    setSpread(*parameters.getRawParameterValue ("spread"));
    setDetune(*parameters.getRawParameterValue ("detune"));

}

void SuperWaveGenerator::setSpread(float newSpread)
{
    int voiceNumber = (int) *parameters.getRawParameterValue ("voiceNumber");
    //float spread = *parameters.getRawParameterValue ("spread");
    float spread = newSpread;//ou la ligne précédente au choix
    
    if(voiceNumber & 1)// voiceNumber est impair
    {
        oscillators[0]->setPan(0.5);
        for (int i=1; i < voiceNumber; i++)
        {
            //oscillators[i] = new WaveGenerator(frequency - pow(-1,i)* n*(frequency*pow(2,detune/12)-frequency));

            if(i & 1)//oscillateur impair pan à gauche
            {//ci-dessous je suis pas très bon je multiplie voicenumber qui est un int avec pan qui est un float
                oscillators[i]->setPan(0.5 + 1. * spread/(voiceNumber-i));//frequence oscillateur=frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
            }
            else
            {
                oscillators[i]->setPan(0.5 - 1. * spread/(voiceNumber - (i - 1)));
            }
        }
    }
    else//voiceNumber est pair
    {
        for (int i=0; i < voiceNumber; i++)
        {
            if(i & 1)//oscillateur impair
            {
                oscillators[i]->setPan(0.5 + 1. * spread /(voiceNumber + 1 - i));//frequence oscillateur=frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
            }
            else
            {
                oscillators[i]->setPan(0.5 - 1. * spread / (voiceNumber - i));
            }
        }
    }
}


void SuperWaveGenerator::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "detune")
    {
        setDetune(newValue);
    }
    
    if (parameterID == "spread")
    {
        setSpread(newValue);
    }
    
    if (parameterID == "voiceNumber")
    {
        setVoiceNumber((int) newValue);
    }
    
    if (parameterID == "amplitude")
    {
        setAmplitude(newValue);
    }
}