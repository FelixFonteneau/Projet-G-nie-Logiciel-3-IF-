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
#include "Capteur.h"
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <list>
#include <map>
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
    void recupererInfos(list<Capteur> capteurs);
    
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
    void analyserCapteurs();
    void analyserMesures();
    void analyserTypeMesures();
    //----------------------------------------------------- Attributs protégés
    list<Capteur> capteurs;
    map<unsigned int, Mesure> mesuresDefaillantes;
};

//-------------------------------- Autres définitions dépendantes de <Factory>

#endif // FACTORY_H

