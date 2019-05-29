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
#include <vector>
#include <map>
#include <fstream>
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
    vector<Capteur> recupererInfos();
    string decompose(char const sep, string uneLigne);
    
    //------------------------------------------------- Surcharge d'opérateurs
    // Factory & operator = ( const Factory & uneFactory );
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
    void analyserCapteurs();
protected:
    //----------------------------------------------------- Méthodes protégées
    
    const string analyserMesure(string ligne);
    void analyserTypeMesure();
    //----------------------------------------------------- Attributs protégés
    vector<Capteur*> capteurs;
    map<unsigned int, Mesure> mesuresDefaillantes;
};

//-------------------------------- Autres définitions dépendantes de <Factory>

#endif // FACTORY_H

