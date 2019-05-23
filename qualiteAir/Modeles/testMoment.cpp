#include <iostream>
#include <string.h> 


using namespace std;

#include "Moment.h"

int main()
{
  Moment m1 ("2016-01-01T00:01:20.609000");
  Moment m2 ("2016-01-01T00:01:20.6090000");

  cout << "Année : " << m1.annee << endl;
  cout << "Mois : " << m1.mois << endl;
  cout << "Jour : " <<  m1.jour << endl; 
  cout << "Heure : " <<  m1.heure << endl;
  cout << "Minute : " <<  m1.minute << endl;
  cout << "Seconde : " <<  m1.seconde << endl;

  bool a = m1>m2 ;
  bool b = m1<m2 ;

  cout << "m1 > m2 ? : " << a << endl;
  cout << "m1 < m2 ? : " << b << endl;

  return 0;
} 
