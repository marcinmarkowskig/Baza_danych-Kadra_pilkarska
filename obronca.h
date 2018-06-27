#ifndef OBRONCA_H
#define OBRONCA_H

#include "pilkarz.h"
#include <iostream>
#include <QMainWindow>

class Obronca: public Pilkarz
{
    Q_OBJECT
private:
    float glowka;
public:
    Obronca();
    QString Pobierz_dane();
    Obronca(QString, QString, QString, int, int, int, float);//imie nazwisko pozycja   numer wiek szybkosc   główka
    double przecietne_umiejetnosci();
};

#endif // OBRONCA_H
