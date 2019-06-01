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

void capteursSimilaires() {   // Ébauche ! D'où le void -> à modifier
    //...
    for(Capteur c1 : capteurs) {
        for(Capteur c2 : capteurs) {
            if(similitude(c1, c2)) {
                //...
            }
        }
    }
}

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
    // cout << coords[0] << endl;
    double atmo = algo.QualiteAir(capteurs, coords[0], coords[1]);
    cout << atmo << endl;
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
