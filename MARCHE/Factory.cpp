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

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Xxx::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// Factory & Factory::operator = ( const Factory & uneFactory )
// Algorithme :
//
// {
// } //----- Fin de operator =

vector<Capteur> Factory::recupererInfos()
{
    cout << "début de la methode recupererInfos" << endl;
    ifstream file ("donneesCapteurs.csv");
    string ligne;
    for (int i = 1; i < 14; i++)
    {
        getline(file,ligne);
    }
    // On arrive à la première ligne intéressante
    
    
    // Commentaire de grande importance : le string ligne que l'on obtient ci-dessus a une structure extrêmement bizzare : entre chaque caratère visible, il y a un caractère null, ce qui fait qu'un string de taille n à l'écran a en réalité une taille (2*n + 1). Le problème est corrigé avec la fonction décompose, indispensable pour pouvoir utiliser stoi.
    
    
    cout << ligne << endl;
    string uneAnnee = decompose('-', ligne);
    ligne = ligne.replace(0, 9 + 1, "");
    int annee = stoi(uneAnnee);
    
    string unMois = decompose('-', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    int mois = stoi(unMois);
    
    string unJour = decompose('T', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    int jour = stoi(unJour);
    
    string uneHeure = decompose(':', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    int heure = stoi(uneHeure);
    
    string uneMinute = decompose(':', ligne);
    ligne = ligne.replace(0, 5 + 1, "");
    int minute = stoi(uneMinute);
    
    string uneSeconde = decompose('.', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1 , "");
    int seconde = stoi(uneSeconde);
    
    const string idCapt = decompose(';', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1, "");
    
    string typeMesure = decompose(';', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1, "");
    
    double valeur = stod(decompose(';', ligne));

    
    
    // Moment moment = Moment(jour, mois, annee, heure, minute, seconde);
    // Mesure mesure = Mesure(valeur, moment, "", typeMesure, "");
    // premier "" description ; second "" unite
    
	
	
    capteurs[0]->addMesureO2(jour, mois, annee, heure, minute, seconde, valeur, typeMesure);
	

    vector<Capteur> liste = {};
    return liste;
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

const string Factory::analyserMesure(string ligne)
{
    // 2017-01-01T00:01:20.6090000;Sensor0;O3;17.8902017543936;
    // cout << endl << ligne << endl;

    string annee = decompose('-', ligne);
    ligne = ligne.replace(0, annee.size() + 1, "");
    string mois = decompose('-', ligne);
    ligne = ligne.replace(0, mois.size() + 1, "");
    string jour = decompose('T', ligne);
    ligne = ligne.replace(0, jour.size() + 1, "");
    string heure = decompose(':', ligne);
    ligne = ligne.replace(0, heure.size() + 1, "");
    string minute = decompose(':', ligne);
    ligne = ligne.replace(0, minute.size() + 1, "");
    string seconde = decompose('.', ligne);
    ligne = ligne.replace(0, ligne.find(';') + 1 , "");
    const string idCapt = decompose(';', ligne);
    ligne = ligne.replace(0, idCapt.size() + 1, "");
    string typeMesure = decompose(';', ligne);
    ligne = ligne.replace(0, typeMesure.size() + 1, "");
    string valeur = decompose(';', ligne);
    ligne = ligne.replace(0, valeur.size() + 1, "");
                     

    return idCapt;
    // cout << annee << " " << mois << " " << jour << " " << heure << " " << minute << " " << seconde << " " << idCapt << " " << typeMesure << " " << valeur << endl;
}

void Factory::analyserCapteurs()
{
    // Sensor0;-8.15758888291083;-34.7692487876719;;
    ifstream file ("descriptionsCapteurs.csv");
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
        cout << idCapt << " " << longitude << " " << latitude << endl;
        capteurs.push_back(capteur);
    }

   
}

//-------------------------------------------- Constructeurs - destructeur
Factory::Factory ( const Factory & uneFactory )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Factory>" << endl;
#endif
} //----- Fin de Factory (constructeur de copie)


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
	for(unsigned int i = 0; i <  capteurs.size() ; i++) {
		delete capteurs[i];
	}

} //----- Fin de ~Factory


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

