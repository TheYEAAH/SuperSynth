#include "PolyBLEPOscillator.h"

// PolyBLEP by Tale
// (slightly modified)
// http://www.kvraudio.com/forum/viewtopic.php?t=375517
double PolyBLEPOscillator::poly_blep(double t)
{
    double dt = mPhaseIncrement / twoPI;
    // 0 <= t < 1
    if (t < dt) {
        t /= dt;
        return t+t - t*t - 1.0;
    }
    // -1 < t < 0
    else if (t > 1.0 - dt) {
        t = (t - 1.0) / dt;
        return t*t + t+t + 1.0;
    }
    // 0 otherwise
    else return 0.0;
}

double PolyBLEPOscillator::nextSample() {
    double value = 0.0;
    double t = mPhase / twoPI;
    
    if (mOscillatorWaveType == OSCILLATOR_WAVETYPE_SINE) {
        value = naiveWaveformForWaveType(OSCILLATOR_WAVETYPE_SINE);
    } else if (mOscillatorWaveType == OSCILLATOR_WAVETYPE_SAW) {
        value = naiveWaveformForWaveType(OSCILLATOR_WAVETYPE_SAW);
        value -= poly_blep(t);
    } else {
        value = naiveWaveformForWaveType(OSCILLATOR_WAVETYPE_SQUARE);
        value += poly_blep(t);
        value -= poly_blep(fmod(t + 0.5, 1.0));
        if (mOscillatorWaveType == OSCILLATOR_WAVETYPE_TRIANGLE) {
            // Leaky integrator: y[n] = A * x[n] + (1 - A) * y[n-1]
            value = mPhaseIncrement * value + (1 - mPhaseIncrement) * lastOutput;
            lastOutput = value;
        }
    }
    
    mPhase += mPhaseIncrement;
    while (mPhase >= twoPI) {
        mPhase -= twoPI;
    }
    return value;
}