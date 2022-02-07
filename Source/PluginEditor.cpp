/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginEditor.h"

#include "PluginProcessor.h"

//==============================================================================
KashiwadeGUIlibAudioProcessorEditor::KashiwadeGUIlibAudioProcessorEditor(
    KashiwadeGUIlibAudioProcessor& p, juce::AudioProcessorValueTreeState& vts)
    : AudioProcessorEditor(&p), audioProcessor(p), valueTreeState(vts) {
  // Make sure that before the constructor has finished, you've set the
  // editor's size to whatever you need it to be.
  addAndMakeVisible(naturalSlider);
  naturalSliderAttachment.reset(
      new SliderAttachment(valueTreeState, "gain", naturalSlider));
  addAndMakeVisible(rotationSlider);
  rotationSliderAttachment.reset(
      new SliderAttachment(valueTreeState, "panangle", rotationSlider));
  addAndMakeVisible(naturalComboBox);
  naturalComboBoxAttachment.reset(
      new ComboBoxAttachment(valueTreeState, "panrule", naturalComboBox));
  naturalComboBox.addItemList(
      juce::StringArray("linear", "balanced", "sin3dB", "sin4.5dB", "sin6dB",
                        "sqrt3dB", "sqrt4.5dB"),
      1);
  setSize(400, 300);
}

KashiwadeGUIlibAudioProcessorEditor::~KashiwadeGUIlibAudioProcessorEditor() {}

//==============================================================================
void KashiwadeGUIlibAudioProcessorEditor::paint(juce::Graphics& g) {
  // (Our component is opaque, so we must completely fill the background with a
  // solid colour)
  g.fillAll(
      getLookAndFeel().findColour(juce::ResizableWindow::backgroundColourId));

  g.setColour(juce::Colours::white);
  g.setFont(15.0f);
  g.drawFittedText("Hello World!", getLocalBounds(),
                   juce::Justification::centred, 1);
}

void KashiwadeGUIlibAudioProcessorEditor::resized() {
  // This is generally where you'll want to lay out the positions of any
  // subcomponents in your editor..
  naturalComboBox.setBounds(10, 10, 100, 100);
  rotationSlider.setBounds(10, 30, 100, 100);
  naturalComboBox.setBounds(10, 60, 100, 100);
}
