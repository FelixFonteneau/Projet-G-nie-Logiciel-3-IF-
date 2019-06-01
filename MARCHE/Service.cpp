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
/* int calculMoyenneLocalise() {}
// Algorithme :
//
//{
//} //----- Fin de Méthode

int qualiteAir() {}


 list<Capteur> capteursDefectueux() {
    list<Capteur> capteursDefectueux;
    for(Capteur c1 : capteurs) {
        if(capteursDefaillants(c)) {
                capteursDefectueux.add(c);
        }
    }
    return capteursDefectueux;
} */




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
