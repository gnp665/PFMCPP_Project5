#pragma once
#include "LeakedObjectDetector.h"

struct Plane
{
    int numWheels;
    int gasTankSizeInGallons;    
    float milesPerGallon;
    float gasPercentFull;
    bool isClean = true;
   
    //Nested UDT 1:   
    struct Engine
    {
        int numCylinders;
        bool hasCoolant;    
        bool hasNormalTemp;
        bool oilPressureIsGood;
        bool isStarted = true;

        Engine();

        bool hasEngineBeenStarted(bool isStarted);
        void checkCylinderPressure(int numCylinders);
        bool isEngineStatusGood(bool hasCoolant, bool hasNormalTemp, bool oilPressureIsGood);
    };

    Engine planeEngine;

    Plane();

    bool hasBeenCleaned(bool isClean);
    void checkTirePressure(int numWheels);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull = 100.0f);

    void printInitialFullTankMiles();      // formerly implemented in-class, moved to cpp file
    void printInitialCurrentTankMiles();   // formerly implemented in-class, moved to cpp file
    void printFullTankMiles();             // formerly implemented in-class, moved to cpp file
    void printCurrentTankMiles();          // formerly implemented in-class, moved to cpp file

    JUCE_LEAK_DETECTOR(Plane)
};
