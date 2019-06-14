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
#include <vector>
#include <fstream>
#include "Factory.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques

vector<Capteur*>* Factory::RecupererInfos(string nomFichierCapteur, string nomFichierDonnees,
                                          string nomCheminType, string utf8)
{
    vector<Capteur*>* listeCapteur = new vector<Capteur*>;
    recupererType(nomCheminType);
    analyserCapteurs(listeCapteur,nomFichierCapteur);
    remplirCapteurs(listeCapteur,nomFichierDonnees,utf8);
    //retourne une référence vers la liste de capteur stockée dans le tas
    return listeCapteur;
}

//------------------------------------------------- Surcharge d'opérateurs

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
void Factory::recupererType(string nomCheminType)
{
  ifstream file (nomCheminType);
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



void Factory::analyserCapteurs(vector<Capteur*>* listeCapteurs,string nomFichierCapteur)
{
/*    string cheminAcces = "donnees/descriptionCapteurs.csv";
	if(nomFichierCapteur.compare("")!=0){
		cheminAcces = nomFichierCapteur;
	}*/
    ifstream file (nomFichierCapteur);
    string ligne;

	getline(file,ligne);
    // Premiere ligne inutile


    while (getline(file,ligne))
    {
		double latitude, longitude;
		string idCapt;

		idCapt = ligne.substr(6,1);
		string sLatitude = "";
		string sLongitude = "";
		char a = ligne[8];
		int i = 8;
		while(a!=';'){
			sLatitude += a;
			a = ligne[++i];
		}
		a = ligne[++i];
		while(a!=';'){
			sLongitude += a;
			a = ligne[++i];
		}
		latitude = stod(sLatitude);
		longitude = stod(sLongitude);


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

Mesure* Factory::analyserLigne(string ligne, string utf8)
{
    // Important : le string ligne que l'on obtient
    // ci-dessus a une structure extrêmement bizzare :
    // entre chaque caratère visible, il y a un caractère null,
    // ce qui fait qu'un string de taille n à l'écran a en réalité
    // une taille (2*n + 1). Le problème est corrigé avec la fonction décompose,
    // indispensable pour pouvoir utiliser stoi.

    // 2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936;
    int annee, mois, jour, heure, minute, seconde;
	string uneAnnee, unMois, unJour, uneHeure, uneMinute, uneSeconde, idCapt, typeMesure;
	double valeur;
	bool b_utf8 = 1;
	if(utf8.compare("N")==0){
		b_utf8 = 0;
	}
	if(b_utf8){
		uneAnnee = ligne.substr (0,4);
		annee = stoi(uneAnnee);
		unMois = ligne.substr (5,2);
		mois = stoi(unMois);
		unJour = ligne.substr(8,2);
		jour = stoi(unJour);
		uneHeure = ligne.substr(11,2);
		heure = stoi(uneHeure);
		uneMinute = ligne.substr(14,2);
		minute = stoi(uneMinute);
		uneSeconde = ligne.substr(17,2);
		seconde = stoi(uneSeconde);
		idCapt = ligne.substr(34,1);
		typeMesure = "";
		char a = ligne[36];
		int i = 36;
		while(a!=';'){
			typeMesure += a;
			a = ligne[++i];
		}
		string sValeur ="";
		a = ligne[++i];
		while(a!=';'){
			sValeur += a;
			a = ligne[++i];
		}
		valeur = stod(sValeur);
	} else {
		uneAnnee = decompose('-', ligne);
		ligne = ligne.replace(0, 9 + 1, "");
		annee = stoi(uneAnnee);
		unMois = decompose('-', ligne);
		ligne = ligne.replace(0, 5 + 1, "");
		mois = stoi(unMois);
		unJour = decompose('T', ligne);
		ligne = ligne.replace(0, 5 + 1, "");
		jour = stoi(unJour);
		uneHeure = decompose(':', ligne);
		ligne = ligne.replace(0, 5 + 1, "");
		heure = stoi(uneHeure);

		uneMinute = decompose(':', ligne);
		ligne = ligne.replace(0, 5 + 1, "");
		minute = stoi(uneMinute);

		uneSeconde = decompose('.', ligne);
		ligne = ligne.replace(0, ligne.find(';') + 1 , "");
		seconde = stoi(uneSeconde);

		idCapt = decompose(';', ligne);
		idCapt = idCapt.substr(6,1);
		ligne = ligne.replace(0, ligne.find(';') + 1, "");
		typeMesure = decompose(';', ligne);
		ligne = ligne.replace(0, ligne.find(';') + 1, "");

		valeur = stod(decompose(';', ligne));
	}



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
    // Mesure mesure(valeur, moment, description, typeMesure, unite, idCapt);
}


void Factory::remplirCapteurs(vector<Capteur*>* listeCapteurs,string nomFichierDonnees,string utf8)
{
    ifstream file(nomFichierDonnees);
    string ligne;

	unsigned i = 0;
	if(file)
  {
		while(getline(file,ligne))
		{
			try {
				++i;
				Mesure *mesure = analyserLigne(ligne,utf8);
        if (mesure != NULL)
        {
          for (Capteur* capteur : *listeCapteurs)
  				{
  					if(capteur->RecupererId().compare( mesure->Capteur()) == 0)
  					{
  						capteur->AjouterMesure(mesure);
  					}
  				}
  				delete mesure;
        }
			} catch (exception const &exc)
			{
				cerr << "Erreur d'analyse du fichier " << nomFichierDonnees << ", verifiez la synthaxe de la ligne " << i  << "."<< endl;
		  }
	  }
  }
  else
  {
  	cout << "Impossible d'ouvrir le fichier" << endl;
  }
  cout << "Nombre de mesures analysées : " << i << endl << endl;;
}
