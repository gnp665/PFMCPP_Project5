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
   
    //Nested UDT 1 of 2:   
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

        void engineMemberFunc1() 
        { 
            this->engineHasBeenStarted(this->isStarted);  
        }  

        void engineMemberFunc2() 
        { 
            this->checkCylinderPressure(this->numCylinders);  
        }  

        void engineMemberFunc3() 
        { 
            this->isEngineStatusGood(this->hasCoolant, this->hasNormalTemp, this->oilPressureIsGood);  
        }  

    };

    Engine carEngine;

    Car();

    bool hasBeenCleaned(bool isClean);
    void checkTirePressure(int numWheels);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull = 100.0f);

    void carMemberFunc1() 
    { 
        this->hasBeenCleaned(this->isClean);  
    }  

    void carMemberFunc2() 
    { 
        this->checkTirePressure(this->numWheels);  
    }  

    void carMemberFunc3() 
    { 
        this->carEngine.engineMemberFunc1();  
    }  

    void carMemberFunc4() 
    { 
        this->carEngine.engineMemberFunc2();  
    }  

    void carMemberFunc5() 
    { 
        this->carEngine.engineMemberFunc3();  
    }  

    void carMemberFunc6() 
    { 
        std::cout << "Total miles on full tank is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon) << " miles" << std::endl;  
    }  

    void carMemberFunc7() 
    { 
        std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon, this->gasPercentFull) << " miles" << std::endl;  
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

bool Car::Engine::engineHasBeenStarted(bool isStarted_)
{
    if(isStarted_)
    {
        std::cout << "The car has been started" << std::endl;
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

    void micCheck(int numMics);
    int totalNumberMixes(int numClients, int mixesPerClient);
    float getTotalInvoiced(int numClients, int mixesPerClient, float hoursPerMix, float rate);

    void studioMemberFunc1() 
    { 
        this->micCheck(this->numMics);  
    }  

    void studioMemberFunc2() 
    { 
        std::cout << "Total number of mixes is " << this->totalNumberMixes(this->numClients, this->mixesPerClient) << std::endl;  
    }  

    void studioMemberFunc3() 
    {  
        std::cout << "Total invoiced is " << this->getTotalInvoiced(this->numClients, this->mixesPerClient, this->hoursPerMix, this->rate) << " dollars" << std::endl;
    }  


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
   
    //Nested UDT 2 of 2:   
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

        void engineMemberFunc1() 
        { 
            this->engineHasBeenStarted(this->isStarted);  
        }  

        void engineMemberFunc2() 
        { 
            this->checkCylinderPressure(this->numCylinders);  
        }  

        void engineMemberFunc3() 
        { 
            this->isEngineStatusGood(this->hasCoolant, this->hasNormalTemp, this->oilPressureIsGood);  
        }  

    };

    Engine planeEngine;

    Plane();

    bool hasBeenCleaned(bool isClean);
    void checkTirePressure(int numWheels);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull = 100.0f);

    void planeMemberFunc1() 
    { 
        this->hasBeenCleaned(this->isClean);  
    }  

    void planeMemberFunc2() 
    { 
        this->checkTirePressure(this->numWheels);  
    }  

    void planeMemberFunc3() 
    { 
        this->planeEngine.engineMemberFunc1();  
    }  

    void planeMemberFunc4() 
    { 
        this->planeEngine.engineMemberFunc2();  
    }  

    void planeMemberFunc5() 
    { 
        this->planeEngine.engineMemberFunc3();  
    }  

    void planeMemberFunc6() 
    { 
        std::cout << "Total miles on full tank is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon) << " miles" << std::endl;  
    }  

    void planeMemberFunc7() 
    { 
        std::cout << "Total miles on current tank level is " << this->getMilesToEmpty(this->gasTankSizeInGallons, this->milesPerGallon, this->gasPercentFull) << " miles" << std::endl;  
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

bool Plane::Engine::engineHasBeenStarted(bool isStarted_)
{
    if(isStarted_)
    {
        std::cout << "The plane has been started" << std::endl;
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

    void fleetMemberFunc1()
    {
        this->checkOnCar();
    }

    void fleetMemberFunc2()
    {
        this->checkOnPlane();
    }

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
    std::cout << "Total miles on current tank level is " << myRedCar.getMilesToEmpty(myRedCar.gasTankSizeInGallons, myRedCar.milesPerGallon, myRedCar.gasPercentFull) << " miles" << std::endl;
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

    void memberFunc1()
    {
        this->checkOnRoomA();
    }

    void memberFunc2()
    {
        this->checkOnRoomB();
    }

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
    myCar.carMemberFunc1(); // "this" version output of above (1 of 41)

    myCar.checkTirePressure(myCar.numWheels); 
    myCar.carMemberFunc2(); // "this" version output of above (2 of 41)

    myCar.carEngine.engineHasBeenStarted(myCar.carEngine.isStarted);
    myCar.carMemberFunc3(); // "this" version of above (3 of 41)

    myCar.carEngine.checkCylinderPressure(myCar.carEngine.numCylinders);
    myCar.carMemberFunc4(); // "this" version output of above (4 of 41)

    myCar.carEngine.isEngineStatusGood(myCar.carEngine.hasCoolant, myCar.carEngine.hasNormalTemp, myCar.carEngine.oilPressureIsGood);
    myCar.carMemberFunc5(); // "this" version output of above (5 of 41)

    std::cout << "Total miles on full tank is " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon) << " miles" << std::endl;
    myCar.carMemberFunc6(); // "this" version output of above (6 of 41)

    std::cout << "Total miles on current tank level " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon, myCar.gasPercentFull) << " miles" << std::endl;
    myCar.carMemberFunc7(); // "this" version output of above (7 of 41)

    std::cout << std::endl << "Test Bench UDT 1 - Instance 2:" << std::endl;
    myOtherCar.hasBeenCleaned(false);
    myOtherCar.isClean = false;
    myOtherCar.carMemberFunc1(); // "this" version output of above (8 of 41)

    myOtherCar.checkTirePressure(4); 
    myOtherCar.carMemberFunc2(); // "this" version output of above (9 of 41)

    myOtherCar.carEngine.engineHasBeenStarted(false);
    myOtherCar.carEngine.isStarted = false;
    myOtherCar.carMemberFunc3(); // "this" version output of above (10 of 41)
    
    myOtherCar.carEngine.checkCylinderPressure(6);
    myOtherCar.carEngine.numCylinders = 6;
    myOtherCar.carMemberFunc4(); // "this" version output of above (11 of 41)

    myOtherCar.carEngine.isEngineStatusGood(true, false, true);
    myOtherCar.carEngine.hasNormalTemp = false;
    myOtherCar.carMemberFunc5(); // "this" version output of above (12 of 41)

    std::cout << "Total miles on full tank is " << myOtherCar.getMilesToEmpty(20, 20.0f) << " miles" << std::endl;
    myOtherCar.gasTankSizeInGallons = 20; 
    myOtherCar.milesPerGallon = 20.0f;
    myOtherCar.carMemberFunc6(); // "this" version output of above (12 of 41)

    std::cout << "Total miles on current tank level is " << myOtherCar.getMilesToEmpty(20, 20.0f, 20.0f) << " miles" << std::endl;
    myOtherCar.gasPercentFull = 20.0f;
    myOtherCar.carMemberFunc7(); // "this" version output of above (13 of 41)


   // Test two instances of UDT 2
    std::cout << std::endl << "Test Bench UDT 2 - Instance 1:" << std::endl;
    myStudio.micCheck(myStudio.numMics);
    myStudio.studioMemberFunc1(); // "this" version output of above (14 of 41)

    std::cout << "Total number of mixes is " << myStudio.totalNumberMixes(myStudio.numClients, myStudio.mixesPerClient) << std::endl;
    myStudio.studioMemberFunc2(); // "this" version output of above (15 of 41)

    std::cout << "Total invoiced is " << myStudio.getTotalInvoiced(myStudio.numClients, myStudio.mixesPerClient, myStudio.hoursPerMix, myStudio.rate) << " dollars" << std::endl;
    myStudio.studioMemberFunc3(); // "this" version output of above (16 of 41)

    std::cout << std::endl << "Test Bench UDT 2 - Instance 2:" << std::endl;
    myOtherStudio.micCheck(4);
    myOtherStudio.numMics = 4;
    myOtherStudio.studioMemberFunc1(); // "this" version output of above (17 of 41)

    std::cout << "Total number of mixes is " << myOtherStudio.totalNumberMixes(15, 1) << std::endl;
    myOtherStudio.numClients = 15;
    myOtherStudio.mixesPerClient = 1;
    myOtherStudio.studioMemberFunc2(); // "this" version output of above (18 of 41)

    std::cout << "Total invoiced is " << myOtherStudio.getTotalInvoiced(15, 1, 8.0f, 20.0f) << " dollars" << std::endl;
    myOtherStudio.hoursPerMix = 8.0f;
    myOtherStudio.rate = 20.0f;
    myOtherStudio.studioMemberFunc3(); // "this" version output of above (19 of 41)


   // Test two instances of UDT 3
    std::cout << std::endl << "Test Bench UDT 3 - Instance 1:" << std::endl;
    myPlane.hasBeenCleaned(myPlane.isClean);
    myPlane.planeMemberFunc1(); // "this" version output of above (20 of 41)

    myPlane.checkTirePressure(myPlane.numWheels); 
    myPlane.planeMemberFunc2(); // "this" version output of above (21 of 41)

    myPlane.planeEngine.engineHasBeenStarted(myPlane.planeEngine.isStarted);
    myPlane.planeMemberFunc3(); // "this" version output of above (22 of 41)

    myPlane.planeEngine.checkCylinderPressure(myPlane.planeEngine.numCylinders);
    myPlane.planeMemberFunc4(); // "this" version output of above (23 of 41)

    myPlane.planeEngine.isEngineStatusGood(myPlane.planeEngine.hasCoolant, myPlane.planeEngine.hasNormalTemp, myPlane.planeEngine.oilPressureIsGood);
    myPlane.planeMemberFunc5(); // "this" version output of above (24 of 41)

    std::cout << "Total miles on full tank is " << myPlane.getMilesToEmpty(myPlane.gasTankSizeInGallons, myPlane.milesPerGallon) << " miles" << std::endl;
    myPlane.planeMemberFunc6(); // "this" version output of above (25 of 41)

    std::cout << "Total miles on current tank level is " << myPlane.getMilesToEmpty(myPlane.gasTankSizeInGallons, myPlane.milesPerGallon, myPlane.gasPercentFull) << " miles" << std::endl;
    myPlane.planeMemberFunc7(); // "this" version output of above (26 of 41)

    std::cout << std::endl << "Test Bench UDT 3 - Instance 2:" << std::endl;
    myOtherPlane.hasBeenCleaned(false);
    myOtherPlane.isClean = false;
    myOtherPlane.planeMemberFunc1(); // "this" version output of above (27 of 41)

    myOtherPlane.checkTirePressure(3); 
    myOtherPlane.planeMemberFunc2(); // "this" version output of above (28 of 41)

    myOtherPlane.planeEngine.engineHasBeenStarted(false);
    myOtherPlane.planeEngine.isStarted = false;
    myOtherPlane.planeMemberFunc3(); // "this" version output of above (29 of 41)

    myOtherPlane.planeEngine.checkCylinderPressure(4);
    myOtherPlane.planeMemberFunc4(); // "this" version output of above (30 of 41)

    myOtherPlane.planeEngine.isEngineStatusGood(true, false, true);
    myOtherPlane.planeEngine.hasNormalTemp = false;
    myOtherPlane.planeMemberFunc5(); // "this" version output of above (31 of 41)

    std::cout << "Total miles on full tank is " << myOtherPlane.getMilesToEmpty(500, 1.42f) << " miles" << std::endl;
    myOtherPlane.gasTankSizeInGallons = 500; 
    myOtherPlane.milesPerGallon = 1.42f;
    myOtherPlane.planeMemberFunc6(); // "this" version output of above (32 of 41)

    std::cout << "Total miles on current tank level " << myOtherPlane.getMilesToEmpty(500, 1.42f, 51.50f) << " miles" << std::endl;
    myOtherPlane.gasPercentFull = 51.50f;
    myOtherPlane.planeMemberFunc7(); // "this" version output of above (33 of 41)


    // Test two instances of UDT 4
    Fleet myFleet; 
    Fleet myOtherFleet;

    std::cout << std::endl << "Test Bench UDT 4 - Instance 1:" << std::endl;
    myFleet.checkOnCar();
    myFleet.fleetMemberFunc1(); // "this" version output of above (34 of 41)

    myFleet.checkOnPlane();
    myFleet.fleetMemberFunc2(); // "this" version output of above (35 of 41)

    std::cout << std::endl << "Test Bench UDT 4 - Instance 2:" << std::endl;
    myOtherFleet.checkOnCar();
    myOtherFleet.fleetMemberFunc1(); // "this" version output of above (36 of 41)
    
    myOtherFleet.checkOnPlane();
    myOtherFleet.fleetMemberFunc2(); // "this" version output of above (37 of 41)


    // Test two instances of UDT 5
    MegaStudio myMegaStudio; 
    MegaStudio myOtherMegaStudio;

    std::cout << std::endl << "Test Bench UDT 5 - Instance 1:" << std::endl;
    myMegaStudio.checkOnRoomA();
    myMegaStudio.memberFunc1(); // "this" version output of above (38 of 41)

    myMegaStudio.checkOnRoomB();
    myMegaStudio.memberFunc2(); // "this" version output of above (39 of 41)

    std::cout << std::endl << "Test Bench UDT 5 - Instance 2:" << std::endl;
    myOtherMegaStudio.checkOnRoomA();
    myOtherMegaStudio.memberFunc1(); // "this" version output of above (40 of 41)

    myOtherMegaStudio.checkOnRoomB();
    myOtherMegaStudio.memberFunc2(); // "this" version output of above (41 of 41)
}
