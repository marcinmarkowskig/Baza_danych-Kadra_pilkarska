#include "pomocnik.h"
#include <iostream>
#include <string>
#include <fstream>
#include "pilkarz.h"
#include "Kadra.h"

Pomocnik::Pomocnik(QString imie, QString nazwisko, QString pozycja, int nr_koszulki, int wiek, int szybkosc, float technika) : Pilkarz(imie, nazwisko, pozycja, nr_koszulki, wiek, szybkosc) {
this->technika=technika;
}
/*void Pomocnik::wyswietl() {
    cout << "IMIE: " << imie << endl;
    cout << "NAZWISKO: " << nazwisko << endl;
    cout << "POZYCJA: " << pozycja << endl;
    cout << "NUMER KOSZULKI: " << nr_koszulki << endl;
    cout << "WIEK: " << wiek << endl;
    cout << "SZYBKOSC: " << szybkosc << endl;
}*/
Pomocnik::Pomocnik()
{

}
QString Pomocnik::Pobierz_dane()
{
    QString dane=imie+"\t"
            +nazwisko+'\t'
            +pozycja+"\t"
            +QString::number(nr_koszulki)+"\t"
            +QString::number(wiek)+"\t"
            +QString::number(szybkosc)+"\t\t\t"
            +QString::number(technika);
    return dane;
}

//void Kadra::Dodaj_pilkarza(Pomocnik *p) {
  //  p=new Pomocnik();
    //    _sklad.push_back(new Pomocnik("Bartosz", "Kapustka", "Pomocnik", 400, 500, 600, 700));
//}

double Pomocnik::przecietne_umiejetnosci() {
    double umiejetnosc = wzorek(wiek, szybkosc, 0, 0, technika, 0, 0);
    return umiejetnosc;
}
