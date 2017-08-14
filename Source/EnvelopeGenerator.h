/*
  ==============================================================================

    EnvelopeGenerator.h
    Created: 31 Oct 2016 3:48:04pm
    Author:  dell

  ==============================================================================
*/

#ifndef ENVELOPEGENERATOR_H_INCLUDED
#define ENVELOPEGENERATOR_H_INCLUDED
#include "../JuceLibraryCode/JuceHeader.h"
/*Enveloppe has a volume parameter and a pan parameter
It changes the level of the signal following the volume parameter
The volume can be modulated by a modulator
It receves midi messages as it can be sensitive to velocity and keyfollow
It can't make the level higher. Only down. So maxGain is 0dB

L'envelopeGenerator appartient à une Voice.La Voice fournit à l'envelopeGenerator les données midis dans l'EG a besoin.

Voice peut indiquer à un module qui a des paramètres pouvant être modulés qu'un EnvelopeGenerator module un de ses paramètres.
Le buffer est donc créé par le module (Amplifier, Filter...)
Ce module appelera donc l'envelopeGenerator en lui fournissant le buffer dans lequel écrire.



*/

//  For a complete explanation of the ADSR envelope generator and code,
//  read the series of articles by the author, starting here:
//  http://www.earlevel.com/main/2013/06/01/envelope-generators/
class EnvelopeGenerator : public AudioProcessor
{
public:
    EnvelopeGenerator();
	~EnvelopeGenerator();

    void prepareToPlay (double sampleRate, int samplesPerBlock) override;
    void releaseResources() override;
    void processBlock (AudioSampleBuffer&, MidiBuffer&) override;

    //==============================================================================
    AudioProcessorEditor* createEditor() override;
    bool hasEditor() const override;

    //==============================================================================
    const String getName() const override;

    const String getInputChannelName (int channelIndex) const override;
    const String getOutputChannelName (int channelIndex) const override;
    bool isInputChannelStereoPair (int index) const override;
    bool isOutputChannelStereoPair (int index) const override;

    bool acceptsMidi() const override;
    bool producesMidi() const override;
    bool silenceInProducesSilenceOut() const override;
    double getTailLengthSeconds() const override;

    //==============================================================================
    int getNumPrograms() override;
    int getCurrentProgram() override;
    void setCurrentProgram (int index) override;
    const String getProgramName (int index) override;
    void changeProgramName (int index, const String& newName) override;

    //==============================================================================
    void getStateInformation (MemoryBlock& destData) override;
    void setStateInformation (const void* data, int sizeInBytes) override;

    


	ADSR(void);
	~ADSR(void);
	float process(void);
    float getOutput(void);
    int getState(void);
	void gate(int on);
    void setAttackRate(float rate);
    void setDecayRate(float rate);
    void setReleaseRate(float rate);
	void setSustainLevel(float level);
    void setTargetRatioA(float targetRatio);
    void setTargetRatioDR(float targetRatio);
    void reset(void);

    enum envState {
        env_idle = 0,
        env_attack,
        env_decay,
        env_sustain,
        env_release
    };

protected:
	int state;
	float output;
	float attackRate;
	float decayRate;
	float releaseRate;
	float attackCoef;
	float decayCoef;
	float releaseCoef;
	float sustainLevel;
    float targetRatioA;
    float targetRatioDR;
    float attackBase;
    float decayBase;
    float releaseBase;
 
    float calcCoef(float rate, float targetRatio);
};

inline float ADSR::process() {
	switch (state) {
        case env_idle:
            break;
        case env_attack:
            output = attackBase + output * attackCoef;
            if (output >= 1.0) {
                output = 1.0;
                state = env_decay;
            }
            break;
        case env_decay:
            output = decayBase + output * decayCoef;
            if (output <= sustainLevel) {
                output = sustainLevel;
                state = env_sustain;
            }
            break;
        case env_sustain:
            break;
        case env_release:
            output = releaseBase + output * releaseCoef;
            if (output <= 0.0) {
                output = 0.0;
                state = env_idle;
            }
	}
	return output;
}

inline void ADSR::gate(int gate) {
	if (gate)
		state = env_attack;
	else if (state != env_idle)
        state = env_release;
}

inline int ADSR::getState() {
    return state;
}

inline void ADSR::reset() {
    state = env_idle;
    output = 0.0;
}

inline float ADSR::getOutput() {
	return output;
}

#endif
//
//  ADSR.cpp
//
//  1.01  2016-01-02  njr   added calcCoef to SetTargetRatio functions that were in the ADSR widget but missing in this code
//  1.02  2017-01-04  njr   in calcCoef, checked for rate 0, to support non-IEEE compliant compilers
//

#include <math.h>


ADSR::ADSR(void) {
    reset();
    setAttackRate(0);
    setDecayRate(0);
    setReleaseRate(0);
    setSustainLevel(1.0);
    setTargetRatioA(0.3);
    setTargetRatioDR(0.0001);
}

ADSR::~ADSR(void) {
}

void ADSR::setAttackRate(float rate) {
    attackRate = rate;
    attackCoef = calcCoef(rate, targetRatioA);
    attackBase = (1.0 + targetRatioA) * (1.0 - attackCoef);
}

void ADSR::setDecayRate(float rate) {
    decayRate = rate;
    decayCoef = calcCoef(rate, targetRatioDR);
    decayBase = (sustainLevel - targetRatioDR) * (1.0 - decayCoef);
}

void ADSR::setReleaseRate(float rate) {
    releaseRate = rate;
    releaseCoef = calcCoef(rate, targetRatioDR);
    releaseBase = -targetRatioDR * (1.0 - releaseCoef);
}

float ADSR::calcCoef(float rate, float targetRatio) {
    return (rate <= 0) ? 0.0 : exp(-log((1.0 + targetRatio) / targetRatio) / rate);
}

void ADSR::setSustainLevel(float level) {
    sustainLevel = level;
    decayBase = (sustainLevel - targetRatioDR) * (1.0 - decayCoef);
}

void ADSR::setTargetRatioA(float targetRatio) {
    if (targetRatio < 0.000000001)
        targetRatio = 0.000000001;  // -180 dB
    targetRatioA = targetRatio;
    attackCoef = calcCoef(attackRate, targetRatioA);
    attackBase = (1.0 + targetRatioA) * (1.0 - attackCoef);
}

void ADSR::setTargetRatioDR(float targetRatio) {
    if (targetRatio < 0.000000001)
        targetRatio = 0.000000001;  // -180 dB
    targetRatioDR = targetRatio;
    decayCoef = calcCoef(decayRate, targetRatioDR);
    releaseCoef = calcCoef(releaseRate, targetRatioDR);
    decayBase = (sustainLevel - targetRatioDR) * (1.0 - decayCoef);
    releaseBase = -targetRatioDR * (1.0 - releaseCoef);
}





////////////////////////////////
    
private:

    //==============================================================================


    
    AudioProcessorValueTreeState parameters;//attached to only one processor, have the same lifetime as the processor

};
/* An EnvelopeGenerator is a ModulationGenerator called when the note is played
There are different types of EnvelopeGenerators

The simplest will be an ADSREnvelopeGenerator
More complex will be a MultiPointEnvelopeGenerator

Needs to know the tempo host for sync
Operates in seconds if not synced
*/
/*
class EnvelopeGenerator
{
private:
	float attackReal;
	float attack;
	float decayReal;
	float decay;
	float sustainReal;
	float sustain;
	float release;

	float sampleRateFactor;

	float tmp;

	int state;
	float actualValue;

public:
	EnvelopeGenerator(float sampleRate)
	{
		state = 0;
		actualValue = 0.0f;

		sampleRateFactor = 0.004f * 44100.0f / sampleRate;

		attack = 0.0f;
		decay = 0.0f;
		sustain = 1.0f;
		release = 0.0f;

		sustainReal = 1.0f;
		decayReal = 0.0f;
		attackReal = 0.0f;
	}

private:
	float scaleValue(float value)
	{
		value = 1.0f - value * 0.5f;
		return 0.0003f * sampleRateFactor + sampleRateFactor * powf(value, 22.0f) * 2.0f;
	}

	float scaleValueAttack(float value)
	{
		value = 1.0f - value * 0.5f;
		return 0.0003f * sampleRateFactor + sampleRateFactor * powf(value, 24.0f) * 7.0f;
	}

	float scaleValueDecay(float value)
	{
		value = 1.0f - value * 0.5f;
		return 0.0003f * sampleRateFactor + sampleRateFactor * powf(value, 23.0f) * 7.0f;
	}

public:
	void setAttack(float value)
	{
		this->attackReal = value;
		this->attack = this->scaleValueAttack(value);
	}

	void setDecay(float value)
	{
		this->decayReal = value;
		this->decay = this->scaleValueDecay(value);
	}

	void setSustain(float value)
	{
		this->sustainReal = value;
		this->sustain = this->scaleValue(value);
	}

	void setRelease(float value)
	{
		this->release = this->scaleValue(value) * 8.0f;
	}

	inline float tick(bool noteOn, bool isAttackExp) 
	{
        float returnValue = 0.0f;
		if (!noteOn && actualValue > 0.0f)
		{
			state = 3;
		}
		if (!noteOn && actualValue <= 0.0f)
		{
			state = 4;
		}
		switch (state)
		{
		case 0:
            if (isAttackExp)
            {
			    actualValue += attack * (actualValue + sampleRateFactor);
            }
            else
            {
                 actualValue += attack * sampleRateFactor * 200.0f * (1.04f + this->attackReal * 0.5f - actualValue);
            }
			if (actualValue > 1.0f)
			{
				actualValue = 1.0f; 
				state = 1;
			}
            if (isAttackExp)
            {
                returnValue = actualValue * actualValue * actualValue * actualValue * actualValue;
            }
            else
            {
                returnValue = actualValue;
            }
            break;
		case 1:
            actualValue -= decay * (actualValue + sampleRateFactor);
            tmp = actualValue;

			if (tmp <= sustainReal)
			{
				tmp = sustainReal;
				state = 2;
			}
            returnValue = tmp;
            break;
        case 2:
            actualValue = sustainReal;
            returnValue = sustainReal;
            break;
		case 3:
			actualValue -= release * (actualValue + sampleRateFactor);
			if (actualValue < 0.0f)
			{
				actualValue = 0.0f;
				state = 4;
			}
            returnValue = actualValue;
            break;
		case 4: 
			returnValue = actualValue = 0.0f;
			break;
		}
		return returnValue;
	}

	bool isNotePlaying(bool noteOn)
	{
		return noteOn || actualValue > 0;
	}

	void resetState()
	{
		state = 0;
	}

	float getValueFasterAttack()
	{
		if (state == 0 && this->attackReal == 0.0f)
		{
			return 1.0f;
		}
		return actualValue;
	}

	void resetAll()
	{
		actualValue = 0.0f;
		state = 0;
	}
};
*/


#endif  // ENVELOPEGENERATOR_H_INCLUDED
