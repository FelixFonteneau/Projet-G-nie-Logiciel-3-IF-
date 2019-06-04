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
#include "../Modeles/Capteur.h"
#include "../Modeles/Mesure.h"

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
  struct typeMesure_t
  {
    // AttributeID;Unit;Description;
    string attributeID;
    string unite;
    string description;
  };
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //


    vector<Capteur*>* AnalyserMesure(string nomFichierCapteur, string nomFichierDonnees, string utf8);
    // Mode d'emploi :
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs
    // Factory & operator = ( const Factory & uneFactory );
    // Mode d'emploi :
    //
    // Contrat :
    //


    //-------------------------------------------- Constructeurs - destructeur
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
    void recupererType();
    // Mode d'emploi :
    //
    // Contrat :
    //

    void analyserCapteurs(vector<Capteur*>* listeCapteurs,string nomFichierCapteur);
    // Mode d'emploi :
    //
    // Contrat :
    //

    string decompose(char const sep, string uneLigne);
    // Mode d'emploi :
    //
    // Contrat :
    //


    Mesure* analyserLigne(string ligne, string utf8);
    // Mode d'emploi :
    //
    // Contrat :
    //

    void remplirCapteurs(vector<Capteur*>* listeCapteurs,string nomFichierDonnees,string utf8);
    // Mode d'emploi :
    //
    // Contrat : doit etre appelee apres analyseCapteurs
    // car la liste de capteurs doit etre initialisee

    //----------------------------------------------------- Attributs protégés
    vector<typeMesure_t> listeType;
};

//-------------------------------- Autres définitions dépendantes de <Factory>

#endif // FACTORY_H
