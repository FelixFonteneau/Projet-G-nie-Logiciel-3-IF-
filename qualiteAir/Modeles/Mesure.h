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
// Permet de stoquer toutes les informations d'une mesure.
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
    double Valeur () const;
    // Mode d'emploi : retourne la valeur de la mesure
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

	virtual string type () const;

	virtual void ajout(vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10)=0;


//------------------------------------------------- Surcharge d'opérateurs
    friend ostream& operator <<(ostream& out, const Mesure& mesure);
    // Mode d'emploi :
    // surchagrge de l'operateur de flux. Permet de d'afficher une mesure.
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

//-------------------------------------------- Constructeurs - destructeur
		Mesure();
		// Mode d'emploi :
    //
    // Contrat :
    //

		Mesure ( double uneValue, Moment& uneDate, string uneDescription,string uneUnite, string unCapteurid );
		// Mode d'emploi :
    //
    // Contrat :
    //


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
    string unite;
    string capteurid;
};

//-------------------------------- Autres définitions dépendantes de <Xxx>

#endif // MESURE_H
