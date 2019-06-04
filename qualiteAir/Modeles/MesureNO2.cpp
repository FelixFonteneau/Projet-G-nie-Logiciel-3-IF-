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
void MesureNO2::ajout( vector<MesureO3>* mesuresO3, vector<MesureNO2>* mesuresNO2, vector<MesureSO2>* mesuresSO2, vector<MesurePM10>* mesuresPM10){
	mesuresNO2->push_back(*this);
}

string MesureNO2::type() const{
	return "NO2";
}


//------------------------------------------------- Surcharge d'opérateurs

//-------------------------------------------- Constructeurs - destructeur

MesureNO2::MesureNO2 ( double uneValue, Moment& uneDate, string uneDescription, string uneUnite, string unCapteurid ) :
Mesure (uneValue, uneDate, uneDescription, uneUnite, unCapteurid)
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
