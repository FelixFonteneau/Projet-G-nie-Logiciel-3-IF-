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
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    // MesureSO2 & operator = ( const MesureSO2 & uneMesureSO2 );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    MesureSO2 ( const MesureSO2 & uneMesureSO2 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    MesureSO2 ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~MesureSO2 ( );
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

