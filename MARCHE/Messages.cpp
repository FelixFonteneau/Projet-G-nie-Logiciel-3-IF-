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
        {
            recupererLocalisation();
            recupererRadius();
            recupererMoment();
            break;
        }
        case 2:
        {
            recupererLocalisation();
            recupererRadius();
            recupererIntervalleTemps();
            break;
        }
            
        case 3:
        {
            recupererLocalisation();
            recupererRadius();
            recupererIntervalleTemps();
            break;
        }
        case 4:
        {
            recupererLocalisation();
            break;
        }
        case 5:
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
    
    // On fixe les attributs
    coords[0] = latitude;
    coords[1] = longitude;
    
    return coord;
}

void Messages::affiche() // Pour les tests élémentaires
{
    cout << coords[0] << endl;
    cout << coords[1] << endl;
    cout << rayon << endl;
    cout << *intervalleTemps[0] << endl;
    cout << *intervalleTemps[1] << endl;
    cout << date << endl;
}

double Messages::recupererRadius()
{
    double radius;
    cout << "Quel est le rayon (en km) ?" << endl;
    cin >> radius;
    
    // On fixe les attributs
    rayon = radius;
    
    return radius;
}

void Messages::afficherCapteursCorreles(vector<pair<Capteur,Capteur>> capteurCorreles){
	for(pair<Capteur,Capteur> p : capteurCorreles){
		vector<double> coords1 = p.first.getCoords();
		vector<double> coords2 = p.second.getCoords();
		cout << "Similarité entre les capteurs " << p.first.RecupererId() << " et " << p.second.RecupererId()<< ", de coordonnées (" << coords1[0] << "," << coords1[1] << ") et (" << coords2[0] << "," << coords2[1] << ")." << endl;
	}
}

Moment* Messages::recupererIntervalleTemps()
{
    // Au format JJ/MM/AAAA HH:MM
    string dateDebut = "01/01/2019 10:10";
    string dateFin = "01/01/2019 10:10";
    cout << "Quelle est la date de début (Au format JJ/MM/AAAA HH:MM) ?" << endl;
    getline(cin, dateDebut);
    while (! (dateDebut[2] == '/' && dateDebut[5] == '/' && dateDebut[10] == ' ' && dateDebut[13] == ':' && dateDebut.length() == 16))
    {
        getline(cin, dateDebut);
        if (! (dateDebut[2] == '/' && dateDebut[5] == '/' && dateDebut[10] == ' ' && dateDebut[13] == ':' && dateDebut.length() == 16))
            cout << "Date au mauvais format (JJ/MM/AAAA HH:MM attendu). Quelle est la date de début ?" << endl;
        
    }
    
    
    cout << "Quelle est la date de fin (Au format JJ/MM/AAAA HH:MM) ?" << endl;
    getline(cin, dateFin);
    while (! (dateFin[2] == '/' && dateFin[5] == '/' && dateFin[10] == ' ' && dateFin[13] == ':' && dateFin.length() == 16) )
    {
        getline(cin, dateFin);
        if (! (dateFin[2] == '/' && dateFin[5] == '/' && dateFin[10] == ' ' && dateFin[13] == ':' && dateFin.length() == 16) )
            cout << "Date au mauvais format (JJ/MM/AAAA HH:MM attendu). Quelle est la date de fin ?" << endl;
    }
    
    Moment* intervalleTempsDemande = nullptr;
    int jourDebut = stoi(dateDebut.substr(0, 2));
    int moisDebut = stoi(dateDebut.substr(3, 2));
    int anneeDebut = stoi(dateDebut.substr(6, 4));
    int heureDebut = stoi(dateDebut.substr(11, 2));
    int minuteDebut = stoi(dateDebut.substr(14, 2));
    // 01/01/2019 10:10
    int jourFin = stoi(dateFin.substr(0, 2));
    int moisFin = stoi(dateFin.substr(3, 2));
    int anneeFin = stoi(dateFin.substr(6, 4));
    int heureFin = stoi(dateFin.substr(11, 2));
    int minuteFin = stoi(dateFin.substr(14, 2));
    Moment momentDebut(jourDebut, moisDebut, anneeDebut, heureDebut, minuteDebut, 0);
    Moment momentFin = Moment(jourFin, moisFin, anneeFin, heureFin, minuteFin, 0);
    
    cout << momentFin;
    intervalleTempsDemande = &momentDebut;
    intervalleTempsDemande[1] = momentFin;
    
    // On fixe les attributs
    *intervalleTemps[0] = momentDebut;
    *intervalleTemps[1] = momentFin;
    return intervalleTempsDemande;
}

Moment Messages::recupererMoment()
{
    string dateDemande = "01/01/2019 10:10";
    
    cout << "Quelle est la date (Au format JJ/MM/AAAA HH:MM) ?" << endl;
    getline(cin, dateDemande);
    while (! (dateDemande[2] == '/' && dateDemande[5] == '/' && dateDemande[10] == ' ' && dateDemande[13] == ':' && dateDemande.length() == 16))
    {
        getline(cin, dateDemande);
        if (! (dateDemande[2] == '/' && dateDemande[5] == '/' && dateDemande[10] == ' ' && dateDemande[13] == ':' && dateDemande.length() == 16))
            cout << "Mauvais format (JJ/MM/AAAA HH:MM demandé). Quelle est la date ?" << endl;
        
    }
    
    int jour = stoi(dateDemande.substr(0, 2));
    int mois = stoi(dateDemande.substr(3, 2));
    int annee = stoi(dateDemande.substr(6, 4));
    int heure = stoi(dateDemande.substr(11, 2));
    int minute = stoi(dateDemande.substr(14, 2));
    
    Moment moment = Moment(jour, mois, annee, heure, minute, 0);
    
    // On fixe les attributs
    date = moment;
    
    return moment;
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


Messages::Messages ( ) : capteur(Capteur("capteurNull", 0, 0, "descriptionNull")), date(Moment(0, 0, 0, 0, 0, 0))
// Algorithme :
//
{
    // capteur = Capteur("capteurNull", 0, 0, "descriptionNull");
    
    intervalleTemps[0] = new Moment(0, 0, 0, 0, 0, 0);
    intervalleTemps[1] = new Moment(0, 0, 0, 0, 0, 0);
    
    
#ifdef MAP
    cout << "Appel au constructeur de <Messages>" << endl;
#endif
} //----- Fin de Messages


Messages::~Messages ( )
// Algorithme :
//
{
    delete intervalleTemps[1];
    delete intervalleTemps[0];
#ifdef MAP
    cout << "Appel au destructeur de <Messages>" << endl;
#endif
} //----- Fin de ~Messages


//------------------------------------------------------------------ PRIVE

//----------------------------------------------------- Méthodes protégées
