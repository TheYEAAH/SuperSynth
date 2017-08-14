/*
  ==============================================================================

    WaveGeneratorAudioSource.h
    Created: 15 Jun 2017 12:08:18am
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"


//==============================================================================
/**
    A simple AudioSource that generates a sine wave.

*/
class WaveGeneratorAudioSource  : public AudioSource
{
public:
    //==============================================================================
    // Creates a ToneGeneratorAudioSource.
    WaveGeneratorAudioSource();

    // Destructor.
    ~WaveGeneratorAudioSource();
    // Holds the parameters being used by a WaveGeneratorAudioSource.
/*    struct Parameters
    {
        Parameters() noexcept
          : amplitude   (0.5f),
            frequency    (0.5f),
            phase   (0.33f),
            waveType   (0.4f),
            pulseWidth      (1.0f),
        {}

        float amplitude;     // Room size, 0 to 1.0, where 1.0 is big, 0 is small. 
        float frequency;      // Damping, 0 to 1.0, where 0 is not damped, 1.0 is fully damped
        float phase;     // Wet level, 0 to 1.0 
        float waveType;     // Dry level, 0 to 1.0 
        float pulseWidth;        // Reverb width, 0 to 1.0, where 1.0 is very wide.
    };*/
    //==============================================================================
    /** Sets the signal's amplitude. */
    void setAmplitude (float newAmplitude);

    /** Sets the signal's frequency. */
    void setFrequency (double newFrequencyHz);


    //==============================================================================
    /** Implementation of the AudioSource method. */
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;

    /** Implementation of the AudioSource method. */
    void releaseResources() override;

    /** Implementation of the AudioSource method. */
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;


private:
    //==============================================================================
    double frequency, sampleRate;
    double currentPhase, phasePerSample;
    float amplitude;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (WaveGeneratorAudioSource)
};