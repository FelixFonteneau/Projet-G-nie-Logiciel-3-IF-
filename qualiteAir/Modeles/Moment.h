/*************************************************************************
                           Moment  -  Décrit un moment
                             -------------------
    début                : 10 mai 2019
    copyright            : (C) Mathis GUILHIN
    e-mail               : mathis.guilhin@insa-lyon.fr
*************************************************************************/



//---------- Interface de la classe <Moment> (fichier Moment.h) ----------------
#if ! defined ( MOMENT_H )
#define MOMENT_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Moment>
//
// Cette classe permet de specifier une date precise a la seconde
// ainsi que d'effectuer des operations dessus.
//
//------------------------------------------------------------------------

class Moment
{
//----------------------------------------------------------------- PUBLIC

public:
//----------------------------------------------------- Méthodes publiques
    unsigned int getJour() const
    {
        return jour;
    }
    unsigned int getMois() const
    {
        return mois;
    }
    unsigned int getAnnee() const
    {
        return annee;
    }
    unsigned int getHeure() const
    {
        return heure;
    }
    unsigned int getMinute() const
    {
        return minute;
    }
    unsigned int getSeconde() const
    {
        return seconde;
    }


//------------------------------------------------- Surcharge d'opérateurs
    friend ostream& operator<<(ostream &strm, const Moment &m);
    // Mode d'emploi (constructeur de copie) :
    // Operateur de flux, permet d'afficher la date.
    //
    // Contrat :
    //

    // operateur de comparaison de date
    bool operator > (const Moment &m);

    Moment& operator = (const Moment &m);

    bool operator < (const Moment &m);

    bool operator == (const Moment &m)
    {
        return (!(*this<m) && !(*this>m));
    }



//-------------------------------------------- Constructeurs - destructeur

	Moment();

    Moment ( const Moment & unMoment );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    Moment(int j, int m, int a, int h, int min, int sec);

    Moment(string s);

    virtual ~Moment ( );
    // Mode d'emploi :
    //
    // Contrat :
    //

//------------------------------------------------------------------ PRIVE

protected:
//----------------------------------------------------- Méthodes protégées

//----------------------------------------------------- Attributs protégés
  unsigned int jour;
  unsigned int mois;
  unsigned int annee;
  unsigned int heure;
  unsigned int minute;
  unsigned int seconde;
};

//-------------------------------- Autres définitions dépendantes de <Moment>

#endif // MOMENT_H
