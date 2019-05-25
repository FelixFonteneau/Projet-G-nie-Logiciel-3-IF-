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
#include "Moment.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Mesure::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode
double Mesure::Valeur () const
{
  return value;
}

string Mesure::Type () const
{
  return type;
}

//------------------------------------------------- Surcharge d'opérateurs
ostream& operator <<(ostream& out, const Mesure& uneMesure)
{
    out << "Le "<< uneMesure.date <<" : " << uneMesure.value << uneMesure.unite
    << " "<< typeid(uneMesure).name();
    return out; // N'oubliez pas de renvoyer le flux, afin de pouvoir chaîner les appels
}



//-------------------------------------------- Constructeurs - destructeur
// Le constructeur de copie présenté ici ne fonctionne pas, il faudrait rajouter les getters
/* Mesure::Mesure ( const Mesure & unMesure ) :
 description(unMesure.description), unite(unMesure.unite),
 type(unMesure.type), value(unMesure.value), date(unMesure.date)
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Mesure>" << endl;
#endif
} //----- Fin de Mesure (constructeur de copie) */


Mesure::Mesure (double uneValue, Moment uneDate, string uneDescription, string unType, string uneUnite) :
       value(uneValue), date(uneDate), description(uneDescription), type(unType), unite(uneUnite)
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
