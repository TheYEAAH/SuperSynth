#ifndef __voice__
#define __voice__
#include "public.sdk/source/vst2.x/audioeffectx.h" //permet d'utiliser VstInt32
#include "superwavegenerator.h" //� inclure dans le futur

//------------------------------------------------------------------------------------------
//Ceci est un objet Voice, en midi il y a 127 voices maximum
//Le programme cr�e 127 Voices au d�part, qui seront pr�sentes jusqu'� la fin.
//Lorsque une note est jou�e, le programme change l'�tat de la voix avec setState()
//La voix cr�e alors une oscillateur. Quand la note est relach�e, la voix efface l'oscillateur.
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
