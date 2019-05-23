/*************************************************************************
                           Mesure  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Mesure> (fichier Mesure.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Mesure.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Mesure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
/*double Mesure::Valeur () const{
  return value;
} */


//------------------------------------------------- Surcharge d'opérateurs
/*ostream& operator <<(ostream& out, const Mesure& uneMesure)
{
    out << "Le "<< uneMesure.date <<" : " << uneMesure.value << uneMesure.unite
    << " "<< typeid(uneMesure).name();
    return out; // N'oubliez pas de renvoyer le flux, afin de pouvoir chaîner les appels
}*/

/*
Mesure & Mesure::operator = ( const Mesure & unMesure )
// Algorithme :
//
{
  this->value = unMesure.value;
  this->description = unMesure.description;
  this->unite = unMesure.unite ;
  this->date = unMesure.date;
  return unMesure;
} //----- Fin de operator = */


//-------------------------------------------- Constructeurs - destructeur
Mesure::Mesure ( const Mesure & unMesure ) :
 description(unMesure.description), unite(unMesure.unite),
 value(unMesure.value), date(unMesure.date)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif
} //----- Fin de Mesure (constructeur de copie)


Mesure::Mesure (double uneValue, Moment uneDate, string uneDescription, string uneUnite ) :
        description(uneDescription), unite(uneUnite), value(uneValue), date(uneDate)
{
  #ifdef MAP
      cout << "Appel au constructeur de <Mesure>" << endl;
  #endif
};



Mesure::~Mesure ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Mesure>" << endl;
#endif
} //----- Fin de ~Mesure


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
