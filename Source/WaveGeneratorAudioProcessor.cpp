/*
  ==============================================================================

    WaveGeneratorAudioProcessor.cpp
    Created: 25 May 2017 10:34:50pm
    Author:  dell

  ==============================================================================
*/

#include "WaveGeneratorAudioProcessor.h"
#include "../JuceLibraryCode/JuceHeader.h"

WaveGeneratorAudioProcessor::WaveGeneratorAudioProcessor()
: parameters (*this, nullptr)
{
    //Parameters: frequency, waveType, retrigg, phase, pulseWidth, pan, amplitude
    parameters.createAndAddParameter ("frequency",       // parameter ID
                                  "frequency",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 20000.0f),    // range
                                  100.0f,         // default value
                                  nullptr,
                                  nullptr);
                                  
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



    parameters.createAndAddParameter ("pan",       // parameter ID
                                  "pan",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  0.5f,         // default value
                                  nullptr,
                                  nullptr);

    parameters.createAndAddParameter ("amplitude",       // parameter ID
                                  "amplitude",       // parameter name
                                  String(),     // parameter label (suffix)
                                  NormalisableRange<float> (0.0f, 1.0f),    // range
                                  1.0f,         // default value
                                  nullptr,
                                  nullptr);

    parameters.state = ValueTree (Identifier ("WaveGeneratorAudioProcessor"));
}

WaveGeneratorAudioProcessor::~WaveGeneratorAudioProcessor()
{
}

//==============================================================================
const String WaveGeneratorAudioProcessor::getName() const
{
    return "WaveGeneratorAudioProcessor";
}

const String WaveGeneratorAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String WaveGeneratorAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool WaveGeneratorAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool WaveGeneratorAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool WaveGeneratorAudioProcessor::acceptsMidi() const
{
    return false;
}

bool WaveGeneratorAudioProcessor::producesMidi() const
{
    return false;
}

bool WaveGeneratorAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double WaveGeneratorAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int WaveGeneratorAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int WaveGeneratorAudioProcessor::getCurrentProgram()
{
    return 0;
}

void WaveGeneratorAudioProcessor::setCurrentProgram (int index)
{
}

const String WaveGeneratorAudioProcessor::getProgramName (int index)
{
    return String();
}

void WaveGeneratorAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void WaveGeneratorAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)//Called before playback starts, to let the filter prepare itself.
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
}

void WaveGeneratorAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}


void WaveGeneratorAudioProcessor::processBlock (AudioSampleBuffer& outputBuffer, MidiBuffer& midiMessages, int startSample, int numSamples)
{    
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
    outputBuffer.clear (i, 0, outputBuffer.getNumSamples());
    
    float tempVar;//variable temporaire qui permet de faire une fois un calcul qui prend beaucoup de ressources
    float phase;//variable temporaire qui permet de faire une fois un calcul qui prend beaucoup de ressources
    float sampleRate;//variable temporaire qui permet de faire une fois un calcul qui prend beaucoup de ressources
    phase = *parameters.getRawParameterValue ("phase");
    sampleRate = getSampleRate();
    while (--numSamples >= 0){
        tempVar = *parameters.getRawParameterValue ("amplitude") * (1 - 2 * phase);

        const float currentSample = tempVar;
        outputBuffer.addSample (0, startSample, *parameters.getRawParameterValue ("pan") * tempVar);
        outputBuffer.addSample (1, startSample, (1 - *parameters.getRawParameterValue ("pan")) * tempVar);

        phase += *parameters.getRawParameterValue ("frequency") / sampleRate;
        if (phase >= 1.0){
            phase = phase - 1.0;
        }
        ++startSample;
    }
}

//==============================================================================
bool WaveGeneratorAudioProcessor::hasEditor() const
{
    return false; // (change this to false if you choose to not supply an editor)
}

/*AudioProcessorEditor* Filter::createEditor()
{
    return new FilterEditor (*this);
}*/

//==============================================================================
void WaveGeneratorAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
    
//Parameters: frequency, waveType, retrigg, phase, pulseWidth, pan, amplitude
    ScopedPointer<XmlElement> xml (parameters.state.createXml());
    copyXmlToBinary (*xml, destData);
}

void WaveGeneratorAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState != nullptr)
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.state = ValueTree::fromXml (*xmlState);
}