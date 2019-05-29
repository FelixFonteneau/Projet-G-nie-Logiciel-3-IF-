/*************************************************************************
 MesureO2  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <MesureO2> (fichier MesureO2.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "MesureO2.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MesureO2::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// MesureO2 & MesureO2::operator = ( const MesureO2 & uneMesureO2 )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/* MesureO2::MesureO2 ( const MesureO2 & uneMesureO2 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MesureO2>" << endl;
#endif
} //----- Fin de MesureO2 (constructeur de copie) */

MesureO2::MesureO2 (double uneValue, Moment& uneDate, string uneDescription, string unType, string uneUnite) :
Mesure(uneValue, uneDate, uneDescription, unType, uneUnite)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MesureO2>" << endl;
#endif
} //----- Fin de MesureO2




/* MesureO2::~MesureO2 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureO2>" << endl;
#endif
} //----- Fin de ~MesureO2 */


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

