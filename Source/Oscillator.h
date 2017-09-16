#pragma once
#include <math.h>

class Oscillator {
public:
    enum OscillatorWaveType {
        OSCILLATOR_WAVETYPE_SINE = 0,
        OSCILLATOR_WAVETYPE_SAW,
        OSCILLATOR_WAVETYPE_SQUARE,
        OSCILLATOR_WAVETYPE_TRIANGLE,
        kNumOscillatorWaveTypes
    };
    void setWaveType(OscillatorWaveType waveType);
    void setFrequency(double frequency);
    void setSampleRate(double sampleRate);
    void generate(double* buffer, int nFrames);
    inline void setMuted(bool muted) { isMuted = muted; }
    virtual double nextSample();
    Oscillator() :
    mOscillatorWaveType(OSCILLATOR_WAVETYPE_SAW),
    mPI(2*acos(0.0)),
    twoPI(2 * mPI),
    isMuted(true),
    mFrequency(440.0),
    mPitchMod(0.0),
    mPhase(0.0) { updateIncrement(); };
    
    void reset() { mPhase = 0.0; }
    void setPitchMod(double amount);
protected:
    double naiveWaveformForWaveType(OscillatorWaveType waveType);
    OscillatorWaveType mOscillatorWaveType;
    const double mPI;
    const double twoPI;
    bool isMuted;
    double mFrequency;
    double mPhase;
    static double mSampleRate;
    double mPhaseIncrement;
    void updateIncrement();
    
    double mPitchMod;
};

