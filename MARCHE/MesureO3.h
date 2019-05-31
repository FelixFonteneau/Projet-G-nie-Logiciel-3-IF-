/*************************************************************************
 MesureO3  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <MesureO3> (fichier MesureO3.h) ----------------
#if ! defined ( MESUREO2_H )
#define MESUREO2_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesureO3>
//
//
//------------------------------------------------------------------------

class MesureO3 : public Mesure
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

    // double Valeur () const;
    // Mode d'emploi :
    //
    // Contrat :

	virtual void ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10);
	
	virtual string type () const;

    //------------------------------------------------- Surcharge d'opérateurs
    // friend ostream& operator <<(ostream& out, const Mesure& mesure);
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    // MesureO3 ( const MesureO3 & uneMesureO3 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

    MesureO3 ( double uneValue, Moment& uneDate, string uneDescription, string uneUnite, string unCapteurid );

    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MesureO3 ( ) = default;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MesureO3>

#endif // MESUREO2_H
