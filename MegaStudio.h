#pragma once
#include "LeakedObjectDetector.h"
#include "Studio.h"

struct MegaStudio
{
    Studio roomA;
    Studio roomB;

    MegaStudio();
    ~MegaStudio();

    void checkOnRoomA();
    void checkOnRoomB(); 

    JUCE_LEAK_DETECTOR(MegaStudio)
};
