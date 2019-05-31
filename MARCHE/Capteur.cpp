/*************************************************************************
 Capteur  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Capteur> (fichier Capteur.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Capteur.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Capteur::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
string Capteur::RecupererId() const
{
  return idCapteur;
}


void Capteur::AjouterMesure(Mesure & mesure)
{
    if(mesure.Type().compare("O3") == 0)
    {
      mesuresO3.push_back(mesure);

    }
    else if ( mesure.Type().compare("NO2") == 0)
    {
      mesuresNO2.push_back(mesure);

    }
    else if ( mesure.Type().compare("SO2") == 0)
    {
      mesuresSO2.push_back(mesure);

    }
    else if ( mesure.Type().compare("PM10") == 0)
    {
      mesuresPM10.push_back(mesure);
    }
    else
    {
      cerr << "Mesure : "<< mesure <<" ne rentre pas dans Capteur" << endl;
    }
}

string Capteur::getDescription()
{
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
//    cout << "Appel au constructeur de copie de <Capteur>" << endl;
// #endif
// } //----- Fin de Capteur (constructeur de copie)


Capteur::Capteur(const string idCapt, const double lat, const double lon, const string description) : idCapteur(idCapt), latitude(lat), longitude(lon), description(description)
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au constructeur de <Capteur>" << endl;
    #endif
} //----- Fin de Capteur


Capteur::~Capteur()
// Algorithme :
//
{
    #ifdef MAP
        cout << "Appel au destructeur de <Capteur>" << endl;
    #endif

} //----- Fin de ~Capteur


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
