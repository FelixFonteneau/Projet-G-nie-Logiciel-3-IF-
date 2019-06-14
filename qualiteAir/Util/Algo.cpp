/*************************************************************************
 Algo  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Algo> (fichier Algo.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
#include <cmath>
#include <float.h>
#include <tuple>
#include <functional>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Algo.h"
//------------------------------------------------------------- Constantes
#define PI  3.141592653589793238463
#define rayonTerrestreKm 6371.0
//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
vector<double> Algo::MoyenneDuree(vector<Moment> intervaleTemps, double radius, vector<double> coordonees, vector<Capteur*>* capteurs)
// Algorithme : Fait la moyenne des moyenne des capteurs.
{
  vector<double> somme;
  vector<double> nbValeurs;
  vector<double> moyenne;
  //initialisation des vecteurs moyenne et somme à 4 valeurs à 0
  for( unsigned i(0); i < 4; i++)
  {
    somme.push_back(0);
    nbValeurs.push_back(0);
  }

//on parcours tous les capteurs
  for(Capteur* capteur : CapteurTerritoire(capteurs, radius, coordonees))
  {
    vector<double> moyenneCapt = moyenneCapteur(capteur, intervaleTemps);

    //pour toutes les valeurs (O3/NO2/SO2/PM10) donc 4
    for(unsigned i(0); i < 4; i++)
    {
        // si aucune valeur => -1
        if(moyenneCapt[i] > 0)
        {
          somme[i] += moyenneCapt[i];
          ++nbValeurs[i];
        }
    }
  }
  //calcul de moyenne
  for(unsigned i(0); i < 4; i++)
  {
      //on regarde si il y a eu des valeurs
      if(nbValeurs[i] > 0 )
      {
        moyenne.push_back(somme[i]/nbValeurs[i]);
      }
      //sinon on met la valeur à -1, pour aucune valeurs
      else
      {
        moyenne.push_back(-1);
      }
  }
  return moyenne;
}

vector<double> Algo::MoyenneInstant(Moment instant, double radius, vector<double> coordonees, vector<Capteur*>* capteurs)
{
  vector<double> somme;
  vector<double> nbValeurs;
  vector<double> moyenne;
  //initialisation des vecteurs moyenne et somme à 4 valeurs à 0
  for( unsigned i(0); i < 4; i++)
  {
    somme.push_back(0);
    nbValeurs.push_back(0);
  }

//on parcours tous les capteurs
  for(Capteur* capteur : CapteurTerritoire(capteurs, radius, coordonees))
  {
    vector<double> mesureCapt = valeursCapteurInstant(capteur, instant);

    //pour toutes les valeurs (O3/NO2/SO2/PM10) donc 4
    for(unsigned i(0); i < 4; i++)
    {
        // si aucune valeur => -1
        if(mesureCapt[i] > 0)
        {
          somme[i] += mesureCapt[i];
          ++nbValeurs[i];
        }
    }
  }
  //calcul de moyenne
  for(unsigned i(0); i < 4; i++)
  {
      //on regarde si il y a eu des valeurs
      if(nbValeurs[i] > 0 )
      {
        moyenne.push_back(somme[i]/nbValeurs[i]);
      }
      //sinon on met la valeur à -1, pour aucune valeurs
      else
      {
        moyenne.push_back(-1);
      }
  }
  return moyenne;
}

vector<int> Algo::QualiteAir(vector<Capteur*>* capteurs, double latitude, double longitude)
{
    double rayonMax = 90;

    //conteneur ayant les capteurs les plus proches compris dans le rayonMax.
    //ces capteurs sont triés (en clef) par leur distance par rapport au coordonees
    multimap <double, Capteur*> capteursProches;

    for (Capteur* capteur : *capteurs)
    {
        vector<double> coordsCapteur = capteur->getCoords();
        double distanceCourante = obtenirDistance(coordsCapteur[0], coordsCapteur[1], latitude, longitude);

        // si le capteur est dans le rayon de 90km on prend le capteur en compte
        if (distanceCourante < rayonMax)
        {
          // ajoute le capteur dans la map
          capteursProches.insert(pair<double, Capteur*> (distanceCourante, capteur));
        }
    }

    int atmo = 0;
    atmo = calculAtmoPondere(capteursProches);

    vector<int> infos;
    int nbCapteur = min((int) capteursProches.size(), 3);
    auto iterateur = capteursProches.begin();
    advance(iterateur, nbCapteur-1);
    int distanceMax =  iterateur->first;
    infos.push_back(atmo);
    infos.push_back(distanceMax);
    infos.push_back(nbCapteur);
    return infos;
}

vector<Capteur*> Algo::CapteurTerritoire(vector<Capteur*>* capteurs, double radius, vector<double> coordonees) {
    vector<Capteur*> captTerritoire;
    for(Capteur* c : *capteurs) {
		vector<double> coords = c->getCoords();
        double dist = obtenirDistance(coordonees[0],coordonees[1],coords[0],coords[1]);
        if(dist < radius) {
            captTerritoire.push_back(c);
        }
    }
    return captTerritoire;
}

vector<tuple<Capteur*, int, Moment>> Algo::CapteursDefaillants(vector<Capteur*> capteurs) {
	bool isIn = false;
    bool valNeg = false, valGrde = false;
    vector<tuple<Capteur*, int, Moment>> capteursDefaillants;
    for(Capteur* c : capteurs) {
        for(MesureO3 m : *c->RecupererMesuresO3()) {
            if (isIn == false && m.Valeur() < 0) {
                capteursDefaillants.push_back(make_tuple(c, 0, m.getDate()));
				isIn = true;
                valNeg = true;
            }
            if (isIn == false && m.Valeur() >= 5*240) {
                capteursDefaillants.push_back(make_tuple(c, 1, m.getDate()));
                isIn = true;
                valGrde = true;
            }
            if ((isIn == true && valNeg && m.Valeur() >= 5*240) || (isIn == true && valGrde && m.Valeur() < 0)) {
                get<1>(capteursDefaillants[capteursDefaillants.size() - 1]) = 2;
            }
		}
        for(MesureNO2 m : *c->RecupererMesuresNO2()) {
            if(isIn == false && m.Valeur() < 0){
                capteursDefaillants.push_back(make_tuple(c, 0, m.getDate()));
				isIn = true;
                valNeg = true;
            }
            if(isIn == false && m.Valeur() >= 5*400){
                capteursDefaillants.push_back(make_tuple(c, 1, m.getDate()));
                isIn = true;
                valGrde = true;
            }
            if ((isIn == true && valNeg && m.Valeur() >= 5*400) || (isIn == true && valGrde && m.Valeur() < 0)) {
                get<1>(capteursDefaillants[capteursDefaillants.size() - 1]) = 2;
            }
        }
        for(MesureSO2 m : *c->RecupererMesuresSO2()) {
            if(isIn == false && m.Valeur() < 0) {
                capteursDefaillants.push_back(make_tuple(c, 0, m.getDate()));
				isIn = true;
                valNeg = true;
            }
            if(isIn == false && m.Valeur() >= 5*500){
                capteursDefaillants.push_back(make_tuple(c, 1, m.getDate()));
                isIn = true;
                valGrde = true;
            }
            if ((isIn == true && valNeg && m.Valeur() >= 5*500) || (isIn == true && valGrde && m.Valeur() < 0)) {
                get<1>(capteursDefaillants[capteursDefaillants.size() - 1]) = 2;
            }
        }
        for(MesurePM10 m : *c->RecupererMesuresPM10()) {
            if(isIn == false && m.Valeur() < 0){
                capteursDefaillants.push_back(make_tuple(c, 0, m.getDate()));
				isIn = true;
                valNeg = true;
            }
            if(isIn == false && m.Valeur() >= 5*80){
                capteursDefaillants.push_back(make_tuple(c, 1, m.getDate()));
                isIn = true;
                valGrde = true;
            }
            if ((isIn == true && valNeg && m.Valeur() >= 5*80) || (isIn == true && valGrde && m.Valeur() < 0)) {
                get<1>(capteursDefaillants[capteursDefaillants.size() - 1]) = 2;
            }
        }
		isIn = false;
        valNeg = false;
        valGrde = false;
    }

    return capteursDefaillants;
}

double** Algo::CalculCapteurCorreles(double** capteurCorreles, vector<Capteur*> capteurConcernes, vector<Moment> moments)
{
    // Calcul des similitudes entre capteurs
    for (unsigned int i = 0; i < capteurConcernes.size() ; i++) {
        for (unsigned int j = i+1; j < capteurConcernes.size() ; j++) {
            double similitude = calculSimilitude(capteurConcernes[i],capteurConcernes[j],moments);
            capteurCorreles[i][j] = similitude;
        }
    }

    // Uniformisation de 0 à 100%

    // Determination du min et max
    double min = pow(10,9);
    double max = 0;
    for (unsigned int i = 0; i< capteurConcernes.size(); i++) {
        for (unsigned int j = i+1; j < capteurConcernes.size() ; j++) {
            double val = capteurCorreles[i][j];
            if (val<min && val != -1) {
                min = val;
            }
            if (val>max) {
                max = val;
            }
        }
    }
    // Uniformisation
    for (unsigned int i = 0; i< capteurConcernes.size(); i++) {
        for (unsigned int j = i+1; j < capteurConcernes.size() ; j++) {
            double val = capteurCorreles[i][j];
            if(val == -1){
                val = 0;
            } else {
				if(min == max){
					capteurCorreles[i][j] = 100;
				}
                else {
					capteurCorreles[i][j] = 100 - ((capteurCorreles[i][j] - min)/(max-min) * 100);
				}
            }
        }
    }
    return capteurCorreles;
}




//-------------------------------------------- Constructeurs - destructeur
Algo::Algo()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Algo>" << endl;
#endif
} //----- Fin de Algo


Algo::~Algo()
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Algo>" << endl;
#endif
} //----- Fin de ~Algo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
double Algo::enRadians(double latitude)
{
    return latitude * PI / 180;
}

// retourne la distance en km
double Algo::obtenirDistance(double lat1d, double lon1d, double lat2d, double lon2d)
{

    double lat1r, lon1r, lat2r, lon2r, u, v;
    lat1r = enRadians(lat1d);
    lon1r = enRadians(lon1d);
    lat2r = enRadians(lat2d);
    lon2r = enRadians(lon2d);
    u = sin((lat2r - lat1r)/2);
    v = sin((lon2r - lon1r)/2);
    return 2.0 * rayonTerrestreKm * asin(sqrt(u * u + cos(lat1r) * cos(lat2r) * v * v));
}

int Algo::calculAtmoPondere(const multimap <double, Capteur*> & capteursProches)
// Algorithme :
// recupere les dernieres mesures des capteurs les plus proches et les
// ponderes selon leur distances.
{
    double atmoNO2(0), atmoO3(0), atmoPM10(0), atmoSO2(0);
    int maxCapteurs = min(3, (int) capteursProches.size());

  // --- calcul atmo NO2 ---
    double sommeCoefficient = 0;
    int nbCapteur = 0;
    for(auto itr = capteursProches.begin(); (itr != capteursProches.end()) && nbCapteur < maxCapteurs; itr++)
    {
      // on recupere la derniere valeur du ieme capteur
      vector<MesureNO2>* mesuresNO2 = itr->second->RecupererMesuresNO2();

      // si il n'y a pas de mesures on passe au capteur suivant
      if ((*mesuresNO2).size()  == 0)
      {
        break;
      }

      double derniereValeurCapteur = mesuresNO2->at((*mesuresNO2).size() - 1).Valeur();

      // on l'ajoute avec un coefficient
      atmoNO2 += (pow(itr->first, -1)) * derniereValeurCapteur;

      //puis on somme les coefficients
      sommeCoefficient += pow(itr->first, -1);
      ++nbCapteur;
    }
    if( nbCapteur == 0 )
    {
      throw length_error("Pas de mesure NO2 dans les capteurs à proximité.");
    }
    else
    {
      atmoNO2 = calculAtmo(atmoNO2/sommeCoefficient,"NO2");
    }

  // --- calcul AtmoO3 ---
    sommeCoefficient = 0;
    nbCapteur = 0;
    for(auto itr = capteursProches.begin(); (itr != capteursProches.end()) && nbCapteur < maxCapteurs; itr++)
    {
      // on recupere la derniere valeur du ieme capteur
      vector<MesureO3>* mesuresO3 = itr->second->RecupererMesuresO3();

      // si il n'y a pas de mesures on passe au capteur suivant
      if ((*mesuresO3).size()  == 0)
      {
        break;
      }

      double derniereValeurCapteur = mesuresO3->at((*mesuresO3).size() - 1).Valeur();

      // on l'ajoute avec un coefficient
      atmoO3 += (pow(itr->first, -1)) * derniereValeurCapteur;

      //puis on somme les coefficients
      sommeCoefficient += pow(itr->first, -1);
      ++nbCapteur;
    }
    if( nbCapteur == 0 )
    {
      throw length_error("Pas de mesure O3 dans les capteurs à proximité.");
    }
    else
    {
      atmoPM10 = calculAtmo(atmoO3/sommeCoefficient,"O3");
    }

  // --- calcul AtmoPM10 ---
    sommeCoefficient = 0;
    nbCapteur = 0;
    for(auto itr = capteursProches.begin(); (itr != capteursProches.end()) && nbCapteur < maxCapteurs; itr++)
    {
      // on recupere la derniere valeur du ieme capteur
      vector<MesurePM10>* mesuresPM10 = itr->second->RecupererMesuresPM10();

      // si il n'y a pas de mesures on passe au capteur suivant
      if ((*mesuresPM10).size()  == 0)
      {
        break;
      }

      double derniereValeurCapteur = mesuresPM10->at((*mesuresPM10).size() - 1).Valeur();

      // on l'ajoute avec un coefficient
      atmoPM10 += (pow(itr->first, -1)) * derniereValeurCapteur;

      //puis on somme les coefficients
      sommeCoefficient += pow(itr->first, -1);
      ++nbCapteur;
    }
    if( nbCapteur == 0 )
    {
      throw length_error("Pas de mesure PM10 dans les capteurs à proximité.");
    }
    else
    {
      atmoPM10 = calculAtmo(atmoPM10/sommeCoefficient,"PM10");
    }

  // --- calcul AtmoSO2 ---
    sommeCoefficient = 0;
    nbCapteur = 0;
    for(auto itr = capteursProches.begin(); (itr != capteursProches.end()) && nbCapteur < maxCapteurs; itr++)
    {
      // on recupere la derniere valeur du ieme capteur
      vector<MesureSO2>* mesuresSO2 = itr->second->RecupererMesuresSO2();

      // si il n'y a pas de mesures on passe au capteur suivant
      if ((*mesuresSO2).size()  == 0)
      {
        break;
      }

      double derniereValeurCapteur = mesuresSO2->at((*mesuresSO2).size() - 1).Valeur();

      // on l'ajoute avec un coefficient
      atmoSO2 += (pow(itr->first, -1)) * derniereValeurCapteur;

      //puis on somme les coefficients
      sommeCoefficient += pow(itr->first, -1);
      ++nbCapteur;
    }
    if( nbCapteur == 0 )
    {
      throw length_error("Pas de mesure SO2 dans les capteurs à proximité.");
    }
    else
    {
      atmoSO2 = calculAtmo(atmoSO2/sommeCoefficient,"SO2");
    }

    // on retourne le max de ces calculs.
    return max( max(int(atmoNO2),int(atmoO3)),
                max(int(atmoPM10),int(atmoSO2)));

}


int Algo::CalculAtmoMoyen(vector<double> moyenne){

	vector<int> atmos;
	atmos.push_back(calculAtmo(moyenne[0],"O3"));
	atmos.push_back(calculAtmo(moyenne[1],"NO2"));
	atmos.push_back(calculAtmo(moyenne[2],"SO2"));
	atmos.push_back(calculAtmo(moyenne[3],"PM10"));
	int atmo = 0;
	for(int val : atmos){
		if(val>atmo){
			atmo = val;
		}
	}
	return atmo;
}





double Algo::calculSimilitude(Capteur* c1, Capteur* c2,vector<Moment> intervaleTemps) {

    double ecartO3, ecartNO2,ecartSO2,ecartPM10,somme = 0,nbMesure = 0    ;

    vector<MesureO3> c1MesuresO3 = *(c1->RecupererMesuresO3());
    vector<MesureO3> c2MesuresO3 = *(c2->RecupererMesuresO3());
    for(unsigned int i = 0; i < min(c1MesuresO3.size(),c2MesuresO3.size()) ; i++)
    {
        if(c1MesuresO3[i].getDate() > intervaleTemps[0] && c1MesuresO3[i].getDate() < intervaleTemps[1])
        {
            somme += pow(c1MesuresO3[i].Valeur()-c2MesuresO3[i].Valeur(),2.0);
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        ecartO3 = sqrt(somme)/nbMesure;
    }
    else
    {
        ecartO3 = -1;
    }
    somme = 0;
    nbMesure = 0;

    vector<MesureSO2> c1MesuresSO2 = *(c1->RecupererMesuresSO2());
    vector<MesureSO2> c2MesuresSO2 = *(c2->RecupererMesuresSO2());
    for(unsigned int i = 0; i < min(c1MesuresSO2.size(),c2MesuresSO2.size()) ; i++)
    {
        if(c1MesuresSO2[i].getDate() > intervaleTemps[0] && c1MesuresSO2[i].getDate() < intervaleTemps[1])
        {
            somme += pow(c1MesuresSO2[i].Valeur()-c2MesuresSO2[i].Valeur(),2.0);
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        ecartSO2 = sqrt(somme)/nbMesure;
    }
    else
    {
        ecartSO2 = -1;
    }
    somme = 0;
    nbMesure = 0;

    vector<MesureNO2> c1MesuresNO2 = *(c1->RecupererMesuresNO2());
    vector<MesureNO2> c2MesuresNO2 = *(c2->RecupererMesuresNO2());
    for(unsigned int i = 0; i < min(c1MesuresNO2.size(),c2MesuresNO2.size()) ; i++)
    {
        if(c1MesuresNO2[i].getDate() > intervaleTemps[0] && c1MesuresNO2[i].getDate() < intervaleTemps[1])
        {
            somme += pow(c1MesuresNO2[i].Valeur()-c2MesuresNO2[i].Valeur(),2.0);
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        ecartNO2 = sqrt(somme)/nbMesure;
    }
    else
    {
        ecartNO2 = -1;
    }
    somme = 0;
    nbMesure = 0;

    vector<MesurePM10> c1MesuresPM10 = *(c1->RecupererMesuresPM10());
    vector<MesurePM10> c2MesuresPM10 = *(c2->RecupererMesuresPM10());
    for(unsigned int i = 0; i < min(c1MesuresPM10.size(),c2MesuresPM10.size()) ; i++)
    {
        if(c1MesuresPM10[i].getDate() > intervaleTemps[0] && c1MesuresPM10[i].getDate() < intervaleTemps[1])
        {
            somme += pow(c1MesuresPM10[i].Valeur()-c2MesuresPM10[i].Valeur(),2.0);
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        ecartPM10 = sqrt(somme)/nbMesure;
    }
    else
    {
        ecartPM10 = -1;
    }
    somme = 0;
    nbMesure = 0;
    const double vMaxO3 = 240;
    const double vMaxNO2 = 400;
    const double vMaxSO2 = 500;
    const double vMaxPM10 = 80;

    double similitude;
    if(ecartO3!=-1 && ecartNO2 != -1 && ecartSO2 != -1 && ecartPM10 != -1){
        similitude = ecartO3*1000/vMaxO3 + ecartNO2*1000/vMaxNO2 + ecartSO2*1000/vMaxSO2 + ecartPM10*1000/vMaxPM10;
    } else {
        similitude = -1;
    }

    //cout << "similitude : " << similitude << endl;
    return similitude;
}

vector<double> Algo::moyenneCapteur(Capteur* capteur, vector<Moment> intervaleTemps)
{
    vector<double> resultatMoyenne;
    double moyO3, moyNO2, moySO2, moyPM10;
    double somme(0);
    double nbMesure(0);

    // calcul moyenne O3
    for(MesureO3 mesure : *capteur->RecupererMesuresO3())
    {
        if(mesure.getDate() > intervaleTemps[0] && mesure.getDate() < intervaleTemps[1])
        {
            somme += mesure.Valeur();
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        moyO3 = somme/nbMesure;
    }
    else
    {
        moyO3 = -1;
    }

    // calcul moyenne NO2
    somme = 0;
    nbMesure = 0;
    for(MesureNO2 mesure : *capteur->RecupererMesuresNO2())
    {
        if(mesure.getDate() > intervaleTemps[0] && mesure.getDate() < intervaleTemps[1])
        {
            somme += mesure.Valeur();
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        moyNO2 = somme/nbMesure;
    }
    else
    {
        moyNO2 = -1;
    }

    // calcul moyenne SO2
    somme = 0;
    nbMesure = 0;
    for(MesureSO2 mesure : *capteur->RecupererMesuresSO2())
    {
        if(mesure.getDate() > intervaleTemps[0] && mesure.getDate() < intervaleTemps[1])
        {
            somme += mesure.Valeur();
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        moySO2 = somme/nbMesure;
    }
    else
    {
        moySO2 = -1;
    }

    // calcul moyenne PM10
    somme = 0;
    nbMesure = 0;
    for(MesurePM10 mesure : *capteur->RecupererMesuresPM10())
    {
        if(mesure.getDate() > intervaleTemps[0] && mesure.getDate() < intervaleTemps[1])
        {
            somme += mesure.Valeur();
            ++nbMesure;
        }
    }
    if(nbMesure > 0)
    {
        moyPM10 = somme/nbMesure;
    }
    else
    {
        moyPM10 = -1;
    }

    resultatMoyenne.push_back(moyO3);
    resultatMoyenne.push_back(moyNO2);
    resultatMoyenne.push_back(moySO2);
    resultatMoyenne.push_back(moyPM10);

    return resultatMoyenne;
}

int Algo::calculAtmo(double valeur, string type)
{
    int result = 0;
    if (type.compare("NO2") == 0)
    {
        if(valeur == -1){
			result = 11;
		} else if (0 <= valeur && valeur <= 29) {
            result = 1;
        } else if (30 <= valeur && valeur <= 54) {
            result = 2;
        } else if (55 <= valeur && valeur <= 84) {
            result = 3;
        } else if (85 <= valeur && valeur <= 109) {
            result = 4;
        } else if (110 <= valeur && valeur <= 134) {
            result = 5;
        } else if (135 <= valeur && valeur <= 164) {
            result = 6;
        } else if (165 <= valeur && valeur <= 199) {
            result = 7;
        } else if (200 <= valeur && valeur <= 274) {
            result = 8;
        } else if (275 <= valeur && valeur <= 399) {
            result = 9;
        } else result = 10;
    }
    else if (type.compare("O3") == 0)
    {
        if(valeur == -1){
			result = 11;
		} else if (0 <= valeur && valeur <= 29) {
            result = 1;
        } else if (30 <= valeur && valeur <= 54) {
            result = 2;
        } else if (55 <= valeur && valeur <= 79) {
            result = 3;
        } else if (80 <= valeur && valeur <= 104) {
            result = 4;
        } else if (105 <= valeur && valeur <= 129) {
            result = 5;
        } else if (130 <= valeur && valeur <= 149) {
            result = 6;
        } else if (150 <= valeur && valeur <= 179) {
            result = 7;
        } else if (180 <= valeur && valeur <= 209) {
            result = 8;
        } else if (210 <= valeur && valeur <= 239) {
            result = 9;
        } else result = 10;
    }
    else if (type.compare("PM10") == 0)
    {
        if(valeur == -1){
			result = 11;
		} else if (0 <= valeur && valeur <= 6) {
            result = 1;
        } else if (7 <= valeur && valeur <= 13) {
            result = 2;
        } else if (14 <= valeur && valeur <= 20) {
            result = 3;
        } else if (21 <= valeur && valeur <= 27) {
            result = 4;
        } else if (28 <= valeur && valeur <= 34) {
            result = 5;
        } else if (35 <= valeur && valeur <= 41) {
            result = 6;
        } else if (42 <= valeur && valeur <= 49) {
            result = 7;
        } else if (50 <= valeur && valeur <= 64) {
            result = 8;
        } else if (65 <= valeur && valeur <= 79) {
            result = 9;
        } else result = 10;
    }
    else if (type.compare("SO2") == 0)
    {
        if(valeur == -1){
			result = 11;
		} else if (0 <= valeur && valeur <= 39) {
            result = 1;
        } else if (40 <= valeur && valeur <= 79) {
            result = 2;
        } else if (80 <= valeur && valeur <= 119) {
            result = 3;
        } else if (120 <= valeur && valeur <= 159) {
            result = 4;
        } else if (160 <= valeur && valeur <= 199) {
            result = 5;
        } else if (200 <= valeur && valeur <= 249) {
            result = 6;
        } else if (250 <= valeur && valeur <= 299) {
            result = 7;
        } else if (300 <= valeur && valeur <= 399) {
            result = 8;
        } else if (400 <= valeur && valeur <= 499) {
            result = 9;
        } else result = 10;
    }
    return result;
}

vector<double> Algo::valeursCapteurInstant(Capteur* capteur, Moment instant)
{
  vector<double> resultatMoyenne;
  double moyO3, moyNO2, moySO2, moyPM10;

  Moment momentSuivant;
  Moment momentPrecedent;
  double valeurSuivant;
  double valeurPrecedent;
  bool predecesseur = false;
  bool successeur = false;

  //  recherche des mesures suivante et précédentes chrnologiquement pour O3
  for(MesureO3 mesure : *capteur->RecupererMesuresO3())
  {

      if(!predecesseur && mesure.getDate() < instant)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
        predecesseur = true;
      }
      else if( mesure.getDate() < instant && mesure.getDate() > momentPrecedent)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
      }

      if(!successeur && mesure.getDate() > instant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
        successeur = true;
      }
      else if( mesure.getDate() > instant && mesure.getDate() < momentSuivant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
      }
  }

  // moyenne des deux
  if (predecesseur && successeur)
  {
    moyO3 = (valeurSuivant + valeurPrecedent) / 2.;
  }
  else if (predecesseur && ! successeur)
  {
    moyO3 = valeurPrecedent;
  }
  else if (!predecesseur &&  successeur)
  {
    moyO3 = valeurSuivant;
  }
  else
  {
    moyO3 = -1;
  }

  predecesseur = false;
  successeur = false;
  //  recherche des mesures suivante et précédentes chrnologiquement pour NO2
  for(MesureNO2 mesure : *capteur->RecupererMesuresNO2())
  {
      if(!predecesseur && mesure.getDate() < instant)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
        predecesseur = true;
      }
      else if( mesure.getDate() < instant && mesure.getDate() > momentPrecedent)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
      }

      if(!successeur && mesure.getDate() > instant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
        successeur = true;
      }
      else if( mesure.getDate() > instant && mesure.getDate() < momentSuivant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
      }
  }

    // moyenne des deux
    if (predecesseur && successeur)
    {
      moyNO2 = (valeurSuivant + valeurPrecedent) / 2.;
    }
    else if (predecesseur && ! successeur)
    {
      moyNO2 = valeurPrecedent;
    }
    else if (!predecesseur &&  successeur)
    {
      moyNO2 = valeurSuivant;
    }
    else
    {
      moyNO2 = -1;
    }

    predecesseur = false;
    successeur = false;
  //  recherche des mesures suivante et précédentes chrnologiquement pour SO2
  for(MesureSO2 mesure : *capteur->RecupererMesuresSO2())
  {
      if(!predecesseur && mesure.getDate() < instant)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
        predecesseur = true;
      }
      else if( mesure.getDate() < instant && mesure.getDate() > momentPrecedent)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
      }

      if(!successeur && mesure.getDate() > instant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
        successeur = true;
      }
      else if( mesure.getDate() > instant && mesure.getDate() < momentSuivant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
      }
    }

    // moyenne des deux
    if (predecesseur && successeur)
    {
      moySO2 = (valeurSuivant + valeurPrecedent) / 2.;
    }
    else if (predecesseur && ! successeur)
    {
      moySO2 = valeurPrecedent;
    }
    else if (!predecesseur &&  successeur)
    {
      moySO2 = valeurSuivant;
    }
    else
    {
      moySO2 = -1;
    }

    predecesseur = false;
    successeur = false;

    predecesseur = false;
    successeur = false;
    //  recherche des mesures suivante et précédentes chrnologiquement pour PM10
    for(MesurePM10 mesure : *capteur->RecupererMesuresPM10())
    {
      if(!predecesseur && mesure.getDate() < instant)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
        predecesseur = true;
      }
      else if( mesure.getDate() < instant && mesure.getDate() > momentPrecedent)
      {
        valeurPrecedent = mesure.Valeur();
        momentPrecedent = mesure.getDate();
      }

      if(!successeur && mesure.getDate() > instant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
        successeur = true;
      }
      else if( mesure.getDate() > instant && mesure.getDate() < momentSuivant)
      {
        valeurSuivant = mesure.Valeur();
        momentSuivant = mesure.getDate();
      }
  }

  // moyenne des deux
  if (predecesseur && successeur)
  {
    moyPM10 = (valeurSuivant + valeurPrecedent) / 2.;
  }
  else if (predecesseur && ! successeur)
  {
    moyPM10 = valeurPrecedent;
  }
  else if (!predecesseur &&  successeur)
  {
    moyPM10 = valeurSuivant;
  }
  else
  {
    moyPM10 = -1;
  }

  predecesseur = false;
  successeur = false;

  resultatMoyenne.push_back(moyO3);
  resultatMoyenne.push_back(moyNO2);
  resultatMoyenne.push_back(moySO2);
  resultatMoyenne.push_back(moyPM10);

  return resultatMoyenne;
}
