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

void Factory::analyserMesure(string ligne)
{
    cout << endl;
    cout << ligne;
    cout << endl;
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

