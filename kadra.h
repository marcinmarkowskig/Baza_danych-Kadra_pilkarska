#ifndef KADRA_H
#define KADRA_H
#include <vector>
#include "pilkarz.h"
#include <iostream>

#include <QMainWindow>
class Kadra:public QMainWindow
{
    Q_OBJECT
private:
    QVector<Pilkarz*> _sklad;
 //   int rozmiarek;
public:
    Kadra();
    ~Kadra();
    void Dodaj_pilkarza(Pilkarz *p);
    Pilkarz* zwroc(int i);
    int rozmiar();
    double Przecietne_umiejetnosci(int i);

    //Pilkarz* oddaj_pilkarza_do_usuniecia(int i);
    QString oddaj_pozycje(int i);
 //   Pilkarz *wywietlenie();
private slots:

};

#endif // KADRA_H
