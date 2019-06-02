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

	bool choixZone = messages.choixZone();
	vector<Capteur*> capteurConcernes;
	if(choixZone){
		vector<double> coords = messages.recupererLocalisation();
		double radius = messages.recupererRadius();
		capteurConcernes = algo.capteurTerritoire(capteurs,radius,coords);
	} else {
		for(Capteur* c : *capteurs) {
            capteurConcernes.push_back(c);
        }
		
    }
	vector<Moment> moments = messages.recupererIntervalleTemps();
	//On stockera ici les capteurs ayant des similitudes
	
	double** capteurCorreles = new double*[capteurConcernes.size()];
	for(unsigned int i = 0; i < capteurConcernes.size(); ++i){
		capteurCorreles[i] = new double[capteurConcernes.size()];
	}
	for(unsigned int i = 0; i < capteurConcernes.size() ; i++) {
		for(unsigned int j = 0; j < capteurConcernes.size();j++){
			capteurCorreles[i][j]=0;
		}
	}
	
	//Calcul des similitudes entre capteurs
	for(unsigned int i = 0; i < capteurConcernes.size() ; i++){
		for(unsigned int j = i+1; j < capteurConcernes.size() ; j++){
			double similitude = algo.similitude(capteurConcernes[i],capteurConcernes[j],moments);
			capteurCorreles[i][j]=similitude;
		}
	}
	
	//Uniformisation de 0 à 100%
	
	//Determination du min et max
	double min = pow(10,9);
	double max = 0;
	for(unsigned int i = 0; i< capteurConcernes.size(); i++){
		for(unsigned int j = i+1; j < capteurConcernes.size() ; j++){
			double val = capteurCorreles[i][j];
			if(val<min && val != -1){
				min = val;
			}
			if (val>max){
				max = val;
			}
		}
	}
	//Uniformisation
	for(unsigned int i = 0; i< capteurConcernes.size(); i++){
		for(unsigned int j = i+1; j < capteurConcernes.size() ; j++){
			double val = capteurCorreles[i][j];
			if(val == -1){
				val = 0;
			} else {
				capteurCorreles[i][j] = 100 - ((capteurCorreles[i][j] - min)/(max-min) * 100);
			}
		}
	}
	
	
	messages.afficherCapteursCorreles(capteurCorreles,capteurConcernes.size());

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
