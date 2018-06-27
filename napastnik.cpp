#include "napastnik.h"
#include <iostream>
#include <string>
#include <fstream>
#include "pilkarz.h"
#include "Kadra.h"
Napastnik::Napastnik()
{

}




Napastnik::Napastnik(QString imie, QString nazwisko, QString pozycja, int nr_koszulki, int wiek, int szybkosc, float wykonczenie, float sila) : Pilkarz(imie, nazwisko, pozycja, nr_koszulki, wiek, szybkosc) {
    this->wykonczenie = wykonczenie;
    this->sila = sila;
}
/*void Pomocnik::wyswietl() {
    cout << "IMIE: " << imie << endl;
    cout << "NAZWISKO: " << nazwisko << endl;
    cout << "POZYCJA: " << pozycja << endl;
    cout << "NUMER KOSZULKI: " << nr_koszulki << endl;
    cout << "WIEK: " << wiek << endl;
    cout << "SZYBKOSC: " << szybkosc << endl;
}*/

QString Napastnik::Pobierz_dane()
{
    QString dane=imie+"\t"
            +nazwisko+'\t'
            +pozycja+"\t"
            +QString::number(nr_koszulki)+"\t"
            +QString::number(wiek)+"\t"
            +QString::number(szybkosc)+"\t\t\t\t"
            +QString::number(wykonczenie)+"\t"//"\t            "
            +QString::number(sila);
    return dane;
}

double Napastnik::przecietne_umiejetnosci() {
    double umiejetnosc = wzorek(wiek, szybkosc, 0, 0, 0, wykonczenie, sila);
    return umiejetnosc;
}
