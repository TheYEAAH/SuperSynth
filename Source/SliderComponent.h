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

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Introjucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SliderComponent  : public Component,
                         public SliderListener,
                         public ComboBoxListener,
                         public ButtonListener
{
public:
    //==============================================================================
    SliderComponent ();
    ~SliderComponent();

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (Graphics& g) override;
    void resized() override;
    void sliderValueChanged (Slider* sliderThatWasMoved) override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;
    void buttonClicked (Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    //[/UserVariables]

    //==============================================================================
    ScopedPointer<TabbedComponent> tabbedComponent;
    ScopedPointer<HyperlinkButton> hyperlinkButton;
    ScopedPointer<GroupComponent> groupComponent2;
    ScopedPointer<Slider> slider21;
    ScopedPointer<Slider> slider22;
    ScopedPointer<Slider> slider23;
    ScopedPointer<Slider> slider24;
    ScopedPointer<Label> label25;
    ScopedPointer<Label> label26;
    ScopedPointer<Label> label27;
    ScopedPointer<Label> label28;
    ScopedPointer<Label> label29;
    ScopedPointer<Label> label30;
    ScopedPointer<Slider> slider28;
    ScopedPointer<GroupComponent> groupComponent3;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<Slider> slider25;
    ScopedPointer<Slider> slider26;
    ScopedPointer<Slider> slider27;
    ScopedPointer<Slider> slider29;
    ScopedPointer<Label> label31;
    ScopedPointer<Label> label32;
    ScopedPointer<Label> label33;
    ScopedPointer<Label> label34;
    ScopedPointer<Label> label35;
    ScopedPointer<Label> label36;
    ScopedPointer<Label> label37;
    ScopedPointer<Label> label38;
    ScopedPointer<Label> label39;
    ScopedPointer<Label> label40;
    ScopedPointer<Label> label41;
    ScopedPointer<Label> label42;
    ScopedPointer<ToggleButton> toggleButton5;
    ScopedPointer<ToggleButton> toggleButton6;
    ScopedPointer<Slider> slider30;
    ScopedPointer<Slider> slider31;
    ScopedPointer<Slider> slider32;
    ScopedPointer<Slider> slider33;
    ScopedPointer<Slider> slider34;
    ScopedPointer<Slider> slider35;
    ScopedPointer<GroupComponent> groupComponent4;
    ScopedPointer<Slider> slider2;
    ScopedPointer<Slider> slider3;
    ScopedPointer<Slider> slider4;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label5;
    ScopedPointer<GroupComponent> groupComponent6;
    ScopedPointer<Label> label8;
    ScopedPointer<ToggleButton> toggleButton2;
    ScopedPointer<GroupComponent> groupComponent5;
    ScopedPointer<Viewport> viewport;
    ScopedPointer<ComboBox> comboBox2;
    ScopedPointer<ComboBox> comboBox3;
    ScopedPointer<Label> label4;
    ScopedPointer<Label> label6;
    ScopedPointer<Slider> slider5;
    ScopedPointer<Label> label7;
    ScopedPointer<ToggleButton> toggleButton3;
    ScopedPointer<GroupComponent> groupComponent7;
    ScopedPointer<Slider> slider6;
    ScopedPointer<Slider> slider7;
    ScopedPointer<Label> label9;
    ScopedPointer<Label> label12;
    ScopedPointer<Label> label13;
    ScopedPointer<Label> label16;
    ScopedPointer<Slider> slider10;
    ScopedPointer<Slider> slider11;
    Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
