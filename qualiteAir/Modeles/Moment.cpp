/*************************************************************************
 Moment  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation du module <Moment> (fichier Moment.cpp) ---------------

/////////////////////////////////////////////////////////////////  INCLUDE
//-------------------------------------------------------- Include système
#include <string>
using namespace std;
//------------------------------------------------------ Include personnel
#include "Moment.h"

///////////////////////////////////////////////////////////////////  PRIVE
//------------------------------------------------------------- Constantes

//------------------------------------------------------------------ Types

//---------------------------------------------------- Variables statiques

//------------------------------------------------------ Fonctions privées
//static type nom ( liste de paramètres )
// Mode d'emploi :
//
// Contrat :
//
// Algorithme :
//
//{
//} //----- fin de nom

//////////////////////////////////////////////////////////////////  PUBLIC
//---------------------------------------------------- Fonctions publiques
// type Nom ( liste de paramètres )
// Algorithme :
//
// {
// } //----- fin de Nom

Moment creerMoment(string s)
{
    
    Moment moment;
    
    //On récupère le début de la ligne qui correspond à la date
    string date = s.substr(0, 22);
    
    //On récupère les différents attributs
    moment.annee = stoi(date.substr(0,4));
    moment.mois = stoi(date.substr(5,2));
    moment.jour = stoi(date.substr(8,2));
    moment.heure = stoi(date.substr(11,2));
    moment.minute = stoi(date.substr(14,2));
    moment.seconde = stoi(date.substr(17,2));
    
    return moment;
}



