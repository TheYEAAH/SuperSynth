/*
  ==============================================================================

    Amplifier.cpp
    Created: 31 Oct 2016 1:33:10pm
    Author:  dell

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#include "Amplifier.h"

Amplifier::Amplifier()
: parameters (*this, nullptr)
{

    
    parameters.createAndAddParameter ("gain",       // parameter ID
                                  "Gain",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                                  
    parameters.createAndAddParameter ("pan",       // parameter ID
                                  "Pan",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                                                                    
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
                                  
    parameters.state = ValueTree (Identifier ("Amplifier"));
}

Amplifier::~Amplifier()
{
}

//==============================================================================
const String Amplifier::getName() const
{
    return "Amplifier";
}

const String Amplifier::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String Amplifier::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool Amplifier::isInputChannelStereoPair (int index) const
{
    return true;
}

bool Amplifier::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool Amplifier::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Amplifier::producesMidi() const
{
    return false;
}

bool Amplifier::silenceInProducesSilenceOut() const
{
    return true;
}

double Amplifier::getTailLengthSeconds() const
{
    return 0.0;
}

int Amplifier::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Amplifier::getCurrentProgram()
{
    return 0;
}

void Amplifier::setCurrentProgram (int index)
{
}

const String Amplifier::getProgramName (int index)
{
    return String();
}

void Amplifier::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Amplifier::prepareToPlay (double sampleRate, int samplesPerBlock)//Called before playback starts, to let the filter prepare itself.
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    //synth.setCurrentPlaybackSampleRate (sampleRate);
}

void Amplifier::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}




void Amplifier::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    const int numSamples = buffer.getNumSamples();
    buffer.applyGain (*gainParameter);
}

//==============================================================================
bool Amplifier::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

/*AudioProcessorEditor* Amplifier::createEditor()
{
    return new AmplifierEditor (*this);
}*/

//==============================================================================
void Amplifier::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    MemoryOutputStream (destData, true).writeFloat (*gainParameter);
    MemoryOutputStream (destData, true).writeFloat (*panParameter);
    MemoryOutputStream (destData, true).writeFloat (*keyFollowParameter);
    MemoryOutputStream (destData, true).writeFloat (*velocityParameter);

}

void Amplifier::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
     *gainParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
     *panParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
     *keyFollowParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
     *velocityParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
}

//==============================================================================
// This creates new instances of the plugin..
/*AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Amplifier();
}


void Amplifier::setDetune(double newDetune)
{

    
}
double Amplifier::getGain() const
{
    return (double) *globalLevelParameter;
}
double Amplifier::getDetune() const
{
    return (double) *detuneParameter;
}*/