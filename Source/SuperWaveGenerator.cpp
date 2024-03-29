/*
  ==============================================================================

    superwavegenerator.cpp
    Created: 11 Oct 2016 12:31:07pm
    Author:  dell

  ==============================================================================
*/

#include "superwavegenerator.h"

//Constructeur par défault et surchargé
SuperWaveGenerator::SuperWaveGenerator(AudioProcessorValueTreeState& parameters, String oscillatorID, float frequency)
: parameters(parameters), oscillatorID(oscillatorID), frequency(frequency)
{   
    
    parameters.addParameterListener	("waveType" + oscillatorID, this);

    /*
    parameters.addParameterListener	("frequency", this);
    parameters.addParameterListener	("phase", this);
    parameters.addParameterListener	("pulseWidth", this);*/
    parameters.addParameterListener	("retrig" + oscillatorID, this);
    parameters.addParameterListener	("voiceNumber" + oscillatorID, this);
    parameters.addParameterListener	("detune" + oscillatorID, this);
    parameters.addParameterListener	("spread" + oscillatorID, this);
    parameters.addParameterListener	("amplitude" + oscillatorID, this);

    /*
    création des oscillateurs. chaque oscillateur a une fréquence qui dépend du detune
    Si le nombre d'oscillateurs est pair, les impairs seront detunés au dessus, les pairs en dessous
    Si le nombre d'oscillateurs est impair, le 1er sera au centre, les impairs au dessus, les pairs en dessous
    En binaire, les nombres pairs finissent par 0. Ici on teste si n fini par 1
    */

    int voiceNumber = 8;//(int) *parameters.getRawParameterValue ("voiceNumber");
    float detune = *parameters.getRawParameterValue ("detune" + oscillatorID);
    float spread = *parameters.getRawParameterValue ("spread" + oscillatorID);
    
    bool retrig = (bool) *parameters.getRawParameterValue ("retrig" + oscillatorID);
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
            {   //frequence oscillateur = frequency * 2^(detune amount/12) avec detune amount entre 0 et 1
                oscillators[i] = new WaveGenerator(frequency * pow(2,2 * detune / (12*(voiceNumber-(i/2)))));
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
    setWaveType((int) *parameters.getRawParameterValue ("waveType" + oscillatorID));
    setSpread(spread);
    setDetune(detune);
    setAmplitude(*parameters.getRawParameterValue ("amplitude" + oscillatorID));

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
    parameters.removeParameterListener	("phase", this);
    parameters.removeParameterListener	("pulseWidth", this);*/
    parameters.removeParameterListener	("waveType" + oscillatorID, this);
    parameters.removeParameterListener	("retrig" + oscillatorID, this);
    parameters.removeParameterListener	("voiceNumber" + oscillatorID, this);
    parameters.removeParameterListener	("detune" + oscillatorID, this);
    parameters.removeParameterListener	("spread" + oscillatorID, this);
    parameters.removeParameterListener	("amplitude" + oscillatorID, this);
}

void SuperWaveGenerator::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const
{
    for (int i=0; i < (int) *parameters.getRawParameterValue ("voiceNumber" + oscillatorID); i++)

    {
        oscillators[i]->renderNextBlock(outputBuffer, startSample, numSamples);
    }

}

void SuperWaveGenerator::setFrequency(float newFrequency)
{
    frequency = newFrequency;
}


void SuperWaveGenerator::setAmplitude(float newAmplitude)
{
    for (int i(0); i < (int) *parameters.getRawParameterValue ("voiceNumber" + oscillatorID); i++)
    {
        oscillators[i]->setAmplitude(newAmplitude);
    }
}

void SuperWaveGenerator::setDetune(float newDetune)
{
    
    int voiceNumber = (int) *parameters.getRawParameterValue ("voiceNumber" + oscillatorID);
    float detune = *parameters.getRawParameterValue ("detune" + oscillatorID);
    
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
    return *parameters.getRawParameterValue ("detune" + oscillatorID);
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
    setSpread(*parameters.getRawParameterValue ("spread" + oscillatorID));
    setDetune(*parameters.getRawParameterValue ("detune" + oscillatorID));

}

void SuperWaveGenerator::setSpread(float newSpread)
{
    int voiceNumber = (int) *parameters.getRawParameterValue ("voiceNumber" + oscillatorID);
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

void SuperWaveGenerator::setWaveType(int newWaveType)
{
    WaveGenerator::WaveGeneratorWaveType waveType = static_cast<WaveGenerator::WaveGeneratorWaveType>(newWaveType);
    
    int i = 8;//(int) *parameters.getRawParameterValue ("voiceNumber");
    while(--i >= 0)
    {
        //oscillators[i]->setWaveType(WaveGenerator::WAVEGENERATOR_WAVETYPE_SINE);
        oscillators[i]->setWaveType(waveType);
    }
}

void SuperWaveGenerator::parameterChanged(const String &parameterID, float newValue)
{
    if (parameterID == "waveType" + oscillatorID)
    {
        setWaveType((int) newValue);
    }
    if (parameterID == "detune" + oscillatorID)
    {
        setDetune(newValue);
    }
    
    if (parameterID == "spread" + oscillatorID)
    {
        setSpread(newValue);
    }
    
    if (parameterID == "voiceNumber" + oscillatorID)
    {
        setVoiceNumber((int) newValue);
    }
    
    if (parameterID == "amplitude" + oscillatorID)
    {
        setAmplitude(newValue);
    }
}