
#pragma once

#include "../JuceLibraryCode/JuceHeader.h"



class ModulationMatrixComponent  : public Component,
                                   public ComboBoxListener
{
public:
    //==============================================================================
    ModulationMatrixComponent ();
    ~ModulationMatrixComponent();

 
    enum
    {
        rowHeight = 52,
        sourceColumnWidth  = 80,
        targetColumnWidth  = 80,
        paramSliderWidth   = 50,
        paramSliderHeight  = 50,
        comboBoxHeight     = 24,
        toggleButtonWidth  = 12,
        toLabelWidth       = 23//label with "->" text
    };

    void paint (Graphics& g) override;
    void resized() override;
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;



private:
    ScopedPointer<Slider> slider;
    ScopedPointer<ToggleButton> toggleButton;
    ScopedPointer<ComboBox> comboBox;
    ScopedPointer<ComboBox> comboBox2;
    ScopedPointer<Label> label;
    ScopedPointer<Label> label2;
    ScopedPointer<Label> label3;
    ScopedPointer<Label> label4;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulationMatrixComponent)
};