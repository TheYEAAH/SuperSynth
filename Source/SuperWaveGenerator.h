/*
  ==============================================================================

    superwavegenerator.h
    Created: 11 Oct 2016 12:31:06pm
    Author:  Philippe SICABAIG

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
#include "wavegenerator.h"
//#include "PolyBLEPOscillator.h"
#include "math.h"

/** A superwave generator, a group of oscillators that creates a superwave together.
The superwave generator has the same parameters as a wave generator, with the addition
of the number of internal oscillators, the detune amount between the oscillators,
the stereo spread wich is the panning of the oscillators relative to the others.

For the moment it only generates supersaws.
In the future it has to be able to use other wave types.

It creates internally listeners for the parameters created in the SuperSynthAudioProcessor class.
(unless phase and puseWidth parameters which are not supported yet)
The listeners for the following parameters are created internally :
    retrig
    voiceNumber
    detune
    spread
    amplitude

Listeners to add in the future :
    phase
    pulseWidth

So basically this class listens to the plugin editor.
This is wrong because this means that the parameter of SuperWaveGeneratorAudioProcessor are actually created by SuperSynthAudioProcessor.
We want to improve that so that the parameters are created within the SuperWaveGeneratorAudioProcessor class
(and more generally within any AudioProcessor used internally).

The SuperWaveGeneratorAudioProcessor should have its own editor and pass its parameters and editor to the SuperSynthAudioProcessor
which should care about including the SuperWaveGeneratorAudioProcessorEditor into the SuperSynthAudioProcessorEditor class.

@See SuperSynthAudioProcessor, SuperSynthAudioProcessorEditor
*/

//------------------------------------------------------------------------------------------

class SuperWaveGenerator : public AudioProcessorValueTreeState::Listener
{
public:
    /** Creates a SuperWaveGenerator. */
    SuperWaveGenerator(AudioProcessorValueTreeState& parameters, String oscillatorID, float frequency = 440.);
    
    /** Destructor. */
	~SuperWaveGenerator();
	
    /** Renders the next block of data.
    The output audio data must be added to the current contents of the buffer provided. 
    Only the region of the buffer between startSample and (startSample + numSamples) should be altered by this method. */
	void renderNextBlock(AudioSampleBuffer& outputBuffer, int startSample, int numSamples) const;
	
	/**Sets the SuperwaveGenerator base frequency. */
	void setFrequency(float newFrequency);//used to change the frequency
	
	/** Sets the detune amount between the oscillators. Ratio between 0 and 1. */
    void setDetune(float newDetune);
    
    /** Returns the detune amount between the oscillators. Ratio between 0 and 1. */
    float getDetune() const;// ratio 0-1
    
    /** Sets the number of WaveGenerator that will be used by the SuperWaveGeneratorAudioProcessor.
    Integer included in [0;8], so a maximum of 8 voices. */
    void setVoiceNumber(int newVoiceNumber);
    
    /** Sets the stereo spread ratio (between 0 and 1) */
    void setSpread(float newSpread);
    
    /** Sets the amplitude (between 0 and 1). */
    void setAmplitude(float newAmplitude);
    
    /** Sets the wave type of the superwave generators. @See WaveGenerator  */
    void setWaveType(int newWaveType);
    
    /** Implements the AudioProcessorValueTreeState::Listener method.
    This callback method is called by the AudioProcessorValueTreeState when a parameter changes.
    @See AudioProcessorValueTreeState::Listener
    */
    void parameterChanged(const String &parameterID, float newValue) override;
    //void setPhase(float newPhase);//sets phase value, between 0 - 1
    //void setPulseWidth
    
static std::unique_ptr<AudioProcessorParameterGroup> SuperWaveGenerator::createProcessorParameters (const String& labelNum)
{
	 auto oscillatorParameterGroup = std::make_unique<AudioProcessorParameterGroup>("oscillator" + labelNum, "oscillator" + labelNum, "|");
	 oscillatorParameterGroup->addChild(
		 std::make_unique<AudioParameterFloat>(
			 "amplitude" + labelNum,// parameter ID
			 "amplitude",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.5f// default value
			 ),
		 std::make_unique<AudioParameterInt>(
			 "waveType" + labelNum,// parameter ID
			 "waveType",// parameter name
			 0,//minValue
			 3,//maxValue
			 1,//defaultValue
			 String(),//label (optional)
			 [](int value, int maximumStringLength)
	 {
		 if (maximumStringLength > 2)
		 {
			 switch (value)
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
		 }
		 else
		 {
			 return " ";
		 }
	 },//stringFromInt (optional)
			 nullptr//intFromString (optional)
		 ),
		 std::make_unique<AudioParameterInt>(
			 "pitch" + labelNum,// parameter ID
			 "pitch",// parameter name
			 -3,//minValue
			 3,//maxValue
			 0,//defaultValue
			 String(),//label (optional)
			 nullptr,//stringFromInt
			 nullptr//intFromString
			 ),
		 std::make_unique<AudioParameterInt>(
			 "voiceNumber" + labelNum,// parameter ID
			 "voiceNumber",// parameter name
			 0,//minValue
			 8,//maxValue
			 6,//defaultValue
			 String(),//label (optional)
			 nullptr,//stringFromInt
			 nullptr//intFromString
			 ),
		 std::make_unique<AudioParameterFloat>(
			 "detune" + labelNum,// parameter ID
			 "detune",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.2f// default value
			 ),
		 std::make_unique<AudioParameterFloat>(
			 "pan" + labelNum,// parameter ID
			 "pan",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.5f// default value
			 ),
		 std::make_unique<AudioParameterFloat>(
			 "phase" + labelNum,// parameter ID
			 "phase",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.0f// default value
			 ),
		 std::make_unique<AudioParameterFloat>(
			 "fine" + labelNum,// parameter ID
			 "fine",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.0f// default value
			 ),
		 std::make_unique<AudioParameterFloat>(
			 "pulseWidth" + labelNum,// parameter ID
			 "pulseWidth",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.0f// default value
			 ),
		 std::make_unique<AudioParameterFloat>(
			 "spread" + labelNum,// parameter ID
			 "spread",// parameter name
			 NormalisableRange<float>(0.0f, 1.0f),//normalisable Range
			 0.5f// default value
			 ),
		 std::make_unique<AudioParameterBool>(
			 "retrig" + labelNum, // parameter ID
			 "retrig",// parameter name
			 false,// default Value
			 String(),// label (optional)
			 nullptr,//stringFromBool
			 nullptr//boolFromString																
			 ),
		 std::make_unique<AudioParameterBool>(
			 "fixed" + labelNum, // parameter ID
			 "fixed",// parameter name
			 false,// default Value
			 String(),// label (optional)
			 nullptr,//stringFromBool
			 nullptr//boolFromString																
			 )
		 );
	 return { std::move(oscillatorParameterGroup) };
}
private:
    WaveGenerator * oscillators[8];
    AudioProcessorValueTreeState& parameters;
    float frequency;
    Random random;
    String oscillatorID;
};
