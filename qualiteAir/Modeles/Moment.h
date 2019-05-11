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

Moment creerMoment(string s);

#endif // Moment_H
