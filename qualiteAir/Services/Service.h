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
// Cette classe sert de point d'entre aux Main afin de choisir les differents
// services que propose notre application. La classe sert donc d'interface
// pour acceder aux differents algoritmes.
//
//------------------------------------------------------------------------

class Service
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    void CalculMoyenneLocalise(int choix);
    // Mode d'emploi :
    //
    // Methode faisant le Calcul de la moyenne sur un territoire, et sur
    //  un intervalle ou un instant de temps donne.
    //
    // Contrat :
    //

    void QualiteAir();
    // Mode d'emploi :
    //
    // Effectuer un calcul d'indice ATMO sur un point precis.
    // Recupere les capteurs les plus proches et utilise leurs dernieres mesures.
    //
    // Contrat :
    //

    void CapteursSimilaires();
    // Mode d'emploi :
    //
    // Cherche la correlation entre des capteurs durant un interval de temps.
    //
    // Contrat :
    //

    void CapteursDefectueux();
    // Mode d'emploi :
    //
    //  Recherche dans tous les capteurs, si des mesures sont erronees
    // (valeur negative) ou aberante puis affiche les capteurs ayant ce defaut.
    //
    // Contrat :
    //

//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur
    Service(string nomFichierCapteur, string nomFichierDonnees, string utf8);
    // Mode d'emploi :
    //
    // prend un nom de fichier de description des capteurs (au format csv)
    // prend un nom de fichier des donnees des capteurs (au format csv)
    // prend un parametre si les fichiers sont au format utf8
    // Puis construit l'objet service en analysant les fichiers et en creant les
    // structures de donnees.
    //
    // Contrat :
    // Les strings doivent designer des nom de fichier valides et ces fichiers
    // doivent correspondrent au format fixe.

    virtual ~Service();
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés

	vector<Capteur*>* capteurs;
	Algo algo;
	Messages messages;
	Factory factory;

};

//-------------------------------- Autres définitions dépendantes de <Service>

#endif // SERVICE_H
