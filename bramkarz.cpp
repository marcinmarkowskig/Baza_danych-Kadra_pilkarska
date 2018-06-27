#include "bramkarz.h"
#include <iostream>
#include <string>
#include <fstream>
#include "pilkarz.h"
#include "Kadra.h"

Bramkarz::Bramkarz()
{

}

Bramkarz::Bramkarz(QString imie, QString nazwisko, QString pozycja, int nr_koszulki, int wiek, int szybkosc, float ustawienie) : Pilkarz(imie, nazwisko, pozycja, nr_koszulki, wiek, szybkosc) {
   this->ustawienie=ustawienie;
}
QString Bramkarz::Pobierz_dane()
{
    QString dane=imie+"\t"
            +nazwisko+'\t'
            +pozycja+"\t"
            +QString::number(nr_koszulki)+"\t"
            +QString::number(wiek)+"\t"
            +QString::number(szybkosc)+"\t"
            +QString::number(ustawienie);
    return dane;
}

double Bramkarz::przecietne_umiejetnosci() {
    double umiejetnosc = wzorek(wiek, szybkosc, ustawienie, 0, 0, 0, 0);
  return umiejetnosc;
}
