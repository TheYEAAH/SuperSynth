#ifndef __voice__
#define __voice__
#include "public.sdk/source/vst2.x/audioeffectx.h" //permet d'utiliser VstInt32
#include "superwavegenerator.h" //à inclure dans le futur

//------------------------------------------------------------------------------------------
//Ceci est un objet Voice, en midi il y a 127 voices maximum
//Le programme crée 127 Voices au départ, qui seront présentes jusqu'à la fin.
//Lorsque une note est jouée, le programme change l'état de la voix avec setState()
//La voix crée alors une oscillateur. Quand la note est relachée, la voix efface l'oscillateur.
//------------------------------------------------------------------------------------------
class Voice
{
public:
    Voice(float frequency = 440.0,bool state=0);
	~Voice();

	bool getState() const;
	void setState(bool newState);
	void getWave(float **outputs, VstInt32 sampleFrames) const;
	void setFrequency(float newFrequency);
	void setVolume(float &newVolume) const;
    void setDetune(float &newDetune) const;
    void setSpread(float &newSpread) const;

private:
    float frequency;
	bool state;//1 note is on 0 note is off
	SuperWaveGenerator * oscillator;
};

#endif
