#include <iostream>
#include <string.h> 


using namespace std;

#include "Moment.h"

int main()
{
  Moment m1 ("2016-01-01T00:01:20.609000");
  Moment m2 ("2016-01-01T00:01:20.6090000");
  Moment m3(23,10,2019,01,01,02);

  cout << "Année : " << m3.annee << endl;
  cout << "Mois : " << m3.mois << endl;
  cout << "Jour : " <<  m3.jour << endl;
  cout << "Heure : " <<  m3.heure << endl;
  cout << "Minute : " <<  m3.minute << endl;
  cout << "Seconde : " <<  m3.seconde << endl;

  bool a = m1>m2 ;
  bool b = m1<m2 ;

  cout << "m1 > m2 ? : " << a << endl;
  cout << "m1 < m2 ? : " << b << endl;

  return 0;
} 
