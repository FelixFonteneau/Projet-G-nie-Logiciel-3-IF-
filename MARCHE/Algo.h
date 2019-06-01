/*************************************************************************
 Algo  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Algo> (fichier Algo.h) ----------------
#if ! defined ( ALGO_H )
#define ALGO_H

//--------------------------------------------------- Interfaces utilisées

#include "Capteur.h"
#include "Moment.h"
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <vector>
#include <list>

//------------------------------------------------------------------------
// Rôle de la classe <Algo>
//
//
//------------------------------------------------------------------------

class Algo
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    vector<double> Moyenne(vector<Moment> intervaleTemps, double radius, vector<double> coordonees, vector<Capteur*>* capteurs);
    // Mode d'emploi :
    // Prend tous les capteurs dans la zone et un interval de temps
    //  retourne la moyenne des mesures sous forme de tableau de Double.
    // L'ordre est O3/NO2/SO2/PM10.
    // Si il n'y a aucune mesure, elle retourne -1 dans la case du tableau.
    //
    // Contrat :
    //

    double QualiteAir(vector<Capteur*>* capteurs, double latitude, double longitude);

    vector<Capteur*> capteurTerritoire(vector<Capteur*>* capteurs, double radius, vector<double> coordonees);

    vector<Capteur*> CapteursDefaillants(vector<Capteur*> capteurs);
  	// Mode d'emploi :
  	//
  	//	Prend une liste de capteurs en paramètre et la parcours afin de
  	//	trouver si certains capteurs ont des données improbables.
    //	Dans ce cas, cela signifie que le capteur est défaillant
  	//	La valeur de max 10^3 est arbitraire
  	//
    // Contrat :
    //


    bool similitude(Capteur* c1, Capteur* c2,vector<Moment> intervaleTemps);

    double ecartTypeRelatif(list<Mesure> mesures);

    list<Capteur> capteursProches(double latitude, double  longitude, list<Capteur> capteurs);

    vector<double> moyenneCapteur(Capteur* capteur, vector<Moment> intervaleTemps);
    // Mode d'emploi :
    // Prend un capteur et un interval de temps et retourne la moyenne des mesures
    // dans l'interval de temps sous forme de tableau de Double.
    // L'ordre est O3/NO2/SO2/PM10.
    // Si il n'y a aucune mesure, elle retourne -1 dans la case du tableau.
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs
    // Algo & operator = ( const Algo & unAlgo );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //-------------------------------------------- Constructeurs - destructeur
    Algo(const Algo & unAlgo);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Algo();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Algo();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    double enRadians(double latitude);
    double obtenirDistance(double lat1d, double lon1d, double lat2d, double lon2d);
    int calculAtmoPondere(double valeurNO2Capt1, double valeurO3Capt1, double valeurPM10Capt1, double valeurSO2Capt1,
                                double valeurNO2Capt2, double valeurO3Capt2, double valeurPM10Capt2, double valeurSO2Capt2,
                                double valeurNO2Capt3, double valeurO3Capt3, double valeurPM10Capt3, double valeurSO2Capt3,
                          double distanceMini1, double distanceMini2, double distanceMini3, int nbCapteur);
    int calculAtmo(double valeur, string type);



    //---------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Algo>

#endif // ALGO_H
