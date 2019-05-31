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
#include <string>
#include "Moment.h"
#include <vector>
using namespace std;
//------------------------------------------------------------- Constantes
//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Mesure>
//
//
//------------------------------------------------------------------------

class MesureO3;
class MesureSO2;
class MesureNO2;
class MesurePM10;


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
    // Mode d'emploi : retourne la valeur de la mesure
    //
    // Contrat :

    string Type () const;
    // Mode d'emploi : retour
    //
    // Contrat :

    string Capteur() const;
    // Mode d'emploi :
    //
    // Contrat :

    Moment getDate() const
    {
        return date;
    }
	
	virtual void ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10)=0;
	
	

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


    //Mesure & operator = ( const Mesure & uneMesure );
    // Mode d'emploi :
    //
    // Contrat :


//-------------------------------------------- Constructeurs - destructeur
	Mesure();
    Mesure ( double uneValue, Moment& uneDate, string uneDescription, string unType, string uneUnite, string unCapteurid );


    Mesure ( const Mesure & uneMesure );
    // Mode d'emploi (constructeur de copie) :
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
    string description;
    string type;
    string unite;
    string capteurid;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // MESURE_H
