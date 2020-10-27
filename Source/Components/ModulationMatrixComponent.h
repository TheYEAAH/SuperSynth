
#pragma once
#include "../JuceLibraryCode/JuceHeader.h"



class ModulationMatrixComponent  : public Component,
                                   public ComboBox::Listener
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

    void resized() override;
    
    void comboBoxChanged (ComboBox* comboBoxThatHasChanged) override;

private:
    /*creates a Label with the given text and textValueSuffix.*/
    void createLabel(Label *label, const String &newText);
    void createLabel(Label &label, const String &newText);
    
    /*creates a ComboBox with the given text and textValueSuffix.*/
    void createComboBox(ComboBox *comboBox, const String &newTooltip);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID);
    
    /*creates a slider with the given text and textValueSuffix.*/
    void createSlider(Slider *slider, const String &newID, const String &suffix);
    
    Label labelSources;
    Label labelTargets;
    Label labelModAmount;
    
    /*Creates a modulation row.*/
    //void createModulationRow    
    ScopedPointer<Slider> modulationSlider;
    ScopedPointer<ToggleButton> toggleButton;
    ScopedPointer<ComboBox> sourcesComboBox;
    ScopedPointer<ComboBox> targetsComboBox;
    ScopedPointer<Label> labelTo;//label with "->" text

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (ModulationMatrixComponent)
};