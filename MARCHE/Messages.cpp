/*************************************************************************
 Messages  -  description
 -------------------
 début                : $DATE$
 copyright            : (C) $YEAR$ par $AUTHOR$
 e-mail               : $EMAIL$
 *************************************************************************/

//---------- Réalisation de la classe <Messages> (fichier Messages.cpp) ------------

//---------------------------------------------------------------- INCLUDE

//-------------------------------------------------------- Include système
#include <iostream>
using namespace std;
#include <list>
#include <map>
#include <ctime>
#include <unistd.h>
#include <regex>
#include <string>
#include <algorithm>

//------------------------------------------------------ Include personnel
#include "Messages.h"

//------------------------------------------------------------- Constantes

//----------------------------------------------------------------- PUBLIC

//----------------------------------------------------- Méthodes publiques
// type Messages::Méthode ( liste des paramètres )
// Algorithme :
//
//{
//} //----- Fin de Méthode


int Messages::MessageMenu()
{
    cout << "Vous souhaitez :" << endl;
    cout << "1 - Obtenir la qualité de l'air moyenne sur un territoire précis à une date précise" << endl;
    cout << "2 - Obtenir la qualité de l'air moyenne sur un terrotoire précis sur une période précise" << endl;
    cout << "3 - Trouver les capteurs ayant un comportement similaire" << endl;
    cout << "4 - Obtenir les valeurs caractérisant la qualité de l'air à un point précis" << endl;
    cout << "5 - Obtenir la liste des capteurs qui ne fonctionnent pas" << endl;
    cout << "6 - Quitter" << endl << endl;
    string tmp;
    getline(cin,tmp);
	cout << endl;
	while(tmp.size() != 1 || !isdigit(tmp[0]) || !tmp.compare("7") || !tmp.compare("8") || !tmp.compare("9")) {
		cout << "Vous devez renseigner un chiffre entre 0 et 6" << endl;
		getline(cin,tmp);
		cout << endl;
	}
	int num = stoi(tmp);
    return num;
}

void Messages::Initialisation()
{
	cout << "Bonjour, et bienvenue dans cette application de surveillance de la qualité de l'air." << endl ;
	cout << "Le service est en cours d'initialisation, veuillez patientez..."  << endl << endl;
}

void Messages::Quitter()
{
	cout << "Merci et à bientôt !"  << endl << endl;
}

vector<double> Messages::RecupererLocalisation()
{
    double latitude(0);
    double longitude(0);
    string tmp;
    const regex txt_regex("^(-?)(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    cout << "Quelle est la latitude centrale du lieu souhaité ? Format : 'nombre' et '.' seulement acceptés, doit etre compris entre -90 et 90." << endl << endl;
    getline(cin, tmp);
    cout << endl;
    do
    {
        while(! regex_match(tmp, txt_regex) ) {
          cout << "Mauvais format," << endl;
          cout << "Quelle est la latitude centrale du lieu souhaité ? Format : 'nombre' et '.' seulement acceptés, doit etre compris entre -90 et 90." << endl << endl;
          getline(cin, tmp);
          cout << endl;
        }
        latitude = stod(tmp);
        tmp = "";
    } while ( latitude > 90 || latitude < -90 );

    cout << "Quelle est la longitude centrale du lieu souhaité ? Format : 'nombre' et '.' seulement acceptés, doit etre compris entre -180 et 180." << endl << endl;
    getline(cin, tmp);
    cout << endl;
    do
    {

        while(! regex_match(tmp, txt_regex))
        {
          cout << "Mauvais format," << endl;
          cout << "Quelle est la longitude centrale du lieu souhaité ? Format : 'nombre' et '.' seulement acceptés, doit etre compris entre -180 et 180." << endl << endl;
          getline(cin, tmp);
          cout << endl;
        }
        longitude = stod(tmp);
        tmp = "";
    } while (longitude > 180 || longitude < -180 );


    vector<double> coord;
    coord.push_back(latitude);
    coord.push_back(longitude);

    return coord;
}

bool Messages::ChoixZone()
{
	string tmp;
	do
    {
      cout << "1 - Effectuer la requête sur tous les capteurs" << endl;
      cout << "2 - Effectuer la requête sur les capteurs d'un territoire délimité" << endl << endl;
      getline(cin,tmp);
      cout << endl;
    } while (tmp.compare("1") != 0 && tmp.compare("2") != 0);
	if (tmp.compare("1") == 0) {
		return false;
	}else{
		return true;
	}
}

bool Messages::ChoixTemporel()
{
	string tmp;
	do{
      cout << "1 - Effectuer la requête sur une durée (entre deux instant de temps)." << endl;
      cout << "2 - Effectuer la requête sur un instant." << endl << endl;
      getline(cin,tmp);
      cout << endl;
    } while (tmp.compare("1") != 0 && tmp.compare("2") != 0);
	if (tmp.compare("1") == 0) {
		return true;
	}else{
		return false;
	}
}

double Messages::RecupererRadius()
{
    double radius;
    string tmp;
    const regex txt_regex("^(0|([1-9][0-9]*))(\\.[0-9]+)?$");
    do
    {
        cout << "Quel est le rayon (en km) ? Format : 'nombres' et '.' seulement acceptés et radius > 0." << endl << endl;
        getline(cin, tmp);
		cout << endl;
    } while (! regex_match(tmp, txt_regex));
    radius = stod(tmp);

    return radius;
}

vector<Moment> Messages::RecupererIntervalleTemps()
{
    // Au format JJ/MM/AAAA HH:MM
    string dateDebut = "01/01/2019 10:10";
    string dateFin = "01/01/2019 10:10";
    cout << "Quelle est la date de début (Au format JJ/MM/AAAA HH:MM) ?" << endl << endl;;
    getline(cin, dateDebut);
	cout << endl;
    const regex txt_regex("^[0-9]{2}/[0-9]{2}/[0-9]{4} [0-9]{2}:[0-9]{2}$");
    while (! regex_match(dateDebut, txt_regex))
    {
        cout << "Mauvais format (JJ/MM/AAAA HH:MM demandé). Quelle est la date ?" << endl;
        getline(cin, dateDebut);
    }

	int jourDebut = stoi(dateDebut.substr(0, 2));
    int moisDebut = stoi(dateDebut.substr(3, 2));
    int anneeDebut = stoi(dateDebut.substr(6, 4));
    int heureDebut = stoi(dateDebut.substr(11, 2));
    int minuteDebut = stoi(dateDebut.substr(14, 2));
    Moment momentDebut(jourDebut, moisDebut, anneeDebut, heureDebut, minuteDebut, 0);
	Moment momentFin;

    cout << "Quelle est la date de fin (Au format JJ/MM/AAAA HH:MM) ?" << endl << endl;
    getline(cin, dateFin);
	cout << endl;
	do
	{
		while (! regex_match(dateFin, txt_regex))
		{
			cout << "Mauvais format (JJ/MM/AAAA HH:MM demandé). Quelle est la date ?" << endl << endl;
			getline(cin, dateFin);
			cout << endl;
		}
		int jourFin = stoi(dateFin.substr(0, 2));
		int moisFin = stoi(dateFin.substr(3, 2));
		int anneeFin = stoi(dateFin.substr(6, 4));
		int heureFin = stoi(dateFin.substr(11, 2));
		int minuteFin = stoi(dateFin.substr(14, 2));
		momentFin = Moment(jourFin, moisFin, anneeFin, heureFin, minuteFin, 0);
		if(momentFin<momentDebut){
			cout << "La date de fin doit être postérieure à la date de début" << endl ;
			cout << "Quelle est la date de fin (Au format JJ/MM/AAAA HH:MM) ?" << endl << endl;
			getline(cin, dateFin);
			cout << endl;
		}
	}
	while(momentFin<momentDebut);
    vector<Moment> intervalleTempsDemande;



    intervalleTempsDemande.push_back(momentDebut);
    intervalleTempsDemande.push_back(momentFin);

    return intervalleTempsDemande;
}

Moment Messages::RecupererMoment()
{
    string dateDemande;

    cout << "Quelle est la date (Au format JJ/MM/AAAA HH:MM) ?" << endl << endl;;
    getline(cin, dateDemande);
	cout << endl;
    const regex txt_regex("^[0-9]{2}/[0-9]{2}/[0-9]{4} [0-9]{2}:[0-9]{2}$");
    while (! regex_match(dateDemande, txt_regex))
    {
        cout << "Mauvais format (JJ/MM/AAAA HH:MM demandé). Quelle est la date ?" << endl << endl;
        getline(cin, dateDemande);
		cout << endl;
    }

    int jour = stoi(dateDemande.substr(0, 2));
    int mois = stoi(dateDemande.substr(3, 2));
    int annee = stoi(dateDemande.substr(6, 4));
    int heure = stoi(dateDemande.substr(11, 2));
    int minute = stoi(dateDemande.substr(14, 2));

    Moment moment = Moment(jour, mois, annee, heure, minute, 0);
    return moment;
}


void Messages::AfficherCapteursCorreles(double** similitudes,int size)
{
    int pourcentage;
    cout << "           | ";
    for (int i = 0; i< size; i++) {
		cout << "Capteur " << i <<  " | " ;
	}
    cout << endl;
    for(int l = 0 ; l < size + 1; l++){
        cout << "------------";
    }
    cout << endl;
	for (int i = 0 ; i < size ; i++) {
		cout << "Capteur " << i << "  ";
		for (int k = 0; k < i; k++)
			cout << "            ";
		for (int j = i; j < size; j++) {
			if (i == j){
				cout << "    100%   ";
			} else {
                pourcentage = (int)similitudes[i][j];
                if (pourcentage < 10 && pourcentage != -1) {
                    cout << "       " << pourcentage << "%   ";
				}else if (pourcentage == 100) {
                    cout << "     100%   ";
                } else cout << "      " << pourcentage << "%   ";
			}
		}
		cout << endl;
		for(int l = 0 ; l < size + 1; l++){
			cout << "------------";
		}
		cout << endl ;
	}
	cout << endl << "(Un score de -1% signifie qu'aucune donnée n'a été trouvée sur cette periode là)" << endl << endl;
}

void Messages::AfficherCapteursDefaillants(vector<pair<Capteur*,int>> capteurs) {
	if(capteurs.size() == 0) {
		cout << "Il n'y a pas de capteur défaillant." << endl;
	} else {
		for(pair<Capteur* , int> c : capteurs) {
            cout << "Le capteur " << c.first->RecupererId();
            if (c.second == 0) {
                cout << " a affectué des mesures dont les valeurs sont négatives." << endl;
            }
            else if (c.second == 1) {
                cout << " a affectué des mesures dont les valeurs sont anormalement elevées." << endl;
            }
            else if (c.second == 2) {
                cout << " a affectué des mesures dont certaines valeurs sont négatives et d'autres pour lesquelles les valeurs sont anormalement elevées." << endl;
            }
		}
	}
	cout << endl;
}

void Messages::AfficherQualiteAir(vector<int> infos)
{
    if (infos[2] == 0) {
        cout << "Il n'y a pas de capteurs dans un rayon de 90 km autour de l'endroit selectionné." << endl << endl;
    }
    else if (infos[2] == 1) {
    cout << "L\'indice ATMO pour l\'endroit selectionné vaut " << infos[0] << " et a été calculé à l'aide de " << infos[2] << " capteur dans un rayon de " << infos[1] << " km." << endl << endl;
    } else cout << "L\'indice ATMO pour l\'endroit selectionné vaut " << infos[0] << " et a été calculé à l'aide de " << infos[2] << " capteurs dans un rayon de " << infos[1] << " km." << endl << endl;
}


void Messages::AfficherMoyenne(vector<double> moyennes, int atmo)
{
  string nomMesure [4] = {"O3","NO2","SO2","PM10"};
  cout << "Les quantités respectives de gaz/particules fines en moyenne dans la zone sont" << endl;
  cout << "(exprimées en microgrammes par mètre cube µg/m3):" << endl;
  for (int i(0); i < 4; i++)
  {
    if (moyennes[i] > 0)
    {
      cout << nomMesure[i] << ": " << moyennes[i] << "," << endl;
    }
    else
    {
      cout << "Aucunes mesures de " << nomMesure[i] << "trouvée." << endl;
    }
  }
  if(atmo!=0){
	  cout << "Indice ATMO : " << atmo << " " ;
	  if( atmo == 1 || atmo == 2 ){
		  cout << "(Très bon)" << endl;
	  } else if( atmo == 3 || atmo == 4 ){
		  cout << "(Bon)" << endl;
	  } else if( atmo == 5){
		  cout << "(Moyen)" << endl;
	  } else if( atmo == 6 || atmo == 7 ){
		  cout << "(Médiocre)" << endl;
	  } else if( atmo == 8 || atmo == 9 ){
		  cout << "(Mauvais)" << endl;
	  } else if( atmo == 10){
		  cout << "(Très mauvais)" << endl;
	  }
  }
  cout << endl;
}

//------------------------------------------------- Surcharge d'opérateurs
// Messages & Messages::operator = ( const Messages & desMessages )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
/* Messages::Messages ( const Messages & desMessages )
 // Algorithme :
 //
 {
 #ifdef MAP
 cout << "Appel au constructeur de copie de <Messages>" << endl;
 #endif
 } //----- Fin de Messages (constructeur de copie) */


Messages::Messages ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de <Messages>" << endl;
#endif
} //----- Fin de Messages


Messages::~Messages ( )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au destructeur de <Messages>" << endl;
#endif
} //----- Fin de ~Messages


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
