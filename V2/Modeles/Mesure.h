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

    void afficher ();


//------------------------------------------------- Surcharge d'opérateurs
    Mesure & operator = ( const Mesure & uneMesure );
    // Mode d'emploi :
    //
    // Contrat :
    //


//-------------------------------------------- Constructeurs - destructeur
    Mesure ( const Mesure & uneMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    Mesure (double uneValue, string uneDescription, string uneUnit);

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
string description;
string unit;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // MESURE_H

