/*************************************************************************
 MesureO3  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <MesureO3> (fichier MesureO3.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "MesureO3.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MesureO3::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// MesureO3 & MesureO3::operator = ( const MesureO3 & uneMesureO3 )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/* MesureO3::MesureO3 ( const MesureO3 & uneMesureO3 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MesureO3>" << endl;
#endif
} //----- Fin de MesureO3 (constructeur de copie) */

MesureO3::MesureO3 ( double uneValue, Moment& uneDate, string uneDescription,
         string unType, string uneUnite, string unCapteurid ) :
Mesure(uneValue, uneDate, uneDescription, unType, uneUnite, unCapteurid)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MesureO3>" << endl;
#endif
} //----- Fin de MesureO3




/* MesureO3::~MesureO3 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureO3>" << endl;
#endif
} //----- Fin de ~MesureO3 */


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
