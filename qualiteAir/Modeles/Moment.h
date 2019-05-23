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

  Moment(string s) :
      jour(stoi(s.substr(0, 22).substr(8,2))),
      mois(stoi(s.substr(0, 22).substr(5,2))),
      annee(stoi(s.substr(0, 22).substr(0,4))),
      heure(stoi(s.substr(0, 22).substr(11,2))),
      minute(stoi(s.substr(0, 22).substr(14,2))),
      seconde(stoi(s.substr(0, 22).substr(17,2))) {}

  Moment(int j, int m, int a, int h, int min, int sec) :
      jour(j),
      mois(m),
      annee(a),
      heure(h),
      minute(min),
      seconde(sec) {}

  bool operator > (const Moment m) {
      bool ans =  (annee>m.annee)
                ||(annee==m.annee && mois>m.mois)
                ||(annee==m.annee && mois==m.mois && jour>m.jour)
                ||(annee==m.annee && mois==m.mois && jour==m.jour && heure>m.heure)
                ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute>m.minute)
                ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute==m.minute && seconde>m.seconde);

      return ans;
  }

  bool operator < (const Moment m) {
      bool ans =  (annee<m.annee)
                ||(annee==m.annee && mois<m.mois)
                ||(annee==m.annee && mois==m.mois && jour<m.jour)
                ||(annee==m.annee && mois==m.mois && jour==m.jour && heure<m.heure)
                ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute<m.minute)
                ||(annee==m.annee && mois==m.mois && jour==m.jour && heure==m.heure && minute==m.minute && seconde<m.seconde);

      return ans;
  }

}Moment;


#endif // Moment_H
