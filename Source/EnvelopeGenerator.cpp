/*
  ==============================================================================

    EnvelopeGenerator.cpp
    Created: 31 Oct 2016 3:48:04pm
    Author:  dell

  ==============================================================================
*/

#include "EnvelopeGenerator.h"
#include "../JuceLibraryCode/JuceHeader.h"
EnvelopeGenerator::EnvelopeGenerator()
: parameters (*this, nullptr)
{

    
    parameters.createAndAddParameter ("attack",       // parameter ID
                                  "attack",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 20.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                                  
    parameters.createAndAddParameter ("decay",       // parameter ID
                                  "decay",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 20.0f),    // range
                                  0.6f,         // default value
                                  nullptr,
                                  nullptr);
                                  
    parameters.createAndAddParameter ("sustain",       // parameter ID
                                  "sustain",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.8f,         // default value
                                  nullptr,
                                  nullptr);
                                  
    parameters.createAndAddParameter ("release",       // parameter ID
                                  "release",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 20.0f),    // range
                                  0.3f,         // default value
                                  nullptr,
                                  nullptr);
/*                                                                    
    parameters.createAndAddParameter ("keyFollow",       // parameter ID
                                  "KeyFollow",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                                                                    
    parameters.createAndAddParameter ("velocity",       // parameter ID
                                  "Velocity",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
 */                                 
    parameters.state = ValueTree (Identifier ("EnvelopeGenerator"));
}

Amplifier::~Amplifier()
{
}

//==============================================================================
const String EnvelopeGenerator::getName() const
{
    return "EnvelopeGenerator";
}

const String EnvelopeGenerator::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String EnvelopeGenerator::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool EnvelopeGenerator::isInputChannelStereoPair (int index) const
{
    return true;
}

bool EnvelopeGenerator::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool EnvelopeGenerator::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool EnvelopeGenerator::producesMidi() const
{
    return false;
}

bool EnvelopeGenerator::silenceInProducesSilenceOut() const
{
    return false;
}

double EnvelopeGenerator::getTailLengthSeconds() const
{
    return 0.0;
}

int EnvelopeGenerator::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int EnvelopeGenerator::getCurrentProgram()
{
    return 0;
}

void EnvelopeGenerator::setCurrentProgram (int index)
{
}

const String EnvelopeGenerator::getProgramName (int index)
{
    return String();
}

void EnvelopeGenerator::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void EnvelopeGenerator::prepareToPlay (double sampleRate, int samplesPerBlock)//Called before playback starts, to let the filter prepare itself.
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    //synth.setCurrentPlaybackSampleRate (sampleRate);
}

void EnvelopeGenerator::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}




void EnvelopeGenerator::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages) override
{
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    const int numSamples = buffer.getNumSamples();
    buffer.applyGain (*gainParameter);
}

//==============================================================================
bool EnvelopeGenerator::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

/*AudioProcessorEditor* Amplifier::createEditor()
{
    return new AmplifierEditor (*this);
}*/

//==============================================================================
void EnvelopeGenerator::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
    ScopedPointer<XmlElement> xml (parameters.state.createXml());
    copyXmlToBinary (*xml, destData);


}

void EnvelopeGenerator::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState != nullptr)
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.state = ValueTree::fromXml (*xmlState);
}