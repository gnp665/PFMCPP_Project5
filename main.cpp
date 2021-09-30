/*
 Project 5: Part 4 / 4
 video: Chapter 3 Part 7

 Create a branch named Part4
 
 Don't #include what you don't use
 
 1) Your task is to refactor your Chapter 3 Part 4 task into separate source and header files.
         Add files via the pane on the left.
 
 2) Put all of your declarations for each class in .h files
         One header file per class ( i.e. Raider.h for a class named "Raider" )
 
 3) Put all of your implementations in .cpp files.
         one cpp file per class ( i.e. Raider.cpp for a class named "Raider" )
 
 4) Put all of your Wrapper classes in a single Wrappers.h file
         if you implemented your wrapper class functions in-class, you'll need to move them to Wrappers.cpp
 
 5) NO IN-CLASS IMPLEMENTATION ALLOWED.
         the only exception is the existing Atomic.h and LeakedObjectDetector.h
 
 6) for every .cpp file you have to make, insert it into the .replit file after 'main.cpp'.  Don't forget the spaces between file names.
 If you need help with this step, send me a DM.
 
 7) click the [run] button.  Clear up any errors or warnings as best you can.
 
 Remember, your Chapter 3 Part 4 task worked when it was all in one file. so you shouldn't need to edit any of it.  
         just split it up into source files and provide the appropriate #include directives.
 */





/*
 UDT 1:
 */

#include <iostream> 
#include "LeakedObjectDetector.h"

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

    JUCE_LEAK_DETECTOR(Car)
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

struct CarWrapper
{
    CarWrapper( Car* ptr ) : pointerToCar( ptr ) { }
    ~CarWrapper()
    {
        delete pointerToCar;
    }

    Car* pointerToCar = nullptr;
};


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

    JUCE_LEAK_DETECTOR(Studio)
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

struct StudioWrapper
{
    StudioWrapper( Studio* ptr ) : pointerToStudio( ptr ) { }
    ~StudioWrapper()
    {
        delete pointerToStudio;
    }

    Studio* pointerToStudio = nullptr;
};


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

    JUCE_LEAK_DETECTOR(Plane)
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

struct PlaneWrapper
{
    PlaneWrapper( Plane* ptr ) : pointerToPlane( ptr ) { }
    ~PlaneWrapper()
    {
        delete pointerToPlane;
    }

    Plane* pointerToPlane = nullptr;
};


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

    JUCE_LEAK_DETECTOR(Fleet)
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

struct FleetWrapper
{
    FleetWrapper( Fleet* ptr ) : pointerToFleet( ptr ) { }
    ~FleetWrapper()
    {
        delete pointerToFleet;
    }

    Fleet* pointerToFleet = nullptr;
};

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

    JUCE_LEAK_DETECTOR(MegaStudio)
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

struct MegaStudioWrapper
{
    MegaStudioWrapper( MegaStudio* ptr ) : pointerToMegaStudio( ptr ) { }
    ~MegaStudioWrapper()
    {
        delete pointerToMegaStudio;
    }

    MegaStudio* pointerToMegaStudio = nullptr;
};


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
    CarWrapper myCar( new Car() );
    CarWrapper myOtherCar( new Car() );

    StudioWrapper myStudio( new Studio() );
    StudioWrapper myOtherStudio( new Studio() );

    PlaneWrapper myPlane( new Plane() );
    PlaneWrapper myOtherPlane( new Plane() );

    // Test two instances of UDT 1
    std::cout << std::endl << "Test Bench UDT 1 - Instance 1:" << std::endl;
    myCar.pointerToCar->hasBeenCleaned( myCar.pointerToCar->isClean );
    myCar.pointerToCar->checkTirePressure( myCar.pointerToCar->numWheels ); 
    myCar.pointerToCar->carEngine.hasEngineBeenStarted( myCar.pointerToCar->carEngine.isStarted );
    myCar.pointerToCar->carEngine.checkCylinderPressure( myCar.pointerToCar->carEngine.numCylinders );
    myCar.pointerToCar->carEngine.isEngineStatusGood( myCar.pointerToCar->carEngine.hasCoolant, myCar.pointerToCar->carEngine.hasNormalTemp, myCar.pointerToCar->carEngine.oilPressureIsGood );

    std::cout << "Total miles on full tank is " << myCar.pointerToCar->getMilesToEmpty( myCar.pointerToCar->gasTankSizeInGallons, myCar.pointerToCar->milesPerGallon ) << " miles" << std::endl; 
    myCar.pointerToCar->printInitialFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myCar.pointerToCar->getMilesToEmpty( myCar.pointerToCar->gasTankSizeInGallons, myCar.pointerToCar->milesPerGallon, myCar.pointerToCar->gasPercentFull ) << " miles" << std::endl; 
    myCar.pointerToCar->printInitialCurrentTankMiles(); // member function output of above 

    std::cout << std::endl << "Test Bench UDT 1 - Instance 2:" << std::endl;
    myCar.pointerToCar->hasBeenCleaned( false );
    myCar.pointerToCar->checkTirePressure( 4 ); 
    myCar.pointerToCar->carEngine.hasEngineBeenStarted( false );
    myCar.pointerToCar->carEngine.checkCylinderPressure( 6 );
    myCar.pointerToCar->carEngine.isEngineStatusGood( true, false, true );

    std::cout << "Total miles on full tank is " << myCar.pointerToCar->getMilesToEmpty(20, 20.0f) << " miles" << std::endl; 
    myCar.pointerToCar->printFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myCar.pointerToCar->getMilesToEmpty(20, 20.0f, 20.0f) << " miles" << std::endl;
    myCar.pointerToCar->printCurrentTankMiles(); // member function output of above 

   // Test two instances of UDT 2
    std::cout << std::endl << "Test Bench UDT 2 - Instance 1:" << std::endl;
    myStudio.pointerToStudio->checkEachMic( myStudio.pointerToStudio->numMics) ;

    std::cout << "Total number of mixes is " << myStudio.pointerToStudio->getTotalNumberOfMixes( myStudio.pointerToStudio->numClients, myStudio.pointerToStudio->mixesPerClient ) << std::endl;
    myStudio.pointerToStudio->printInitialNumberOfMixes(); // member function output of above 
    
    std::cout << "Total invoiced is " << myStudio.pointerToStudio->getTotalInvoiced( myStudio.pointerToStudio->numClients, myStudio.pointerToStudio->mixesPerClient, myStudio.pointerToStudio->hoursPerMix, myStudio.pointerToStudio->rate ) << " dollars" << std::endl; 
    myStudio.pointerToStudio->printInitialTotalInvoiced(); // member function output of above 
    
    std::cout << std::endl << "Test Bench UDT 2 - Instance 2:" << std::endl;
    myOtherStudio.pointerToStudio->checkEachMic( 4 );
    std::cout << "Total number of mixes is " << myOtherStudio.pointerToStudio->getTotalNumberOfMixes( 15, 1 ) << std::endl; 
    myOtherStudio.pointerToStudio->printNumberOfMixes(); // member function output of above 
    
    std::cout << "Total invoiced is " << myOtherStudio.pointerToStudio->getTotalInvoiced( 15, 1, 8, 20 ) << " dollars" << std::endl; 
    myOtherStudio.pointerToStudio->printTotalInvoiced(); // member function output of above 
    
   // Test two instances of UDT 3
    std::cout << std::endl << "Test Bench UDT 3 - Instance 1:" << std::endl;
    myPlane.pointerToPlane->hasBeenCleaned( myPlane.pointerToPlane->isClean );
    myPlane.pointerToPlane->checkTirePressure(myPlane.pointerToPlane->numWheels); 
    myPlane.pointerToPlane->planeEngine.hasEngineBeenStarted( myPlane.pointerToPlane->planeEngine.isStarted );
    myPlane.pointerToPlane->planeEngine.checkCylinderPressure( myPlane.pointerToPlane->planeEngine.numCylinders );
    myPlane.pointerToPlane->planeEngine.isEngineStatusGood( myPlane.pointerToPlane->planeEngine.hasCoolant, myPlane.pointerToPlane->planeEngine.hasNormalTemp, myPlane.pointerToPlane->planeEngine.oilPressureIsGood );

    std::cout << "Total miles on full tank is " << myPlane.pointerToPlane->getMilesToEmpty( myPlane.pointerToPlane->gasTankSizeInGallons, myPlane.pointerToPlane->milesPerGallon ) << " miles" << std::endl; 
    myPlane.pointerToPlane->printInitialFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myPlane.pointerToPlane->getMilesToEmpty( myPlane.pointerToPlane->gasTankSizeInGallons, myPlane.pointerToPlane->milesPerGallon, myPlane.pointerToPlane->gasPercentFull ) << " miles" << std::endl; 
    myPlane.pointerToPlane->printInitialCurrentTankMiles(); // member function output of above 

    std::cout << std::endl << "Test Bench UDT 3 - Instance 2:" << std::endl;
    myPlane.pointerToPlane->hasBeenCleaned( false );
    myPlane.pointerToPlane->checkTirePressure( 3 ); 
    myPlane.pointerToPlane->planeEngine.hasEngineBeenStarted( false );
    myPlane.pointerToPlane->planeEngine.checkCylinderPressure( 4 );
    myPlane.pointerToPlane->planeEngine.isEngineStatusGood( true, false, true );

    std::cout << "Total miles on full tank is " << myPlane.pointerToPlane->getMilesToEmpty( 500, 1.42f ) << " miles" << std::endl; 
    myPlane.pointerToPlane->printFullTankMiles(); // member function output of above 

    std::cout << "Total miles on current tank level " << myPlane.pointerToPlane->getMilesToEmpty( 500, 1.42f, 51.50f ) << " miles" << std::endl; 
    myPlane.pointerToPlane->printCurrentTankMiles(); // member function output of above 

    // Test two instances of UDT 4
    FleetWrapper myFleet( new Fleet() );
    FleetWrapper myOtherFleet( new Fleet() );
    std::cout << std::endl << "Test Bench UDT 4 - Instance 1:" << std::endl;
    myFleet.pointerToFleet->checkOnCar();
    myFleet.pointerToFleet->checkOnPlane();
    std::cout << std::endl << "Test Bench UDT 4 - Instance 2:" << std::endl;
    myOtherFleet.pointerToFleet->checkOnCar();
    myOtherFleet.pointerToFleet->checkOnPlane();

    // Test two instances of UDT 5
    MegaStudioWrapper myMegaStudio( new MegaStudio() );
    MegaStudioWrapper myOtherMegaStudio( new MegaStudio() );

    std::cout << std::endl << "Test Bench UDT 5 - Instance 1:" << std::endl;
    myMegaStudio.pointerToMegaStudio->checkOnRoomA();
    myMegaStudio.pointerToMegaStudio->checkOnRoomB();
    std::cout << std::endl << "Test Bench UDT 5 - Instance 2:" << std::endl;
    myOtherMegaStudio.pointerToMegaStudio->checkOnRoomA();
    myOtherMegaStudio.pointerToMegaStudio->checkOnRoomB();
}
