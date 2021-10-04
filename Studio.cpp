#include "Studio.h"

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

void Studio::printInitialNumberOfMixes() 
{ 
    std::cout << "Total number of mixes is " << this->getTotalNumberOfMixes(this->numClients, this->mixesPerClient) << std::endl;  
}  

void Studio::printInitialTotalInvoiced() 
{  
    std::cout << "Total invoiced is " << this->getTotalInvoiced(this->numClients, this->mixesPerClient, this->hoursPerMix, this->rate) << " dollars" << std::endl;
}  

void Studio::printNumberOfMixes() 
{ 
    std::cout << "Total number of mixes is " << this->getTotalNumberOfMixes(this->numClients = 15, this->mixesPerClient = 1) << std::endl;  
}  

void Studio::printTotalInvoiced() 
{  
    std::cout << "Total invoiced is " << this->getTotalInvoiced(this->numClients = 15, this->mixesPerClient = 1, this->hoursPerMix = 8.0f, this->rate = 20.0f) << " dollars" << std::endl;
}  
