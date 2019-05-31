 /*************************************************************************
                           Moment  -  description
                             -------------------
    début                : $DATE$
    copyright            : (C) $YEAR$ par $AUTHOR$
    e-mail               : $EMAIL$
*************************************************************************/

//---------- Réalisation de la classe <Moment> (fichier Moment.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;

//------------------------------------------------------ Include personnel
#include "Moment.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Moment::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


//------------------------------------------------- Surcharge d'opérateurs
ostream& operator<<(ostream &strm, const Moment &m) {

    string annee = to_string(m.annee);
    string mois = to_string(m.mois);
    if(mois.length()==1){mois = "0" + mois;}
    string jour = to_string(m.jour);
    if(jour.length()==1){jour = "0" + jour;}
    string heure = to_string(m.heure);
    if(heure.length()==1){heure = "0" + heure;}
    string minute = to_string(m.minute);
    if(minute.length()==1){minute = "0" + minute;}
    string seconde = to_string(m.seconde);
    if(seconde.length()==1){seconde = "0" + seconde;}

    return strm << jour << "/" << mois << "/" << annee << " " << heure << ":" << minute << ":" << seconde;

}

bool Moment::operator < (const  Moment &m)
{
    bool ans =  (annee<m.annee)
              ||(annee==m.annee && mois<m.mois)
              ||(annee==m.annee && mois==m.mois && jour<m.jour)
              ||(annee==m.annee && mois==m.mois && jour==m.jour && heure<m.heure)
              ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute<m.minute)
              ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute==m.minute && seconde<m.seconde);

    return ans;
}

bool Moment::operator > (const Moment &m) {
    bool ans =  (annee>m.annee)
              ||(annee==m.annee && mois>m.mois)
              ||(annee==m.annee && mois==m.mois && jour>m.jour)
              ||(annee==m.annee && mois==m.mois && jour==m.jour && heure>m.heure)
              ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute>m.minute)
              ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute==m.minute && seconde>m.seconde);

    return ans;
}

Moment& Moment::operator = (const Moment& m)
{
    jour = m.getJour();
    mois = m.getMois();
    annee = m.getAnnee();
    heure = m.getHeure();
    minute = m.getMinute();
    seconde = m.getSeconde();
    return *this;
}
//-------------------------------------------- Constructeurs - destructeur
Moment::Moment(){}

Moment::Moment ( const Moment & unMoment )
// Algorithme :
//
{
      jour = unMoment.jour;
      mois = unMoment.mois;
      annee = unMoment.annee;
      heure = unMoment.heure;
      minute = unMoment.minute;
      seconde = unMoment.seconde;
    #ifdef MAP
        cout << "Appel au constructeur de copie de <Moment>" << endl;
    #endif
} //----- Fin de Moment (constructeur de copie)

Moment::Moment(int j, int m, int a, int h, int min, int sec) :
    jour(j), mois(m), annee(a), heure(h), minute(min), seconde(sec)
{
    #ifdef MAP
      cout << "Appel au constructeur de <Moment>" << endl;
    #endif
}

Moment::Moment(string s) :
    jour(stoi(s.substr(0, 22).substr(8,2))),
    mois(stoi(s.substr(0, 22).substr(5,2))),
    annee(stoi(s.substr(0, 22).substr(0,4))),
    heure(stoi(s.substr(0, 22).substr(11,2))),
    minute(stoi(s.substr(0, 22).substr(14,2))),
    seconde(stoi(s.substr(0, 22).substr(17,2)))
{
  #ifdef MAP
      cout << "Appel au constructeur de <Moment>" << endl;
  #endif
}


Moment::~Moment ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Moment>" << endl;
#endif
} //----- Fin de ~Moment


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
