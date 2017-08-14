/*
  ==============================================================================

    SuperWaveGeneratorAudioSource.cpp
    Created: 18 Jun 2017 7:58:21pm
    Author:  dell

  ==============================================================================
*/
#include "../JuceLibraryCode/JuceHeader.h"
#include "SuperWaveGeneratorAudioSource.h"


SuperWaveGeneratorAudioSource::SuperWaveGeneratorAudioSource()
   : currentSampleRate (0.0), bufferSizeExpected (0)
{
}

SuperWaveGeneratorAudioSource::~SuperWaveGeneratorAudioSource()
{
    removeAllInputs();
}

//==============================================================================
void SuperWaveGeneratorAudioSource::addInputSource (AudioSource* input, const bool deleteWhenRemoved)
{
    if (input != nullptr && ! inputs.contains (input))
    {
        double localRate;
        int localBufferSize;

        {
            const ScopedLock sl (lock);
            localRate = currentSampleRate;
            localBufferSize = bufferSizeExpected;
        }

        if (localRate > 0.0)
            input->prepareToPlay (localBufferSize, localRate);

        const ScopedLock sl (lock);

        inputsToDelete.setBit (inputs.size(), deleteWhenRemoved);
        inputs.add (input);
    }
}

void SuperWaveGeneratorAudioSource::removeInputSource (AudioSource* const input)
{
    if (input != nullptr)
    {
        ScopedPointer<AudioSource> toDelete;

        {
            const ScopedLock sl (lock);
            const int index = inputs.indexOf (input);

            if (index < 0)
                return;

            if (inputsToDelete [index])
                toDelete = input;

            inputsToDelete.shiftBits (-1, index);
            inputs.remove (index);
        }

        input->releaseResources();
    }
}

void SuperWaveGeneratorAudioSource::removeAllInputs()
{
    OwnedArray<AudioSource> toDelete;

    {
        const ScopedLock sl (lock);

        for (int i = inputs.size(); --i >= 0;)
            if (inputsToDelete[i])
                toDelete.add (inputs.getUnchecked(i));

        inputs.clear();
    }

    for (int i = toDelete.size(); --i >= 0;)
        toDelete.getUnchecked(i)->releaseResources();
}

void SuperWaveGeneratorAudioSource::prepareToPlay (int samplesPerBlockExpected, double sampleRate)
{
    tempBuffer.setSize (2, samplesPerBlockExpected);

    const ScopedLock sl (lock);

    currentSampleRate = sampleRate;
    bufferSizeExpected = samplesPerBlockExpected;

    for (int i = inputs.size(); --i >= 0;)
        inputs.getUnchecked(i)->prepareToPlay (samplesPerBlockExpected, sampleRate);
}

void SuperWaveGeneratorAudioSource::releaseResources()
{
    const ScopedLock sl (lock);

    for (int i = inputs.size(); --i >= 0;)
        inputs.getUnchecked(i)->releaseResources();

    tempBuffer.setSize (2, 0);

    currentSampleRate = 0;
    bufferSizeExpected = 0;
}

void SuperWaveGeneratorAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& info)
{
    const ScopedLock sl (lock);

    if (inputs.size() > 0)
    {
        inputs.getUnchecked(0)->getNextAudioBlock (info);

        if (inputs.size() > 1)
        {
            tempBuffer.setSize (jmax (1, info.buffer->getNumChannels()),
                                info.buffer->getNumSamples());

            AudioSourceChannelInfo info2 (&tempBuffer, 0, info.numSamples);

            for (int i = 1; i < inputs.size(); ++i)
            {
                inputs.getUnchecked(i)->getNextAudioBlock (info2);

                for (int chan = 0; chan < info.buffer->getNumChannels(); ++chan)
                    info.buffer->addFrom (chan, info.startSample, tempBuffer, chan, 0, info.numSamples);
            }
        }
    }
    else
    {
        info.clearActiveBufferRegion();
    }
}