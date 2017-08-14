/*
  ==============================================================================

    WaveGeneratorAudioProcessor.h
    Created: 25 May 2017 10:34:50pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
/*
Ceci n'est pas un synthétiseur, c'est un oscillateur. Dans un synthétiseur il peut y avoir plusieurs oscillateurs par voix.
*/
class WaveGeneratorAudioProcessor : public AudioProcessor
{
public:
    WaveGeneratorAudioProcessor();
	~WaveGeneratorAudioProcessor();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override {};//this is replaced
    
    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    
    //Methods
    void processBlock (AudioSampleBuffer&, MidiBuffer&, int startSample, int numSamples);
    //VARIABLEs
    
private:
    AudioProcessorValueTreeState parameters;//attached to only one processor, have the same lifetime as the processor
}