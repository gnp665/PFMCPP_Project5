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
    PlaneWrapper( Plane* ptr );
    ~PlaneWrapper();

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
