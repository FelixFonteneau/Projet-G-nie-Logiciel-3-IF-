/*************************************************************************
 Messages  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Interface de la classe <Messages> (fichier Messages.h) ----------------
#if ! defined ( MESSAGES_H )
#define MESSAGES_H

//--------------------------------------------------- Interfaces utilisées
#include "../Modeles/Moment.h"
#include "../Modeles/Capteur.h"
//#include "../Modeles/Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <list>
#include <map>
//------------------------------------------------------------------------
// Rôle de la classe <Messages>
//
//
//------------------------------------------------------------------------

class Messages
{
    //----------------------------------------------------------------- PUBLIC
    
public:
    //----------------------------------------------------- Méthodes publiques
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //
    void messageMenu();
    double* recupererLocalisation();
    double recupererRadius();
    double recupererCapteur();
    Moment* recupererIntervalleTemps();
    Moment recupererMoment();
    void afficherCapteursCorreles(map<Capteur,Capteur> capteurs);
    void afficherMoyenne(Mesure* mesuresMoyennes, double indiceATMO);
    //void afficherDefaillance(Capteur capteur, list<Mesure> mesures);
    
    
    
    //------------------------------------------------- Surcharge d'opérateurs
    Messages & operator = ( const Messages & desMessages );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    
    //-------------------------------------------- Constructeurs - destructeur
    Messages ( const Messages & desMessages );
    // Mode d'emploi (constructeur de copie) :
    //
    // Contrat :
    //
    
    Messages ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    virtual ~Messages ( );
    // Mode d'emploi :
    //
    // Contrat :
    //
    
    //------------------------------------------------------------------ PRIVE
    
protected:
    //----------------------------------------------------- Méthodes protégées
    
    //----------------------------------------------------- Attributs protégés
    
};

//-------------------------------- Autres définitions dépendantes de <Messages>

#endif // MESSAGES_H

