#include <iostream>


using namespace std;

#include "Mesure.h"
void afficherMenu()
{
    cout << "Choisir" << endl;
    cout << "1. option 1" << endl;
    cout << "blabla" << endl;
    cout << "blabla" << endl;
    cout << "blabla" << endl;

}
int main()
{
    afficherMenu();
    Mesure uneMesure = Mesure(2,"voici la des","microgr par mcube");
    uneMesure.afficher();
   return 0;
}
