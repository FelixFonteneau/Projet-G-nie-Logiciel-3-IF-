/*************************************************************************
 Factory  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Factory> (fichier Factory.h) ----------------
#if ! defined ( FACTORY_H )
#define FACTORY_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Factory>
//
//
//------------------------------------------------------------------------

class Factory
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
    Factory & operator = ( const Factory & uneFactory );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Factory ( const Factory & uneFactory );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Factory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Factory ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <Factory>

#endif // FACTORY_H

