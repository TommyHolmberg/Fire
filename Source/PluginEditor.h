/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "DSP/Distortion.h"
#include "LookAndFeel.h"
#include "Graph Components/Oscilloscope.h"
#include "Graph Components/DistortionGraph.h"
#include "Multiband/Multiband.h"

//==============================================================================
/**
*/
class FireAudioProcessorEditor : public juce::AudioProcessorEditor, //2019/12/28
                                 public juce::Slider::Listener,
                                 public juce::ComboBox::Listener, //2020/08/08
                                 public juce::Timer               //edited 2020/07/03 fps
{
public:
    //typedef AudioProcessorValueTreeState::SliderAttachment SliderAttachment;
    FireAudioProcessorEditor(FireAudioProcessor &);
    ~FireAudioProcessorEditor();

    //==============================================================================
    void paint(juce::Graphics &g) override;
    void resized() override;
    void timerCallback() override;

private:
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    FireAudioProcessor &processor;
    state::StateComponent stateComponent;
    
    // Oscilloscope
    Oscilloscope oscilloscope {processor};
    
    // Distortion graph
    DistortionGraph distortionGraph;
    
    // Multiband
    Multiband multiband;
    
    // Spectrum
    SpectrumComponent spectrum;
    
    // ff meter
    foleys::LevelMeterLookAndFeel lnf;
    foleys::LevelMeter inputMeter{foleys::LevelMeter::Minimal};
    foleys::LevelMeter outputMeter{foleys::LevelMeter::Minimal};

    // Sliders
    juce::Slider
        driveKnob,
        downSampleKnob,
        outputKnob,
        recKnob,
        mixKnob,
        cutoffKnob,
        resKnob,
        colorKnob,
        biasKnob;
    
    int knobSize = 100;
    float tempDriveValue = 1;
    float tempBiasValue = 0;

    // Labels
    juce::Label
        hqLabel,
        driveLabel,
        downSampleLabel,
        outputLabel,
        recLabel,
        mixLabel,
        cutoffLabel,
        resLabel,
        linkedLabel,
        safeLabel,
        recOffLabel,
        recHalfLabel,
        recFullLabel,
        filterOffLabel,
        filterLowLabel,
        colorLabel,
        biasLabel;

    // Buttons
    juce::TextButton
        hqButton,
        linkedButton,
        safeButton,
        filterOffButton,
        filterPreButton,
        filterPostButton,
        filterLowButton,
        filterBandButton,
        filterHighButton,
        windowLeftButton,
        windowRightButton;

    // group toggle buttons
    enum RadioButtonIds
    {
        // filter state: off, pre, post
        filterStateButtons = 1001,
        // filter mode: low, band, high
        filterModeButtons = 1002,
        // window selection: left, right
        windowButtons = 1003,
    };

    void updateToggleState();
    //void setCutoffButtonState(TextButton* textButton, Slider* slider, Slider* slider2);
    
    void updateWindowState();
    
    

    // override listener functions
    // linked
    void sliderValueChanged(juce::Slider *slider) override;
    // combobox changed and set knob enable/disable
    void comboBoxChanged(juce::ComboBox *combobox) override;

    // Slider attachment
    std::unique_ptr<juce::AudioProcessorValueTreeState::SliderAttachment>
        //inputAttachment,
        driveAttachment,
        downSampleAttachment,
        recAttachment,
        outputAttachment,
        mixAttachment,
        cutoffAttachment,
        resAttachment,
        colorAttachment,
        biasAttachment;

    // Button attachment
    std::unique_ptr<juce::AudioProcessorValueTreeState::ButtonAttachment>
        hqAttachment,
        linkedAttachment,
        safeAttachment,
        filterOffAttachment,
        filterPreAttachment,
        filterPostAttachment,
        filterLowAttachment,
        filterBandAttachment,
        filterHighAttachment,
        windowLeftButtonAttachment,
        windowRightButtonAttachment;

    // ComboBox attachment
    juce::ComboBox distortionMode;
    std::unique_ptr<juce::AudioProcessorValueTreeState::ComboBoxAttachment> modeAttachment;

    // create own knob style
    OtherLookAndFeel otherLookAndFeel;
    RoundedButtonLnf roundedButtonLnf;
    //FlatButtonLnf flatButtonLnf;
    
    Distortion distortionProcessor;

    
    //return function value by different modes
    //float getFunctionValue(FireAudioProcessor& processor, float value);
    //int modeChoice;
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR(FireAudioProcessorEditor)
};
