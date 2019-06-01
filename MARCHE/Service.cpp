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
  Moment intervaleTemps[2];
  Moment m1 ("2010-01-01T00:01:20.609000");
  Moment m2 ("2020-01-01T00:01:20.6090000");
  intervaleTemps[0] = m2;
  intervaleTemps[1] = m1;

  for(double d : algo.moyenneCapteur(*( (*capteurs)[0] ), intervaleTemps ) )
  {
    cout << " moyenne :" << d <<endl;
  }
} //----- Fin de Méthode





void Service::qualiteAir()
{

    double* coords = messages.recupererLocalisation();
    double atmo = algo.QualiteAir(capteurs, coords[0], coords[1]);
    cout << atmo << endl;
}

//Necessaire pour insertion dans la multimap
bool operator< (const Capteur &c1, const Capteur &c2){
	return true;
}

void Service::capteursSimilaires() {

	double* coords = messages.recupererLocalisation();
	double radius = messages.recupererRadius();
	Moment* moments = messages.recupererIntervalleTemps();
	vector<Capteur*> capteurConcernes = algo.capteurTerritoire(*capteurs,radius,coords);
	multimap<Capteur,Capteur> capteurCorreles;
	for(unsigned int i = 0; i < capteurConcernes.size() ; i++){
		for(unsigned int j = i+1; j < capteurConcernes.size() ; j++){
			if(algo.similitude(*capteurConcernes[i],*capteurConcernes[j],moments)){

				capteurCorreles.insert({*capteurConcernes[i],*capteurConcernes[j]});
			}
		}
	}

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
