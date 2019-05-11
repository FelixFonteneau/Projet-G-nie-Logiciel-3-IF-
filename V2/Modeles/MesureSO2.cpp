/*************************************************************************
 MesureSO2  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <MesureSO2> (fichier MesureSO2.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "MesureSO2.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type MesureSO2::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
// MesureSO2 & MesureSO2::operator = ( const MesureSO2 & uneMesureSO2 )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
MesureSO2::MesureSO2 ( const MesureSO2 & uneMesureSO2 )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <MesureSO2>" << endl;
#endif
} //----- Fin de MesureSO2 (constructeur de copie)


MesureSO2::MesureSO2 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <MesureSO2>" << endl;
#endif
} //----- Fin de MesureSO2


MesureSO2::~MesureSO2 ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <MesureSO2>" << endl;
#endif
} //----- Fin de ~MesureSO2


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

