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
    Mesure* moyenne(Moment intervaleTemps[2], double radius, double coordonees[2], list<Capteur> capteurs);
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    double QualiteAir(vector<Capteur*>* capteurs, double* coordonees);

    vector<Capteur*> capteurTerritoire(vector<Capteur*> capteurs, double radius, double* coordonees);

    list<Capteur> capteurDefaillants(list<Capteur> capteurs);

    bool similitude(Capteur c1, Capteur c2,Moment* trancheHoraire);

    double ecartTypeRelatif(list<Mesure> mesures);

    list<Capteur> capteursProches(double latitude, double  longitude, list<Capteur> capteurs);
    
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
                          double distanceMini1, double distanceMini2, double distanceMini3);
    int calculAtmo(double valeur, string type);
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <Algo>

#endif // ALGO_H

