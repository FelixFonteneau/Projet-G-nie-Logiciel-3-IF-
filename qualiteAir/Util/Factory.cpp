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

