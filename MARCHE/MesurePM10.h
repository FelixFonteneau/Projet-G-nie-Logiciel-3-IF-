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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	//virtual void ajout(Capteur* capteur);

    //------------------------------------------------- Surcharge d'opérateurs
    // MesurePM10 & operator = ( const MesurePM10 & uneMesurePM10 );
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    // MesurePM10 ( const MesurePM10 & uneMesurePM10 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //

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
