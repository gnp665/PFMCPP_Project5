#include "Car.h"

Car::Car() : numWheels(4), gasTankSizeInGallons (20)
{
    milesPerGallon = 23.4f;
    gasPercentFull = 69.2f;
}

Car::Engine::Engine() : numCylinders(6), hasCoolant (true)
{
    hasNormalTemp = true;
    oilPressureIsGood = true;
}

bool Car::hasBeenCleaned(bool isClean_)
{
    if(isClean_)
    {
        std::cout << "The car is already clean" << std::endl;
        return false;
    }

    std::cout << "The car was dirty and now has been cleaned" << std::endl;
    return true;
}

void Car::checkTirePressure(int numWheels_)
{
    for (int i = 1; i <= numWheels_; ++i)
        std::cout << "Tire number " << i << ": Pressure has been checked" << std::endl;
}

bool Car::Engine::hasEngineBeenStarted(bool isStarted_)
{
    if(isStarted_)
    {
        std::cout << "The car is has been started" << std::endl;
        return true;
    }

    std::cout << "The car has NOT been started" << std::endl;
    return false;
}

void Car::Engine::checkCylinderPressure(int numCylinders_)
{
    for (int i = 1; i <= numCylinders_; ++i)
        std::cout << "Cylinder number " << i << ": Pressure has been checked" << std::endl;
}

bool Car::Engine::isEngineStatusGood(bool hasCoolant_, bool hasNormalTemp_, bool oilPressureIsGood_)
{
    if(hasCoolant_ && hasNormalTemp_ && oilPressureIsGood_)
    {
        std::cout << "The engine status is Good" << std::endl;
        return true;
    }

    std::cout << "The engine status is BAD!" << std::endl;
    return false;
}

float Car::getMilesToEmpty(int gasTankSizeInGallons_, float milesPerGallon_, float gasPercentFull_)
{
    return (gasTankSizeInGallons_ * milesPerGallon_ * gasPercentFull_ / 100);
}

void Car::printInitialFullTankMiles() 
{ 
    std::cout << "Total miles on full tank is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon) << " miles" << std::endl;  
}  

void Car::printInitialCurrentTankMiles() 
{ 
    std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon, this->gasPercentFull) << " miles" << std::endl;  
} 

void Car::printFullTankMiles() 
{   
    std::cout << "Total miles on full tank is " << this->getMilesToEmpty (this->gasTankSizeInGallons = 20, this->milesPerGallon = 20.0f) << " miles" << std::endl;  
}  

void Car::printCurrentTankMiles() 
{ 
    std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons = 20, this->milesPerGallon = 20.0f, this->gasPercentFull = 20.0f) << " miles" << std::endl;  
} 
