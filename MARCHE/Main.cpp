#include <iostream>
#include <string.h>
#include <regex>


using namespace std;


#include "Moment.h"
#include "Mesure.h"
#include "MesureNO2.h"
#include "MesureO3.h"
#include "MesureSO2.h"
#include "MesurePM10.h"

#include "Capteur.h"
#include "Service.h"
#include "Algo.h"
#include "Factory.h"
#include "Messages.h"



int main()
{
    Messages unMessage;
	unMessage.Initialisation(); 
    Service unService = Service();
    int choix = unMessage.MessageMenu();
	while(choix!=6){
		switch (choix)
		{
			case 1:
			{
				unService.CalculMoyenneLocalise(choix);
				break;
			}
			case 2:
			{
				unService.CalculMoyenneLocalise(choix);
				break;
			}

			case 3:
			{
				unService.CapteursSimilaires();
				break;
			}
			case 4:
			{
				unService.QualiteAir();
				break;
			}
			case 5:
			{
				unService.CapteursDefaillants();
				break;
			}
			case 6:
			{
				unMessage.Quitter();
				break;
			}
			default:
			{
				break;
			}
		}
		choix = unMessage.MessageMenu();
	}
    return 0;
}
