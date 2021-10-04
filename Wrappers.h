#pragma once
#include "Car.h"
#include "Studio.h"
#include "Plane.h"
#include "Fleet.h"
#include "MegaStudio.h"

struct CarWrapper
{
    CarWrapper( Car* ptr );
    ~CarWrapper();
 
    Car* pointerToCar = nullptr;
};

struct StudioWrapper
{
    StudioWrapper( Studio* ptr );
    ~StudioWrapper();

    Studio* pointerToStudio = nullptr;
};

struct PlaneWrapper
{
    PlaneWrapper( Plane* ptr ) : pointerToPlane( ptr ) { }
    ~PlaneWrapper()
    {
        delete pointerToPlane;
    }

    Plane* pointerToPlane = nullptr;
};

struct FleetWrapper
{
    FleetWrapper( Fleet* ptr );
    ~FleetWrapper();

    Fleet* pointerToFleet = nullptr;
};

struct MegaStudioWrapper
{
    MegaStudioWrapper( MegaStudio* ptr );
    ~MegaStudioWrapper();

    MegaStudio* pointerToMegaStudio = nullptr;
};
