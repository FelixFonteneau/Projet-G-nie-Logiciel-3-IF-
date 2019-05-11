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
#include <map>
#include <string>
using namespace std;
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Capteur>
//
//
//------------------------------------------------------------------------

class Capteur : public Ancetre
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


//------------------------------------------------- Surcharge d'opérateurs
    Capteur & operator = ( const Capteur & unCapteur );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Capteur ( const Capteur & unCapteur );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Capteur ( const unsigned int id; const double lat, const double lon, const string description) id(id), (latitude(lat), longitude(lon), description(description));
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
	multimap < Moment; Mesure > [4] mesures;
	const unsigned int id;
	double latitude;
	double longitude;
	string description;
};

//-------------------------------- Autres définitions dépendantes de <Capteur>

#endif // CAPTEUR_H

