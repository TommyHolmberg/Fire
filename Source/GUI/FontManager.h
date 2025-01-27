/*
  ==============================================================================

    FontManager.h
    Created: 27 Jan 2025 6:48:37pm
    Author:  Tommy

  ==============================================================================
*/

#pragma once
#include <JuceHeader.h>
#include "InterfaceDefines.h"



class FontManager
{
public:
    static juce::Font getKnobFont(float size, juce::Font::FontStyleFlags flags = juce::Font::plain)
    {
        juce::Font fontToTest;
        fontToTest.setPreferredFallbackFamilies(fontNamesToTry);
        fontToTest = fontToTest.findSuitableFontForText("A", {});
        fontToTest.setHeight(size);
        fontToTest.setStyleFlags(flags);
        return fontToTest;
    }

private:
    inline static const juce::StringArray fontNamesToTry{ KNOB_FONT, "Arial", "Helvetica Neue", "Helvetica", "Segoe UI", "Tahoma", "Verdana", "sans-serif" };
};
