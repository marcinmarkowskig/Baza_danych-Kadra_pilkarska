#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "kadra.h"
#include <string>
#include <QFileDialog>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    //
    void otworz_plik();
    QString tekst;
    //
    void zapisz_plik();
    QString poprzedniaSciezka;
    void zapisz_plik(QString fileName);
    //
    void pomoc();
    void informacje();

private slots:
    void on_pushButton_clicked();
    //void on_przycisk_clicked();
     void on_actionOtw_rz_triggered();
     void on_actionZapisz_triggered();
     void on_actionZapisz_jako_2_triggered();
     void on_actionZamknij_triggered();

     void on_actionWyswietl_pomoc_triggered();
     void on_actionInformacje_triggered();
     void on_pushButton_2_clicked();

     void on_pomocnik_clicked();

     void on_pushButton_3_clicked();

     void on_imie_cursorPositionChanged(int arg1, int arg2);

     void on_nazwisko_cursorPositionChanged(int arg1, int arg2);

     void on_gotowe_clicked();

     void on_pozycja_cursorPositionChanged(int arg1, int arg2);

     void on_nr_koszulki_cursorPositionChanged(int arg1, int arg2);

     void on_wiek_cursorPositionChanged(int arg1, int arg2);

     void on_szybkosc_cursorPositionChanged(int arg1, int arg2);

     void on_ustawienie_na_linii_cursorPositionChanged(int arg1, int arg2);

     void on_glowka_cursorPositionChanged(int arg1, int arg2);

     void on_technika_cursorPositionChanged(int arg1, int arg2);

     void on_sila_cursorPositionChanged(int arg1, int arg2);

     void on_wykonczenie_cursorPositionChanged(int arg1, int arg2);

     void on_wyswiet_pomocnikow_clicked();

     void on_wyswietl_napastnikow_clicked();

     void on_wzorek_pomocnik_clicked();


     void on_napastnik_clicked();

     void on_bramkarz_clicked();

     void on_wzorek_bramkarz_clicked();

     void on_wyswietl_bramkarzy_clicked();

     void on_bramkarz_gotowe_clicked();

     void on_pushButton_4_clicked();

     void on_pushButton_5_clicked();

     void on_obronca_clicked();

     void on_obronca_gotowe_clicked();

     void on_napastnik_gotowe_clicked();

     void on_wyswietl_obroncow_clicked();

     void on_pushButton_6_clicked();

     void on_pushButton_7_clicked();

   //  void on_lineEdit_cursorPositionChanged(int arg1, int arg2);

 //    void on_pushButton_8_clicked();

private:
    Ui::MainWindow *ui;
    Kadra *ka;
};

#endif // MAINWINDOW_H
