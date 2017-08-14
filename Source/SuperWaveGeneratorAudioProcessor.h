/*
  ==============================================================================

    SuperWaveGeneratorAudioProcessor.h
    Created: 25 May 2017 3:53:30pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
/*
Ceci n'est pas un synthétiseur, c'est un oscillateur. Dans un synthétiseur il peut y avoir plusieurs oscillateurs par voix.
*/
class SuperWaveGeneratorAudioProcessor : public AudioProcessor
{
public:
    SuperWaveGeneratorAudioProcessor();
	~SuperWaveGeneratorAudioProcessor();

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
    /*AudioParameterChoice* waveTypeParameter;
    AudioParameterBool* retriggParameter;//1 retrig on, 0 retrig off (starts at a random phase)
    AudioParameterFloat* frequencyParameter;//frequency in Hz from 0.0 to 20000 Hz
    AudioParameterFloat* phaseParameter;//ratio betwenn 0.0 and 1
    AudioParameterFloat* pulseWidthParameter;//ratio betwenn 0 - 
    AudioParameterInt* voiceNumberParameter;//voice number between 0-8
    AudioParameterFloat* detuneParameter;//ratio between 0-1
    AudioParameterFloat* spreadParameter;//ratio between 0-1
    AudioParameterFloat* volumeParameter;//ratio between 0-1*/

    
private:
    AudioProcessorValueTreeState parameters;//attached to only one processor, have the same lifetime as the processor
}