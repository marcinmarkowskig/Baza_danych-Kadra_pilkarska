#ifndef PILKARZ_H
#define PILKARZ_H

#include <QMainWindow>
#include <iostream>

#include <string>
#include <fstream>
class Pilkarz:public QMainWindow
{
    Q_OBJECT
protected:
    QString imie;
    QString nazwisko;
    QString pozycja;
    int nr_koszulki;
    int wiek;
    int szybkosc;

public:
    Pilkarz();
    Pilkarz(QString imie, QString nazwisko, QString pozycja, int nr_koszulki, int wiek, int szybkosc);
    virtual QString Pobierz_dane()=0;
    QString pokaz_pozycje();
    virtual double przecietne_umiejetnosci()=0;
    double wzorek(int, int, float, float, float, float, float);
};

#endif // PILKARZ_H
