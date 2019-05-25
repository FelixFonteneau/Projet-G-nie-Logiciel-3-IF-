/*************************************************************************
                           Service  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Service> (fichier Service.h) ----------------
#if ! defined ( SERVICE_H )
#define SERVICE_H

//--------------------------------------------------- Interfaces utilisées

#include "../Util/Algo.h"
#include "../Util/Messages.h"
#include "../Util/Factory.h"
#include "../Modeles/Capteur.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Service>
//
//
//------------------------------------------------------------------------

class Service 
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    /* int calculMoyenneLocalise();
    // Mode d'emploi :
    //
    // Contrat :
    //
	
    int qualiteAir();
	
    list<Capteur> capteursSimilaires();
	
    list<Capteur> capteursDefectueux(); */
	
//------------------------------------------------- Surcharge d'opérateurs
    // Service & operator = (const Service & unService);
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Service(const Service & unService);
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Service();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Service();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
	list<Capteur> capteurs;
	Algo algo;
	Messages messages;
	Factory factory;

};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // SERVICE_H
