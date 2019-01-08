/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 5.4.1

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2017 - ROLI Ltd.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include "JuceHeader.h"
//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SliderComponent  : public Component,
                         public Slider::Listener,
                         public ComboBox::Listener,
                         public Button::Listener
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
    std::unique_ptr<TabbedComponent> tabbedComponent;
    std::unique_ptr<HyperlinkButton> hyperlinkButton;
    std::unique_ptr<GroupComponent> groupComponent2;
    std::unique_ptr<Slider> slider21;
    std::unique_ptr<Slider> slider22;
    std::unique_ptr<Slider> slider23;
    std::unique_ptr<Slider> slider24;
    std::unique_ptr<Label> label25;
    std::unique_ptr<Label> label26;
    std::unique_ptr<Label> label27;
    std::unique_ptr<Label> label28;
    std::unique_ptr<Label> label29;
    std::unique_ptr<Label> label30;
    std::unique_ptr<Slider> slider28;
    std::unique_ptr<GroupComponent> groupComponent3;
    std::unique_ptr<ComboBox> comboBox;
    std::unique_ptr<Slider> slider25;
    std::unique_ptr<Slider> slider26;
    std::unique_ptr<Slider> slider27;
    std::unique_ptr<Slider> slider29;
    std::unique_ptr<Label> label31;
    std::unique_ptr<Label> label32;
    std::unique_ptr<Label> label33;
    std::unique_ptr<Label> label34;
    std::unique_ptr<Label> label35;
    std::unique_ptr<Label> label36;
    std::unique_ptr<Label> label37;
    std::unique_ptr<Label> label38;
    std::unique_ptr<Label> label39;
    std::unique_ptr<Label> label40;
    std::unique_ptr<Label> label41;
    std::unique_ptr<Label> label42;
    std::unique_ptr<ToggleButton> toggleButton5;
    std::unique_ptr<ToggleButton> toggleButton6;
    std::unique_ptr<Slider> slider30;
    std::unique_ptr<Slider> slider31;
    std::unique_ptr<Slider> slider32;
    std::unique_ptr<Slider> slider33;
    std::unique_ptr<Slider> slider34;
    std::unique_ptr<Slider> slider35;
    std::unique_ptr<GroupComponent> groupComponent4;
    std::unique_ptr<Slider> slider2;
    std::unique_ptr<Slider> slider3;
    std::unique_ptr<Slider> slider4;
    std::unique_ptr<Label> label2;
    std::unique_ptr<Label> label3;
    std::unique_ptr<Label> label5;
    std::unique_ptr<GroupComponent> groupComponent6;
    std::unique_ptr<Label> label8;
    std::unique_ptr<ToggleButton> toggleButton2;
    std::unique_ptr<GroupComponent> groupComponent5;
    std::unique_ptr<Viewport> viewport;
    std::unique_ptr<ComboBox> comboBox2;
    std::unique_ptr<ComboBox> comboBox3;
    std::unique_ptr<Label> label4;
    std::unique_ptr<Label> label6;
    std::unique_ptr<Slider> slider5;
    std::unique_ptr<Label> label7;
    std::unique_ptr<ToggleButton> toggleButton3;
    std::unique_ptr<GroupComponent> groupComponent7;
    std::unique_ptr<Slider> slider6;
    std::unique_ptr<Slider> slider7;
    std::unique_ptr<Label> label9;
    std::unique_ptr<Label> label12;
    std::unique_ptr<Label> label13;
    std::unique_ptr<Label> label16;
    std::unique_ptr<Slider> slider10;
    std::unique_ptr<Slider> slider11;
    Path internalPath1;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SliderComponent)
};

//[EndFile] You can add extra defines here...
//[/EndFile]
