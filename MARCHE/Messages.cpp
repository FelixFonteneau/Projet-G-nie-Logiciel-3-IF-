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
void Messages::messageMenu()
{
    cout << "Bonjour. Vous souhaitez :" << endl;
    cout << "1 - Obtenir la qualité de l'air moyenne sur un territoire précis à une date précise" << endl;
    cout << "2 - Obtenir la qualité de l'air moyenne sur un terrotoire précis sur une période précise" << endl;
    cout << "3 - Trouver les capteurs ayant un comportement similaire" << endl;
    cout << "4 - Obtenir les valeurs caractérisant la qualité de l'air à un point précis" << endl;
    cout << "5 - Obtenir la liste des capteurs qui ne fonctionnent pas" << endl;
    cout << "6 - Quitter" << endl;
    int num;
    cin >> num;
    double* coords = nullptr;
    // double rayon;
    
    switch (num)
    {
        case 1:
        {
            coords = recupererLocalisation();
            // rayon = recupererRadius();
            // Moment date = recupererMoment();
            break;
        }
        case 2:
        {
            // coords = recupererLocalisation();
            // rayon = recupererRadius();
            // Moment* intervalleTemps = recupererIntervalleTemps();
            break;
        }
        case 3:
        {
            cout << "Latitude centrale du lieu souhaité" << endl;
            cout << "Longitude centrale du lieu souhaité" << endl;
            cout << "Rayon (en km)" << endl;
            cout << "Date de début" << endl;
            cout << "Date de fin" << endl;
            break;
        }
        case 4:
        {
            cout << "Latitude" << endl;
            cout << "Longitude" << endl;
            
            break;
        }
        case 5:
        {
            break;
        }
        case 6:
        {
            break;
        }
        default:
        {
            break;
        }
    }
}

double* Messages::recupererLocalisation()
{
    double latitude;
    double longitude;
    cout << "Quelle est la latitude centrale du lieu souhaité ?" << endl;
    cin >> latitude;
    cout << "Quelle est la longitude centrale du lieu souhaité ?" << endl;
    cin >> longitude;
    double* coord = &latitude;
    coord[1] = longitude;
    return coord;
}

double recupererRadius()
{
    double radius;
    cout << "Quel est le rayon (en km) ?" << endl;
    cin >> radius;
    return radius;
}

Moment* Messages::recupererIntervalleTemps()
{
    // Au format JJ/MM/AAAA HH:MM
    string dateDebut;
    string dateFin;
    cout << "Quelle est la date de début (Au format JJ/MM/AAAA HH:MM) ?" << endl;
    getline(cin, dateDebut);
    while (! (dateDebut[2] == '/' && dateDebut[5] == '/' && dateDebut[10] == ' ' && dateDebut[13] == ':' && dateDebut.length() == 16))
    {
        cout << "Date au mauvais format (JJ/MM/AAAA HH:MM attendu). Quelle est la date de début ?" << endl;
        getline(cin, dateDebut);
    }
    

    cout << "Quelle est la date de fin (Au format JJ/MM/AAAA HH:MM) ?" << endl;
    getline(cin, dateFin);
    while (! (dateFin[2] == '/' && dateFin[5] == '/' && dateFin[10] == ' ' && dateFin[13] == ':' && dateFin.length() == 16) )
    {
        cout << "Date au mauvais format (JJ/MM/AAAA HH:MM attendu). Quelle est la date de fin ?" << endl;
        getline(cin, dateFin);
    }
    
    Moment* intervalleTemps = nullptr;
    int jourDebut = stoi(dateDebut.substr(0, 2));
    int moisDebut = stoi(dateDebut.substr(3, 2));
    int anneeDebut = stoi(dateDebut.substr(6, 4));
    int heureDebut = stoi(dateDebut.substr(11, 2));
    int minuteDebut = stoi(dateDebut.substr(14, 2));
    // 01/01/2019 10:10
    int jourFin = stoi(dateFin.substr(0, 2));
    int moisFin = stoi(dateFin.substr(3, 2));
    int anneeFin = stoi(dateFin.substr(6, 2));
    int heureFin = stoi(dateFin.substr(11, 2));
    int minuteFin = stoi(dateFin.substr(14, 2));
    Moment momentDebut(jourDebut, moisDebut, anneeDebut, heureDebut, minuteDebut, 0);
    Moment momentFin = Moment(jourFin, moisFin, anneeFin, heureFin, minuteFin, 0);
    intervalleTemps = &momentDebut;
    intervalleTemps[1] = momentFin;
    return intervalleTemps;
}

Moment Messages::recupererMoment()
{
    string date;
    
    cout << "Quelle est la date (Au format JJ/MM/AAAA HH:MM) ?" << endl;
    getline(cin, date);
    while (! (date[2] == '/' && date[5] == '/' && date[10] == ' ' && date[13] == ':' && date.length() == 16))
    {
        cout << "Date au mauvais format (JJ/MM/AAAA HH:MM attendu). Quelle est la date ?" << endl;
        getline(cin, date);
    }

    int jour = stoi(date.substr(0, 2));
    int mois = stoi(date.substr(3, 2));
    int annee = stoi(date.substr(6, 4));
    int heure = stoi(date.substr(11, 2));
    int minute = stoi(date.substr(14, 2));

    Moment moment(jour, mois, annee, heure, minute, 0);

    return moment;
}



//------------------------------------------------- Surcharge d'opérateurs
// Messages & Messages::operator = ( const Messages & desMessages )
// Algorithme :
//
// {
// } //----- Fin de operator =


//-------------------------------------------- Constructeurs - destructeur
Messages::Messages ( const Messages & desMessages )
// Algorithme :
//
{
#ifdef MAP
    cout << "Appel au constructeur de copie de <Messages>" << endl;
#endif
} //----- Fin de Messages (constructeur de copie)


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

