#include "../JuceLibraryCode/JuceHeader.h"
#include "WaveGeneratorAudioSource.h"


WaveGeneratorAudioSource::WaveGeneratorAudioSource()
    : frequency (1000.0),
      sampleRate (44100.0),
      currentPhase (0.0),
      phasePerSample (0.0),
      amplitude (0.5f)
{
}

WaveGeneratorAudioSource::~WaveGeneratorAudioSource()
{
}

//==============================================================================
void WaveGeneratorAudioSource::setAmplitude (const float newAmplitude)
{
    amplitude = newAmplitude;
}

void WaveGeneratorAudioSource::setFrequency (const double newFrequencyHz)
{
    frequency = newFrequencyHz;
    phasePerSample = 0.0;
}

//==============================================================================
void WaveGeneratorAudioSource::prepareToPlay (int /*samplesPerBlockExpected*/, double rate)
{
    currentPhase = 0.0;
    phasePerSample = 0.0;
    sampleRate = rate;
}

void WaveGeneratorAudioSource::releaseResources()
{
}

void WaveGeneratorAudioSource::getNextAudioBlock (const AudioSourceChannelInfo& info)
{
    if (phasePerSample == 0.0)
        phasePerSample = double_Pi * 2.0 / (sampleRate / frequency);

    for (int i = 0; i < info.numSamples; ++i)
    {
        const float sample = amplitude * (float) std::sin (currentPhase);
        currentPhase += phasePerSample;

        for (int j = info.buffer->getNumChannels(); --j >= 0;)
            info.buffer->setSample (j, info.startSample + i, sample);
    }
}
