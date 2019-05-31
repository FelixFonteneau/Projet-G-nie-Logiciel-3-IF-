/*************************************************************************
 MesureNO2  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <MesureNO2> (fichier MesureNO2.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "MesureNO2.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MesureNO2::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



void MesureNO2::ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10){
	mesuresNO2->push_back(*this);
}


//------------------------------------------------- Surcharge d'opérateurs
// MesureNO2 & MesureNO2::operator = ( const MesureNO2 & uneMesureNO2 )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/* MesureNO2::MesureNO2 ( const MesureNO2 & uneMesureNO2 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MesureNO2>" << endl;
#endif
} //----- Fin de MesureNO2 (constructeur de copie) */


MesureNO2::MesureNO2 ( double uneValue, Moment& uneDate, string uneDescription, string uneUnite, string unCapteurid ) :
Mesure (uneValue, uneDate, uneDescription, "NO2", uneUnite, unCapteurid)
// Algorithme :
//
{

#ifdef MAP
    cout << "Appel au constructeur de <MesureNO2>" << endl;
#endif
} //----- Fin de MesureNO2


/* MesureNO2::~MesureNO2 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureNO2>" << endl;
#endif
} //----- Fin de ~MesureNO2 */


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
