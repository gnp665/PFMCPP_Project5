/*
 Project 5: Part 3 / 4
 video: Chapter 3 Part 4: 

Create a branch named Part3

 the 'new' keyword

 1) add #include "LeakedObjectDetector.h" to main
 
 2) Add 'JUCE_LEAK_DETECTOR(OwnerClass)' at the end of your UDTs.
 
 3) write the name of your class where it says "OwnerClass"
 
 4) write wrapper classes for each type similar to how it was shown in the video
 
 5) update main() 
      replace your objects with your wrapper classes, which have your UDTs as pointer member variables.
      
    This means if you had something like the following in your main() previously: 
*/
#if false
 Axe axe;
 std::cout << "axe sharpness: " << axe.sharpness << "\n";
 #endif
 /*
    you would update that to use your wrappers:
    
 */

#if false
AxeWrapper axWrapper( new Axe() );
std::cout << "axe sharpness: " << axWrapper.axPtr->sharpness << "\n";
#endif
/*
notice that the object name has changed from 'axe' to 'axWrapper'
You don't have to do this, you can keep your current object name and just change its type to your Wrapper class

6) If you have a class that has a nested class in it, and an instantiation of that nested class as a member variable, 
    - you do not need to write a Wrapper for that nested class
    - you do not need to replace that nested instance with a wrapped instance.
    If you want an explanation, message me in Slack

 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
 see here for an example: https://repl.it/@matkatmusic/ch3p04example

 you can safely ignore any warnings about exit-time-destructors.
 if you would like to suppress them, add -Wno-exit-time-destructors to the .replit file 
   with the other warning suppression flags
 */




/*
 UDT 1:
 */

#include <iostream> 

struct Car
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

    Engine carEngine;

    Car();

    bool hasBeenCleaned(bool isClean);
    void checkTirePressure(int numWheels);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull = 100.0f);

    void printInitialFullTankMiles() 
    { 
        std::cout << "Total miles on full tank is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon) << " miles" << std::endl;  
    }  

    void printInitialCurrentTankMiles() 
    { 
        std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon, this->gasPercentFull) << " miles" << std::endl;  
    } 

    void printFullTankMiles() 
    {   
        std::cout << "Total miles on full tank is " << this->getMilesToEmpty (this->gasTankSizeInGallons = 20, this->milesPerGallon = 20.0f) << " miles" << std::endl;  
    }  

    void printCurrentTankMiles() 
    { 
        std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons = 20, this->milesPerGallon = 20.0f, this->gasPercentFull = 20.0f) << " miles" << std::endl;  
    } 
};

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

/*
 UDT 2:
 */

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

    void printInitialNumberOfMixes() 
    { 
        std::cout << "Total number of mixes is " << this->getTotalNumberOfMixes(this->numClients, this->mixesPerClient) << std::endl;  
    }  

    void printInitialTotalInvoiced() 
    {  
        std::cout << "Total invoiced is " << this->getTotalInvoiced(this->numClients, this->mixesPerClient, this->hoursPerMix, this->rate) << " dollars" << std::endl;
    }  

    void printNumberOfMixes() 
    { 
        std::cout << "Total number of mixes is " << this->getTotalNumberOfMixes(this->numClients = 15, this->mixesPerClient = 1) << std::endl;  
    }  

    void printTotalInvoiced() 
    {  
        std::cout << "Total invoiced is " << this->getTotalInvoiced(this->numClients = 15, this->mixesPerClient = 1, this->hoursPerMix = 8.0f, this->rate = 20.0f) << " dollars" << std::endl;
    }  
};

Studio::Studio() : numMics(8), numClients (10)
{
    hoursPerMix = 4.5f;
    mixesPerClient = 2;
}

void Studio::checkEachMic(int numMics_)
{
    int i = 1;
    while(i <= numMics_)
    {
        std::cout << "Mic number " << i << ": Signal has been checked" << std::endl;
        i++;
    }
}

int Studio::getTotalNumberOfMixes(int numClients_, int mixesPerClient_)
{
    return (numClients_ * mixesPerClient_);
}

float Studio::getTotalInvoiced(int numClients_, int mixesPerClient_, float hoursPerMix_, float rate_)
{
    return (numClients_ * mixesPerClient_ * hoursPerMix_ * rate_);
}


/*
 UDT 3:
 */

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

    void printInitialFullTankMiles() 
    { 
        std::cout << "Total miles on full tank is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon) << " miles" << std::endl;  
    }  

    void printInitialCurrentTankMiles() 
    { 
        std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon, this->gasPercentFull) << " miles" << std::endl;  
    } 

    void printFullTankMiles() 
    {   
        std::cout << "Total miles on full tank is " << this->getMilesToEmpty (this->gasTankSizeInGallons = 500, this->milesPerGallon = 1.42f) << " miles" << std::endl;  
    }  

    void printCurrentTankMiles() 
    { 
        std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons = 500, this->milesPerGallon = 1.42f, this->gasPercentFull = 51.50f) << " miles" << std::endl;  
    } 
};

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

/*
 new UDT 4:
 */

struct Fleet
{
    Car myRedCar;
    Plane myBluePlane;

    Fleet();
    ~Fleet();

    void checkOnCar();
    void checkOnPlane(); 
};

Fleet::Fleet()
{
    std::cout << std::endl << "UDT 4 - Constructor for Fleet:" << std::endl;
    myRedCar.checkTirePressure(myRedCar.numWheels);
    myBluePlane.planeEngine.checkCylinderPressure(myBluePlane.planeEngine.numCylinders);
}

Fleet::~Fleet()
{
    std::cout << std::endl << "UDT 4 - Destructor for Fleet:" << std::endl;
    std::cout << "Total miles on current tank level " << myRedCar.getMilesToEmpty(myRedCar.gasTankSizeInGallons, myRedCar.milesPerGallon, myRedCar.gasPercentFull) << " miles" << std::endl;
    std::cout << "Total miles on current tank level " << myBluePlane.getMilesToEmpty(20, 20.0f, 20.0f) << " miles" << std::endl;
}

void Fleet::checkOnCar() 
{
    myRedCar.checkTirePressure(myRedCar.numWheels);
}

void Fleet::checkOnPlane() 
{
    myBluePlane.checkTirePressure(myBluePlane.numWheels);
}

/*
 new UDT 5:
 */

struct MegaStudio
{
    Studio roomA;
    Studio roomB;

    MegaStudio();
    ~MegaStudio();

    void checkOnRoomA();
    void checkOnRoomB(); 
};

MegaStudio::MegaStudio()
{
    std::cout << std::endl << "UDT 5 - Constructor for MegaStudio:" << std::endl;
    roomA.checkEachMic(roomA.numMics);
    roomB.checkEachMic(4);
}

MegaStudio::~MegaStudio()
{
    std::cout << std::endl << "UDT 5 - Destructor for MegaStudio:" << std::endl;
    std::cout << "Total invoiced is " << roomA.getTotalInvoiced(roomA.numClients, roomA.mixesPerClient, roomA.hoursPerMix, roomA.rate) << " dollars" << std::endl;
    std::cout << "Total invoiced is " << roomB.getTotalInvoiced(15, 1, 8, 20) << " dollars" << std::endl << std::endl;
}

void MegaStudio::checkOnRoomA() 
{
    roomA.checkEachMic(roomA.numMics);
}

void MegaStudio::checkOnRoomB() 
{
    roomB.checkEachMic(roomB.numMics);
}

/*
 MAKE SURE YOU ARE NOT ON THE MASTER BRANCH
 Commit your changes by clicking on the Source Control panel on the left, entering a message, and click [Commit and push].
 
 If you didn't already: 
    Make a pull request after you make your first commit
    pin the pull request link and this repl.it link to our DM thread in a single message.
 send me a DM to review your pull request when the project is ready for review.
 Wait for my code review.
 */


int main()
{
    Car myCar, myOtherCar;
    Studio myStudio, myOtherStudio;
    Plane myPlane, myOtherPlane;

    // Test two instances of UDT 1
    std::cout << std::endl << "Test Bench UDT 1 - Instance 1:" << std::endl;
    myCar.hasBeenCleaned(myCar.isClean);
    myCar.checkTirePressure(myCar.numWheels); 
    myCar.carEngine.hasEngineBeenStarted(myCar.carEngine.isStarted);
    myCar.carEngine.checkCylinderPressure(myCar.carEngine.numCylinders);
    myCar.carEngine.isEngineStatusGood(myCar.carEngine.hasCoolant, myCar.carEngine.hasNormalTemp, myCar.carEngine.oilPressureIsGood);

    std::cout << "Total miles on full tank is " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon) << " miles" << std::endl; 
    myCar.printInitialFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon, myCar.gasPercentFull) << " miles" << std::endl; 
    myCar.printInitialCurrentTankMiles(); // member function output of above 

    std::cout << std::endl << "Test Bench UDT 1 - Instance 2:" << std::endl;
    myCar.hasBeenCleaned(false);
    myCar.checkTirePressure(4); 
    myCar.carEngine.hasEngineBeenStarted(false);
    myCar.carEngine.checkCylinderPressure(6);
    myCar.carEngine.isEngineStatusGood(true, false, true);

    std::cout << "Total miles on full tank is " << myCar.getMilesToEmpty(20, 20.0f) << " miles" << std::endl; 
    myCar.printFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myCar.getMilesToEmpty(20, 20.0f, 20.0f) << " miles" << std::endl;
    myCar.printCurrentTankMiles(); // member function output of above 

   // Test two instances of UDT 2
    std::cout << std::endl << "Test Bench UDT 2 - Instance 1:" << std::endl;
    myStudio.checkEachMic(myStudio.numMics);

    std::cout << "Total number of mixes is " << myStudio.getTotalNumberOfMixes(myStudio.numClients, myStudio.mixesPerClient) << std::endl;
    myStudio.printInitialNumberOfMixes(); // member function output of above 
    
    std::cout << "Total invoiced is " << myStudio.getTotalInvoiced(myStudio.numClients, myStudio.mixesPerClient, myStudio.hoursPerMix, myStudio.rate) << " dollars" << std::endl; 
    myStudio.printInitialTotalInvoiced(); // member function output of above 
    
    std::cout << std::endl << "Test Bench UDT 2 - Instance 2:" << std::endl;
    myOtherStudio.checkEachMic(4);
    std::cout << "Total number of mixes is " << myOtherStudio.getTotalNumberOfMixes(15, 1) << std::endl; 
    myOtherStudio.printNumberOfMixes(); // member function output of above 
    
    std::cout << "Total invoiced is " << myOtherStudio.getTotalInvoiced(15, 1, 8, 20) << " dollars" << std::endl; 
    myOtherStudio.printTotalInvoiced(); // member function output of above 
    
   // Test two instances of UDT 3
    std::cout << std::endl << "Test Bench UDT 3 - Instance 1:" << std::endl;
    myPlane.hasBeenCleaned(myPlane.isClean);
    myPlane.checkTirePressure(myPlane.numWheels); 
    myPlane.planeEngine.hasEngineBeenStarted(myPlane.planeEngine.isStarted);
    myPlane.planeEngine.checkCylinderPressure(myPlane.planeEngine.numCylinders);
    myPlane.planeEngine.isEngineStatusGood(myPlane.planeEngine.hasCoolant, myPlane.planeEngine.hasNormalTemp, myPlane.planeEngine.oilPressureIsGood);

    std::cout << "Total miles on full tank is " << myPlane.getMilesToEmpty(myPlane.gasTankSizeInGallons, myPlane.milesPerGallon) << " miles" << std::endl; 
    myPlane.printInitialFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myPlane.getMilesToEmpty(myPlane.gasTankSizeInGallons, myPlane.milesPerGallon, myPlane.gasPercentFull) << " miles" << std::endl; 
    myPlane.printInitialCurrentTankMiles(); // member function output of above 

    std::cout << std::endl << "Test Bench UDT 3 - Instance 2:" << std::endl;
    myPlane.hasBeenCleaned(false);
    myPlane.checkTirePressure(3); 
    myPlane.planeEngine.hasEngineBeenStarted(false);
    myPlane.planeEngine.checkCylinderPressure(4);
    myPlane.planeEngine.isEngineStatusGood(true, false, true);

    std::cout << "Total miles on full tank is " << myPlane.getMilesToEmpty(500, 1.42f) << " miles" << std::endl; 
    myPlane.printFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myPlane.getMilesToEmpty(500, 1.42f, 51.50f) << " miles" << std::endl; 
    myPlane.printCurrentTankMiles(); // member function output of above 

    // Test two instances of UDT 4
    Fleet myFleet; 
    Fleet myOtherFleet;
    std::cout << std::endl << "Test Bench UDT 4 - Instance 1:" << std::endl;
    myFleet.checkOnCar();
    myFleet.checkOnPlane();
    std::cout << std::endl << "Test Bench UDT 4 - Instance 2:" << std::endl;
    myOtherFleet.checkOnCar();
    myOtherFleet.checkOnPlane();

    // Test two instances of UDT 5
    MegaStudio myMegaStudio; 
    MegaStudio myOtherMegaStudio;
    std::cout << std::endl << "Test Bench UDT 5 - Instance 1:" << std::endl;
    myMegaStudio.checkOnRoomA();
    myMegaStudio.checkOnRoomB();
    std::cout << std::endl << "Test Bench UDT 5 - Instance 2:" << std::endl;
    myOtherMegaStudio.checkOnRoomA();
    myOtherMegaStudio.checkOnRoomB();
}
