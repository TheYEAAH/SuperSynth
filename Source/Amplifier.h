/*
  ==============================================================================

    Amplifier.h
    Created: 31 Oct 2016 1:33:10pm
    Author:  dell

  ==============================================================================
*/
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
/*Amplifier has a volume parameter and a pan parameter
It changes the level of the signal following the volume parameter
The volume can be modulated by a modulator
It receves midi messages as it can be sensitive to velocity and keyfollow
It can't make the level higher. Only down. So maxGain is 0dB
*/
class Amplifier : public AudioProcessor
{
public:
    Amplifier();
	~Amplifier();

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
    //void setPan(float newPan);//used to change the pan
    //void setGain(float &newGain);//used to change the volume
    //VARIABLES
    AudioParameterFloat* panParameter;//gain in dB, from 0.0 (-infinity) to 1.0 (0dB)
    AudioParameterFloat* gainParameter;//ratio betwenn 0.0 and 1.0
    AudioParameterFloat* keyFollowParameter;//ratio betwenn -100;+100
    AudioParameterFloat* velocityParameter;//ratio betwenn -100;+100
    
private:

    //==============================================================================


    
    AudioProcessorValueTreeState parameters;//attached to only one processor, have the same lifetime as the processor

};