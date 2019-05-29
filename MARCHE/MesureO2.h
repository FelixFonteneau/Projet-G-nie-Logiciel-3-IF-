/*************************************************************************
 MesureO2  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <MesureO2> (fichier MesureO2.h) ----------------
#if ! defined ( MESUREO2_H )
#define MESUREO2_H

//--------------------------------------------------- Interfaces utilisées
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesureO2>
//
//
//------------------------------------------------------------------------

class MesureO2 : public Mesure
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


    //------------------------------------------------- Surcharge d'opérateurs
    // friend ostream& operator <<(ostream& out, const Mesure& mesure);
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
    // MesureO2 ( const MesureO2 & uneMesureO2 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    MesureO2 (double uneValue, Moment& uneDate, string uneDescription, string unType, string uneUnite);
 
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~MesureO2 ( ) = default;
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées

    //----------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <MesureO2>

#endif // MESUREO2_H
