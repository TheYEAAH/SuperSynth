/*
  ==============================================================================

    SineWaveVoice.cpp
    Created: 6 Feb 2016 11:58:58pm
    Author:  dell

  ==============================================================================
*/

#include "SineWaveVoice.h"

SineWaveVoice::SineWaveVoice(AudioProcessorValueTreeState& parameters, double currentAngle, double angleDelta, double tailOff)
: currentAngle(currentAngle), angleDelta(angleDelta), tailOff(tailOff), parameters(parameters)
{
    leftFilter.setCoefficients(IIRCoefficients::makeLowPass(getSampleRate(),20000.0));
    rightFilter.setCoefficients(IIRCoefficients::makeLowPass(getSampleRate(),20000.0));
}

bool SineWaveVoice::canPlaySound (SynthesiserSound* sound)
{
    return dynamic_cast<SineWaveSound*> (sound) != nullptr;
}

void SineWaveVoice::startNote (int midiNoteNumber, float velocity, SynthesiserSound* /*sound*/, int /*currentPitchWheelPosition*/)
{
    currentAngle = 0.0;
    //level = velocity * globalLevel;//velocity * 1.15;
    tailOff = 0.0;

    double cyclesPerSecond = MidiMessage::getMidiNoteInHertz (midiNoteNumber);
    double cyclesPerSample = cyclesPerSecond / getSampleRate();

    angleDelta = cyclesPerSample * 2.0 * double_Pi;
    
    //à l'activation de la note on crée un SuperWaveGenerator
    oscillator = new SuperWaveGenerator(parameters,(float)cyclesPerSecond);
    state = 1;
    
}

void SineWaveVoice::stopNote (float /*velocity*/, bool allowTailOff)
{
    if (allowTailOff)
    {
            //start a tail-off by setting this flag. The render callback will pick up on
            //this and do a fade out, calling clearCurrentNote() when it's finished.

        if (tailOff == 0.0)
        {
            tailOff = 1.0;
        }
    }
    else
    {// we're being told to stop playing immediately, so reset everything..
        clearCurrentNote();
        angleDelta = 0.0;

        state = 0;
    }
}

void SineWaveVoice::pitchWheelMoved (int /*newValue*/)
{
        // not implemented for the purposes of this demo!
}

void SineWaveVoice::controllerMoved (int /*controllerNumber*/, int /*newValue*/)
{
    // not implemented for the purposes of this demo!
}

void SineWaveVoice::renderNextBlock (AudioSampleBuffer& outputBuffer, int startSample, int numSamples)
{
    if (angleDelta != 0.0)
    {
        if (tailOff > 0)//on a arrêté d'appuyer sur la touche, release
        {
            /*oscillator->getWave(outputBuffer, startSample, numSamples);
            leftFilter.processSamples(outputBuffer.getWritePointer(0),numSamples);//left channel
            rightFilter.processSamples(outputBuffer.getWritePointer(1),numSamples);//right channel*/
            while (--numSamples >= 0)
            {
                /*const float currentSample = (float) (sin (currentAngle) * globalLevel * tailOff);

                for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);

                currentAngle += angleDelta;
                ++startSample;*/

                tailOff *= 0.99;

                if (tailOff <= 0.005)
                {
                    // tells the synth that this voice has stopped
                    clearCurrentNote();
                    //delete oscillator;//on libère la case mémoire pointée par le WaveGenerator (on efface pas le pointeur)
                    angleDelta = 0.0;
                    break;
                }
            }
        
        //oscillator->getWave(outputBuffer.getArrayOfWritePointers(), numSamples);
        }
        else
        {
            oscillator->renderNextBlock(outputBuffer, startSample, numSamples);
            leftFilter.processSamples(outputBuffer.getWritePointer(0),numSamples);//left channel
            rightFilter.processSamples(outputBuffer.getWritePointer(1),numSamples);//right channel
            
            /*while (--numSamples >= 0)
            {
                const float currentSample = (float) (sin (currentAngle) * globalLevel);

                for (int i = outputBuffer.getNumChannels(); --i >= 0;)
                    outputBuffer.addSample (i, startSample, currentSample);

                currentAngle += angleDelta;
                ++startSample;
            }*/
        }
        
    }
    
}