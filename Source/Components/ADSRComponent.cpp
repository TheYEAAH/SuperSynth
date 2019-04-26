#include "ADSRComponent.h"

//==============================================================================
ADSRComponent::ADSRComponent(AudioProcessorValueTreeState& vts)
: valueTreeState (vts)
{
    envelopeGroup = new GroupComponent;
    attackLabel = new Label;
    attackSlider = new Slider;
    decayLabel = new Label;
    decaySlider = new Slider;   
    sustainLabel = new Label;
    sustainSlider = new Slider;      
    releaseLabel = new Label;
    releaseSlider = new Slider;
    
    setSize (162, 64);
    
    
    //ADSRGroup
    envelopeGroup->setText("Envelope");
    addAndMakeVisible (envelopeGroup);
    
    //attack
    createLabel(attackLabel, "attack");
    createSlider(attackSlider, "attack"," s");
    attackAttachment = new SliderAttachment (valueTreeState, "attack", *attackSlider);
    
    //decay
    createLabel(decayLabel, "decay");
    createSlider(decaySlider, "decay"," s");
    decayAttachment = new SliderAttachment (valueTreeState, "decay", *decaySlider);
    
    //sustain
    createLabel(sustainLabel, "sustain");
    createSlider(sustainSlider, "sustain");
    sustainAttachment = new SliderAttachment (valueTreeState, "sustain", *sustainSlider);
    
    //release
    //Label
    createLabel(releaseLabel, "release");
    createSlider(releaseSlider, "release"," s");
    releaseAttachment = new SliderAttachment (valueTreeState, "release", *releaseSlider);
}

ADSRComponent::~ADSRComponent()
{
    
    attackAttachment = nullptr;
    decayAttachment = nullptr;
    sustainAttachment = nullptr;
    releaseAttachment = nullptr;
    
    envelopeGroup  = nullptr;
    attackLabel = nullptr;
    attackSlider = nullptr;
    decayLabel = nullptr;
    decaySlider = nullptr;
    sustainLabel = nullptr;
    sustainSlider = nullptr;   
    releaseLabel = nullptr;
    releaseSlider = nullptr;
}

void ADSRComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    envelopeGroup->setBounds(0, 0, 162, 64);
    
    attackLabel->setBounds (3, 18, 40, 12);//x,y,width,height
    attackSlider->setBounds(8,30,30,30);
    decayLabel->setBounds (43, 18, 40, 12);//x,y,width,height
    decaySlider->setBounds(48,30,30,30);
    sustainLabel->setBounds (83, 18, 40, 12);//x,y,width,height
    sustainSlider->setBounds(88,30,30,30);
    releaseLabel->setBounds (123, 18, 40, 12);//x,y,width,height
    releaseSlider->setBounds(128,30,30,30);
}

void ADSRComponent::createLabel(Label *label, const String &newText)
{
    label->setFont (Font (12.00f, Font::plain));
    label->setJustificationType (Justification::centred);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    label->setText (newText, dontSendNotification);
    addAndMakeVisible (label);
}

void ADSRComponent::createSlider(Slider *slider, const String &newID)
{
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setRange (0.0, 1.0, 0.0);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    slider->setPopupDisplayEnabled (false, true, this);
    slider->setValue (1.0);
    slider->setComponentID(newID);
    addAndMakeVisible (slider);
}
void ADSRComponent::createSlider(Slider *slider, const String &newID, const String &suffix)
{
    createSlider(slider, newID);
    slider->setTextValueSuffix (suffix);
}