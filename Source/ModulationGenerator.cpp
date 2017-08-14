/*
  ==============================================================================

    ModulationGenerator.cpp
    Created: 31 Oct 2016 2:46:36pm
    Author:  dell

  ==============================================================================
*/

#include "ModulationGenerator.h"
#include "../JuceLibraryCode/JuceHeader.h"
//constructeurs et destructeurs
//Constructeur par défault et surchargé
ModulationGenerator::ModulationGenerator()
: sampleRate(41000.0)//updateSampleRate();
{
}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

ModulationGenerator::~ModulationGenerator()
{
}

void ModulationGenerator::getWave(MidiBuffer& midiBuffer, int startSample, int numSamples)
{

}