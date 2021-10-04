#include "Wrappers.h"

//----------------------------

CarWrapper::CarWrapper( Car* ptr ) : pointerToCar( ptr ) { }

CarWrapper::~CarWrapper()
{
    delete pointerToCar;
}

//----------------------------

StudioWrapper::StudioWrapper( Studio* ptr ) : pointerToStudio( ptr ) { }
StudioWrapper::~StudioWrapper()
{
    delete pointerToStudio;
}

//----------------------------

FleetWrapper::FleetWrapper( Fleet* ptr ) : pointerToFleet( ptr ) { }
FleetWrapper::~FleetWrapper()
{
    delete pointerToFleet;
}

//----------------------------

MegaStudioWrapper::MegaStudioWrapper( MegaStudio* ptr ) : pointerToMegaStudio( ptr ) { }
MegaStudioWrapper::~MegaStudioWrapper()
{
    delete pointerToMegaStudio;
}

