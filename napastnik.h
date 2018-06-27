#ifndef NAPASTNIK_H
#define NAPASTNIK_H
#include "pilkarz.h"
#include <iostream>
#include <QMainWindow>

class Napastnik: public Pilkarz
{

    Q_OBJECT
private:
    float sila, wykonczenie;
public:
    Napastnik();
    QString Pobierz_dane();
    Napastnik(QString, QString, QString, int, int, int, float, float);//imie nazwisko pozycja   numer wiek szybkosc   technika
    double przecietne_umiejetnosci();
};

#endif // NAPASTNIK_H



