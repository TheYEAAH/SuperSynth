/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.1.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library - "Jules' Utility Class Extensions"
  Copyright (c) 2015 - ROLI Ltd.

  ==============================================================================
*/

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "SliderComponent.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SliderComponent::SliderComponent ()
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    addAndMakeVisible (tabbedComponent = new TabbedComponent (TabbedButtonBar::TabsAtTop));
    tabbedComponent->setTabBarDepth (30);
    tabbedComponent->addTab (TRANS("Tab 0"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Tab 1"), Colours::lightgrey, 0, false);
    tabbedComponent->addTab (TRANS("Tab 2"), Colours::lightgrey, 0, false);
    tabbedComponent->setCurrentTabIndex (0);

    addAndMakeVisible (hyperlinkButton = new HyperlinkButton (TRANS("new hyperlink"),
                                                              URL ("http://www.juce.com")));
    hyperlinkButton->setTooltip (TRANS("http://www.juce.com"));

    addAndMakeVisible (groupComponent2 = new GroupComponent ("new group",
                                                             TRANS("Oscillator1")));

    addAndMakeVisible (slider21 = new Slider ("new slider"));
    slider21->setRange (0, 10, 0);
    slider21->setSliderStyle (Slider::RotaryVerticalDrag);
    slider21->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider21->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider21->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider21->addListener (this);

    addAndMakeVisible (slider22 = new Slider ("new slider"));
    slider22->setRange (0, 10, 0);
    slider22->setSliderStyle (Slider::RotaryVerticalDrag);
    slider22->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider22->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider22->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider22->addListener (this);

    addAndMakeVisible (slider23 = new Slider ("new slider"));
    slider23->setRange (0, 10, 0);
    slider23->setSliderStyle (Slider::RotaryVerticalDrag);
    slider23->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider23->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider23->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider23->addListener (this);

    addAndMakeVisible (slider24 = new Slider ("new slider"));
    slider24->setRange (0, 10, 0);
    slider24->setSliderStyle (Slider::RotaryVerticalDrag);
    slider24->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider24->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider24->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider24->addListener (this);

    addAndMakeVisible (label25 = new Label ("new label",
                                            TRANS("Cutoff")));
    label25->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label25->setJustificationType (Justification::centred);
    label25->setEditable (false, false, false);
    label25->setColour (TextEditor::textColourId, Colours::black);
    label25->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label26 = new Label ("new label",
                                            TRANS("KeyTrk")));
    label26->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label26->setJustificationType (Justification::centred);
    label26->setEditable (false, false, false);
    label26->setColour (TextEditor::textColourId, Colours::black);
    label26->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label27 = new Label ("new label",
                                            TRANS("Env")));
    label27->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label27->setJustificationType (Justification::centred);
    label27->setEditable (false, false, false);
    label27->setColour (TextEditor::textColourId, Colours::black);
    label27->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label28 = new Label ("new label",
                                            TRANS("Res")));
    label28->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label28->setJustificationType (Justification::centred);
    label28->setEditable (false, false, false);
    label28->setColour (TextEditor::textColourId, Colours::black);
    label28->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label29 = new Label ("new label",
                                            TRANS("Type")));
    label29->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label29->setJustificationType (Justification::centred);
    label29->setEditable (false, false, false);
    label29->setColour (TextEditor::textColourId, Colours::black);
    label29->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label30 = new Label ("new label",
                                            TRANS("Vel")));
    label30->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label30->setJustificationType (Justification::centred);
    label30->setEditable (false, false, false);
    label30->setColour (TextEditor::textColourId, Colours::black);
    label30->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (slider28 = new Slider ("new slider"));
    slider28->setRange (0, 10, 0);
    slider28->setSliderStyle (Slider::RotaryVerticalDrag);
    slider28->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider28->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider28->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider28->addListener (this);

    addAndMakeVisible (groupComponent3 = new GroupComponent ("new group",
                                                             TRANS("Filter1")));

    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (TRANS("Low24dB"));
    comboBox->setTextWhenNoChoicesAvailable (TRANS("Low12dB, High12dB, High24dB"));
    comboBox->addListener (this);

    addAndMakeVisible (slider25 = new Slider ("new slider"));
    slider25->setRange (0, 10, 0);
    slider25->setSliderStyle (Slider::RotaryVerticalDrag);
    slider25->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider25->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider25->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider25->addListener (this);

    addAndMakeVisible (slider26 = new Slider ("new slider"));
    slider26->setRange (0, 10, 0);
    slider26->setSliderStyle (Slider::RotaryVerticalDrag);
    slider26->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider26->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider26->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider26->addListener (this);

    addAndMakeVisible (slider27 = new Slider ("new slider"));
    slider27->setRange (0, 10, 0);
    slider27->setSliderStyle (Slider::RotaryVerticalDrag);
    slider27->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider27->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider27->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider27->addListener (this);

    addAndMakeVisible (slider29 = new Slider ("new slider"));
    slider29->setRange (0, 10, 0);
    slider29->setSliderStyle (Slider::RotaryVerticalDrag);
    slider29->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider29->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider29->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider29->addListener (this);

    addAndMakeVisible (label31 = new Label ("new label",
                                            TRANS("Attack")));
    label31->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label31->setJustificationType (Justification::centred);
    label31->setEditable (false, false, false);
    label31->setColour (TextEditor::textColourId, Colours::black);
    label31->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label32 = new Label ("new label",
                                            TRANS("Pan")));
    label32->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label32->setJustificationType (Justification::centred);
    label32->setEditable (false, false, false);
    label32->setColour (TextEditor::textColourId, Colours::black);
    label32->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label33 = new Label ("new label",
                                            TRANS("Phase")));
    label33->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label33->setJustificationType (Justification::centred);
    label33->setEditable (false, false, false);
    label33->setColour (TextEditor::textColourId, Colours::black);
    label33->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label34 = new Label ("new label",
                                            TRANS("Decay")));
    label34->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label34->setJustificationType (Justification::centred);
    label34->setEditable (false, false, false);
    label34->setColour (TextEditor::textColourId, Colours::black);
    label34->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label35 = new Label ("new label",
                                            TRANS("Sustain")));
    label35->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label35->setJustificationType (Justification::centred);
    label35->setEditable (false, false, false);
    label35->setColour (TextEditor::textColourId, Colours::black);
    label35->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label36 = new Label ("new label",
                                            TRANS("Fine")));
    label36->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label36->setJustificationType (Justification::centred);
    label36->setEditable (false, false, false);
    label36->setColour (TextEditor::textColourId, Colours::black);
    label36->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label37 = new Label ("new label",
                                            TRANS("Fixed")));
    label37->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label37->setJustificationType (Justification::centred);
    label37->setEditable (false, false, false);
    label37->setColour (TextEditor::textColourId, Colours::black);
    label37->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label38 = new Label ("new label",
                                            TRANS("Release")));
    label38->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label38->setJustificationType (Justification::centred);
    label38->setEditable (false, false, false);
    label38->setColour (TextEditor::textColourId, Colours::black);
    label38->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label39 = new Label ("new label",
                                            TRANS("Spread")));
    label39->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label39->setJustificationType (Justification::centred);
    label39->setEditable (false, false, false);
    label39->setColour (TextEditor::textColourId, Colours::black);
    label39->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label40 = new Label ("new label",
                                            TRANS("PW")));
    label40->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label40->setJustificationType (Justification::centred);
    label40->setEditable (false, false, false);
    label40->setColour (TextEditor::textColourId, Colours::black);
    label40->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label41 = new Label ("new label",
                                            TRANS("Detune")));
    label41->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label41->setJustificationType (Justification::centred);
    label41->setEditable (false, false, false);
    label41->setColour (TextEditor::textColourId, Colours::black);
    label41->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label42 = new Label ("new label",
                                            TRANS("Retrig")));
    label42->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label42->setJustificationType (Justification::centred);
    label42->setEditable (false, false, false);
    label42->setColour (TextEditor::textColourId, Colours::black);
    label42->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (toggleButton5 = new ToggleButton ("new toggle button"));
    toggleButton5->setButtonText (String());
    toggleButton5->addListener (this);

    addAndMakeVisible (toggleButton6 = new ToggleButton ("new toggle button"));
    toggleButton6->setButtonText (String());
    toggleButton6->addListener (this);

    addAndMakeVisible (slider30 = new Slider ("new slider"));
    slider30->setRange (0, 10, 0);
    slider30->setSliderStyle (Slider::RotaryVerticalDrag);
    slider30->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider30->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider30->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider30->addListener (this);

    addAndMakeVisible (slider31 = new Slider ("new slider"));
    slider31->setRange (0, 10, 0);
    slider31->setSliderStyle (Slider::RotaryVerticalDrag);
    slider31->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider31->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider31->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider31->addListener (this);

    addAndMakeVisible (slider32 = new Slider ("new slider"));
    slider32->setRange (0, 10, 0);
    slider32->setSliderStyle (Slider::RotaryVerticalDrag);
    slider32->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider32->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider32->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider32->addListener (this);

    addAndMakeVisible (slider33 = new Slider ("new slider"));
    slider33->setRange (0, 10, 0);
    slider33->setSliderStyle (Slider::RotaryVerticalDrag);
    slider33->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider33->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider33->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider33->addListener (this);

    addAndMakeVisible (slider34 = new Slider ("new slider"));
    slider34->setRange (0, 10, 0);
    slider34->setSliderStyle (Slider::RotaryVerticalDrag);
    slider34->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider34->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider34->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider34->addListener (this);

    addAndMakeVisible (slider35 = new Slider ("new slider"));
    slider35->setRange (0, 10, 0);
    slider35->setSliderStyle (Slider::RotaryVerticalDrag);
    slider35->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider35->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider35->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider35->addListener (this);

    addAndMakeVisible (groupComponent4 = new GroupComponent ("new group",
                                                             TRANS("Envelope1")));

    addAndMakeVisible (slider2 = new Slider ("new slider"));
    slider2->setRange (0, 10, 0);
    slider2->setSliderStyle (Slider::RotaryVerticalDrag);
    slider2->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider2->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider2->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider2->addListener (this);

    addAndMakeVisible (slider3 = new Slider ("new slider"));
    slider3->setRange (0, 10, 0);
    slider3->setSliderStyle (Slider::RotaryVerticalDrag);
    slider3->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider3->setColour (Slider::trackColourId, Colour (0xff5e6e75));
    slider3->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider3->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider3->addListener (this);

    addAndMakeVisible (slider4 = new Slider ("new slider"));
    slider4->setRange (0, 10, 0);
    slider4->setSliderStyle (Slider::RotaryVerticalDrag);
    slider4->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider4->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider4->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider4->addListener (this);

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("wave")));
    label2->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centred);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("Rate")));
    label3->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centred);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label5 = new Label ("new label",
                                           TRANS("Offset")));
    label5->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label5->setJustificationType (Justification::centred);
    label5->setEditable (false, false, false);
    label5->setColour (TextEditor::textColourId, Colours::black);
    label5->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (groupComponent6 = new GroupComponent ("new group",
                                                             TRANS("LFO")));

    addAndMakeVisible (label8 = new Label ("new label",
                                           TRANS("free")));
    label8->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label8->setJustificationType (Justification::centred);
    label8->setEditable (false, false, false);
    label8->setColour (TextEditor::textColourId, Colours::black);
    label8->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (toggleButton2 = new ToggleButton ("new toggle button"));
    toggleButton2->setButtonText (String());
    toggleButton2->addListener (this);

    addAndMakeVisible (groupComponent5 = new GroupComponent ("new group",
                                                             TRANS("ModMatrix")));

    addAndMakeVisible (viewport = new Viewport ("new viewport"));
    viewport->setScrollBarThickness (18);

    addAndMakeVisible (comboBox2 = new ComboBox ("new combo box"));
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (String());
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox2->addListener (this);

    addAndMakeVisible (comboBox3 = new ComboBox ("new combo box"));
    comboBox3->setEditableText (false);
    comboBox3->setJustificationType (Justification::centredLeft);
    comboBox3->setTextWhenNothingSelected (String());
    comboBox3->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox3->addListener (this);

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("Sources")));
    label4->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centred);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label6 = new Label ("new label",
                                           TRANS("Targets")));
    label6->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label6->setJustificationType (Justification::centred);
    label6->setEditable (false, false, false);
    label6->setColour (TextEditor::textColourId, Colours::black);
    label6->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (slider5 = new Slider ("new slider"));
    slider5->setRange (0, 10, 0);
    slider5->setSliderStyle (Slider::RotaryVerticalDrag);
    slider5->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider5->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider5->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider5->addListener (this);

    addAndMakeVisible (label7 = new Label ("new label",
                                           TRANS("ModAmount")));
    label7->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label7->setJustificationType (Justification::centred);
    label7->setEditable (false, false, false);
    label7->setColour (TextEditor::textColourId, Colours::black);
    label7->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (toggleButton3 = new ToggleButton ("new toggle button"));
    toggleButton3->setButtonText (String());
    toggleButton3->addListener (this);

    addAndMakeVisible (groupComponent7 = new GroupComponent ("new group",
                                                             TRANS("Envelope1")));

    addAndMakeVisible (slider6 = new Slider ("new slider"));
    slider6->setRange (0, 10, 0);
    slider6->setSliderStyle (Slider::RotaryVerticalDrag);
    slider6->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider6->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider6->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider6->addListener (this);

    addAndMakeVisible (slider7 = new Slider ("new slider"));
    slider7->setRange (0, 10, 0);
    slider7->setSliderStyle (Slider::RotaryVerticalDrag);
    slider7->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider7->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider7->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider7->addListener (this);

    addAndMakeVisible (label9 = new Label ("new label",
                                           TRANS("Attack")));
    label9->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label9->setJustificationType (Justification::centred);
    label9->setEditable (false, false, false);
    label9->setColour (TextEditor::textColourId, Colours::black);
    label9->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label12 = new Label ("new label",
                                            TRANS("Decay")));
    label12->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label12->setJustificationType (Justification::centred);
    label12->setEditable (false, false, false);
    label12->setColour (TextEditor::textColourId, Colours::black);
    label12->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label13 = new Label ("new label",
                                            TRANS("Sustain")));
    label13->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label13->setJustificationType (Justification::centred);
    label13->setEditable (false, false, false);
    label13->setColour (TextEditor::textColourId, Colours::black);
    label13->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label16 = new Label ("new label",
                                            TRANS("Release")));
    label16->setFont (Font (12.00f, Font::plain).withTypefaceStyle ("Regular"));
    label16->setJustificationType (Justification::centred);
    label16->setEditable (false, false, false);
    label16->setColour (TextEditor::textColourId, Colours::black);
    label16->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (slider10 = new Slider ("new slider"));
    slider10->setRange (0, 10, 0);
    slider10->setSliderStyle (Slider::RotaryVerticalDrag);
    slider10->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider10->setColour (Slider::trackColourId, Colour (0xff338eb5));
    slider10->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider10->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider10->addListener (this);

    addAndMakeVisible (slider11 = new Slider ("new slider"));
    slider11->setRange (0, 10, 0);
    slider11->setSliderStyle (Slider::RotaryVerticalDrag);
    slider11->setTextBoxStyle (Slider::NoTextBox, true, 60, 12);
    slider11->setColour (Slider::textBoxHighlightColourId, Colour (0xa41111ee));
    slider11->setColour (Slider::textBoxOutlineColourId, Colour (0xb2b92828));
    slider11->addListener (this);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (600, 400);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SliderComponent::~SliderComponent()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    tabbedComponent = nullptr;
    hyperlinkButton = nullptr;
    groupComponent2 = nullptr;
    slider21 = nullptr;
    slider22 = nullptr;
    slider23 = nullptr;
    slider24 = nullptr;
    label25 = nullptr;
    label26 = nullptr;
    label27 = nullptr;
    label28 = nullptr;
    label29 = nullptr;
    label30 = nullptr;
    slider28 = nullptr;
    groupComponent3 = nullptr;
    comboBox = nullptr;
    slider25 = nullptr;
    slider26 = nullptr;
    slider27 = nullptr;
    slider29 = nullptr;
    label31 = nullptr;
    label32 = nullptr;
    label33 = nullptr;
    label34 = nullptr;
    label35 = nullptr;
    label36 = nullptr;
    label37 = nullptr;
    label38 = nullptr;
    label39 = nullptr;
    label40 = nullptr;
    label41 = nullptr;
    label42 = nullptr;
    toggleButton5 = nullptr;
    toggleButton6 = nullptr;
    slider30 = nullptr;
    slider31 = nullptr;
    slider32 = nullptr;
    slider33 = nullptr;
    slider34 = nullptr;
    slider35 = nullptr;
    groupComponent4 = nullptr;
    slider2 = nullptr;
    slider3 = nullptr;
    slider4 = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label5 = nullptr;
    groupComponent6 = nullptr;
    label8 = nullptr;
    toggleButton2 = nullptr;
    groupComponent5 = nullptr;
    viewport = nullptr;
    comboBox2 = nullptr;
    comboBox3 = nullptr;
    label4 = nullptr;
    label6 = nullptr;
    slider5 = nullptr;
    label7 = nullptr;
    toggleButton3 = nullptr;
    groupComponent7 = nullptr;
    slider6 = nullptr;
    slider7 = nullptr;
    label9 = nullptr;
    label12 = nullptr;
    label13 = nullptr;
    label16 = nullptr;
    slider10 = nullptr;
    slider11 = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SliderComponent::paint (Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (Colours::white);

    {
        float x = 0, y = 0;
        Colour fillColour = Colour (0xff2aa4a5);
        //[UserPaintCustomArguments] Customize the painting arguments here..
        //[/UserPaintCustomArguments]
        g.setColour (fillColour);
        g.fillPath (internalPath1, AffineTransform::translation(x, y));
    }

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SliderComponent::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    tabbedComponent->setBounds (656, 72, 200, 150);
    hyperlinkButton->setBounds (96, 352, 150, 24);
    groupComponent2->setBounds (72, 432, 200, 140);
    slider21->setBounds (80, 602, 30, 30);
    slider22->setBounds (120, 602, 30, 30);
    slider23->setBounds (80, 645, 30, 30);
    slider24->setBounds (120, 645, 30, 30);
    label25->setBounds (75, 589, 40, 12);
    label26->setBounds (75, 633, 40, 12);
    label27->setBounds (115, 633, 40, 12);
    label28->setBounds (115, 589, 40, 12);
    label29->setBounds (155, 589, 40, 12);
    label30->setBounds (155, 633, 40, 12);
    slider28->setBounds (160, 645, 30, 30);
    groupComponent3->setBounds (72, 576, 168, 104);
    comboBox->setBounds (160, 609, 70, 16);
    slider25->setBounds (77, 457, 30, 30);
    slider26->setBounds (117, 457, 30, 30);
    slider27->setBounds (77, 501, 30, 30);
    slider29->setBounds (117, 501, 30, 30);
    label31->setBounds (72, 445, 40, 12);
    label32->setBounds (72, 489, 40, 12);
    label33->setBounds (112, 489, 40, 12);
    label34->setBounds (112, 445, 40, 12);
    label35->setBounds (152, 445, 40, 12);
    label36->setBounds (152, 489, 40, 12);
    label37->setBounds (152, 533, 40, 12);
    label38->setBounds (192, 445, 40, 12);
    label39->setBounds (232, 489, 40, 12);
    label40->setBounds (192, 489, 40, 12);
    label41->setBounds (232, 445, 40, 12);
    label42->setBounds (112, 533, 40, 12);
    toggleButton5->setBounds (122, 544, 20, 20);
    toggleButton6->setBounds (162, 544, 20, 20);
    slider30->setBounds (157, 457, 30, 30);
    slider31->setBounds (197, 457, 30, 30);
    slider32->setBounds (237, 457, 30, 30);
    slider33->setBounds (157, 501, 30, 30);
    slider34->setBounds (197, 501, 30, 30);
    slider35->setBounds (237, 501, 30, 30);
    groupComponent4->setBounds (296, 192, 200, 140);
    slider2->setBounds (69, 140, 30, 30);
    slider3->setBounds (64, 288, 64, 54);
    slider4->setBounds (69, 183, 30, 30);
    label2->setBounds (64, 127, 40, 12);
    label3->setBounds (64, 171, 40, 12);
    label5->setBounds (104, 127, 40, 12);
    groupComponent6->setBounds (200, 112, 96, 96);
    label8->setBounds (104, 176, 40, 12);
    toggleButton2->setBounds (114, 188, 20, 20);
    groupComponent5->setBounds (304, 416, 296, 240);
    viewport->setBounds (488, 128, 168, 208);
    comboBox2->setBounds (312, 456, 104, 16);
    comboBox3->setBounds (424, 456, 104, 16);
    label4->setBounds (336, 432, 40, 12);
    label6->setBounds (456, 432, 40, 12);
    slider5->setBounds (560, 448, 30, 30);
    label7->setBounds (536, 432, 56, 12);
    toggleButton3->setBounds (536, 456, 20, 20);
    groupComponent7->setBounds (-2, 2, 162, 64);
    slider6->setBounds (3, 32, 30, 30);
    slider7->setBounds (43, 32, 30, 30);
    label9->setBounds (-2, 20, 40, 12);
    label12->setBounds (38, 20, 40, 12);
    label13->setBounds (78, 20, 40, 12);
    label16->setBounds (118, 20, 40, 12);
    slider10->setBounds (83, 32, 30, 30);
    slider11->setBounds (123, 32, 30, 30);
    internalPath1.clear();
    internalPath1.startNewSubPath (280.0f, 312.0f);
    internalPath1.lineTo (344.0f, 216.0f);
    internalPath1.lineTo (512.0f, 264.0f);
    internalPath1.lineTo (888.0f, 312.0f);
    internalPath1.closeSubPath();

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SliderComponent::sliderValueChanged (Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == slider21)
    {
        //[UserSliderCode_slider21] -- add your slider handling code here..
        //[/UserSliderCode_slider21]
    }
    else if (sliderThatWasMoved == slider22)
    {
        //[UserSliderCode_slider22] -- add your slider handling code here..
        //[/UserSliderCode_slider22]
    }
    else if (sliderThatWasMoved == slider23)
    {
        //[UserSliderCode_slider23] -- add your slider handling code here..
        //[/UserSliderCode_slider23]
    }
    else if (sliderThatWasMoved == slider24)
    {
        //[UserSliderCode_slider24] -- add your slider handling code here..
        //[/UserSliderCode_slider24]
    }
    else if (sliderThatWasMoved == slider28)
    {
        //[UserSliderCode_slider28] -- add your slider handling code here..
        //[/UserSliderCode_slider28]
    }
    else if (sliderThatWasMoved == slider25)
    {
        //[UserSliderCode_slider25] -- add your slider handling code here..
        //[/UserSliderCode_slider25]
    }
    else if (sliderThatWasMoved == slider26)
    {
        //[UserSliderCode_slider26] -- add your slider handling code here..
        //[/UserSliderCode_slider26]
    }
    else if (sliderThatWasMoved == slider27)
    {
        //[UserSliderCode_slider27] -- add your slider handling code here..
        //[/UserSliderCode_slider27]
    }
    else if (sliderThatWasMoved == slider29)
    {
        //[UserSliderCode_slider29] -- add your slider handling code here..
        //[/UserSliderCode_slider29]
    }
    else if (sliderThatWasMoved == slider30)
    {
        //[UserSliderCode_slider30] -- add your slider handling code here..
        //[/UserSliderCode_slider30]
    }
    else if (sliderThatWasMoved == slider31)
    {
        //[UserSliderCode_slider31] -- add your slider handling code here..
        //[/UserSliderCode_slider31]
    }
    else if (sliderThatWasMoved == slider32)
    {
        //[UserSliderCode_slider32] -- add your slider handling code here..
        //[/UserSliderCode_slider32]
    }
    else if (sliderThatWasMoved == slider33)
    {
        //[UserSliderCode_slider33] -- add your slider handling code here..
        //[/UserSliderCode_slider33]
    }
    else if (sliderThatWasMoved == slider34)
    {
        //[UserSliderCode_slider34] -- add your slider handling code here..
        //[/UserSliderCode_slider34]
    }
    else if (sliderThatWasMoved == slider35)
    {
        //[UserSliderCode_slider35] -- add your slider handling code here..
        //[/UserSliderCode_slider35]
    }
    else if (sliderThatWasMoved == slider2)
    {
        //[UserSliderCode_slider2] -- add your slider handling code here..
        //[/UserSliderCode_slider2]
    }
    else if (sliderThatWasMoved == slider3)
    {
        //[UserSliderCode_slider3] -- add your slider handling code here..
        //[/UserSliderCode_slider3]
    }
    else if (sliderThatWasMoved == slider4)
    {
        //[UserSliderCode_slider4] -- add your slider handling code here..
        //[/UserSliderCode_slider4]
    }
    else if (sliderThatWasMoved == slider5)
    {
        //[UserSliderCode_slider5] -- add your slider handling code here..
        //[/UserSliderCode_slider5]
    }
    else if (sliderThatWasMoved == slider6)
    {
        //[UserSliderCode_slider6] -- add your slider handling code here..
        //[/UserSliderCode_slider6]
    }
    else if (sliderThatWasMoved == slider7)
    {
        //[UserSliderCode_slider7] -- add your slider handling code here..
        //[/UserSliderCode_slider7]
    }
    else if (sliderThatWasMoved == slider10)
    {
        //[UserSliderCode_slider10] -- add your slider handling code here..
        //[/UserSliderCode_slider10]
    }
    else if (sliderThatWasMoved == slider11)
    {
        //[UserSliderCode_slider11] -- add your slider handling code here..
        //[/UserSliderCode_slider11]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SliderComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    //[UsercomboBoxChanged_Pre]
    //[/UsercomboBoxChanged_Pre]

    if (comboBoxThatHasChanged == comboBox)
    {
        //[UserComboBoxCode_comboBox] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox]
    }
    else if (comboBoxThatHasChanged == comboBox2)
    {
        //[UserComboBoxCode_comboBox2] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox2]
    }
    else if (comboBoxThatHasChanged == comboBox3)
    {
        //[UserComboBoxCode_comboBox3] -- add your combo box handling code here..
        //[/UserComboBoxCode_comboBox3]
    }

    //[UsercomboBoxChanged_Post]
    //[/UsercomboBoxChanged_Post]
}

void SliderComponent::buttonClicked (Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == toggleButton5)
    {
        //[UserButtonCode_toggleButton5] -- add your button handler code here..
        //[/UserButtonCode_toggleButton5]
    }
    else if (buttonThatWasClicked == toggleButton6)
    {
        //[UserButtonCode_toggleButton6] -- add your button handler code here..
        //[/UserButtonCode_toggleButton6]
    }
    else if (buttonThatWasClicked == toggleButton2)
    {
        //[UserButtonCode_toggleButton2] -- add your button handler code here..
        //[/UserButtonCode_toggleButton2]
    }
    else if (buttonThatWasClicked == toggleButton3)
    {
        //[UserButtonCode_toggleButton3] -- add your button handler code here..
        //[/UserButtonCode_toggleButton3]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SliderComponent" componentName=""
                 parentClasses="public Component" constructorParams="" variableInitialisers=""
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="600" initialHeight="400">
  <BACKGROUND backgroundColour="ffffffff">
    <PATH pos="0 0 100 100" fill="solid: ff2aa4a5" hasStroke="0" nonZeroWinding="1">s 280 312 l 344 216 l 512 264 l 888 312 x</PATH>
  </BACKGROUND>
  <TABBEDCOMPONENT name="new tabbed component" id="73c8a87a06cb69b9" memberName="tabbedComponent"
                   virtualName="" explicitFocusOrder="0" pos="656 72 200 150" orientation="top"
                   tabBarDepth="30" initialTab="0">
    <TAB name="Tab 0" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Tab 1" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
    <TAB name="Tab 2" colour="ffd3d3d3" useJucerComp="0" contentClassName=""
         constructorParams="" jucerComponentFile=""/>
  </TABBEDCOMPONENT>
  <HYPERLINKBUTTON name="new hyperlink" id="d946e1cc11b753b4" memberName="hyperlinkButton"
                   virtualName="" explicitFocusOrder="0" pos="96 352 150 24" tooltip="http://www.juce.com"
                   buttonText="new hyperlink" connectedEdges="0" needsCallback="0"
                   radioGroupId="0" url="http://www.juce.com"/>
  <GROUPCOMPONENT name="new group" id="5c527b3c1ef70e22" memberName="groupComponent2"
                  virtualName="" explicitFocusOrder="0" pos="72 432 200 140" title="Oscillator1"/>
  <SLIDER name="new slider" id="fc10bc31c233c07" memberName="slider21"
          virtualName="" explicitFocusOrder="0" pos="80 602 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="72b1a49153b15ea1" memberName="slider22"
          virtualName="" explicitFocusOrder="0" pos="120 602 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="81cc2a8eaa9a403b" memberName="slider23"
          virtualName="" explicitFocusOrder="0" pos="80 645 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="6e677fe847119071" memberName="slider24"
          virtualName="" explicitFocusOrder="0" pos="120 645 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="511eda47fd0b5b18" memberName="label25" virtualName=""
         explicitFocusOrder="0" pos="75 589 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Cutoff" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="89ce106dee5d3ec5" memberName="label26" virtualName=""
         explicitFocusOrder="0" pos="75 633 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="KeyTrk" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8a15ed1eb1b01d8" memberName="label27" virtualName=""
         explicitFocusOrder="0" pos="115 633 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Env" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bba782a2c35e47c3" memberName="label28" virtualName=""
         explicitFocusOrder="0" pos="115 589 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Res" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="31188f9a53a0645b" memberName="label29" virtualName=""
         explicitFocusOrder="0" pos="155 589 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Type" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="5dea0c79a98f8174" memberName="label30" virtualName=""
         explicitFocusOrder="0" pos="155 633 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Vel" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="523cf10b03a650eb" memberName="slider28"
          virtualName="" explicitFocusOrder="0" pos="160 645 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <GROUPCOMPONENT name="new group" id="178aa3edd85edb44" memberName="groupComponent3"
                  virtualName="" explicitFocusOrder="0" pos="72 576 168 104" title="Filter1"/>
  <COMBOBOX name="new combo box" id="7b499a20f8f97f4a" memberName="comboBox"
            virtualName="" explicitFocusOrder="0" pos="160 609 70 16" editable="0"
            layout="33" items="" textWhenNonSelected="Low24dB" textWhenNoItems="Low12dB, High12dB, High24dB"/>
  <SLIDER name="new slider" id="57fb5a05e85412bf" memberName="slider25"
          virtualName="" explicitFocusOrder="0" pos="77 457 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="181a729a6d23aaff" memberName="slider26"
          virtualName="" explicitFocusOrder="0" pos="117 457 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="f2cd3713e7e6ac1e" memberName="slider27"
          virtualName="" explicitFocusOrder="0" pos="77 501 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="daf245f09beb289" memberName="slider29"
          virtualName="" explicitFocusOrder="0" pos="117 501 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="a9e44697382ce8c4" memberName="label31" virtualName=""
         explicitFocusOrder="0" pos="72 445 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="20188252938ffb50" memberName="label32" virtualName=""
         explicitFocusOrder="0" pos="72 489 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Pan" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="cc8de1c57420729a" memberName="label33" virtualName=""
         explicitFocusOrder="0" pos="112 489 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Phase" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="69d99ca293a0c3af" memberName="label34" virtualName=""
         explicitFocusOrder="0" pos="112 445 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="bdf6efd41fc709b2" memberName="label35" virtualName=""
         explicitFocusOrder="0" pos="152 445 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="8f0b028bf244fd72" memberName="label36" virtualName=""
         explicitFocusOrder="0" pos="152 489 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Fine" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="39ac182971043598" memberName="label37" virtualName=""
         explicitFocusOrder="0" pos="152 533 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Fixed" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="f564bb1f158a513f" memberName="label38" virtualName=""
         explicitFocusOrder="0" pos="192 445 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="cce872b5fcc437ee" memberName="label39" virtualName=""
         explicitFocusOrder="0" pos="232 489 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Spread" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="de886499ccf6554" memberName="label40" virtualName=""
         explicitFocusOrder="0" pos="192 489 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="PW" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="e5745a9aa44b1437" memberName="label41" virtualName=""
         explicitFocusOrder="0" pos="232 445 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Detune" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="7000aa0ecbfc5b72" memberName="label42" virtualName=""
         explicitFocusOrder="0" pos="112 533 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Retrig" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="eecc47148fcbc0f2" memberName="toggleButton5"
                virtualName="" explicitFocusOrder="0" pos="122 544 20 20" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <TOGGLEBUTTON name="new toggle button" id="f867d016b2f0ba18" memberName="toggleButton6"
                virtualName="" explicitFocusOrder="0" pos="162 544 20 20" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <SLIDER name="new slider" id="ef61ce96a918d5eb" memberName="slider30"
          virtualName="" explicitFocusOrder="0" pos="157 457 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="5072b76bd64a34f4" memberName="slider31"
          virtualName="" explicitFocusOrder="0" pos="197 457 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="6047383354814bcc" memberName="slider32"
          virtualName="" explicitFocusOrder="0" pos="237 457 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="ec9cbe7f88eb0896" memberName="slider33"
          virtualName="" explicitFocusOrder="0" pos="157 501 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="a3b83f3f5c0120fa" memberName="slider34"
          virtualName="" explicitFocusOrder="0" pos="197 501 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="afc4897328dddd66" memberName="slider35"
          virtualName="" explicitFocusOrder="0" pos="237 501 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <GROUPCOMPONENT name="new group" id="80f8ed367b16f79e" memberName="groupComponent4"
                  virtualName="" explicitFocusOrder="0" pos="296 192 200 140" title="Envelope1"/>
  <SLIDER name="new slider" id="ef6614ded8aa67bb" memberName="slider2"
          virtualName="" explicitFocusOrder="0" pos="69 140 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="4a35b4c550640ca4" memberName="slider3"
          virtualName="" explicitFocusOrder="0" pos="64 288 64 54" trackcol="ff5e6e75"
          textboxhighlight="a41111ee" textboxoutline="b2b92828" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="12" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="5d46a958bd047fe8" memberName="slider4"
          virtualName="" explicitFocusOrder="0" pos="69 183 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="24894c70e70dc0a9" memberName="label2" virtualName=""
         explicitFocusOrder="0" pos="64 127 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="wave" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="4e7fc1b39dc324d0" memberName="label3" virtualName=""
         explicitFocusOrder="0" pos="64 171 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Rate" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="727bbd7602430254" memberName="label5" virtualName=""
         explicitFocusOrder="0" pos="104 127 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Offset" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <GROUPCOMPONENT name="new group" id="97ff342ba044cef7" memberName="groupComponent6"
                  virtualName="" explicitFocusOrder="0" pos="200 112 96 96" title="LFO"/>
  <LABEL name="new label" id="7d724f6d75fcc543" memberName="label8" virtualName=""
         explicitFocusOrder="0" pos="104 176 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="free" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="85f390a6e82be965" memberName="toggleButton2"
                virtualName="" explicitFocusOrder="0" pos="114 188 20 20" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <GROUPCOMPONENT name="new group" id="e8074e683dd568a7" memberName="groupComponent5"
                  virtualName="" explicitFocusOrder="0" pos="304 416 296 240" title="ModMatrix"/>
  <VIEWPORT name="new viewport" id="f866baec512d9fdb" memberName="viewport"
            virtualName="" explicitFocusOrder="0" pos="488 128 168 208" vscroll="1"
            hscroll="1" scrollbarThickness="18" contentType="0" jucerFile=""
            contentClass="" constructorParams=""/>
  <COMBOBOX name="new combo box" id="d4dc4445d08bf6ce" memberName="comboBox2"
            virtualName="" explicitFocusOrder="0" pos="312 456 104 16" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <COMBOBOX name="new combo box" id="ee259f4b1481ebd1" memberName="comboBox3"
            virtualName="" explicitFocusOrder="0" pos="424 456 104 16" editable="0"
            layout="33" items="" textWhenNonSelected="" textWhenNoItems="(no choices)"/>
  <LABEL name="new label" id="204aeef33f6fc8a7" memberName="label4" virtualName=""
         explicitFocusOrder="0" pos="336 432 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Sources" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="3c228603a4552b01" memberName="label6" virtualName=""
         explicitFocusOrder="0" pos="456 432 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Targets" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="4ba2fb7ad0c61e75" memberName="slider5"
          virtualName="" explicitFocusOrder="0" pos="560 448 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="2e7d4a6eea9d3623" memberName="label7" virtualName=""
         explicitFocusOrder="0" pos="536 432 56 12" edTextCol="ff000000"
         edBkgCol="0" labelText="ModAmount" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <TOGGLEBUTTON name="new toggle button" id="40f324abac97019" memberName="toggleButton3"
                virtualName="" explicitFocusOrder="0" pos="536 456 20 20" buttonText=""
                connectedEdges="0" needsCallback="1" radioGroupId="0" state="0"/>
  <GROUPCOMPONENT name="new group" id="3980ff0b69859c77" memberName="groupComponent7"
                  virtualName="" explicitFocusOrder="0" pos="-2 2 162 64" title="Envelope1"/>
  <SLIDER name="new slider" id="dbe83d41d5a7d050" memberName="slider6"
          virtualName="" explicitFocusOrder="0" pos="3 32 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <SLIDER name="new slider" id="9903444c3b5c1847" memberName="slider7"
          virtualName="" explicitFocusOrder="0" pos="43 32 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
  <LABEL name="new label" id="37b181109736cb3f" memberName="label9" virtualName=""
         explicitFocusOrder="0" pos="-2 20 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Attack" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="31a07baf67146bef" memberName="label12" virtualName=""
         explicitFocusOrder="0" pos="38 20 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Decay" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="1e98a5f3df831c2c" memberName="label13" virtualName=""
         explicitFocusOrder="0" pos="78 20 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Sustain" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <LABEL name="new label" id="97a9dfd0d947ec" memberName="label16" virtualName=""
         explicitFocusOrder="0" pos="118 20 40 12" edTextCol="ff000000"
         edBkgCol="0" labelText="Release" editableSingleClick="0" editableDoubleClick="0"
         focusDiscardsChanges="0" fontname="Default font" fontsize="12"
         kerning="0" bold="0" italic="0" justification="36"/>
  <SLIDER name="new slider" id="b12334d26160270d" memberName="slider10"
          virtualName="" explicitFocusOrder="0" pos="83 32 30 30" trackcol="ff338eb5"
          textboxhighlight="a41111ee" textboxoutline="b2b92828" min="0"
          max="10" int="0" style="RotaryVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="60" textBoxHeight="12" skewFactor="1"
          needsCallback="1"/>
  <SLIDER name="new slider" id="785fa77b076f9bff" memberName="slider11"
          virtualName="" explicitFocusOrder="0" pos="123 32 30 30" textboxhighlight="a41111ee"
          textboxoutline="b2b92828" min="0" max="10" int="0" style="RotaryVerticalDrag"
          textBoxPos="NoTextBox" textBoxEditable="0" textBoxWidth="60"
          textBoxHeight="12" skewFactor="1" needsCallback="1"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]
