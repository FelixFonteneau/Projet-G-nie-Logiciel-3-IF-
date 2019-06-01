/*************************************************************************
                           Capteur  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Capteur> (fichier Capteur.h) ----------------
#if ! defined ( CAPTEUR_H )
#define CAPTEUR_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"
#include "MesureNO2.h"
#include "MesureO3.h"
#include "MesureSO2.h"
#include "MesurePM10.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <vector>
//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------



class Capteur
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void AjouterMesure(Mesure *mesure);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string RecupererId() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<MesureO3>* RecupererMesuresO3()
    {
        return & mesuresO3;
    }

    vector<MesureNO2>* RecupererMesuresNO2()
    {
        return & mesuresNO2;
    }

    vector<MesureSO2>* RecupererMesuresSO2()
    {
        return & mesuresSO2;
    }

    vector<MesurePM10>* RecupererMesuresPM10()
    {
        return & mesuresPM10;
    }



	string getDescription() const;

    vector<double> getCoords();

//------------------------------------------------- Surcharge d'opérateurs
    // Capteur & operator = (const Capteur & unCapteur);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    // Capteur (const Capteur & unCapteur);
    Capteur (const string idCapt, const double lat, const double lon, const string description);
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Capteur ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	vector<MesureO3> mesuresO3;
	vector<MesureNO2> mesuresNO2;
	vector<MesureSO2> mesuresSO2;
	vector<MesurePM10> mesuresPM10;
	const string idCapteur;
	double latitude;
	double longitude;
	string description;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H
