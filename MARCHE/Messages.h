/*************************************************************************
 Messages  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Messages> (fichier Messages.h) ----------------
#if ! defined ( MESSAGES_H )
#define MESSAGES_H

//--------------------------------------------------- Interfaces utilisées
#include "Moment.h"
#include "Capteur.h"
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <list>
#include <map>

//------------------------------------------------------------------------
// Rôle de la classe <Messages>
//
//
//------------------------------------------------------------------------

class Messages
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    int MessageMenu();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    vector<double> RecupererLocalisation();
	
    double RecupererRadius();
	
    double RecupererCapteur();
	
    vector<Moment> RecupererIntervalleTemps();
	
    Moment RecupererMoment();
	
	bool ChoixZone();
	
    void AfficherCapteursCorreles(double** similitude, int size);
	
    void AfficherMoyenne(Mesure* mesuresMoyennes, double indiceATMO);
	
    void AfficherCapteursDefaillants(vector<Capteur*> capteurs);
    
    void AfficherQualiteAir(vector<int> infos);
	
	// Chaque méthode sert au traitement des messages affichées dans lors des appels aux services




    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    Messages ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Messages ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés
};

//-------------------------------- Autres définitions dépendantes de <Messages>

#endif // MESSAGES_H
