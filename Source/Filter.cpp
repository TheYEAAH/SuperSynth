/*
  ==============================================================================

    Filter.cpp
    Created: 21 May 2017 8:09:40pm
    Author:  dell

  ==============================================================================
*/

#include "Filter.h"
#include "../JuceLibraryCode/JuceHeader.h"

Filter::Filter()
: parameters (*this, nullptr)
{

    
    parameters.createAndAddParameter ("cutoff",       // parameter ID
                                  "Cutoff",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                                  
    parameters.createAndAddParameter ("resonance",       // parameter ID
                                  "Resonance",       // parameter name
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
                                  
    parameters.state = ValueTree (Identifier ("Filter"));
}

Filter::~Filter()
{
}

//==============================================================================
const String Filter::getName() const
{
    return "Filter";
}

const String Filter::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String Filter::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool Filter::isInputChannelStereoPair (int index) const
{
    return true;
}

bool Filter::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool Filter::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool Filter::producesMidi() const
{
    return false;
}

bool Filter::silenceInProducesSilenceOut() const
{
    return false;
}

double Filter::getTailLengthSeconds() const
{
    return 0.0;
}

int Filter::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int Filter::getCurrentProgram()
{
    return 0;
}

void Filter::setCurrentProgram (int index)
{
}

const String Filter::getProgramName (int index)
{
    return String();
}

void Filter::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void Filter::prepareToPlay (double sampleRate, int samplesPerBlock)//Called before playback starts, to let the filter prepare itself.
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    //synth.setCurrentPlaybackSampleRate (sampleRate);
}

void Filter::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}




void Filter::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    const int numSamples = buffer.getNumSamples();

}

//==============================================================================
bool Filter::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

/*AudioProcessorEditor* Filter::createEditor()
{
    return new FilterEditor (*this);
}*/

//==============================================================================
void Filter::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    MemoryOutputStream (destData, true).writeFloat (*cutoffParameter);
    MemoryOutputStream (destData, true).writeFloat (*resonanceParameter);
    MemoryOutputStream (destData, true).writeFloat (*keyFollowParameter);
    MemoryOutputStream (destData, true).writeFloat (*velocityParameter);

}

void Filter::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
     *cutoffParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
     *resonanceParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
     *keyFollowParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
     *velocityParameter = MemoryInputStream (data, static_cast<size_t> (sizeInBytes), false).readFloat();
}

//==============================================================================
// This creates new instances of the plugin..
/*AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new Filter();
}


void Filter::setDetune(double newDetune)
{

    
}
double Filter::getGain() const
{
    return (double) *globalLevelParameter;
}
double Filter::getDetune() const
{
    return (double) *detuneParameter;
}*/
