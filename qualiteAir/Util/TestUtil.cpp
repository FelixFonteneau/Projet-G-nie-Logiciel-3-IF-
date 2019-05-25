#include <iostream>


using namespace std;

#include "../Modeles/Mesure.h"
#include "../Modeles/MesureNO2.h"
#include "../Modeles/MesureO2.h"
#include "../Modeles/MesureSO2.h"
#include "../Modeles/MesurePM10.h"
#include "../Modeles/Moment.h"
#include "../Modeles/Capteur.h"
#include "../Services/Service.h"
#include "../Util/Algo.h"
#include "../Util/Factory.h"
#include "../Util/Messages.h"

void testAlgo()
{
    
}

void testFactory()
{
    
}

void testMessages()
{
    Messages unMessage;
    unMessage.recupererIntervalleTemps();
}

int main()
{
    testMessages();
    return 0;
}

