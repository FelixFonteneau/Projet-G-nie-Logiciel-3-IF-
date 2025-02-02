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



int main(int argc, char* argv[])
{
    Messages unMessage;
    if(argc < 5 && argc != 1)
    {
        unMessage.ErreurNbArguments();
    } else {
        string nomFichierDescription;
        string nomFichierDonnees;
        string nomCheminType;
        string utf8;
        if (argc == 1)
        {
          nomFichierDescription = "donnees/descriptionCapteurs.csv";
          nomFichierDonnees = "donnees/donneesCapteurs.csv";
          nomCheminType = "donnees/AttributeType.csv";
          utf8 = "N";
        }
        else
        {
          nomFichierDescription = (argv[1]);
          nomFichierDonnees = (argv[2]);
          nomCheminType = (argv[3]);
          utf8 = (argv[4]);
        }
        if(unMessage.VerifierEntree(nomFichierDescription,nomFichierDonnees, nomCheminType, utf8))
        {
            unMessage.Initialisation();
            Service* unService = new Service(nomFichierDescription,nomFichierDonnees, nomCheminType, utf8);
            int choix = unMessage.MessageMenu();
            while(choix!=7)
            {
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
                        unService->CapteursDefectueux();
                        break;
                    }
                    case 6:
                    {
                        vector<string> nomsFichiers = unMessage.RecupererNomsFichiers();
                        delete unService;
                        unService = new Service(nomsFichiers[0],nomsFichiers[1],nomsFichiers[2],nomsFichiers[3]);
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
            delete unService;
        }
        else 
        {
            unMessage.ErreurArguments();
        }

    }

    return 0;
}
