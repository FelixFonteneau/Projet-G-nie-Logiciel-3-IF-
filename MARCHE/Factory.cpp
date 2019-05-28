/*************************************************************************
 Factory  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Xxx> (fichier Xxx.cpp) ------------

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

list<Capteur> Factory::recupererInfos()
{
    ifstream file ("donneesCapteurs.csv");
    string ligne;
    for (int i = 1; i < 14; i++)
    {
        getline(file,ligne);
    }
    // On arrive à la première ligne intéressante
   
    analyserMesure(ligne);
    // Capteur capteur = Capteur("youhou",0,0,"");
    list<Capteur> liste = {};
    return liste;
}

string Factory::decompose(char const sep, string uneLigne)
{
    int i = 0;
    char a = uneLigne[i];
    string retour = "";
    while (a != sep)
    {
        retour += a;
        a = uneLigne[++i];
    }
    return retour;
}

void Factory::analyserMesure(string ligne)
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
    string idCapt = decompose(';', ligne);
    ligne = ligne.replace(0, idCapt.size() + 1, "");
    string typeMesure = decompose(';', ligne);
    ligne = ligne.replace(0, typeMesure.size() + 1, "");
    string valeur = decompose(';', ligne);
    ligne = ligne.replace(0, valeur.size() + 1, "");
                     


    // cout << annee << " " << mois << " " << jour << " " << heure << " " << minute << " " << seconde << " " << idCapt << " " << typeMesure << " " << valeur << endl;
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
} //----- Fin de ~Factory


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

