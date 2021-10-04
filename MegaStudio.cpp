#include "MegaStudio.h"

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
