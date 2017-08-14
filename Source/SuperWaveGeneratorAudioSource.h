/*
  ==============================================================================

    SuperWaveGeneratorAudioSource.h
    Created: 18 Jun 2017 7:58:21pm
    Author:  dell

  ==============================================================================
*/

#pragma once
#include "../JuceLibraryCode/JuceHeader.h"
//==============================================================================
/**
    An AudioSource that mixes together the output of a set of other AudioSources.

    Input sources can be added and removed while the mixer is running as long as their
    prepareToPlay() and releaseResources() methods are called before and after adding
    them to the mixer.
*/
class SuperWaveGeneratorAudioSource  : public AudioSource
{
public:
    //==============================================================================
    /** Creates a MixerAudioSource. */
    SuperWaveGeneratorAudioSource();

    /** Destructor. */
    ~SuperWaveGeneratorAudioSource();

    //==============================================================================
    /** Adds an input source to the mixer.

        If the mixer is running you'll need to make sure that the input source
        is ready to play by calling its prepareToPlay() method before adding it.
        If the mixer is stopped, then its input sources will be automatically
        prepared when the mixer's prepareToPlay() method is called.

        @param newInput             the source to add to the mixer
        @param deleteWhenRemoved    if true, then this source will be deleted when
                                    no longer needed by the mixer.
    */
    void addInputSource (AudioSource* newInput, bool deleteWhenRemoved);

    /** Removes an input source.
        If the source was added by calling addInputSource() with the deleteWhenRemoved
        flag set, it will be deleted by this method.
    */
    void removeInputSource (AudioSource* input);

    /** Removes all the input sources.
        Any sources which were added by calling addInputSource() with the deleteWhenRemoved
        flag set will be deleted by this method.
    */
    void removeAllInputs();

    //==============================================================================
    /** Implementation of the AudioSource method.
        This will call prepareToPlay() on all its input sources.
    */
    void prepareToPlay (int samplesPerBlockExpected, double sampleRate) override;

    /** Implementation of the AudioSource method.
        This will call releaseResources() on all its input sources.
    */
    void releaseResources() override;

    /** Implementation of the AudioSource method. */
    void getNextAudioBlock (const AudioSourceChannelInfo&) override;


private:
    //==============================================================================
    Array<AudioSource*> inputs;
    BigInteger inputsToDelete;
    CriticalSection lock;
    AudioSampleBuffer tempBuffer;
    double currentSampleRate;
    int bufferSizeExpected;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SuperWaveGeneratorAudioSource)
};