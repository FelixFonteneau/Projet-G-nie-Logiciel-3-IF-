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
#include <cmath>
#include <float.h>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Algo.h"
const double PI = 3.141592653589793238463;
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Algo::QualiteAir(vector<Capteur*>* capteurs, double* coordonees)
{
    double distanceMini = DBL_MAX;
    
    
    vector<MesureSO2>* MesuresSO2;
    vector<MesureO3>* MesuresO3;
    vector<MesurePM10>* MesuresPM10;
    vector<MesureNO2>* MesuresNO2;
    
    for (Capteur* capteur : *capteurs)
    {
        vector<double> coordsCapteur = capteur->getCoords();
        double distanceCourante = obtenirDistance(coordsCapteur, coordonees);
        if (distanceCourante < distanceMini)
        {
            distanceMini = distanceCourante;
            
            MesuresSO2 = (*capteur).RecupererMesuresSO2();
            MesuresO3 = (*capteur).RecupererMesuresO3();
            MesuresPM10 = (*capteur).RecupererMesuresPM10();
            MesuresNO2 = (*capteur).RecupererMesuresNO2();
        }
    }
    
    int derniereMesure = (*MesuresSO2).size() - 1;
    // cout << MesuresSO2->at(0) << endl;
    double atmo = calculAtmo(MesuresNO2->at(derniereMesure).Valeur(), MesuresO3->at(derniereMesure).Valeur(), MesuresPM10->at(derniereMesure).Valeur(), MesuresSO2->at(derniereMesure).Valeur());
    
    return atmo;
}

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
double Algo::enRadians(double latitude)
{
    return latitude * PI / 180;
}

double Algo::obtenirDistance(vector<double> coordonees1, double coordonees2[2])
{
    double lat1 = coordonees1[0];
    double lon1 = coordonees1[1];
    double lat2 = coordonees2[0];
    double lon2 = coordonees2[1];
    
    int R = 6371000; // metres
    double phi1 = enRadians(lat1);
    double phi2 = enRadians(lat2);
    double deltaPhi = enRadians(lat2-lat1);
    double deltaLambda = enRadians(lon2-lon1);
    
    double a = sin(deltaPhi/2) * sin(deltaPhi/2) + cos(phi1) * cos(phi2) * sin(deltaLambda/2) * sin(deltaLambda/2);
    double c = 2 * atan2(sqrt(a),sqrt(1-a));
    double d = R * c;
    return d;
}

int Algo::calculAtmo(double valeurNO2, double valeurO3, double valeurPM10, double valeurSO2)
{
    int atmoNO2;
    int atmoO3;
    int atmoPM10;
    int atmoSO2;
    
    if (0 <= valeurNO2 && valeurNO2 <= 29) {
        atmoNO2 = 1;
    } else if (30 <= valeurNO2 && valeurNO2 <= 54) {
        atmoNO2 = 2;
    } else if (55 <= valeurNO2 && valeurNO2 <= 84) {
        atmoNO2 = 3;
    } else if (85 <= valeurNO2 && valeurNO2 <= 109) {
        atmoNO2 = 4;
    } else if (110 <= valeurNO2 && valeurNO2 <= 134) {
        atmoNO2 = 5;
    } else if (135 <= valeurNO2 && valeurNO2 <= 164) {
        atmoNO2 = 6;
    } else if (165 <= valeurNO2 && valeurNO2 <= 199) {
        atmoNO2 = 7;
    } else if (200 <= valeurNO2 && valeurNO2 <= 274) {
        atmoNO2 = 8;
    } else if (275 <= valeurNO2 && valeurNO2 <= 399) {
        atmoNO2 = 9;
    } else atmoNO2 = 9;

    if (0 <= valeurO3 && valeurO3 <= 29) {
        atmoO3 = 1;
    } else if (30 <= valeurO3 && valeurO3 <= 54) {
        atmoO3 = 2;
    } else if (55 <= valeurO3 && valeurO3 <= 79) {
        atmoO3 = 3;
    } else if (80 <= valeurO3 && valeurO3 <= 104) {
        atmoO3 = 4;
    } else if (105 <= valeurO3 && valeurO3 <= 129) {
        atmoO3 = 5;
    } else if (130 <= valeurO3 && valeurO3 <= 149) {
        atmoO3 = 6;
    } else if (150 <= valeurO3 && valeurO3 <= 179) {
        atmoO3 = 7;
    } else if (180 <= valeurO3 && valeurO3 <= 209) {
        atmoO3 = 8;
    } else if (210 <= valeurO3 && valeurO3 <= 239) {
        atmoO3 = 9;
    } else atmoO3 = 10;

    if (0 <= valeurPM10 && valeurPM10 <= 6) {
        atmoPM10 = 1;
    } else if (7 <= valeurPM10 && valeurPM10 <= 13) {
        atmoPM10 = 2;
    } else if (14 <= valeurPM10 && valeurPM10 <= 20) {
        atmoPM10 = 3;
    } else if (21 <= valeurPM10 && valeurPM10 <= 27) {
        atmoPM10 = 4;
    } else if (28 <= valeurPM10 && valeurPM10 <= 34) {
        atmoPM10 = 5;
    } else if (35 <= valeurPM10 && valeurPM10 <= 41) {
        atmoPM10 = 6;
    } else if (42 <= valeurPM10 && valeurPM10 <= 49) {
        atmoPM10 = 7;
    } else if (50 <= valeurPM10 && valeurPM10 <= 64) {
        atmoPM10 = 8;
    } else if (65 <= valeurPM10 && valeurPM10 <= 79) {
        atmoPM10 = 9;
    } else atmoPM10 = 10;

    if (0 <= valeurSO2 && valeurSO2 <= 39) {
        atmoSO2 = 1;
    } else if (40 <= valeurSO2 && valeurSO2 <= 79) {
        atmoSO2 = 2;
    } else if (80 <= valeurSO2 && valeurSO2 <= 119) {
        atmoSO2 = 3;
    } else if (120 <= valeurSO2 && valeurSO2 <= 159) {
        atmoSO2 = 4;
    } else if (160 <= valeurSO2 && valeurSO2 <= 199) {
        atmoSO2 = 5;
    } else if (200 <= valeurSO2 && valeurSO2 <= 249) {
        atmoSO2 = 6;
    } else if (250 <= valeurSO2 && valeurSO2 <= 299) {
        atmoSO2 = 7;
    } else if (300 <= valeurSO2 && valeurSO2 <= 399) {
        atmoSO2 = 8;
    } else if (400 <= valeurSO2 && valeurSO2 <= 499) {
        atmoSO2 = 9;
    } else atmoSO2 = 10;

    return max(max(atmoNO2, atmoO3), max(atmoPM10, atmoSO2));
}
