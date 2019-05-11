/*************************************************************************
 MesureNO2  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <MesureNO2> (fichier MesureNO2.h) ----------------
#if ! defined ( MESURENO2_H )
#define MESURENO2_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <MesureNO2>
//
//
//------------------------------------------------------------------------

class MesureNO2 : public Mesure
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
    // MesureNO2 & operator = ( const MesureNO2 & uneMesureNO2 );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    MesureNO2 ( const MesureNO2 & uneMesureNO2 );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    MesureNO2 ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~MesureNO2 ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <MesureNO2>

#endif // MESURENO2_H

