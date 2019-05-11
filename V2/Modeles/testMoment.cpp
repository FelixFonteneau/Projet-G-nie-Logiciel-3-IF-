#include <iostream>
#include <string.h> 


using namespace std;

#include "Moment.h"

int main()
{
  Moment m1;
  Moment m2;
  m1 = creerMoment("2017-01-01T00:01:20.6090000");
  m2 = creerMoment("2018-01-01T00:01:20.6090000");

  /*cout << "Année : " << m1.annee << endl;
  cout << "Mois : " << m1.mois << endl;
  cout << "Jour : " <<  m1.jour << endl; 
  cout << "Heure : " <<  m1.heure << endl;
  cout << "Minute : " <<  m1.minute << endl;
  cout << "Seconde : " <<  m1.seconde << endl;*/

  /*bool a = m1<m2 ;
  bool b = m2<m1 ; 

  cout << "m1 < m2 ? : " << a << endl;
  cout << "m2 < m1 ? : " << b << endl;*/

  return 0;
} 
