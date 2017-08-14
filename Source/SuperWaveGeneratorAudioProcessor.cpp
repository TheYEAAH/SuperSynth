/*
  ==============================================================================

    SuperWaveGeneratorAudioProcessor.cpp
    Created: 25 May 2017 3:53:30pm
    Author:  dell

  ==============================================================================
*/

#include "SuperWaveGeneratorAudioProcessor.h"
#include "../JuceLibraryCode/JuceHeader.h"


SuperWaveGeneratorAudioProcessor::SuperWaveGeneratorAudioProcessor()
: parameters (*this, nullptr)
{
    parameters.createAndAddParameter ("waveType", // parameter ID
                                  "waveType",// parameter name
                                  String(),// parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f, 1.0f),// range
                                  0.0f,// default value
                                  [](float value)
                                  {
                                      // value to text function
                                      return value < 0.5 ? "Sine" : "Saw";
                                  },
                                  [](const String& text)
                                  {
                                      // text to value function
                                      if (text == "Sine")    return 0.0f;
                                      if (text == "Saw")  return 1.0f;
                                      return 0.0f;
                                  });

    parameters.createAndAddParameter ("retrigg", // parameter ID
                                  "retrigg",// parameter name
                                  String(),// parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f, 1.0f),// range
                                  0.0f,// default value
                                  [](float value)
                                  {
                                      // value to text function
                                      return value < 0.5 ? "No" : "Yes";
                                  },
                                  [](const String& text)
                                  {
                                      // text to value function
                                      if (text == "No")    return 0.0f;
                                      if (text == "Yes")  return 1.0f;
                                      return 0.0f;
                                  });
                         
    parameters.createAndAddParameter ("phase",       // parameter ID
                                  "phase",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                       
    parameters.createAndAddParameter ("pulseWidth",       // parameter ID
                                  "pulseWidth",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);

    parameters.createAndAddParameter ("voiceNumber",       // parameter ID
                                  "voiceNumber",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 8.0f,1.0f),    // range
                                  1.0f,         // default value
                                  nullptr,
                                  nullptr);
    parameters.createAndAddParameter ("detune",       // parameter ID
                                  "detune",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);

    parameters.createAndAddParameter ("spread",       // parameter ID
                                  "spread",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);

    parameters.createAndAddParameter ("amplitude",       // parameter ID
                                  "amplitude",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.0f,         // default value
                                  nullptr,
                                  nullptr);
                                  
    parameters.state = ValueTree (Identifier ("SuperWaveGeneratorAudioProcessor"));
}
SuperWaveGeneratorAudioProcessor::~SuperWaveGeneratorAudioProcessor()
{
}

//==============================================================================
const String SuperWaveGeneratorAudioProcessor::getName() const
{
    return "SuperWaveGeneratorAudioProcessor";
}

const String SuperWaveGeneratorAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String SuperWaveGeneratorAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool SuperWaveGeneratorAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool SuperWaveGeneratorAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool SuperWaveGeneratorAudioProcessor::acceptsMidi() const
{
    return false;
}

bool SuperWaveGeneratorAudioProcessor::producesMidi() const
{
    return false;
}

bool SuperWaveGeneratorAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SuperWaveGeneratorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SuperWaveGeneratorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SuperWaveGeneratorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SuperWaveGeneratorAudioProcessor::setCurrentProgram (int index)
{
}

const String SuperWaveGeneratorAudioProcessor::getProgramName (int index)
{
    return String();
}

void SuperWaveGeneratorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SuperWaveGeneratorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)//Called before playback starts, to let the filter prepare itself.
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void SuperWaveGeneratorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}




void SuperWaveGeneratorAudioProcessor::processBlock (AudioSampleBuffer& outputBuffer, MidiBuffer& midiMessages, int startSample, int numSamples)
{    


}

//==============================================================================
bool SuperWaveGeneratorAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

/*AudioProcessorEditor* Filter::createEditor()
{
    return new FilterEditor (*this);
}*/

//==============================================================================
void SuperWaveGeneratorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    ScopedPointer<XmlElement> xml (parameters.state.createXml());
    copyXmlToBinary (*xml, destData);
}

void SuperWaveGeneratorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState != nullptr)
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.state = ValueTree::fromXml (*xmlState);
}
