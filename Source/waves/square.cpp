#include "sawtooth.h"

double sawtooth(int frequency,VstInt32 sampleFrames){
    //frequency is the frequency of the saw wave in Hertz
    //sampleFrames. number of sampleFrames in the buffer For a duration of 1s, sampleFrames=44100
    double onde[length];
    P=1/frequency;//periode d'oscillation en s

    double samplePeriod=1/44100;
    int n(0);
    int nOscillations(0);

    while (n < length - 1)
        onde[n] = 1 - 2 * frequency * n * samplePeriod + 2 * nOscillations;
        if (n * samplePeriod + samplePeriod > nOscillations * P + P)
            nOscillations = nOscillations + 1;
        end
        n = n + 1;
    end
    return onde;
}
void Supersynth::processReplacing (float** inputs, float** outputs, VstInt32 sampleFrames)
{
    //float* in1  =  inputs[0];
    //float* in2  =  inputs[1];
    float* out1 = outputs[0];
    float* out2 = outputs[1];
    float onde[sampleFrames];
    float sampleRate = updateSampleRate();
    int n=0;

    while (--sampleFrames >= 0){
        onde[n] = 1 - 2 * fFrequency * nSamples / sampleRate + 2 * nOsc;
        (*out1++) = onde[n]; //mafonction saw
        (*out2++) = onde[n];
        if ((nSamples + 1) / sampleRate >= (nOsc + 1) / fFrequency){//Period=1/fFrequency=periode d'oscillation en s
            nOsc = nOsc + 1;
        }
        nSamples=nSamples + 1;
        n=n+1;
    }
}
