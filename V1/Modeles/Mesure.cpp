/*************************************************************************
                           Xxx  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Xxx.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;


//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
void Mesure::afficher ()
// Algorithme :
//
{
    cout << "La valeur est " << value << endl;
    cout << "La description est " << description << endl;
    cout << "L'unité est " << unit << endl;
} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
//Mesure & Mesure::operator = ( const Mesure & uneMesure )
// Algorithme :
//
//{
//} //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure ( const Mesure & uneMesure )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Xxx>" << endl;
#endif
} //----- Fin de Xxx (constructeur de copie)


Mesure::Mesure (double uneValue, string uneDescription, string uneUnit)
// Algorithme :
//
{
    value = uneValue;
    description = uneDescription;
    unit = uneUnit;
#ifdef MAP
    cout << "Appel au constructeur de <Xxx>" << endl;
#endif
} //----- Fin de Xxx


Mesure::~Mesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Xxx>" << endl;
#endif
} //----- Fin de ~Xxx


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

