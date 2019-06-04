/*************************************************************************
 MesureSO2  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <MesureSO2> (fichier MesureSO2.h) ----------------
#if ! defined ( MESURESO2_H )
#define MESURESO2_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesureSO2>
//
//
//------------------------------------------------------------------------

class MesureSO2 : public Mesure
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
	virtual void ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10);

	virtual string type () const;


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

    MesureSO2 ( double uneValue, Moment& uneDate, string uneDescription,string uneUnite, string unCapteurid );
    //
    // Contrat :
    //

    virtual ~MesureSO2 ( ) = default;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MesureSO2>

#endif // MESURESO2_H
