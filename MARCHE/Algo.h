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

    list<Capteur> capteurTerritoire(double radius, double coordonees[2]);

    list<Capteur> capteurDefaillants(list<Capteur> capteurs);

    bool similitude(Capteur c1, Capteur c2);

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
    double obtenirDistance(vector<double> coordonees1, double coordonees2[2]);
    int calculAtmo(double valeurNO2, double valeurO3, double valeurPM10, double valeurSO2);
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <Algo>

#endif // ALGO_H

