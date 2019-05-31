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
#define PI  3.141592653589793238463
#define earthRadiusKm 6371000.0
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

double Algo::QualiteAir(vector<Capteur*>* capteurs, double* coordonees)
{
    double distanceMini1 = DBL_MAX, distanceMini2 = DBL_MAX, distanceMini3 = DBL_MAX;
    
    vector<MesureSO2> *MesuresSO2Capt1, *MesuresSO2Capt2, *MesuresSO2Capt3;
    vector<MesureO3> *MesuresO3Capt1, *MesuresO3Capt2, *MesuresO3Capt3;
    vector<MesurePM10> *MesuresPM10Capt1, *MesuresPM10Capt2, *MesuresPM10Capt3;
    vector<MesureNO2> *MesuresNO2Capt1, *MesuresNO2Capt2, *MesuresNO2Capt3;
    
    for (Capteur* capteur : *capteurs)
    {
        vector<double> coordsCapteur = capteur->getCoords();
        double distanceCourante = obtenirDistance(coordsCapteur[0], coordsCapteur[1], coordonees[0], coordonees[1]);
        if (distanceCourante < distanceMini1)
        {
            distanceMini1 = distanceCourante;
            
            MesuresSO2Capt1 = (*capteur).RecupererMesuresSO2();
            MesuresO3Capt1 = (*capteur).RecupererMesuresO3();
            MesuresPM10Capt1 = (*capteur).RecupererMesuresPM10();
            MesuresNO2Capt1 = (*capteur).RecupererMesuresNO2();
        }
        if (distanceMini1 < distanceCourante && distanceCourante < distanceMini2)
        {
            distanceMini2 = distanceCourante;
            
            MesuresSO2Capt2 = (*capteur).RecupererMesuresSO2();
            MesuresO3Capt2 = (*capteur).RecupererMesuresO3();
            MesuresPM10Capt2 = (*capteur).RecupererMesuresPM10();
            MesuresNO2Capt2 = (*capteur).RecupererMesuresNO2();
        }
        if (distanceMini2 < distanceCourante && distanceCourante < distanceMini3)
        {
            distanceMini3 = distanceCourante;
            
            MesuresSO2Capt3 = (*capteur).RecupererMesuresSO2();
            MesuresO3Capt3 = (*capteur).RecupererMesuresO3();
            MesuresPM10Capt3 = (*capteur).RecupererMesuresPM10();
            MesuresNO2Capt3 = (*capteur).RecupererMesuresNO2();
        }
    }
    
  

    
    int derniereMesureCapt1 = (*MesuresSO2Capt1).size() - 1, derniereMesureCapt2 = (*MesuresSO2Capt2).size() - 1, derniereMesureCapt3 = (*MesuresSO2Capt3).size() - 1;
  
    
    int atmo = calculAtmoPondere(MesuresNO2Capt1->at(derniereMesureCapt1).Valeur(),
                                MesuresO3Capt1->at(derniereMesureCapt1).Valeur(),
                                MesuresPM10Capt1->at(derniereMesureCapt1).Valeur(),
                                MesuresSO2Capt1->at(derniereMesureCapt1).Valeur(),
                                    
                                MesuresNO2Capt2->at(derniereMesureCapt2).Valeur(),
                                MesuresO3Capt2->at(derniereMesureCapt2).Valeur(),
                                MesuresPM10Capt2->at(derniereMesureCapt2).Valeur(),
                                MesuresSO2Capt2->at(derniereMesureCapt2).Valeur(),
                                    
                                MesuresNO2Capt3->at(derniereMesureCapt3).Valeur(),
                                MesuresO3Capt3->at(derniereMesureCapt3).Valeur(),
                                MesuresPM10Capt3->at(derniereMesureCapt3).Valeur(),
                                MesuresSO2Capt3->at(derniereMesureCapt3).Valeur(),
                                
                                distanceMini1,
                                distanceMini2,
                                distanceMini3);
    
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

// retourne la distance en metres
double Algo::obtenirDistance(double lat1d, double lon1d, double lat2d, double lon2d)
{
    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = enRadians(lat1d);
    lon1r = enRadians(lon1d);
    lat2r = enRadians(lat2d);
    lon2r = enRadians(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * earthRadiusKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

int Algo::calculAtmoPondere(double valeurNO2Capt1, double valeurO3Capt1, double valeurPM10Capt1, double valeurSO2Capt1,
                            double valeurNO2Capt2, double valeurO3Capt2, double valeurPM10Capt2, double valeurSO2Capt2,
                            double valeurNO2Capt3, double valeurO3Capt3, double valeurPM10Capt3, double valeurSO2Capt3,
                            double distanceMini1, double distanceMini2, double distanceMini3)
{
    int atmoNO2, atmoO3, atmoPM10, atmoSO2;
    double somme = distanceMini1 + distanceMini2 + distanceMini3;
    string NO2 = "NO2", O3 = "O3", PM10 = "PM10", SO2 = "SO2";
    
    atmoNO2 = distanceMini1*calculAtmo(valeurNO2Capt1, NO2) + distanceMini2*calculAtmo(valeurNO2Capt2, NO2) +distanceMini3*calculAtmo(valeurNO2Capt3, NO2);
    atmoNO2 /= somme;
    
    atmoO3 = distanceMini1*calculAtmo(valeurO3Capt1, O3) + distanceMini2*calculAtmo(valeurO3Capt2, O3) + distanceMini3*calculAtmo(valeurO3Capt3, O3);
    atmoO3 /= somme;
    
    atmoPM10 = distanceMini1*calculAtmo(valeurPM10Capt1, PM10) + distanceMini2*calculAtmo(valeurPM10Capt2, PM10) + distanceMini3*calculAtmo(valeurPM10Capt3, PM10);
    atmoPM10 /= somme;
    
    atmoSO2 = distanceMini1*calculAtmo(valeurSO2Capt1, SO2) + distanceMini2*calculAtmo(valeurSO2Capt2, SO2) + distanceMini3*calculAtmo(valeurSO2Capt3, SO2);
    atmoSO2 /= somme;
    
    cout << distanceMini1 << " " << distanceMini2 << " " << distanceMini3 << endl;
    // Incohérent : quand je mets les coordonnées exates du premier capteur, la distance mini est bien trop élevée
    
    return max(max(atmoNO2,atmoO3), max(atmoPM10,atmoSO2));
    
}

int Algo::calculAtmo(double valeur, string type)
{
    string NO2 ="NO2";
    int result = 0;
    if (type.compare(NO2) == 0)
    {
        if (0 <= valeur && valeur <= 29) {
            result = 1;
        } else if (30 <= valeur && valeur <= 54) {
            result = 2;
        } else if (55 <= valeur && valeur <= 84) {
            result = 3;
        } else if (85 <= valeur && valeur <= 109) {
            result = 4;
        } else if (110 <= valeur && valeur <= 134) {
            result = 5;
        } else if (135 <= valeur && valeur <= 164) {
            result = 6;
        } else if (165 <= valeur && valeur <= 199) {
            result = 7;
        } else if (200 <= valeur && valeur <= 274) {
            result = 8;
        } else if (275 <= valeur && valeur <= 399) {
            result = 9;
        } else result = 10;
    }
    else if (type.compare("O3") == 0)
    {
        if (0 <= valeur && valeur <= 29) {
            result = 1;
        } else if (30 <= valeur && valeur <= 54) {
            result = 2;
        } else if (55 <= valeur && valeur <= 79) {
            result = 3;
        } else if (80 <= valeur && valeur <= 104) {
            result = 4;
        } else if (105 <= valeur && valeur <= 129) {
            result = 5;
        } else if (130 <= valeur && valeur <= 149) {
            result = 6;
        } else if (150 <= valeur && valeur <= 179) {
            result = 7;
        } else if (180 <= valeur && valeur <= 209) {
            result = 8;
        } else if (210 <= valeur && valeur <= 239) {
            result = 9;
        } else result = 10;
    }
    else if (type.compare("PM10") == 0)
    {
        if (0 <= valeur && valeur <= 6) {
            result = 1;
        } else if (7 <= valeur && valeur <= 13) {
            result = 2;
        } else if (14 <= valeur && valeur <= 20) {
            result = 3;
        } else if (21 <= valeur && valeur <= 27) {
            result = 4;
        } else if (28 <= valeur && valeur <= 34) {
            result = 5;
        } else if (35 <= valeur && valeur <= 41) {
            result = 6;
        } else if (42 <= valeur && valeur <= 49) {
            result = 7;
        } else if (50 <= valeur && valeur <= 64) {
            result = 8;
        } else if (65 <= valeur && valeur <= 79) {
            result = 9;
        } else result = 10;
    }
    else if (type.compare("SO2") == 0)
    {
        if (0 <= valeur && valeur <= 39) {
            result = 1;
        } else if (40 <= valeur && valeur <= 79) {
            result = 2;
        } else if (80 <= valeur && valeur <= 119) {
            result = 3;
        } else if (120 <= valeur && valeur <= 159) {
            result = 4;
        } else if (160 <= valeur && valeur <= 199) {
            result = 5;
        } else if (200 <= valeur && valeur <= 249) {
            result = 6;
        } else if (250 <= valeur && valeur <= 299) {
            result = 7;
        } else if (300 <= valeur && valeur <= 399) {
            result = 8;
        } else if (400 <= valeur && valeur <= 499) {
            result = 9;
        } else result = 10;
    }
    return result;
}
                            
