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
    void AjouterMesure(Mesure & mesure);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string RecupererId() const;
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<Mesure>* RecupererMesuresO3()
    {
        return & mesuresO3;
    }

    vector<Mesure>* RecupererMesuresNO2()
    {
        return & mesuresNO2;
    }

    vector<Mesure>* RecupererMesuresSO2()
    {
        return & mesuresSO2;
    }

    vector<Mesure>* RecupererMesuresPM10()
    {
        return & mesuresPM10;
    }

	string getDescription();

//------------------------------------------------- Surcharge d'opérateurs
    // Capteur & operator = ( const Capteur & unCapteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
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
  vector<Mesure> mesuresO3;
  vector<Mesure> mesuresNO2;
  vector<Mesure> mesuresSO2;
  vector<Mesure> mesuresPM10;
	const string idCapteur;
	double latitude;
	double longitude;
	string description;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H
