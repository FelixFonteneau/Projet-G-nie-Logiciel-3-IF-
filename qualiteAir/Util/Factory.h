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
// Cette classe permet d'analyser les differents fichiers necessaires a
// l'aplication, puis retourne les structures de donnees.
//
//------------------------------------------------------------------------

class Factory
{

  //---- structure privee de classe ----
  // permet de mieux transmettre les donnees dans les methodes
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
    vector<Capteur*>* RecupererInfos(string nomFichierCapteur,
                                     string nomFichierDonnees, string utf8);
    // Mode d'emploi :
    //
    // Prend en entree le nom du fichier de la description des capteur,
    // le nom du fichier de mesures et un string demandant si l'encodage des fichier
    // est en utf8.
    // La methode analyse les differents fichiers et creer les structures de
    // donnee puis les renvoies.
    //
    // Contrat :
    //


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur
    Factory ( );

    virtual ~Factory ( );

    //------------------------------------------------------------------ PRIVE
protected:
    //----------------------------------------------------- Méthodes protégées
    void recupererType(string accesRepertoire);
    // Mode d'emploi :
    //
    // Analyse le fichier contenant les differentes informations des mesures
    // par type et les ajoutes dans l'attribut listeType
    //
    // Contrat :
    //

    void analyserCapteurs(vector<Capteur*>* listeCapteurs,string nomFichierCapteur);
    // Mode d'emploi :
    //
    // Prend un en parametre un pointeur sur un vecteur de vapteur vide
    // puis remplis ce vetor des differents grace qu fichier de description
    // des capteurs.
    //
    // Contrat :
    //

    string decompose(char const sep, string uneLigne);
    // Mode d'emploi :
    //
    // Cette methode est utile uniquement pour decomposer des lignges d'un
    // fichier à l'encodage n'etant pas utf8
    //
    // Contrat :
    //


    Mesure* analyserLigne(string ligne, string utf8);
    // Mode d'emploi :
    //
    // Cette methode analyse une ligne du fichier contenant les donnees des
    // mesures, puis retourne une mesure.
    //
    // Contrat :
    //

    void remplirCapteurs(vector<Capteur*>* listeCapteurs,string nomFichierDonnees,
                         string utf8);
    // Mode d'emploi :
    //
    // Remplis le vector de capteurs. Necessite que le vector soit deja rempli.
    //
    // Contrat : doit etre appelee apres analyseCapteurs
    // car la liste de capteurs doit etre initialisee

    string recupererRepertoire(string nomFichierCapteur);
    // Mode d'emploi :
    //
    // récupere le chemin d'acces 
    //
    // Contrat : doit etre appelee apres analyseCapteurs
    // car la liste de capteurs doit etre initialisee

    //----------------------------------------------------- Attributs protégés
    vector<typeMesure_t> listeType;
};

//-------------------------------- Autres définitions dépendantes de <Factory>

#endif // FACTORY_H
