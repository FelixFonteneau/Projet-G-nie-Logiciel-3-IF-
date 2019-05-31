/*************************************************************************
 MesurePM10  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <MesurePM10> (fichier MesurePM10.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "MesurePM10.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MesurePM10::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode



void MesurePM10::ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10){
	mesuresPM10->push_back(*this);
}

string MesurePM10::type() const{
	return "PM10";
}

//------------------------------------------------- Surcharge d'opérateurs
// MesurePM10 & MesurePM10::operator = ( const MesurePM10 & uneMesurePM10 )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/* MesurePM10::MesurePM10 ( const MesurePM10 & uneMesurePM10 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MesurePM10>" << endl;
#endif
} //----- Fin de MesurePM10 (constructeur de copie) */


MesurePM10::MesurePM10 ( double uneValue, Moment& uneDate, string uneDescription, string uneUnite, string unCapteurid ) :
Mesure(uneValue, uneDate, uneDescription, uneUnite, unCapteurid)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MesurePM10>" << endl;
#endif
} //----- Fin de MesurePM10


/* MesurePM10::~MesurePM10 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesurePM10>" << endl;
#endif
} //----- Fin de ~MesurePM10 */


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
