/*
Project 5: Part 1 / 4
 video Chapter 2 - Part 12
 Create a branch named Part1
Purpose:  This project continues developing Project3.
       you will learn how to take code from existing projects and migrate only what you need to new projects
       you will learn how to write code that doesn't leak as well as how to refactor. 
=============================================
Since you didn't do Project 3:
=============================================
write 3 UDTs below that EACH have: 
        5 member variables
            the member variable names and types should be relevant to the work the UDT will perform.
            pick properties that can be represented with 'int float double bool char std::string'
        3 member functions with an arbitrary number of parameters
            give some of those parameters default values.
        constructors that initialize some of these member variables
            the remaining member variables should be initialized in-class
        for() or while() loops that modify member variables
 1) 2 of your 3 UDTs need to have a nested UDT.
    this nested UDT should fulfill the same requirements as above:
        5 member variables  
        3 member functions
        constructors and loops.
        
 2) Define your implementations of all functions OUTSIDE of the class. 
 NO IN-CLASS IMPLEMENTATION ALLOWED
 3) add destructors to all of your UDTs
        make the destructors do something like print out the name of the class.
 
 4) add 2 new UDTs that use only the types you copied above as member variables.
 
 5) Add destructors to these 2 new types that do something.  
        maybe print out the name of the class being destructed, or call a member function of one of the members.  be creative
 
 6) use at least 2 instances of each of your UDTs in main. 
        add some std::cout statements in main() that use your UDT's member variables.
 
 7) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 
If you need inspiration for what to write, take a look at previously approved student projects in the Slack Workspace channel for this project part.
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

        bool engineHasBeenStarted(bool isStarted);
        void checkCylinderPressure(int numCylinders);
        bool isEngineStatusGood(bool hasCoolant, bool hasNormalTemp, bool oilPressureIsGood);
    };

    Engine carEngine;

    Car();

    bool hasBeenCleaned(bool isClean);
    void checkTirePressure(int numWheels);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull);
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

bool Car::hasBeenCleaned(bool isClean)
{
    if(isClean)
    {
        std::cout << "The car is already clean" << std::endl;
        return false;
    }

    std::cout << "The car was dirty and now has been cleaned" << std::endl;
    return true;
}

void Car::checkTirePressure(int numWheels)
{
    for (int i = 1; i <= numWheels; ++i)
        std::cout << "Tire number " << i << ": Pressure has been checked" << std::endl;
}

bool Car::Engine::engineHasBeenStarted(bool isStarted)
{
    if(isStarted)
    {
        std::cout << "The car is has been started" << std::endl;
        return true;
    }

    std::cout << "The car has NOT been started" << std::endl;
    return false;
}

void Car::Engine::checkCylinderPressure(int numCylinders)
{
    for (int i = 1; i <= numCylinders; ++i)
        std::cout << "Cylinder number " << i << ": Pressure has been checked" << std::endl;
}

bool Car::Engine::isEngineStatusGood(bool hasCoolant, bool hasNormalTemp, bool oilPressureIsGood)
{
    if(hasCoolant && hasNormalTemp && oilPressureIsGood)
    {
        std::cout << "The engine status is Good" << std::endl;
        return true;
    }

    std::cout << "The engine status is BAD!" << std::endl;
    return false;
}

float Car::getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull = 100.0f)
{
  return (gasTankSizeInGallons * milesPerGallon * gasPercentFull / 100);
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

    void micCheck(int numMics);
    int totalNumberMixes(int numClients, int mixesPerClient);
    auto getTotalInvoiced(int numClients, int mixesPerClient, float hoursPerMix, float rate);
};

Studio::Studio() : numMics(8), numClients (10)
{
    hoursPerMix = 4.5f;
    mixesPerClient = 2;
}

void Studio::micCheck(int numMics)
{
    int i = 1;
    while(i <= numMics)
    {
        std::cout << "Mic number " << i << ": Signal has been checked" << std::endl;
        i++;
    }
}

int Studio::totalNumberMixes(int numClients, int mixesPerClient)
{
  return (numClients * mixesPerClient);
}

auto Studio::getTotalInvoiced(int numClients, int mixesPerClient, float hoursPerMix, float rate)
{
  return (numClients * mixesPerClient * hoursPerMix * rate);
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

        bool engineHasBeenStarted(bool isStarted);
        void checkCylinderPressure(int numCylinders);
        bool isEngineStatusGood(bool hasCoolant, bool hasNormalTemp, bool oilPressureIsGood);
    };

    Engine planeEngine;

    Plane();

    bool hasBeenCleaned(bool isClean);
    void checkTirePressure(int numWheels);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull);
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

bool Plane::hasBeenCleaned(bool isClean)
{
    if(isClean)
    {
        std::cout << "The plane is already clean" << std::endl;
        return false;
    }

    std::cout << "The plane was dirty and now has been cleaned" << std::endl;
    return true;
}

void Plane::checkTirePressure(int numWheels)
{
    for (int i = 1; i <= numWheels; ++i)
        std::cout << "Tire number " << i << ": Pressure has been checked" << std::endl;
}

bool Plane::Engine::engineHasBeenStarted(bool isStarted)
{
    if(isStarted)
    {
        std::cout << "The plane is has been started" << std::endl;
        return true;
    }

    std::cout << "The plane has NOT been started" << std::endl;
    return false;
}

void Plane::Engine::checkCylinderPressure(int numCylinders)
{
    for (int i = 1; i <= numCylinders; ++i)
        std::cout << "Cylinder number " << i << ": Pressure has been checked" << std::endl;
}

bool Plane::Engine::isEngineStatusGood(bool hasCoolant, bool hasNormalTemp, bool oilPressureIsGood)
{
    if(hasCoolant && hasNormalTemp && oilPressureIsGood)
    {
        std::cout << "The engine status is Good" << std::endl;
        return true;
    }

    std::cout << "The engine status is BAD!" << std::endl;
    return false;
}

float Plane::getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull = 100.0f)
{
  return (gasTankSizeInGallons * milesPerGallon * gasPercentFull / 100);
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

/*
 new UDT 5:
 */

struct MegaStudio
{
    Studio roomA;
    Studio roomB;

    MegaStudio();
    ~MegaStudio();

};

MegaStudio::MegaStudio()
{
    std::cout << std::endl << "UDT 5 - Constructor for MegaStudio:" << std::endl;
    roomA.micCheck(roomA.numMics);
    roomB.micCheck(4);
}

MegaStudio::~MegaStudio()
{
    std::cout << std::endl << "UDT 5 - Destructor for MegaStudio:" << std::endl;
    std::cout << "Total invoiced is " << roomA.getTotalInvoiced(roomA.numClients, roomA.mixesPerClient, roomA.hoursPerMix, roomA.rate) << " dollars" << std::endl;
    std::cout << "Total invoiced is " << roomB.getTotalInvoiced(15, 1, 8, 20) << " dollars" << std::endl << std::endl;
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
    myCar.carEngine.engineHasBeenStarted(myCar.carEngine.isStarted);
    myCar.carEngine.checkCylinderPressure(myCar.carEngine.numCylinders);
    myCar.carEngine.isEngineStatusGood(myCar.carEngine.hasCoolant, myCar.carEngine.hasNormalTemp, myCar.carEngine.oilPressureIsGood);
    std::cout << "Total miles on full tank is " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon) << " miles" << std::endl;
    std::cout << "Total miles on current tank level " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon, myCar.gasPercentFull) << " miles" << std::endl << std::endl;

    std::cout << std::endl << "Test Bench UDT 1 - Instance 2:" << std::endl;
    myCar.hasBeenCleaned(false);
    myCar.checkTirePressure(4); 
    myCar.carEngine.engineHasBeenStarted(false);
    myCar.carEngine.checkCylinderPressure(6);
    myCar.carEngine.isEngineStatusGood(true, false, true);
    std::cout << "Total miles on full tank is " << myCar.getMilesToEmpty(20, 20.0f) << " miles" << std::endl;
    std::cout << "Total miles on current tank level " << myCar.getMilesToEmpty(20, 20.0f, 20.0f) << " miles" << std::endl << std::endl;

   // Test two instances of UDT 2
    std::cout << "Test Bench UDT 2 - Instance 1:" << std::endl;
    myStudio.micCheck(myStudio.numMics);
    std::cout << "Total number of mixes is " << myStudio.totalNumberMixes(myStudio.numClients, myStudio.mixesPerClient) << std::endl;
    std::cout << "Total invoiced is " << myStudio.getTotalInvoiced(myStudio.numClients, myStudio.mixesPerClient, myStudio.hoursPerMix, myStudio.rate) << " dollars" << std::endl << std::endl;

    std::cout << "Test Bench UDT 2 - Instance 2:" << std::endl;
    myOtherStudio.micCheck(4);
    std::cout << "Total number of mixes is " << myOtherStudio.totalNumberMixes(15, 1) << std::endl;
    std::cout << "Total invoiced is " << myOtherStudio.getTotalInvoiced(15, 1, 8, 20) << " dollars" << std::endl << std::endl;

   // Test two instances of UDT 3
    std::cout << std::endl << "Test Bench UDT 3 - Instance 1:" << std::endl;
    myPlane.hasBeenCleaned(myPlane.isClean);
    myPlane.checkTirePressure(myPlane.numWheels); 
    myPlane.planeEngine.engineHasBeenStarted(myPlane.planeEngine.isStarted);
    myPlane.planeEngine.checkCylinderPressure(myPlane.planeEngine.numCylinders);
    myPlane.planeEngine.isEngineStatusGood(myPlane.planeEngine.hasCoolant, myPlane.planeEngine.hasNormalTemp, myPlane.planeEngine.oilPressureIsGood);
    std::cout << "Total miles on full tank is " << myPlane.getMilesToEmpty(myPlane.gasTankSizeInGallons, myPlane.milesPerGallon) << " miles" << std::endl;
    std::cout << "Total miles on current tank level " << myPlane.getMilesToEmpty(myPlane.gasTankSizeInGallons, myPlane.milesPerGallon, myPlane.gasPercentFull) << " miles" << std::endl << std::endl;

    std::cout << std::endl << "Test Bench UDT 3 - Instance 2:" << std::endl;
    myPlane.hasBeenCleaned(false);
    myPlane.checkTirePressure(3); 
    myPlane.planeEngine.engineHasBeenStarted(false);
    myPlane.planeEngine.checkCylinderPressure(4);
    myPlane.planeEngine.isEngineStatusGood(true, false, true);
    std::cout << "Total miles on full tank is " << myPlane.getMilesToEmpty(500, 1.42f) << " miles" << std::endl;
    std::cout << "Total miles on current tank level " << myPlane.getMilesToEmpty(500, 1.42f, 51.50f) << " miles" << std::endl << std::endl;

    // Test two instances of UDT 4
    Fleet myFleet; 
    Fleet myOtherFleet;

    // Test two instances of UDT 5
    MegaStudio myMegaStudio; 
    MegaStudio myOtherMegaStudio;
 
}
