/*
  ==============================================================================

    ADSRGenerator.h
    Created: 13 Sep 2017 10:43:06pm
    Author:  dell

  ==============================================================================
*/

#pragma once
//
//  EnvelopeGenerator.h
//  SpaceBass
//
//  Created by Martin on 08.04.14.
//
//

#include <cmath>

class ADSRGenerator {
public:
    enum EnvelopeStage {
        ENVELOPE_STAGE_OFF = 0,
        ENVELOPE_STAGE_ATTACK,
        ENVELOPE_STAGE_DECAY,
        ENVELOPE_STAGE_SUSTAIN,
        ENVELOPE_STAGE_RELEASE,
        kNumEnvelopeStages
    };
    void enterStage(EnvelopeStage newStage);
    double nextSample();
    static void setSampleRate(double newSampleRate);
    inline EnvelopeStage getCurrentStage() const { return currentStage; };
    const double minimumLevel;
    
    ADSRGenerator() :
    minimumLevel(0.0001),
    currentStage(ENVELOPE_STAGE_OFF),
    currentLevel(minimumLevel),
    multiplier(1.0),
    currentSampleIndex(0),
    nextStageSampleIndex(0) {
        stageValue[ENVELOPE_STAGE_OFF] = 0.0;
        stageValue[ENVELOPE_STAGE_ATTACK] = 0.01;
        stageValue[ENVELOPE_STAGE_DECAY] = 0.5;
        stageValue[ENVELOPE_STAGE_SUSTAIN] = 0.1;
        stageValue[ENVELOPE_STAGE_RELEASE] = 1.0;
    };
    
    void setStageValue(EnvelopeStage stage, double value);
    
   // Signal0<> beganEnvelopeCycle;
  //  Signal0<> finishedEnvelopeCycle;
    
    void reset() {
        currentStage = ENVELOPE_STAGE_OFF;
        currentLevel = minimumLevel;
        multiplier = 1.0;
        currentSampleIndex = 0;
        nextStageSampleIndex = 0;
    }
private:
    EnvelopeStage currentStage;
    double currentLevel;
    double multiplier;
    static double sampleRate;
    double stageValue[kNumEnvelopeStages];
    void calculateMultiplier(double startLevel, double endLevel, unsigned long long lengthInSamples);
    unsigned long long currentSampleIndex;
    unsigned long long nextStageSampleIndex;
};
