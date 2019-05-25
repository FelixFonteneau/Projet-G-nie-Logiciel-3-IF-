/*************************************************************************
 Algo  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Algo> (fichier Algo.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Algo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
/*Mesure* moyenne(Moment intervaleTemps[2], double radius, double coordonees[2], list<Capteur> capteurs) {
    Mesure mesures[4];
    sumNO2 = 0;
    sumCO2 = 0;
    sumNO4 = 0;
    sumH1N1 = 0;
    for(Moment m : capteurs.getMoment()) {
        //if(c.getMesure().getMoment()) {
            sumNO2 += c.getMesures[1].getValue;
            //...
        //}
    }

    return mesures
}


double qualiteAir(list<Capteur> capteurs, double coordonees[2]) {
    //à compléter
}


list<Capteur> capteurTerritoire(list<Capteur> capteurs, double radius, double coordonees[2]) {
    list<Capteur> captTerritory;
    for(Capteur c : capteurs) {
        double dist = pow((c.getLatitude()-coordonees[0]),2)+pow(c.getLongitude()-coordonees[1], 2);
        if(dist < radius) {
            captTerritory.insert(captTerritory.end(), c);
        }
    }
    return captTerritory;
}

list<Capteur> capteurDefaillants(list<Capteur> capteurs) {
    list<Capteur> captDefaillants;
    for(Capteur c : capteurs) {
        for(Mesure m : c.getMesures()[0]) {
            if(m.value < 0){
                captDefaillants.insert(captDefaillants.end(), c);
            }
        }
        for(Mesure m : c.getMesures()[1]) {
            if(m.value < 0){
                captDefaillants.insert(captDefaillants.end(), c);
            }
        }
        for(Mesure m : c.getMesures()[2]) {
            if(m.value < 0){
                captDefaillants.insert(captDefaillants.end(), c);
            }
        }
        for(Mesure m : c.getMesures()[3]) {
            if(m.value < 0){
                captDefaillants.insert(captDefaillants.end(), c);
            }
        }
    }
    return captDefaillants;
}


bool similitude(Capteur c1, Capteur c2) {
    for(int i = 0; i < 3; i++) {

    }
}

double ecartTypeRelatif(list<Mesure> mesures) {
    return 4;
}

list<Capteur> capteursProches(double latitude, double  longitude, list<Capteur> capteurs) {
    return nullptr;
}*/
//------------------------------------------------- Surcharge d'opérateurs
// Algo & Algo::operator = ( const Algo & unAlgo )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Algo::Algo(const Algo & unAlgo)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Algo>" << endl;
#endif
} //----- Fin de Algo (constructeur de copie)


Algo::Algo()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Algo>" << endl;
#endif
} //----- Fin de Algo


Algo::~Algo()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Algo>" << endl;
#endif
} //----- Fin de ~Algo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

