/*
Project 5: Part 2 / 4
 video: Chapter 3 Part 1

Create a branch named Part2

 The 'this' keyword
 
 The purpose of this project part is to show you how accessing member variables of objects INSIDE member functions is very similar to accessing member variables of objects OUTSIDE of member functions, via 'this->' and via the '.' operator.
 This project part will break the D.R.Y. rule, but that is fine for the purpose of this project part.
 
 
 1) if you don't have any std::cout statements in main() that access member variables of your U.D.Ts
         write some.
    You can copy some from your Project3's main() if needed.
 
 2) For each std::cout statement in main() that accessed member variables of your types or printed out the results of your member function calls,
        a) write a member function that prints the same thing out, but uses the proper techniques inside the member functions to access the same member variables/functions.
        b) be explicit with your use of 'this->' in those member functions so we see how you're accessing/calling those member variables and functions *inside*
        c) call that member function after your std::cout statement in main.
        d) you should see 2 (almost) identical messages in the program output for each member function you add:
            one for the std::cout line, and one for the member function's output
 
 
 3) After you finish, click the [run] button.  Clear up any errors or warnings as best you can.
 */

/*
 example:
 */
#include <iostream>
namespace Example
{
    //a User-Defined Type
    struct MyFoo
    {
        MyFoo() { std::cout << "creating MyFoo" << std::endl; }
        ~MyFoo() { std::cout << "destroying MyFoo" << std::endl; }
        
		// 2a) the member function whose function body is almost identical to the std::cout statement in main.
        void memberFunc() 
        { 
            // 2b) explicitly using 'this' inside this member function.
            std::cout << "MyFoo returnValue(): " << this->returnValue() << " and MyFoo memberVariable: " << this->memberVariable << std::endl; 
        }  
        
        int returnValue() { return 3; }
        float memberVariable = 3.14f;

        /*
        note: the example functions are implemented in-class, and the ctor/dtor show the curly braces on the same line as the function declaration.
        Do not do this.  Follow the instructions and coding style for the course.
        */
    };
    
    int main()
    {
        //an instance of the User-Defined Type named mf
        MyFoo mf;
        
        // 1) a std::cout statement that uses mf's member variables
        std::cout << "mf returnValue(): " << mf.returnValue() << " and mf memberVariable: " << mf.memberVariable << std::endl; 
        
        // 2c) calling mf's member function.  the member function's body is almost identical to the cout statement above.
        mf.memberFunc();
        return 0;
    }
}


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

bool Car::Engine::engineHasBeenStarted(bool isStarted_)
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

float Car::getMilesToEmpty(int gasTankSizeInGallons_, float milesPerGallon_, float gasPercentFull_ = 100.0f)
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

    void micCheck(int numMics);
    int totalNumberMixes(int numClients, int mixesPerClient);
    auto getTotalInvoiced(int numClients, int mixesPerClient, float hoursPerMix, float rate);
};

Studio::Studio() : numMics(8), numClients (10)
{
    hoursPerMix = 4.5f;
    mixesPerClient = 2;
}

void Studio::micCheck(int numMics_)
{
    int i = 1;
    while(i <= numMics_)
    {
        std::cout << "Mic number " << i << ": Signal has been checked" << std::endl;
        i++;
    }
}

int Studio::totalNumberMixes(int numClients_, int mixesPerClient_)
{
    return (numClients_ * mixesPerClient_);
}

auto Studio::getTotalInvoiced(int numClients_, int mixesPerClient_, float hoursPerMix_, float rate_)
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

bool Plane::Engine::engineHasBeenStarted(bool isStarted_)
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

float Plane::getMilesToEmpty(int gasTankSizeInGallons_, float milesPerGallon_, float gasPercentFull_ = 100.0f)
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
    roomA.micCheck(roomA.numMics);
    roomB.micCheck(4);
}

MegaStudio::~MegaStudio()
{
    std::cout << std::endl << "UDT 5 - Destructor for MegaStudio:" << std::endl;
    std::cout << "Total invoiced is " << roomA.getTotalInvoiced(roomA.numClients, roomA.mixesPerClient, roomA.hoursPerMix, roomA.rate) << " dollars" << std::endl;
    std::cout << "Total invoiced is " << roomB.getTotalInvoiced(15, 1, 8, 20) << " dollars" << std::endl << std::endl;
}

void MegaStudio::checkOnRoomA() 
{
    roomA.micCheck(roomA.numMics);
}

void MegaStudio::checkOnRoomB() 
{
    roomB.micCheck(roomB.numMics);
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
