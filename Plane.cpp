#include "Plane.h"

Plane::Plane() : numWheels(3), gasTankSizeInGallons (500)
{
    milesPerGallon = 1.23f;
    gasPercentFull = 58.7f;
}

Plane::Engine::Engine() : numCylinders(4), hasCoolant (true)
{
    hasNormalTemp = true;
    oilPressureIsGood = true;
}

bool Plane::hasBeenCleaned(bool isClean_)
{
    if(isClean_)
    {
        std::cout << "The plane is already clean" << std::endl;
        return false;
    }

    std::cout << "The plane was dirty and now has been cleaned" << std::endl;
    return true;
}

void Plane::checkTirePressure(int numWheels_)
{
    for (int i = 1; i <= numWheels_; ++i)
        std::cout << "Tire number " << i << ": Pressure has been checked" << std::endl;
}

bool Plane::Engine::hasEngineBeenStarted(bool isStarted_)
{
    if(isStarted_)
    {
        std::cout << "The plane is has been started" << std::endl;
        return true;
    }

    std::cout << "The plane has NOT been started" << std::endl;
    return false;
}

void Plane::Engine::checkCylinderPressure(int numCylinders_)
{
    for (int i = 1; i <= numCylinders_; ++i)
        std::cout << "Cylinder number " << i << ": Pressure has been checked" << std::endl;
}

bool Plane::Engine::isEngineStatusGood(bool hasCoolant_, bool hasNormalTemp_, bool oilPressureIsGood_)
{
    if(hasCoolant_ && hasNormalTemp_ && oilPressureIsGood_)
    {
        std::cout << "The engine status is Good" << std::endl;
        return true;
    }

    std::cout << "The engine status is BAD!" << std::endl;
    return false;
}

float Plane::getMilesToEmpty(int gasTankSizeInGallons_, float milesPerGallon_, float gasPercentFull_)
{
    return (gasTankSizeInGallons_ * milesPerGallon_ * gasPercentFull_ / 100);
}

void Plane::printInitialFullTankMiles() 
{ 
    std::cout << "Total miles on full tank is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon) << " miles" << std::endl;  
}  

void Plane::printInitialCurrentTankMiles() 
{ 
    std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon, this->gasPercentFull) << " miles" << std::endl;  
} 

void Plane::printFullTankMiles() 
{   
    std::cout << "Total miles on full tank is " << this->getMilesToEmpty (this->gasTankSizeInGallons = 500, this->milesPerGallon = 1.42f) << " miles" << std::endl;  
}  

void Plane::printCurrentTankMiles() 
{ 
    std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons = 500, this->milesPerGallon = 1.42f, this->gasPercentFull = 51.50f) << " miles" << std::endl;  
} 
