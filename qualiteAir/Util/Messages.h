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
#include "../Modeles/Mesure.h"
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <list>

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
    int MessageMenu();
    // type Méthode ( liste des paramètres );
    // Mode d'emploi :
    //
    // Contrat :
    //

	void Initialisation();

	bool VerifierEntree(string nomFichierDescription, string nomFichierDonnes,
                      string nomCheminType, string utf8);

	void ErreurNbArguments();

	void ErreurArguments();

	void Quitter();

  vector<double> RecupererLocalisation();

  double RecupererRadius();

  double RecupererCapteur();

  vector<Moment> RecupererIntervalleTemps();

	vector<string> RecupererNomsFichiers();

  Moment RecupererMoment();

	bool ChoixZone();

  bool ChoixTemporel();
    // Mode d'emploi : Demande à l'utilisateur si il veut faire un choix sur
    // un intervalle de temps ou sur un moment direct.
    // Renvoie true si Intervalle / false si Instant
    // Contrat :
    //

    void AfficherCapteursCorreles(double** similitude, int size);

    void AfficherMoyenne(Mesure* mesuresMoyennes, double indiceATMO);

    void AfficherCapteursDefectueux(vector<tuple<Capteur*, int, Moment>> capteurs);

    void AfficherQualiteAir(vector<int> infos);

	// Chaque méthode sert au traitement des messages affichées dans lors des appels aux services

    void AfficherMoyenne(vector<double> moyennes, int atmo);


    //------------------------------------------------- Surcharge d'opérateurs

    //-------------------------------------------- Constructeurs - destructeur

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
