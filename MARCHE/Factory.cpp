/*************************************************************************
 Factory  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Factory> (fichier Factory.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Factory.h"
#include <vector>
#include <fstream>

#include "Capteur.h"
#include "Mesure.h"
//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Factory::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


vector<Capteur*>* Factory::AnalyserMesure()
{
  vector<Capteur*>* listeCapteur = new vector<Capteur*>;
  recupererType();
  analyserCapteurs(listeCapteur);
  remplirCapteurs(listeCapteur);
  //retourne une référence vers la liste de capteur stockée dans le tas
  return listeCapteur;
}

//------------------------------------------------- Surcharge d'opérateurs
// Factory & Factory::operator = ( const Factory & uneFactory )
// Algorithme :
//
// {
// } //----- Fin de operator =



//-------------------------------------------- Constructeurs - destructeur
Factory::Factory ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Factory>" << endl;
#endif
} //----- Fin de Factory


Factory::~Factory ( )
// Algorithme :
//
{

	#ifdef MAP
		cout << "Appel au destructeur de <Factory>" << endl;
	#endif

} //----- Fin de ~Factory


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
void Factory::recupererType()
{
  ifstream file ("donnees/AttributeType.csv");
  string ligne;

  // Premiere ligne inutile
  getline(file,ligne);
  while (!file.eof())
  {
      getline(file,ligne);
      string id = ligne.substr(0, ligne.find(";"));
      ligne.erase(0, ligne.find(";") + 1);
      string unite = ligne.substr(0, ligne.find(";"));
      ligne.erase(0, ligne.find(";") + 1);
      string description = ligne.substr(0, ligne.find(";"));
      typeMesure_t type;
      type.attributeID = id;
      type.unite = unite;
      type.description = description;
#ifdef MAP
      cout << id << " " << unite << " " << description << endl;
#endif
      listeType.push_back(type);
  }
}



void Factory::analyserCapteurs(vector<Capteur*>* listeCapteurs)
{
    // Sensor0;-8.15758888291083;-34.7692487876719;;
    ifstream file ("donnees/descriptionsCapteurs.csv");
    string ligne;

    // Premiere ligne inutile
    getline(file,ligne);

    while (!file.eof())
    {

        getline(file,ligne);
        // cout << ligne;
        // On arrive à la première ligne intéressante
        string idCapt = decompose(';', ligne);
        ligne = ligne.replace(0, idCapt.size() + 1, "");
        const double latitude = stod(decompose(';', ligne));
        ligne = ligne.replace(0, ligne.find(';') + 1, "");
        const double longitude = stod(decompose(';', ligne));
        ligne = ligne.replace(0, ligne.find(';') + 1, "");
        Capteur *capteur = new Capteur(idCapt, latitude, longitude, "une description");
#ifdef MAP
        cout << idCapt << " " << longitude << " " << latitude << endl;
#endif
        listeCapteurs->push_back(capteur);
    }
}





string Factory::decompose(char const sep, string uneLigne)
{
    int i = 0;
    char a = uneLigne[i];
    string retour = "";
    while (a != sep)
    {

        if (a != 0)
        {
            retour += a;
        }
        a = uneLigne[++i];
    }
    return retour;
}

Mesure* Factory::analyserLigne(string ligne)
{
  // Commentaire de grande importance : le string ligne que l'on obtient
  // ci-dessus a une structure extrêmement bizzare :
  // entre chaque caratère visible, il y a un caractère null,
  // ce qui fait qu'un string de taille n à l'écran a en réalité
  // une taille (2*n + 1). Le problème est corrigé avec la fonction décompose,
  // indispensable pour pouvoir utiliser stoi.


    // 2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936;
    // cout << endl << ligne << endl;
    int annee, mois, jour, heure, minute, seconde;
    string uneAnnee = decompose('-', ligne);
    ligne = ligne.replace(0, 9 + 1, "");
    annee = stoi(uneAnnee);

    string unMois = decompose('-', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    mois = stoi(unMois);

    string unJour = decompose('T', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    jour = stoi(unJour);

    string uneHeure = decompose(':', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    heure = stoi(uneHeure);

    string uneMinute = decompose(':', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    minute = stoi(uneMinute);

    string uneSeconde = decompose('.', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1 , "");
    seconde = stoi(uneSeconde);

    // Sensor2
    string idCapt = decompose(';', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1, "");
    string typeMesure = decompose(';', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1, "");

    double valeur = stod(decompose(';', ligne));

    Moment moment = Moment(jour, mois, annee, heure, minute, seconde);

    string unite, description;
    for (typeMesure_t type : listeType)
    {
      if(type.attributeID.compare(typeMesure) == 0)
      {
        unite = type.unite;
        description = type.description;
      }
    }


	if(typeMesure.compare("O3")==0){
		MesureO3 *mesure = new MesureO3(valeur, moment, description, unite, idCapt);
		return mesure;
	} else if(typeMesure.compare("NO2")==0){
		MesureNO2 *mesure = new MesureNO2(valeur, moment, description, unite, idCapt);
		return mesure;
	} else if(typeMesure.compare("SO2")==0){	
		MesureSO2 *mesure = new MesureSO2(valeur, moment, description, unite, idCapt);
		return mesure;
	} else if(typeMesure.compare("PM10")==0){	
		MesurePM10 *mesure = new MesurePM10(valeur, moment, description, unite, idCapt);
		return mesure;
	} else {
		Mesure * mesurePtr = NULL;
		return mesurePtr;
	}
    //Mesure mesure(valeur, moment, description, typeMesure, unite, idCapt);
}


void Factory::remplirCapteurs(vector<Capteur*>* listeCapteurs)
{

    ifstream file ("donnees/donneesCapteurs.csv");
    string ligne;

    // on passes les premières 14 lignes inutiles
    for (int i = 1; i < 14; i++)
    {
        getline(file,ligne);
    }

    //puis on analyse toutes les lignes
    unsigned i = 0;
    for(unsigned y(0); y<1000; y++)
	//C'est quoi ce 1000?
    {
        ++i;
        getline(file,ligne);
        Mesure *mesure = analyserLigne(ligne);
		//cout << mesure->quiSuisJe() << endl;
        for (Capteur* capteur : *listeCapteurs)
        {
          if(capteur->RecupererId().compare( mesure->Capteur()) == 0)
          {
            capteur->AjouterMesure(*mesure);
          }
        }
    }
#ifdef MAP
    cout << "nombre de mesures analysees : " << i << endl;
#endif
}
