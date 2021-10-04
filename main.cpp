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

#include <iostream> 
#include "LeakedObjectDetector.h"
#include "Car.h"
#include "Studio.h"
#include "Plane.h"
#include "Fleet.h"
#include "MegaStudio.h"
#include "Wrappers.h"

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
