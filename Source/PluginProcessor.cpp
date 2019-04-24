/*
  ==============================================================================

    This file was auto-generated by the Introjucer!

    It contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"

//==============================================================================
SuperSynthAudioProcessor::SuperSynthAudioProcessor()
: parameters (*this, nullptr, Identifier ("SupersynthAPVTS"),
                {
                    std::make_unique<AudioParameterBool> (
                                                            "retrig", // parameter ID
                                                            "retrig",// parameter name
                                                            false,// default Value
                                                            String(),// label (optional)
                                                            nullptr,//stringFromBool
                                                            nullptr//boolFromString
                                                         ),
                    std::make_unique<AudioParameterFloat> (
                                                            "amplitude",// parameter ID
                                                            "amplitude",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.5f// default value
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "pan",// parameter ID
                                                            "pan",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.5f// default value
                                                          ),
                    std::make_unique<AudioParameterInt> (
                                                            "waveType",// parameter ID
                                                            "waveType",// parameter name
                                                            0,//minValue
                                                            3,//maxValue
                                                            1,//defaultValue
                                                            String(),//label (optional)
                                                            [](int value, int maximumStringLength){
                                    if (maximumStringLength >2)
                                    {
                                        switch ( value )
                                        {
                                            case 0:
                                            return "sin";
                                            case 1:
                                            return "saw";
                                            case 2:
                                            return "sqr";
                                            case 3:
                                            return "tri";
                                            default:
                                            return "wav";
                                        }
                                    }else
                                    {
                                        return " ";
                                    }
                                    },//stringFromInt (optional)
                                                            nullptr//intFromString (optional)
                                                          ),
                    std::make_unique<AudioParameterInt> (
                                                            "pitch",// parameter ID
                                                            "pitch",// parameter name
                                                            -3,//minValue
                                                            3,//maxValue
                                                            0,//defaultValue
                                                            String(),//label (optional)
                                                            nullptr,//stringFromInt
                                                            nullptr//intFromString
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "fine",// parameter ID
                                                            "fine",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),                                                          
                    std::make_unique<AudioParameterFloat> (
                                                            "phase",// parameter ID
                                                            "phase",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),       
                    std::make_unique<AudioParameterFloat> (
                                                            "pulseWidth",// parameter ID
                                                            "pulseWidth",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),
                    std::make_unique<AudioParameterInt> (
                                                            "voiceNumber",// parameter ID
                                                            "voiceNumber",// parameter name
                                                            0,//minValue
                                                            8,//maxValue
                                                            6,//defaultValue
                                                            String(),//label (optional)
                                                            nullptr,//stringFromInt
                                                            nullptr//intFromString
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "detune",// parameter ID
                                                            "detune",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.2f// default value
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "spread",// parameter ID
                                                            "spread",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.5f// default value
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "ampAttack",// parameter ID
                                                            "ampAttack",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "ampSustain",// parameter ID
                                                            "ampSustain",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),                                  
                    std::make_unique<AudioParameterFloat> (
                                                            "ampRelease",// parameter ID
                                                            "ampRelease",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),       
                    std::make_unique<AudioParameterFloat> (
                                                            "filterAttack",// parameter ID
                                                            "filterAttack",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),
                    std::make_unique<AudioParameterFloat> (
                                                            "filterSustain",// parameter ID
                                                            "filterSustain",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f
                                                          ),                                  
                    std::make_unique<AudioParameterFloat> (
                                                            "filterRelease",// parameter ID
                                                            "filterRelease",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.0f// default value
                                                          ),                                        
                    std::make_unique<AudioParameterFloat> (
                                                            "globalLevel",// parameter ID
                                                            "globalLevel",// parameter name
                                                            NormalisableRange<float> (0.0f, 1.0f),//normalisable Range
                                                            0.5f// default value
                                                          )
                  })//this was the AudioProcessorValueTreeState::ParameterLayout

{                                             
    //parameters.state = ValueTree (Identifier ("Supersynth"));

    //initializing the synth 
    const int numVoices = 128;//128 voices
    // Add some voices...
    for (int i = numVoices; --i >= 0;)
        synth.addVoice (new SineWaveVoice(parameters));
    // ..and give the synth a sound to play
    synth.addSound (new SineWaveSound());

}

SuperSynthAudioProcessor::~SuperSynthAudioProcessor()
{
}

//==============================================================================
const String SuperSynthAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

const String SuperSynthAudioProcessor::getInputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

const String SuperSynthAudioProcessor::getOutputChannelName (int channelIndex) const
{
    return String (channelIndex + 1);
}

bool SuperSynthAudioProcessor::isInputChannelStereoPair (int index) const
{
    return true;
}

bool SuperSynthAudioProcessor::isOutputChannelStereoPair (int index) const
{
    return true;
}

bool SuperSynthAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SuperSynthAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SuperSynthAudioProcessor::silenceInProducesSilenceOut() const
{
    return false;
}

double SuperSynthAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SuperSynthAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SuperSynthAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SuperSynthAudioProcessor::setCurrentProgram (int index)
{
}

const String SuperSynthAudioProcessor::getProgramName (int index)
{
    return String();
}

void SuperSynthAudioProcessor::changeProgramName (int index, const String& newName)
{
}

//==============================================================================
void SuperSynthAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)//Called before playback starts, to let the filter prepare itself.
{
    // Use this method as the place to do any pre-playback
    // initialisation that you need..
    synth.setCurrentPlaybackSampleRate (sampleRate);
}

void SuperSynthAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}




void SuperSynthAudioProcessor::processBlock (AudioSampleBuffer& buffer, MidiBuffer& midiMessages)
{
    // In case we have more outputs than inputs, this code clears any output
    // channels that didn't contain input data, (because these aren't
    // guaranteed to be empty - they may contain garbage).
    // I've added this to avoid people getting screaming feedback
    // when they first compile the plugin, but obviously you don't need to
    // this code if your algorithm already fills all the output channels.
    
    //Gestion des midiEvents
/*    int time;
    MidiMessage m;
 
    for (MidiBuffer::Iterator i (midiMessages); i.getNextEvent (m, time);)
    {
        if (m.isNoteOn())
        {
            //m.getNoteNumber();
        }
        else if (m.isNoteOff())
        {
        }
        else if (m.isAftertouch())
        {
        }
        else if (m.isPitchWheel())
        {
        }
    
    }
*/    
    
    
    
    
    for (int i = getNumInputChannels(); i < getNumOutputChannels(); ++i)
        buffer.clear (i, 0, buffer.getNumSamples());
    
    const int numSamples = buffer.getNumSamples();
    synth.renderNextBlock (buffer, midiMessages, 0, numSamples);
    buffer.applyGain (*parameters.getRawParameterValue ("globalLevel"));
    
 
}

//==============================================================================
bool SuperSynthAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

AudioProcessorEditor* SuperSynthAudioProcessor::createEditor()
{
    return new SuperSynthAudioProcessorEditor (*this, parameters);
}

//==============================================================================
void SuperSynthAudioProcessor::getStateInformation (MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.

    ScopedPointer<XmlElement> xml (parameters.state.createXml());
    copyXmlToBinary (*xml, destData);

}

void SuperSynthAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
    ScopedPointer<XmlElement> xmlState (getXmlFromBinary (data, sizeInBytes));
    if (xmlState != nullptr)
        if (xmlState->hasTagName (parameters.state.getType()))
            parameters.state = ValueTree::fromXml (*xmlState);
}

//==============================================================================
// This creates new instances of the plugin..
AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SuperSynthAudioProcessor();
}