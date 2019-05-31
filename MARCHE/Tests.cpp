#include <iostream>
#include <string.h>


using namespace std;


#include "Moment.h"

#include "Mesure.h"
#include "MesureNO2.h"
#include "MesureO3.h"
#include "MesureSO2.h"
#include "MesurePM10.h"

#include "Capteur.h"
#include "Algo.h"
#include "Factory.h"
#include "Messages.h"

void testAlgo()
{

}

void testFactory()
{
    unsigned i = 0;
    Factory uneFactory;
    vector<Capteur*>* listCapteur = uneFactory.AnalyserMesure();
    for(Capteur * capteur : *listCapteur)
    {
      cout << "\n\n\n-- valeurs capteur : " << capteur->RecupererId() << endl;
      cout << "mesures O3 : " << endl;
      for(Mesure mesure : *capteur->RecupererMesuresO3())
      {
        ++i;
        cout << mesure << endl;
      }
      cout << "\nmesures NO2 : " << endl;
      for(Mesure mesure : *capteur->RecupererMesuresNO2())
      {
        ++i;
        cout << mesure << endl;
      }
      cout << "\nmesures SO2 : " << endl;
      for(Mesure mesure : *capteur->RecupererMesuresSO2())
      {
        ++i;
        cout << mesure << endl;
      }
      cout << "\nmesures PM10 : " << endl;
      for(Mesure mesure : *capteur->RecupererMesuresPM10())
      {
        ++i;
        cout << mesure << endl;
      }
    }

    //doit normalement avoir 1000-1 mesures prises dans la factory
    cout << "\n\n" << i << "mesures sont en mémoire" << endl;
	
	for(Capteur * capteur : *listCapteur)
    {
      delete capteur;
    }
	delete listCapteur;
	
}

void testMessages()
{
    Messages unMessage;
    unMessage.affiche();
    unMessage.messageMenu();
    unMessage.affiche();
}



void testMoment()
{
    Moment m1 ("2016-01-01T00:01:20.609000");
    Moment m2 ("2016-01-01T00:01:20.6090000");
    Moment m3(23,10,2019,01,01,02);

    cout << m1 << endl;

    bool a = m1>m3 ;
    bool b = m1<m3 ;
    bool c = m1==m3;

    m1 = m3;

    cout << "m1 > m3 ? : " << a << endl;
    cout << "m1 < m3 ? : " << b << endl;
    cout << "m1 = m3 ? : " << c << endl;
    cout << m1 << endl;
}

/*
void testMesure()
{
    Moment m1 ("2016-01-01T00:01:20.609000");
    Moment m2 ("2016-01-01T00:01:20.6090000");
    Moment m3(23,10,2019,01,01,02);
    Mesure mesure(100,m1,"bla","NO2","pute/s");
    cout << mesure << endl;

    Mesure mesure2(200,m3,"shit","O2","pute/s");
    cout << mesure2 << endl;

    bool a = mesure > mesure2 ;
    bool b = mesure < mesure2 ;
    bool c = mesure == mesure2;

    cout << "m1 > m2 ? : " << a << endl;
    cout << "m1 < m2 ? : " << b << endl;
    cout << "m1 = m2 ? : " << c << endl;

    //MesureNO2 mesure2(200,m2,"chat","salope/s");
    //cout << mesure2 << endl;

    Mesure mt(mesure);
    cout << mt << endl;
    cout << "valeur m1 : " << mesure.Valeur() << endl;
    cout << "valeur m2 : " << mesure2.Valeur() << endl;

    cout << "Type m1 : " << mesure.Type() << endl;
    cout << "Type m2 : " << mesure2.Type() << endl;
} */

int main()
{
    /* cout << endl << "******" << endl;
    cout << "Voici les tests Moments";
    cout << endl << "******" << endl << endl;
    testMoment();


    cout << endl << "******" << endl;
    cout << "Voici les tests Mesure";
    cout << endl << "******" << endl << endl;
    testMesure(); */

    testFactory();
    // testMoment();

    return 0;
}
