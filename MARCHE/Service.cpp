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



void Service::capteursSimilaires() {

	double* coords = messages.recupererLocalisation();
	cout << coords[0] << "|" <<  coords[1] << endl;
	double radius = messages.recupererRadius();
	Moment* moments = messages.recupererIntervalleTemps();
	vector<Capteur*> capteurConcernes = algo.capteurTerritoire(capteurs,radius,coords);
	cout << "taille : " << capteurConcernes.size() << endl;
	vector<pair<Capteur,Capteur>> capteurCorreles;
	vector<vector<double>> moyennesCapteur;
	for(unsigned int i = 0; i < capteurConcernes.size() ; i++){
		vector<double> moy = algo.moyenneCapteur(*capteurConcernes[i],moments);
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
