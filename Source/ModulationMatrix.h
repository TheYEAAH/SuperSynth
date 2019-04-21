/*
  ==============================================================================

    ModulationMatrix.h
    Created: 31 Oct 2016 6:41:55pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"

/**
A modulation matrix that knows :
- all the instances that can be modulated and the list of the paramaters that can be modulated for each device.
- the modulators that can be used
It will have the look of a table with the following columns:
sources -> targets, modAmount, modType (multiply or add)


le rôle de la ModulationMatrix est d'informer une device que l'un de ses paramètres est modulé
et de lui envoyer la modulation et le modAmount
Si un paramètre est modulé par plusieurs modulateurs,
la modulationMatrix crée un buffer qui somme ces modulations, les clipes, etc

Fonctionnement:
Lorsqu'un paramètre est assigné à une modulation, la modMatrix prévient la device qui contien le paramètre
A chaque buffer, la device demande le modAmount et l'adresse du buffer et du modAmount
Lorsque le paramètre n'est plus modulé la modMatrix prévient la device
*/

class ModulationMatrix : public AudioProcessorValueTreeState::Listener
{
public:
    
    ModulationMatrix(
    /*Processor processorsList,
    Modulation modulations*/
    );
    
	~ModulationMatrix();
	
 /** Renders the next block of data.
    The output audio data must be added to the current contents of the buffer provided. 
    Only the region of the buffer between startSample and (startSample + numSamples) 
    should be altered by this method. */
	void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const;

	/** Adds a new processor. */
	//void addProcessor(AudioProcessor newProcessor);
	
	
	/**Sets the modulation target. */
    //void setTarget(Modulation modulation, parameter processorParameterToBeModulated);
    
    	
	/**Sets the modulation source */
   // void setSource(Modulation modulation, Processor source);
    
	/**Sets the modulation amplitude */
   // void setModulationAmplitude(Modulation modulation, float newAmplitude);
    
    /**Sets the modulation type (multiply or add). 0 for multiply, 1 for add.*/
    //void setModulationtType(Modulation modulation, bool modulationType);
    
    /** Implements the AudioProcessorValueTreeState::Listener method.
    This callback method is called by the AudioProcessorValueTreeState when a parameter changes.
    @See AudioProcessorValueTreeState::Listener
    */
    void parameterChanged(const String &parameterID, float newValue) override;
    
private:
    /** Adds a modulation. */
	void addModulation();
	//Modulation * modulations[8];
	//Processor * processors[8];
    double sampleRate;
};