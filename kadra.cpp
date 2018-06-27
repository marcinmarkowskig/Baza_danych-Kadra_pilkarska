#include "kadra.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "pilkarz.h"
#include "Kadra.h"
#include "bramkarz.h"
#include "obronca.h"
#include "pomocnik.h"
#include "napastnik.h"
Kadra::Kadra()
{

}

Kadra::~Kadra(){
    for(int i=0;i<_sklad.size();i++){
        delete _sklad[i];
    }
}

int Kadra::rozmiar(){
    return _sklad.size();
}

//void Kadra::Dodaj_pilkarza() {
  //      _sklad.push_back(new Pomocnik("Bartosz", "Kapustka", "Pomocnik", 400, 500, 600, 700));
//}

void Kadra::Dodaj_pilkarza(Pilkarz *p) {
       _sklad.push_back(p);
}
Pilkarz* Kadra::zwroc(int i ){
   return  _sklad.at(i);
}
QString Kadra::oddaj_pozycje(int i){
   QString a=_sklad.at(i)->pokaz_pozycje();
   return a;
}

double Kadra::Przecietne_umiejetnosci(int o) {
    for (int i = 0; i < _sklad.size(); i++) {
        QString a=_sklad.at(i)->pokaz_pozycje();
        if(i==o){
        if (a == "Bramkarz") {
          return  _sklad[i]->przecietne_umiejetnosci();

        }
        else if(a== "Obronca") {
            return _sklad[i]->przecietne_umiejetnosci();

        }
        else if (a == "Pomocnik") {
           return _sklad[i]->przecietne_umiejetnosci();

        }
        else if (a == "Napastnik") {
          return  _sklad[i]->przecietne_umiejetnosci();

        }
        }
    }//return _sklad.at(i);
}

//Pilkarz* Kadra::oddaj_pilkarza_do_usuniecia(int i){
  //     return  _sklad.at(i);
//}
