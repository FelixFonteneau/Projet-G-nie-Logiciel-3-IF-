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
    switch (num)
    {
        case 1:
        // recupererIntervalleTemps();
        break;
        case 2:
        cout << "Latitude centrale du lieu souhaité" << endl;
        cout << "Longitude centrale du lieu souhaité" << endl;
        cout << "Rayon (en km)" << endl;
        cout << "Date de début" << endl;
        cout << "Date de fin" << endl;
        break;
        case 3:
        cout << "Latitude centrale du lieu souhaité" << endl;
        cout << "Longitude centrale du lieu souhaité" << endl;
        cout << "Rayon (en km)" << endl;
        cout << "Date de début" << endl;
        cout << "Date de fin" << endl;
        break;
        case 4:
        cout << "Latitude" << endl;
        cout << "Longitude" << endl;
        break;
        case 5:
        break;
        case 6:
        break;
        default:
        break;
    }
}

double* Messages::recupererLocalisation()
{
    double latitude;
    double longitude;
    cout << "Latitude centrale du lieu souhaité" << endl;
    cin >> latitude;
    cout << "Longitude centrale du lieu souhaité" << endl;
    cin >> longitude;
    double* coord = &latitude;
    coord[1] = longitude;
    return coord;
}

double recupererRadius()
{
    double radius;
    cout << "Rayon (en km)" << endl;
    cin >> radius;
    return radius;
}

Moment* Messages::recupererIntervalleTemps() 
{
    // Au format JJ/MM/AAAA HH:MM
    string dateDebut;
    string dateFin;
    cout << "Date de début (Au format JJ/MM/AAAA HH:MM)" << endl;
    cin >> dateDebut;
    cout << dateDebut[2];
    /* if (! (dateDebut == "/" && dateDebut[5] == "/" && dateDebut[10] == " " && dateDebut[13] == ":" && dateDebut.length() == 16))
    {
        cout << "mauvais format" << endl;
    }*/
    cout << "Date de fin (Au format JJ/MM/AAAA HH:MM)" << endl;
    cin >> dateFin;

    int jourDebut = stoi(dateDebut.substr(0, 2));
    int moisDebut = stoi(dateDebut.substr(3, 2));
    int anneeDebut = stoi(dateDebut.substr(6, 2));
    int heureDebut = stoi(dateDebut.substr(11, 2));
    int minuteDebut = stoi(dateDebut.substr(14, 2));
    cout << jourDebut << moisDebut << anneeDebut << heureDebut << minuteDebut;

    int jourFin = stoi(dateFin.substr(0, 2));
    int moisFin = stoi(dateFin.substr(3, 2));
    int anneeFin = stoi(dateFin.substr(6, 2));
    int heureFin = stoi(dateFin.substr(11, 2));
    int minuteFin = stoi(dateFin.substr(14, 2));
    Moment momentDebut(jourDebut, moisDebut, anneeDebut, heureDebut, minuteDebut, 0);
    Moment momentFin = Moment(jourFin, moisFin, anneeFin, heureFin, minuteFin, 0);
    Moment* intervalleTemps = &momentDebut;
    intervalleTemps[1] = momentFin;

    return intervalleTemps;
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

