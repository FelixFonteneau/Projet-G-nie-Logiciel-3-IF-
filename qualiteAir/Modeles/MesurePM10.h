/*************************************************************************
 MesurePM10  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <MesurePM10> (fichier MesurePM10.h) ----------------
#if ! defined ( MESUREPM10_H )
#define MESUREPM10_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesurePM10>
//
//
//------------------------------------------------------------------------

class MesurePM10 : public Mesure
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques

	virtual void ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10);

	virtual string type () const;
    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    MesurePM10 ( double uneValue, Moment& uneDate, string uneDescription, string uneUnite, string unCapteurid );
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MesurePM10 ( ) = default;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MesurePM10>

#endif // MESUREPM10_H
