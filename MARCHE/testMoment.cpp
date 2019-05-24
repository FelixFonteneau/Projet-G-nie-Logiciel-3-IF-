#include <iostream>
#include <string.h>


using namespace std;

#include "Moment.h"
#include "Mesure.h"

int main()
{


  Moment m1 ("2016-01-01T00:01:20.609000");
  Moment m2 ("2016-01-01T00:01:20.6090000");
  Moment m3(23,10,2019,01,01,02);

  cout << m1 << endl;

  bool a = m1>m2 ;
  bool b = m1<m2 ;
  bool c = m1==m2;

  cout << "m1 > m2 ? : " << a << endl;
  cout << "m1 < m2 ? : " << b << endl;
  cout << "m1 = m2 ? : " << c << endl;



  Mesure mesure(100,m1,"bla","pute/s");
  cout << mesure << endl;

  //MesureNO2 mesure2(200,m2,"chat","salope/s");
  //cout << mesure2 << endl;

  Mesure mt(mesure);
  cout << mt << endl;

  return 0;
}
