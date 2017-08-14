/*
  ==============================================================================

    ModulationGenerator.h
    Created: 31 Oct 2016 2:46:36pm
    Author:  dell

  ==============================================================================
*/

#ifndef MODULATIONGENERATOR_H_INCLUDED
#define MODULATIONGENERATOR_H_INCLUDED

#include "../JuceLibraryCode/JuceHeader.h"
/* A ModulationGenerator can create modulation knowing when the note starts, and which is the note
Some modulators may need to know midi data
A ModulationGenerator can be used to modulate various parameters,
so a ModulationGenerator writes in his own buffer when asked to
and he communicates the buffer's adress to modulated components who will read the buffer

A ModulationGenerator can have parameters that can also be modulated

A ModulationGenerator creates modulations between 0.0 and 1.0,
so when modulations are summed, their maximum level will be 1.0
If the sum is bigger than 1.0, then it will clipped

ModulationGenerators need to be called before audioprocessing starts,
so that audio processors can use the modulations

Needs two fonctions:
one called every buffer, that writes the modulation in a buffer
one that sends the adress of the buffer to the modulated devices so that they can  read it
*/
class ModulationGenerator
{
public:
    ModulationGenerator();
	~ModulationGenerator();

	void getWave(MidiBuffer& midiBuffer, int startSample, int numSamples);

private:
    float sampleRate;
    //*float modulation;

};




#endif  // MODULATIONGENERATOR_H_INCLUDED
