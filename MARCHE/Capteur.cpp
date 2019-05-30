/*************************************************************************
 Capteur  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode

void Capteur::addMesureO2(int jour, int mois, int annee, int heure, int minute, int seconde, double valeur, string typeMesure)
{
    Moment moment = Moment(jour, mois, annee, heure, minute, seconde);
    Mesure *mesure = new Mesure(valeur, moment, "", typeMesure, "");
    cout << "Mesure  : " << *mesure << endl;
    mesuresO2.push_back(mesure);
}

string Capteur::getDescription(){
	return description;
}

//------------------------------------------------- Surcharge d'opérateurs
// Capteur & Capteur::operator = ( const Capteur & unCapteur )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
// Capteur::Capteur ( const Capteur & unCapteur )
// Algorithme :
//
// {
// #ifdef MAP
//    cout << "Appel au constructeur de copie de <Xxx>" << endl;
// #endif
// } //----- Fin de Capteur (constructeur de copie)


Capteur::Capteur(const string idCapt, const double lat, const double lon, const string description) : idCapteur(idCapt), latitude(lat), longitude(lon), description(description)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Capteur>" << endl;
    #endif
} //----- Fin de Xxx


Capteur::~Capteur()
// Algorithme :
//
{
	for(unsigned int i = 0; i < mesuresO2.size() ; i++){
		delete mesuresO2[i];
	}
	for(unsigned int i = 0; i < mesuresNO2.size() ; i++){
		delete mesuresNO2[i];
	}
	for(unsigned int i = 0; i < mesuresSO2.size() ; i++){
		delete mesuresSO2[i];
	}
	for(unsigned int i = 0; i < mesuresPM10.size() ; i++){
		delete mesuresPM10[i];
	}
    #ifdef MAP
        cout << "Appel au destructeur de <Capteur>" << endl;
    #endif

} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
