#include "pilkarz.h"
#include <iostream>
#include <string>
#include <fstream>

Pilkarz::Pilkarz()
{

}

Pilkarz::Pilkarz(QString imie, QString nazwisko, QString pozycja, int nr_koszulki, int wiek, int szybkosc) {
    this->imie = imie;
    this->nazwisko = nazwisko;
    this->pozycja = pozycja;
    this->nr_koszulki = nr_koszulki;
    this->wiek = wiek;
    this->szybkosc = szybkosc;
}
/*ostream &operator<<(ostream &ekran, const Pilkarz &p) {//operator pokazywania na ekranie
    ekran << "IMIE\t\t\t"; ekran << p.imie; ekran << endl;
    ekran << "NAZWISKO\t\t"; ekran << p.nazwisko; ekran << endl;
    ekran << "POZYCJA\t\t\t";
    if (p.pozycja == "Obronca") {
        ekran << "Obronca"; ekran << endl;
    }
    else if (p.pozycja == "Pomocnik") {
        ekran << "Pomocnik"; ekran << endl;
    }
    else if (p.pozycja == "Napastnik") {
        ekran << "Napastnik"; ekran << endl;
    }
    else if (p.pozycja == "Bramkarz") {
        ekran << "Bramkarz"; ekran << endl;
    }
    ekran << "NR KOSZULKI\t\t"; ekran << p.nr_koszulki; ekran << endl;
    ekran << "WIEK\t\t\t"; ekran << p.wiek; ekran << endl;
    ekran << "SZYBKOSC BIEGU\t\t"; ekran << p.szybkosc; ekran << endl;
    ekran << endl;
    return ekran;
}
*/

/*QString Pilkarz::Pobierz_dane(){
    QString dane=imie+" "
            +nazwisko+" "
            +pozycja+" "
            +QString::number(nr_koszulki)+" "
            +QString::number(wiek)+" "
            +QString::number(szybkosc);
    return dane;
}// tu trzeba było przekonwertować na QString numerki :D
*/
QString Pilkarz::pokaz_pozycje(){
    return pozycja;
}



double Pilkarz::wzorek(int a, int b, float c, float d, float e, float f, float g) {
    double wzorek = 2.12*a + 1.84*(b+a) + c + d + e + f + g;

    return wzorek;
}



