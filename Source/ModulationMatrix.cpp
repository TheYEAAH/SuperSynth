/*
  ==============================================================================

    ModulationMatrix.cpp
    Created: 31 Oct 2016 6:41:55pm
    Author:  dell

  ==============================================================================
*/

#include "ModulationMatrix.h"

//Constructeur par défault et surchargé
ModulationMatrix::ModulationMatrix(/*processorList, modulations*/)
: /*parameters(parameters), frequency(frequency)*/
{   
    /*
    parameters.addParameterListener	("frequency", this);
    parameters.addParameterListener	("phase", this);
    parameters.addParameterListener	("pulseWidth", this);*/


    /*
    Checks if parameters can be modulated in the listed processors and lists the possible sources and targets
    */

}
//Constructeur de copie
//WaveGenerator::WaveGenerator(WaveGenerator const& existant)

ModulationMatrix::~ModulationMatrix()
{
/*
    parameters.removeParameterListener	("phase", this);
    parameters.removeParameterListener	("pulseWidth", this);*/
}

void ModulationMatrix::renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const
{
}

void ModulationMatrix::addProcessor(Processor newProcessor);
{
    /* adds a new processor to the list, checks if it can be a source or has targets for modulations and add them to the list.*/
}

void ModulationMatrix::setTarget(Modulation modulation, parameter processorParameterToBeModulated)
{    
    /*sets the modulation's target*/
}
    	
void ModulationMatrix::setSource(Modulation modulation, Processor source)
{
        /*sets the modulation's source*/

}

void ModulationMatrix::setModulationAmplitude(Modulation modulation, float newAmplitude)
{
    /*sets the modulation's amplitude*/

}
void ModulationMatrix::setModulationtType(Modulation modulation, bool modulationType)
{
    /*sets the modulation type*/

}

void ModulationMatrix::parameterChanged(const String &parameterID, float newValue)
{
        /*if (parameterID == "amplitude")
    {
        setAmplitude(newValue);
    }*/
}