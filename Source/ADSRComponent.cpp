#include "ADSRComponent.h"

//==============================================================================
ADSRComponent::ADSRComponent()
{
    // In your constructor, you should add any child components, and
    // initialise any special settings that your component needs.
    
    ADSRGroup = new GroupComponent;
    attackLabel = new Label;
    attack = new Slider;
    decayLabel = new Label;
    decay = new Slider;   
    sustainLabel = new Label;
    sustain = new Slider;      
    releaseLabel = new Label;
    release = new Slider;
    
    setSize (162, 64);
    
    
    //ADSRGroup
    ADSRGroup->setText("ADSR");
    addAndMakeVisible (ADSRGroup);
    
    //attack
    //Label
    attackLabel->setFont (Font (12.00f, Font::plain));
    attackLabel->setJustificationType (Justification::centred);
    attackLabel->setEditable (false, false, false);
    attackLabel->setColour (TextEditor::textColourId, Colours::black);
    attackLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    attackLabel->setText ("Attack", dontSendNotification);
    addAndMakeVisible (attackLabel);
    //Slider
    attack->setSliderStyle (Slider::RotaryVerticalDrag);
    attack->setRange (0.0, 127.0, 1.0);
    attack->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    attack->setPopupDisplayEnabled (true, this);
    attack->setTextValueSuffix (" s");
    attack->setValue (1.0);
    attack->setComponentID("attack");
    addAndMakeVisible (attack);
    
    //decay
    //Label
    decayLabel->setFont (Font (12.00f, Font::plain));
    decayLabel->setJustificationType (Justification::centred);
    decayLabel->setEditable (false, false, false);
    decayLabel->setColour (TextEditor::textColourId, Colours::black);
    decayLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    decayLabel->setText ("Decay", dontSendNotification);
    addAndMakeVisible (decayLabel);
    //Slider
    decay->setSliderStyle (Slider::RotaryVerticalDrag);
    decay->setRange (0.0, 127.0, 1.0);
    decay->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    decay->setPopupDisplayEnabled (true, this);
    decay->setTextValueSuffix (" s");
    decay->setValue (1.0);
    decay->setComponentID("decay");
    addAndMakeVisible (decay);
    
    //sustain
    //Label
    sustainLabel->setFont (Font (12.00f, Font::plain));
    sustainLabel->setJustificationType (Justification::centred);
    sustainLabel->setEditable (false, false, false);
    sustainLabel->setColour (TextEditor::textColourId, Colours::black);
    sustainLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    sustainLabel->setText ("Sustain", dontSendNotification);
    addAndMakeVisible (sustainLabel);
    //Slider
    sustain->setSliderStyle (Slider::RotaryVerticalDrag);
    sustain->setRange (0.0, 127.0, 1.0);
    sustain->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    sustain->setPopupDisplayEnabled (true, this);
    sustain->setTextValueSuffix (" s");
    sustain->setValue (1.0);
    sustain->setComponentID("sustain");
    addAndMakeVisible (sustain);
    
    //release
    //Label
    releaseLabel->setFont (Font (12.00f, Font::plain));
    releaseLabel->setJustificationType (Justification::centred);
    releaseLabel->setEditable (false, false, false);
    releaseLabel->setColour (TextEditor::textColourId, Colours::black);
    releaseLabel->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    releaseLabel->setText ("Release", dontSendNotification);
    addAndMakeVisible (sustainLabel);
    //Slider
    release->setSliderStyle (Slider::RotaryVerticalDrag);
    release->setRange (0.0, 127.0, 1.0);
    release->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    release->setPopupDisplayEnabled (true, this);
    release->setTextValueSuffix (" s");
    release->setValue (1.0);
    release->setComponentID("release");
    addAndMakeVisible (release);
}

ADSRComponent::~ADSRComponent()
{
    ADSRGroup  = nullptr;
    attackLabel = nullptr;
    attack = nullptr;
    decayLabel = nullptr;
    decay = nullptr;
    sustainLabel = nullptr;
    sustain = nullptr;   
    releaseLabel = nullptr;
    release = nullptr;
}

void ADSRComponent::paint (Graphics& g)
{
    /* This demo code just fills the component's background and
       draws some placeholder text to get you started.

       You should replace everything in this method with your own
       drawing code..
    */
/*
    g.fillAll (Colours::white);   // clear the background

    g.setColour (Colours::grey);
    g.drawRect (getLocalBounds(), 1);   // draw an outline around the component

    g.setColour (Colours::lightblue);
    g.setFont (14.0f);
    g.drawText ("FilterComponent", getLocalBounds(),
                Justification::centred, true);   // draw some placeholder tex*/
}

void ADSRComponent::resized()
{
    // This method is where you should set the bounds of any child
    // components that your component contains..
    ADSRGroup->setBounds(0, 0, 162, 64);
    
    attackLabel->setBounds (3, 18, 40, 12);//x,y,width,height
    attack->setBounds(8,30,30,30);
    decayLabel->setBounds (43, 18, 40, 12);//x,y,width,height
    decay->setBounds(48,30,30,30);
    sustainLabel->setBounds (83, 18, 40, 12);//x,y,width,height
    sustain->setBounds(88,30,30,30);
    releaseLabel->setBounds (123, 18, 40, 12);//x,y,width,height
    release->setBounds(128,30,30,30);
}
