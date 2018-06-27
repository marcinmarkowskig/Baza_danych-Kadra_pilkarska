#ifndef BRAMKARZ_H
#define BRAMKARZ_H

#include "pilkarz.h"
#include <iostream>
#include <QMainWindow>

class Bramkarz: public Pilkarz
{
    Q_OBJECT
private:
float ustawienie;
public:
    Bramkarz();
    QString Pobierz_dane();
    Bramkarz(QString, QString, QString, int, int, int, float);//imie nazwisko pozycja   numer wiek szybkosc   ustawienie na linii
    double przecietne_umiejetnosci();
};

#endif // BRAMKARZ_H
