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
#include <string>
using namespace std;
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

    double Valeur () const;
    // Mode d'emploi :
    //
    // Contrat :

    string Type () const;
    // Mode d'emploi :
    //
    // Contrat :



//------------------------------------------------- Surcharge d'opérateurs
    friend ostream& operator <<(ostream& out, const Mesure& mesure);
    // Mode d'emploi :
    //
    // Contrat :


    bool operator > (const Mesure &m)
    // Mode d'emploi :
    // compare des mesures selon la date
    {
      return date >  m.date;
    }

    bool operator < (const Mesure &m)
    // Mode d'emploi :
    // compare des mesures selon la date
    {
      return date < m.date;
    }

    bool operator == (const Mesure &m)
    // Mode d'emploi :
    // compare des mesures selon la date
    {
        return date == m.date;
    }

    Moment getDate() const
    {
        return date;
    }

    //Mesure & operator = ( const Mesure & uneMesure );
    // Mode d'emploi :
    //
    // Contrat :


//-------------------------------------------- Constructeurs - destructeur
    Mesure ( const Mesure & uneMesure );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //


    Mesure (double uneValue, Moment& uneDate, string uneDescription, string unType, string uneUnite);


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
    string description;
    string type;
    string unite;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // MESURE_H
