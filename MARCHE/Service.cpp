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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Service.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Service::CalculMoyenneLocalise()
// Algorithme :
//
{
  vector<double> coords = messages.recupererLocalisation();
  double radius = messages.recupererRadius();
  vector<Moment> moments = messages.recupererIntervalleTemps();
  vector<double> moyenne = algo.Moyenne(moments, radius, coords, capteurs );
} //----- Fin de Méthode





void Service::qualiteAir()
{

    vector<double> coords = messages.recupererLocalisation();
    double atmo = algo.QualiteAir(capteurs, coords[0], coords[1]);
    cout << atmo << endl;
}



void Service::capteursSimilaires() {

	vector<double> coords = messages.recupererLocalisation();
	double radius = messages.recupererRadius();
	vector<Moment> moments = messages.recupererIntervalleTemps();
	vector<Capteur*> capteurConcernes = algo.capteurTerritoire(capteurs,radius,coords);
	vector<pair<Capteur,Capteur>> capteurCorreles;
	vector<vector<double>> moyennesCapteur;
	for(unsigned int i = 0; i < capteurConcernes.size() ; i++){
		vector<double> moy = algo.moyenneCapteur(capteurConcernes[i],moments);
		if(moy[0] != -1 && moy[1]!=-1 && moy[2]!=-1 && moy[3]!=-1){
			moyennesCapteur.push_back(moy);
		} else {
			capteurConcernes.erase(capteurConcernes.begin() + i);
			if(i!=capteurConcernes.size() - 1){
				i--;
			}
		}
	}
	for(unsigned int i = 0; i < capteurConcernes.size() ; i++){
		for(unsigned int j = i+1; j < capteurConcernes.size() ; j++){
			if(algo.similitude(moyennesCapteur[i],moyennesCapteur[j])){
				capteurCorreles.push_back({*capteurConcernes[i],*capteurConcernes[j]});
			}
		}
	}
	messages.afficherCapteursCorreles(capteurCorreles);

}

void Service::capteursDefaillants() {
	messages.afficherCapteursDefaillants(algo.CapteursDefaillants(*capteurs));
}
//------------------------------------------------- Surcharge d'opérateurs
// Service & Service::operator = ( const Service & unXxx )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Service::Service()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Service>" << endl;
#endif
  // Messages messages;
  // Algo algo;
  // Factory factory;
  capteurs = factory.AnalyserMesure();

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
