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
    bool isClean = false;

    Car();

    void checkTirePressure(int numWheels);
    bool carHasBeenCleaned(bool isClean);
    float getMilesToEmpty(int gasTankSizeInGallons, float milesPerGallon, float gasPercentFull);
};

Car::Car() : numWheels(4), gasTankSizeInGallons (20)
{
    milesPerGallon = 23.4f;
    gasPercentFull = 69.2f;
}

bool Car::carHasBeenCleaned(bool isClean)
{
    if(isClean)
    {
        std::cout << "The car is already clean!" << std::endl;
        return false;
    }

    std::cout << "The car has been cleaned!" << std::endl;
    return true;
}

void Car::checkTirePressure(int numWheels)
{
    for (int i = 1; i <= numWheels; ++i)
        std::cout << "Tire number " << i << ": Pressure has been checked" << std::endl;
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

/*
 new UDT 4:
 */

/*
 new UDT 5:
 */

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

    // Test Bench UDT 2 - Instance 1:
    myStudio.micCheck(myStudio.numMics);
    std::cout << "Total number of mixes is " << myStudio.totalNumberMixes(myStudio.numClients, myStudio.mixesPerClient) << std::endl;
    std::cout << "Total invoiced is " << myStudio.getTotalInvoiced(myStudio.numClients, myStudio.mixesPerClient, myStudio.hoursPerMix, myStudio.rate) << " dollars" << std::endl;

    // Test Bench UDT 2 - Instance 2:
    myOtherStudio.micCheck(4);
    std::cout << "Total number of mixes is " << myOtherStudio.totalNumberMixes(15, 1) << std::endl;
    std::cout << "Total invoiced is " << myOtherStudio.getTotalInvoiced(15, 1, 8, 20) << " dollars" << std::endl;
    
    #if 0
    // Test Bench UDT 1 - Instance 1:
    myCar.carHasBeenCleaned(myCar.isClean);
    myCar.checkTirePressure(myCar.numWheels);   
    std::cout << "Total miles on full tank is " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon) << " miles" << std::endl;
    std::cout << "Total miles on current tank level " << myCar.getMilesToEmpty(myCar.gasTankSizeInGallons, myCar.milesPerGallon, myCar.gasPercentFull) << " miles" << std::endl;

    // Test Bench UDT 1 - Instance 2:
    myOtherCar.carHasBeenCleaned(true);
    myOtherCar.checkTirePressure(myOtherCar.numWheels);
    std::cout << "Total miles on full tank is " << myOtherCar.getMilesToEmpty(20, 20.0f) << " miles" << std::endl;
    std::cout << "Total miles on current tank is " << myOtherCar.getMilesToEmpty(20, 20.0f, 50.0f) << " miles" << std::endl;
    
    #endif

    std::cout << "good to go!" << std::endl;
}
