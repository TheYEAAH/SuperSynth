
#include "ModulationMatrixComponent.h"



ModulationMatrixComponent::ModulationMatrixComponent ()
{
    addAndMakeVisible (toggleButton = new ToggleButton ("toggleButton"));
    toggleButton->setButtonText (String());


    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 0, 0);

    //sourcesComboBox
    createComboBox(sourcesComboBox = new ComboBox ("new combo box"),"Select a source");
    sourcesComboBox->addItem (TRANS("Env 1"), 1);
    sourcesComboBox->addItem (TRANS("Env 2"), 2);
    sourcesComboBox->addItem (TRANS("LFO 1"), 3);
    sourcesComboBox->addItem (TRANS("LFO 2"), 4);
    
    //targetsComboBox
    createComboBox(targetsComboBox = new ComboBox ("new combo box"),"Select a target");
    targetsComboBox->addItem (TRANS("Filter1:cutoff"), 1);
    
    //Columns labels
    createLabel(labelSources = new Label ("new label", TRANS("Sources")), "Sources");
    createLabel (labelTargets = new Label ("new label", TRANS("Targets")),"Targets");

    createLabel (labelModAmount = new Label ("new label", TRANS("ModAmount")),"ModAmount");
    createLabel (labelTo = new Label ("new label", TRANS("->")),"->");

    setSize (sourceColumnWidth +toLabelWidth + targetColumnWidth + toggleButtonWidth + paramSliderWidth, 600);

}

ModulationMatrixComponent::~ModulationMatrixComponent()
{
    slider = nullptr;
    toggleButton = nullptr;
    sourcesComboBox = nullptr;
    targetsComboBox = nullptr;
    labelSources = nullptr;
    labelTargets = nullptr;
    labelModAmount = nullptr;
    labelTo = nullptr;
}

//==============================================================================

void ModulationMatrixComponent::resized()
{
    Rectangle<int> r = getLocalBounds();

    //Column titles
    Rectangle<int> firstRow = r.removeFromTop(rowHeight);
    labelSources->setBounds(firstRow.removeFromLeft(sourceColumnWidth));
    firstRow.removeFromLeft(toLabelWidth);
    labelTargets->setBounds(firstRow.removeFromLeft(targetColumnWidth));
    labelModAmount->setBounds(firstRow.removeFromLeft(toggleButtonWidth + paramSliderWidth));

    //rows
    slider->setSize (paramSliderWidth,paramSliderWidth);

    Rectangle<int> row = r.removeFromTop(rowHeight);
    sourcesComboBox->setBounds (row.removeFromLeft(sourceColumnWidth).withSizeKeepingCentre(sourceColumnWidth,comboBoxHeight));
    labelTo->setBounds (row.removeFromLeft(toLabelWidth));
    targetsComboBox->setBounds (row.removeFromLeft(targetColumnWidth).withSizeKeepingCentre(sourceColumnWidth,comboBoxHeight));
    toggleButton->setBounds (row.removeFromLeft(toggleButtonWidth));
    toggleButton->changeWidthToFitText();	
    slider->setBounds (row.removeFromLeft(paramSliderWidth));
}

void ModulationMatrixComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
    if (comboBoxThatHasChanged == sourcesComboBox)
    {
    }
    else if (comboBoxThatHasChanged == targetsComboBox)
    {
    }
}

void ModulationMatrixComponent::createLabel(Label *label, const String &newText)
{
    labelSources->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    labelSources->setJustificationType (Justification::centredLeft);
    labelSources->setEditable (false, false, false);
    labelSources->setColour (TextEditor::textColourId, Colours::black);
    labelSources->setColour (TextEditor::backgroundColourId, Colour (0x00000000));
    addAndMakeVisible (label);
}

void ModulationMatrixComponent::createSlider(Slider *slider, const String &newID)
{
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setRange (0.0, 1.0, 0.0);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 40, 12);
    slider->setPopupDisplayEnabled (false, true, this);
    slider->setValue (1.0);
    slider->setComponentID(newID);
    addAndMakeVisible (slider);
}
void ModulationMatrixComponent::createSlider(Slider *slider, const String &newID, const String &suffix)
{
    createSlider(slider, newID);
    slider->setTextValueSuffix (suffix);
}

void ModulationMatrixComponent::createComboBox(ComboBox *comboBox, const String &newToolTip)
{ 
    comboBox->setTooltip (TRANS(newToolTip));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addListener (this);
    addAndMakeVisible (comboBox);
}