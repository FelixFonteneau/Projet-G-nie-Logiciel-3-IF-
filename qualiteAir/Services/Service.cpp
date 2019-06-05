/*************************************************************************
 Service  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Service> (fichier Service.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Service.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Service::CalculMoyenneLocalise(int choix)
// Algorithme :
//
{
  vector<double> coords = messages.RecupererLocalisation();
  double radius = messages.RecupererRadius();

  vector<double> moyenne;
  //on fait le choix entre une durée et un instant
  if(choix==2)
  {
    vector<Moment> moments = messages.RecupererIntervalleTemps();
    moyenne = algo.MoyenneDuree(moments, radius, coords, capteurs);
  }
  else
  {
    Moment moment = messages.RecupererMoment();
    moyenne = algo.MoyenneInstant(moment, radius, coords, capteurs);
  }

  int atmo = algo.CalculAtmoMoyen(moyenne);

  messages.AfficherMoyenne(moyenne, atmo);
} //----- Fin de Méthode

void Service::QualiteAir()
{

    vector<double> coords = messages.RecupererLocalisation();
    vector<int> atmoInfos = algo.QualiteAir(capteurs, coords[0], coords[1]);
    messages.AfficherQualiteAir(atmoInfos);
}

void Service::CapteursSimilaires() {

	bool choixZone = messages.ChoixZone();
	vector<Capteur*> capteurConcernes;
	if(choixZone){
		vector<double> coords = messages.RecupererLocalisation();
		double radius = messages.RecupererRadius();
		capteurConcernes = algo.CapteurTerritoire(capteurs,radius,coords);
	} else {
		for(Capteur* c : *capteurs) {
            capteurConcernes.push_back(c);
        }
    }

	vector<Moment> moments = messages.RecupererIntervalleTemps();

    //On stockera ici les capteurs ayant des similitudes
	double** capteurCorreles = new double*[capteurConcernes.size()];
	for (unsigned int i = 0; i < capteurConcernes.size(); ++i){
		capteurCorreles[i] = new double[capteurConcernes.size()];
	}
	for (unsigned int i = 0; i < capteurConcernes.size() ; i++) {
		for (unsigned int j = 0; j < capteurConcernes.size();j++) {
			capteurCorreles[i][j]=0;
		}
	}
  capteurCorreles = algo.CalculCapteurCorreles(capteurCorreles, capteurConcernes, moments);
  messages.AfficherCapteursCorreles(capteurCorreles,capteurConcernes.size());

  //destruction de capteurCorreles
  for (unsigned int i = 0; i < capteurConcernes.size(); ++i){
    delete[] capteurCorreles[i];
  }
  delete[] capteurCorreles;
}

void Service::CapteursDefectueux() {
    vector<tuple<Capteur*, int, Moment>> capteursDefaillants = algo.CapteursDefaillants(*capteurs);
	messages.AfficherCapteursDefectueux(capteursDefaillants);
}


//-------------------------------------------- Constructeurs - destructeur
Service::Service(string nomFichierCapteur, string nomFichierDonnees,
                 string nomCheminType, string utf8)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
  // Messages messages;
  // Algo algo;
  // Factory factory;
  capteurs = factory.RecupererInfos(nomFichierCapteur, nomFichierDonnees, nomCheminType, utf8);
} //----- Fin de Service


Service::~Service()
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au destructeur de <Service>" << endl;
#endif
  //destruction des pointeurs vers capteurs
  for(Capteur* capteurPtr : *capteurs)
  {
    delete capteurPtr;
  }

  //destruction du vecteur
  delete capteurs;
} //----- Fin de ~Service


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
