#ifndef sawtooth_H_INCLUDED
#define sawtooth_H_INCLUDED
double sawtooth(int frequency,VstInt32 sampleFrames);
    //frequency is the frequency of the saw wave in Hertz
    //length=number of samples or sampleFrames. For a duration of 1s, length=44100
    //y is a vector which will be played with wavplay(y,44100);
    //retourne un tableau de longueur length

#endif // SAWTOOTH_H_INCLUDED
