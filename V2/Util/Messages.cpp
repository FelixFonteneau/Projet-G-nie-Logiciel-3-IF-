/*************************************************************************
 Messages  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Messages> (fichier Messages.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <list>
#include <map>

//------------------------------------------------------ Include personnel
#include "Messages.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Messages::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
void Messages::messageMenu()
{
    
}
double* Messages::recupererLocalisation()
{
    
}
double Messages::recupererRadius()
{
    
}
double Messages::recupererCapteur()
{
    
}
Moment* Messages::recupererIntervalleTemps()
{
    
}
Moment Messages::recupererMoment()
{
    
}
void Messages::afficherCapteursCorreles(map<Capteur,Capteur> capteurs)
{
    
}
void Messages::afficherMoyenne(Mesure* mesuresMoyennes, double indiceATMO)
{
    
}
void Messages::afficherDefaillance(Capteur capteur, list<Mesure> mesures)
{
    
}

//------------------------------------------------- Surcharge d'opérateurs
// Messages & Messages::operator = ( const Messages & desMessages )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Messages::Messages ( const Messages & desMessages )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Messages>" << endl;
#endif
} //----- Fin de Messages (constructeur de copie)


Messages::Messages ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Messages>" << endl;
#endif
} //----- Fin de Messages


Messages::~Messages ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Messages>" << endl;
#endif
} //----- Fin de ~Messages


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées

