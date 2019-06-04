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

#include "../Modeles/Capteur.h"
#include "../Modeles/Moment.h"
#include "../Modeles/Mesure.h"

//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types
#include <vector>
#include <list>

//------------------------------------------------------------------------
// Rôle de la classe <Algo>
//
// Classe contenant tous les diffents algorithmes important de notre projet
// Cette classe est utilisee par service afin de sous traiter les taches
// difficiles.
//
//------------------------------------------------------------------------

class Algo
{
    //----------------------------------------------------------------- PUBLIC

public:
    //----------------------------------------------------- Méthodes publiques
    vector<double> MoyenneDuree(vector<Moment> intervaleTemps, double radius, vector<double> coordonees, vector<Capteur*>* capteurs);
    // Mode d'emploi :
    //
    // Prend tous les capteurs dans la zone et un interval de temps
    //  retourne la moyenne des mesures sous forme de tableau de Double.
    // L'ordre est O3/NO2/SO2/PM10.
    // Si il n'y a aucune mesure, elle retourne -1 dans la case du tableau.
    //
    // Contrat :
    // toutes les variables doivent etre initialisees.
    // radius doit etre positif
    // les coordonees doivent etre valides
    //

    vector<double> MoyenneInstant(Moment instant, double radius, vector<double> coordonees, vector<Capteur*>* capteurs);
    // Mode d'emploi :
    //
    // Meme fonctionnement que MoyenneDuree mais prend qu'un seul instant
    //
    // Contrat :
    // toutes les variables doivent etre initialisees.
    // radius doit etre positif
    // les coordonees doivent etre valides
    //

    vector<int> QualiteAir(vector<Capteur*>* capteurs, double latitude, double longitude);
    // Mode d'emploi :
    //
    // Prend en entree tous les capteurs et une latitude/longitude.
    // Puis calcul l'indice ATMO sur les 3 capteurs les plus proches, s'ils sont dans un rayon de moins de 90km.
    // Sinon en prend 1, le plus proche. (Triangulation pas possible)
    // L'incide atmo est calcule avec les mesures les plus recentes
    //
    // Contrat :
    // toutes les variables doivent etre initialisees.
    // radius doit etre positif
    // les coordonees doivent etre valides
    //

    vector<Capteur*> CapteurTerritoire(vector<Capteur*>* capteurs, double radius, vector<double> coordonees);
    // Mode d'emploi :
    //
    // Prend en entree tous les catpeur, puis une zone delimitee par des coordonees et radius
    // Retourne un vecteur de tous les capteurs se trouvant dans la zone.
    //
    // Contrat :
    // toutes les variables doivent etre initialisees.
    // radius doit etre positif
    // les coordonees doivent etre valides
    //

    vector<tuple<Capteur*, int, Moment>> CapteursDefaillants(vector<Capteur*> capteurs);
  	// Mode d'emploi :
  	//
  	//	Prend une liste de capteurs en paramètre et la parcours afin de
  	//	trouver si certains capteurs ont des données improbables.
    //	Dans ce cas, cela signifie que le capteur est défaillant
  	//	La valeur de max 10^3 est arbitraire
  	//
    // Contrat :
    //

    double** CalculCapteurCorreles(double** capteurCorreles, vector<Capteur*> capteurConcernes, vector<Moment> moments);
    // Mode d'emploi :
    //
    // Calcul la corelation de chaques capteurssur une periode.
    // Renvoie un tableau avec les pourcentage de correspondance de chaques capteurs.
    //
    // Contrat :
    // il faut que (double**) capteurCorreles soit deja aloue avec en dimension taille(capteurConcernes)xtaille(capteurConcernes)
    //

	  int CalculAtmoMoyen(vector<double> moyenne );
    // Mode d'emploi :
    //
    // Calcul l'indice ATMO en fonction des valeur des gaz.
    // Retourne l'indice atmo correspodant.
    // Retourne 11 si l'indice ATMO n'est pas calculable
    //
    // Contrat :
    // Le vector doit etre de taille 4 avec des valeurs positives
    // L'ordre des valeurs est O3/NO2/SO2/PM10.

    //------------------------------------------------- Surcharge d'opérateurs


    //-------------------------------------------- Constructeurs - destructeur
    Algo();
    // Mode d'emploi :
    //
    // Contrat :
    //

    virtual ~Algo();
    // Mode d'emploi :
    //
    // Contrat :
    //

    //------------------------------------------------------------------ PRIVE

protected:
    //----------------------------------------------------- Méthodes protégées
    double enRadians(double latitude);

    double obtenirDistance(double lat1d, double lon1d, double lat2d, double lon2d);

    int calculAtmoPondere(double valeurNO2Capt1, double valeurO3Capt1, double valeurPM10Capt1, double valeurSO2Capt1,
                                double valeurNO2Capt2, double valeurO3Capt2, double valeurPM10Capt2, double valeurSO2Capt2,
                                double valeurNO2Capt3, double valeurO3Capt3, double valeurPM10Capt3, double valeurSO2Capt3,
                          double distanceMini1, double distanceMini2, double distanceMini3, int nbCapteur);



    double calculSimilitude(Capteur* c1, Capteur* c2,vector<Moment> intervaleTemps);

	  int calculAtmo(double valeur, string type);


    vector<double> moyenneCapteur(Capteur* capteur, vector<Moment> intervaleTemps);
    // Mode d'emploi :
    // Prend un capteur et un interval de temps et retourne la moyenne des mesures
    // dans l'interval de temps sous forme de tableau de Double.
    // L'ordre est O3/NO2/SO2/PM10.
    // Si il n'y a aucune mesure, elle retourne -1 dans la case du tableau.
    //
    // Contrat :
    //
    vector<double> valeursCapteurInstant(Capteur* capteur, Moment instant);
    //---------------------------------------------------- Attributs protégés

};

//-------------------------------- Autres définitions dépendantes de <Algo>

#endif // ALGO_H
