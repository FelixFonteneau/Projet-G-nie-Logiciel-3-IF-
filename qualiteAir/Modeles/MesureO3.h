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

	virtual void ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10);

	virtual string type () const;

    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

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
