#pragma once
#include "LeakedObjectDetector.h"
#include "Car.h"
#include "Plane.h"

struct Fleet
{
    Car myRedCar;
    Plane myBluePlane;

    Fleet();
    ~Fleet();

    void checkOnCar();
    void checkOnPlane(); 

    JUCE_LEAK_DETECTOR(Fleet)
};
