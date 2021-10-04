#pragma once
#include "LeakedObjectDetector.h"

struct Studio
{
    int numMics;
    int numClients;    
    float hoursPerMix;
    int mixesPerClient;
    float rate = 30.0f;

    Studio();

    void checkEachMic(int numMics);
    int getTotalNumberOfMixes(int numClients, int mixesPerClient);
    float getTotalInvoiced(int numClients, int mixesPerClient, float hoursPerMix, float rate);

    void printInitialNumberOfMixes();  // formerly implemented in-class, moved to cpp file
    void printInitialTotalInvoiced();  // formerly implemented in-class, moved to cpp file
    void printNumberOfMixes();         // formerly implemented in-class, moved to cpp file
    void printTotalInvoiced();         // formerly implemented in-class, moved to cpp file
    
    JUCE_LEAK_DETECTOR(Studio)
};
