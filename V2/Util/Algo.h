/*************************************************************************
 Algo  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Algo> (fichier Algo.h) ----------------
#if ! defined ( ALGO_H )
#define ALGO_H

//--------------------------------------------------- Interfaces utilisées

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//------------------------------------------------------------------------
// Rôle de la classe <Algo>
//
//
//------------------------------------------------------------------------

class Algo
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
    // Algo & operator = ( const Algo & unAlgo );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Algo ( const Algo & unAlgo );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Algo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Algo ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <Algo>

#endif // ALGO_H

