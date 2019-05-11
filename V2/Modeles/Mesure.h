/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Interface de la classe <Xxx> (fichier Xxx.h) ----------------
#if ! defined ( MESURE_H )
#define MESURE_H


//--------------------------------------------------- Interfaces utilisées
#include "Moment.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class Mesure
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
    Mesure & operator = ( const Mesure & uneMesure );
    // Mode d'emploi :
    //
    // Contrat :
    ///Users/Aymeric/Desktop/Projet-Genie-Logiciel-3IF/V1/Modeles/Mesure.h


//-------------------------------------------- Constructeurs - destructeur
    Mesure ( const Mesure & uneMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Mesure (double uneValue, Moment uneDate);

    Mesure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Mesure ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  double value;
  Moment date;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // MESURE_H
