
#include "ModulationMatrixComponent.h"



ModulationMatrixComponent::ModulationMatrixComponent ()
{
    addAndMakeVisible (toggleButton = new ToggleButton ("toggleButton"));
    toggleButton->setButtonText (String());


    addAndMakeVisible (slider = new Slider ("new slider"));
    slider->setRange (0, 10, 0);
    slider->setSliderStyle (Slider::RotaryVerticalDrag);
    slider->setTextBoxStyle (Slider::NoTextBox, true, 0, 0);


    addAndMakeVisible (comboBox = new ComboBox ("new combo box"));
    comboBox->setTooltip (TRANS("Select a source"));
    comboBox->setEditableText (false);
    comboBox->setJustificationType (Justification::centredLeft);
    comboBox->setTextWhenNothingSelected (String());
    comboBox->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox->addItem (TRANS("Env 1"), 1);
    comboBox->addItem (TRANS("Env 2"), 2);
    comboBox->addItem (TRANS("LFO 1"), 3);
    comboBox->addItem (TRANS("LFO 2"), 4);
    comboBox->addListener (this);

    addAndMakeVisible (comboBox2 = new ComboBox ("new combo box"));
    comboBox2->setTooltip (TRANS("Select a target"));
    comboBox2->setEditableText (false);
    comboBox2->setJustificationType (Justification::centredLeft);
    comboBox2->setTextWhenNothingSelected (String());
    comboBox2->setTextWhenNoChoicesAvailable (TRANS("(no choices)"));
    comboBox2->addItem (TRANS("Filter1:cutoff"), 1);
    comboBox2->addListener (this);

    addAndMakeVisible (label = new Label ("new label",
                                          TRANS("Sources")));
    label->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label->setJustificationType (Justification::centredLeft);
    label->setEditable (false, false, false);
    label->setColour (TextEditor::textColourId, Colours::black);
    label->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label2 = new Label ("new label",
                                           TRANS("Targets")));
    label2->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label2->setJustificationType (Justification::centredLeft);
    label2->setEditable (false, false, false);
    label2->setColour (TextEditor::textColourId, Colours::black);
    label2->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label3 = new Label ("new label",
                                           TRANS("ModAmount")));
    label3->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label3->setJustificationType (Justification::centredLeft);
    label3->setEditable (false, false, false);
    label3->setColour (TextEditor::textColourId, Colours::black);
    label3->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    addAndMakeVisible (label4 = new Label ("new label",
                                           TRANS("->")));
    label4->setFont (Font (15.00f, Font::plain).withTypefaceStyle ("Regular"));
    label4->setJustificationType (Justification::centredLeft);
    label4->setEditable (false, false, false);
    label4->setColour (TextEditor::textColourId, Colours::black);
    label4->setColour (TextEditor::backgroundColourId, Colour (0x00000000));

    setSize (sourceColumnWidth +toLabelWidth + targetColumnWidth + toggleButtonWidth + paramSliderWidth, 600);

}

ModulationMatrixComponent::~ModulationMatrixComponent()
{


    slider = nullptr;
    toggleButton = nullptr;
    comboBox = nullptr;
    comboBox2 = nullptr;
    label = nullptr;
    label2 = nullptr;
    label3 = nullptr;
    label4 = nullptr;


}

//==============================================================================
void ModulationMatrixComponent::paint (Graphics& g)
{

}

void ModulationMatrixComponent::resized()
{

    Rectangle<int> r = getLocalBounds();

    //Column titles
    Rectangle<int> firstRow = r.removeFromTop(rowHeight);
    label->setBounds(firstRow.removeFromLeft(sourceColumnWidth));
    firstRow.removeFromLeft(toLabelWidth);
    label2->setBounds(firstRow.removeFromLeft(targetColumnWidth));
    label3->setBounds(firstRow.removeFromLeft(toggleButtonWidth + paramSliderWidth));

    //rows


    slider->setSize (paramSliderWidth,paramSliderWidth);

    Rectangle<int> row = r.removeFromTop(rowHeight);
    comboBox->setBounds (row.removeFromLeft(sourceColumnWidth).withSizeKeepingCentre(sourceColumnWidth,comboBoxHeight));
    label4->setBounds (row.removeFromLeft(toLabelWidth));
    comboBox2->setBounds (row.removeFromLeft(targetColumnWidth).withSizeKeepingCentre(sourceColumnWidth,comboBoxHeight));
    toggleButton->setBounds (row.removeFromLeft(toggleButtonWidth));
    toggleButton->changeWidthToFitText();	
    slider->setBounds (row.removeFromLeft(paramSliderWidth));


}

void ModulationMatrixComponent::comboBoxChanged (ComboBox* comboBoxThatHasChanged)
{
 

    if (comboBoxThatHasChanged == comboBox)
    {

    }
    else if (comboBoxThatHasChanged == comboBox2)
    {

    }

}
