#include <iostream>
#include <string.h>
#include <regex>
#include <vector>


using namespace std;


#include "../Modeles/Moment.h"
#include "../Modeles/Mesure.h"
#include "../Modeles/MesureNO2.h"
#include "../Modeles/MesureO3.h"
#include "../Modeles/MesureSO2.h"
#include "../Modeles/MesurePM10.h"
#include "../Modeles/Capteur.h"

#include "../Services/Service.h"

#include "../Util/Algo.h"
#include "../Util/Factory.h"
#include "../Util/Messages.h"



int main()
{
    Messages unMessage;
	unMessage.Initialisation(); 
    Service* unService = new Service("../donnees/descriptionCapteurs.csv","../donnees/donneesCapteurs.csv","N");
    int choix = unMessage.MessageMenu();
	while(choix!=7){
		switch (choix)
		{
			case 1:
			{
				unService->CalculMoyenneLocalise(choix);
				break;
			}
			case 2:
			{
				unService->CalculMoyenneLocalise(choix);
				break;
			}

			case 3:
			{
				unService->CapteursSimilaires();
				break;
			}
			case 4:
			{
				unService->QualiteAir();
				break;
			}
			case 5:
			{
				unService->CapteursDefaillants();
				break;
			}
			case 6:
			{
				vector<string> nomsFichiers = unMessage.RecupererNomsFichiers();
				delete unService;
				unService = new Service(nomsFichiers[0],nomsFichiers[1],nomsFichiers[2]);
				break;
			}
			default:
			{
				break;
			}
		}
		choix = unMessage.MessageMenu();
	}
	unMessage.Quitter();
    return 0;
}
