/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

#include "PluginProcessor.h"

//==============================================================================
/**
 */
class KashiwadeGUIlibAudioProcessorEditor : public juce::AudioProcessorEditor {
 public:
  KashiwadeGUIlibAudioProcessorEditor(KashiwadeGUIlibAudioProcessor&,
                                      juce::AudioProcessorValueTreeState&);
  ~KashiwadeGUIlibAudioProcessorEditor() override;

  //==============================================================================
  void paint(juce::Graphics&) override;
  void resized() override;

 private:
  // This reference is provided as a quick way for your editor to
  // access the processor object that created it.
  KashiwadeGUIlibAudioProcessor& audioProcessor;

  typedef juce::AudioProcessorValueTreeState::SliderAttachment
      SliderAttachment;  // 追加
  typedef juce::AudioProcessorValueTreeState::ComboBoxAttachment
      ComboBoxAttachment;
  juce::AudioProcessorValueTreeState& valueTreeState;
  juce::Slider naturalSlider;
  std::unique_ptr<SliderAttachment> naturalSliderAttachment;
  juce::Slider rotationSlider;
  std::unique_ptr<SliderAttachment> rotationSliderAttachment;
  juce::ComboBox naturalComboBox;
  std::unique_ptr<ComboBoxAttachment> naturalComboBoxAttachment;
  JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(
      KashiwadeGUIlibAudioProcessorEditor)
};
