#ifndef POMOCNIK_H
#define POMOCNIK_H

#include "pilkarz.h"
#include <iostream>
#include <QMainWindow>

class Pomocnik : public Pilkarz
{
    Q_OBJECT
private:
    float technika;
public:
    Pomocnik();
    Pomocnik(QString, QString, QString, int, int, int, float);//imie nazwisko pozycja   numer wiek szybkosc   technika
    QString Pobierz_dane();
    double przecietne_umiejetnosci();
};
#endif // POMOCNIK_H


