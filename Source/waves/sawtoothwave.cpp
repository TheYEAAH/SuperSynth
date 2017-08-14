#include "sawtoothwave.h"

void sawtoothWave(float frequency,VstInt32 sampleFrames){
    //frequency is the frequency of the saw wave in Hertz
    //sampleFrames. number of sampleFrames in the buffer For a duration of 1s, sampleFrames=44100
    //nSamples est le nombre de samples écoulé depuis la mise en route de l'oscillateur

    //WaveGenerator envoie un float[] à sawtoothWave qui le modifie
    float onde[sampleFrames];
    float sampleRate = updateSampleRate();
    double samplePeriod=1/44100;
    int n(0);

    while (n < length - 1)
        onde[n] = 1 - 2 * fFrequency * nSamples / sampleRate + 2 * nOscillations;
        if ((nSamples + 1) / sampleRate >= (nOscillations + 1) / fFrequency){//Period=1/fFrequency=periode d'oscillation en s
            nOscillations = nOscillations + 1;
        }
        nSamples=nSamples + 1;
        n=n+1;
    end
    return onde;
}
void Supersynth::processReplacing (float** inputs, float** outputs, VstInt32 sampleFrames)
{
    float* out1 = outputs[0];
    float* out2 = outputs[1];
    float onde[sampleFrames];
    float sampleRate = updateSampleRate();
    int n=0;

    while (--sampleFrames >= 0){
        onde[n] = 1 - 2 * fFrequency * nSamples / sampleRate + 2 * nOscillations;
        (*out1++) = onde[n]; //mafonction saw
        (*out2++) = onde[n];
        if ((nSamples + 1) / sampleRate >= (nOscillations + 1) / fFrequency){//Period=1/fFrequency=periode d'oscillation en s
            nOscillations = nOscillations + 1;
        }
        nSamples=nSamples + 1;
        n=n+1;
    }
}
