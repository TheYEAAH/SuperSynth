/*
  ==============================================================================

    Filter.h
    Created: 21 May 2017 8:09:40pm
    Author:  dell

  ==============================================================================
*/
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
/*
It receives midi messages as it can be sensitive to velocity and keyfollow
*/
class Filter : public AudioProcessor
{
public:
    Filter();
	~Filter();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

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

    //VARIABLES
    AudioParameterFloat* cutoffParameter;//cutoff frequency in Hz from 0.0 (-infinity) to 20000 Hz
    AudioParameterFloat* resonanceParameter;//ratio betwenn 0.0 and 1.0
    AudioParameterFloat* keyFollowParameter;//ratio betwenn -100;+100
    AudioParameterFloat* velocityParameter;//ratio betwenn -100;+100
    
private:
    AudioProcessorValueTreeState parameters;//attached to only one processor, have the same lifetime as the processor
    
};