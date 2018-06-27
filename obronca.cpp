#include "obronca.h"
#include <iostream>
#include <string>
#include <fstream>
#include "pilkarz.h"
#include "Kadra.h"

Obronca::Obronca()
{

}

Obronca::Obronca(QString imie, QString nazwisko, QString pozycja, int nr_koszulki, int wiek, int szybkosc, float glowka) : Pilkarz(imie, nazwisko, pozycja, nr_koszulki, wiek, szybkosc) {
    this->glowka=glowka;
}

QString Obronca::Pobierz_dane()
{
    QString dane=imie+"\t"
            +nazwisko+'\t'
            +pozycja+"\t"
            +QString::number(nr_koszulki)+"\t"
            +QString::number(wiek)+"\t"
            +QString::number(szybkosc)+"\t\t"
            +QString::number(glowka);
    return dane;
}

double Obronca::przecietne_umiejetnosci() {
    double umiejetnosc = wzorek(wiek, szybkosc, 0, glowka, 0, 0, 0);
    return umiejetnosc;
}
