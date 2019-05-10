/*************************************************************************
                           Moment  -  Décrit un moment
                             -------------------
    début                : 10 mai 2019
    copyright            : (C) Mathis GUILHIN
    e-mail               : mathis.guilhin@insa-lyon.fr
*************************************************************************/

//---------- Interface du module <Moment> (fichier Moment.h) -------------------
#if ! defined ( Moment_H )
#define Moment_H

typedef struct Moment{
  int jour;
  int mois;
  int annee;
  int heure;
  int minute;
  int seconde;

  inline bool operator > (Moment m) {
    bool ans =  (annee<m.annee)
              ||(annee==m.annee && mois<m.mois)
	      ||(annee==m.annee && mois==m.mois && jour<m.jour)
	      ||(annee==m.annee && mois==m.mois && jour==m.jour && heure<m.heure)
	      ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute<m.minute)
	      ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute==m.minute && seconde<m.seconde);
	
    return ans;
  }
} Moment;

Moment creerMoment(string s){
  
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

#endif // Moment_H
