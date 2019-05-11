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
using namespace std;

//------------------------------------------------------ Include personnel
#include "Algo.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Algo::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// Algo & Algo::operator = ( const Algo & unAlgo )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Algo::Algo ( const Algo & unAlgo )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Algo>" << endl;
#endif
} //----- Fin de Algo (constructeur de copie)


Algo::Algo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Algo>" << endl;
#endif
} //----- Fin de Algo


Algo::~Algo ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Algo>" << endl;
#endif
} //----- Fin de ~Algo


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

