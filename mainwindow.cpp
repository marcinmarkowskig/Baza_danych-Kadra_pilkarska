#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "kadra.h"
#include "bramkarz.h"
#include "obronca.h"
#include "pomocnik.h"
#include "napastnik.h"
#include <QDialog>
#include <QFileDialog>
#include <QTextStream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ka = new Kadra();
}

MainWindow::~MainWindow()
{
    delete ui;
}

////////////////////////zapis i odczyt z pliku CAŁEJ kadry
////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::otworz_plik()//otwarcie i wczytanie całego pliku działa
{
    // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
    // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
    QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

    QFile plik(fileName);

    // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
    if(!plik.open(QIODevice::ReadWrite | QIODevice::Text))
        return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku

    // czyścimy wcześniej zapełnioną zmienną tekstową
    tekst.clear();

    QTextStream stream(&plik);

    // czytamy wszystkie dane
   // tekst = stream.readAll();
    int r;
        //r=QString::number(stream.readLine());
        r=stream.readLine().toInt();
    QString t1,t2,t3,t4,t5,t6,t7,t8; // tymczasowe zmienne przechowujące kolejne linie

    for(int i=0;i<100;i++){
    tekst = stream.readLine();
        if (tekst == "Pomocnik") {

            t1 = stream.readLine();
            t2 = stream.readLine();
            t3 = stream.readLine();
            t4 = stream.readLine();
            t5 = stream.readLine();
            t6 = stream.readLine();
            t7 = stream.readLine();
            ka->Dodaj_pilkarza(new Pomocnik(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt()));
        }else
            if (tekst == "Napastnik") {

            t1 = stream.readLine();
            t2 = stream.readLine();
            t3 = stream.readLine();
            t4 = stream.readLine();
            t5 = stream.readLine();
            t6 = stream.readLine();
            t7 = stream.readLine();
            t8 = stream.readLine();
            ka->Dodaj_pilkarza(new Napastnik(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt(), t8.toInt()));
        }else
            if (tekst == "Bramkarz") {

                t1 = stream.readLine();
                t2 = stream.readLine();
                t3 = stream.readLine();
                t4 = stream.readLine();
                t5 = stream.readLine();
                t6 = stream.readLine();
                t7 = stream.readLine();
                ka->Dodaj_pilkarza(new Bramkarz(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt()));
            }else
                if (tekst == "Obronca") {

                    t1 = stream.readLine();
                    t2 = stream.readLine();
                    t3 = stream.readLine();
                    t4 = stream.readLine();
                    t5 = stream.readLine();
                    t6 = stream.readLine();
                    t7 = stream.readLine();
                    ka->Dodaj_pilkarza(new Obronca(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt()));
        }
    }
    int y=ka->rozmiar();
        // umieszczamy je wewnątrz text boxa
        //for(int i=0;i<licznik;i++)
        //for(int i=y;i<licznik;i++)
         //ui->pole->append(ka->zwroc(i)->Pobierz_dane());
         for(int i=0;i<y;i++)
         ui->pole->append(ka->zwroc(i)->Pobierz_dane());
    plik.close();

    poprzedniaSciezka = fileName;
}
void MainWindow::on_actionOtw_rz_triggered()
{
    otworz_plik();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::zapisz_plik(QString fileName)///zapis do pliku działa
{
    tekst = ui->pole->toPlainText();

    if(fileName.isEmpty())
        fileName = QFileDialog::getSaveFileName
                (this,tr("Zapisz plik jako..."),tr("/home/"),tr("Pliki tekstowe (*.txt)"));

    if(fileName.isEmpty())
        return;
  //  fileName="Zapis.txt";
  //  QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

  //  QFile plik(fileName);
    QFile plik(fileName);
    plik.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    QTextStream stream(&plik);
    stream << tekst;

poprzedniaSciezka = fileName;
    plik.close();

}
void MainWindow::on_actionZapisz_triggered()
{
    zapisz_plik(poprzedniaSciezka);
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::zapisz_plik()///zapis jako  do pliku działa
{
    QString fileName;
    tekst = ui->pole->toPlainText();

    if(fileName.isEmpty())
        fileName = QFileDialog::getSaveFileName
                (this,tr("Zapisz plik jako..."),tr("/home/"),tr("Pliki tekstowe (*.txt)"));

    if(fileName.isEmpty())
        return;
  //  fileName="Zapis.txt";
  //  QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

  //  QFile plik(fileName);
    QFile plik(fileName);
    plik.open(QIODevice::WriteOnly | QIODevice::Truncate | QIODevice::Text);

    QTextStream stream(&plik);
    stream << tekst;

poprzedniaSciezka = fileName;
    plik.close();

}
void MainWindow::on_actionZapisz_jako_2_triggered()
{
    zapisz_plik();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////////MENU u góry ekranu
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_actionZamknij_triggered()////wyjscie działa
{
    qApp->exit();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::pomoc()//pomoc działa
{
  tekst.clear();
  //k=new Okienko;
  //k->show();
  QString a="Tworzysz własną kadrę piłkarską.\n\nWczytanie kadry z pliku CTRL+O)\nZapisanie kadry do ostatnio używanego pliku(CTRL+Z)\nZapisanie kadry do nowego pliku(CTRL+J)\nWyświetlenie pomocy(CTRL+P)\nWyświetlenie informacji(CTRL+I)\nZamknięcie programu (CTRL+E)";
  ui->pole->setText(a);
}
void MainWindow::on_actionWyswietl_pomoc_triggered(){
    pomoc();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::informacje()//informacje działa
{
  tekst.clear();
  //k=new Okienko;
  //k->show();
  QString a="Menedżer piłkarski 2016";
  ui->pole->setText(a);
}
void MainWindow::on_actionInformacje_triggered(){
    informacje();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////

/////////////////////dodatkowe opcje
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_4_clicked()//wczytanie bramkarzy z pliku działa
{
    ui->pole->clear();
      // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
      // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
      QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

      QFile plik(fileName);

      // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
      if(!plik.open(QIODevice::ReadWrite | QIODevice::Text))
          return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku

      // czyścimy wcześniej zapełnioną zmienną tekstową
      tekst.clear();

      QTextStream stream(&plik);

      // czytamy wszystkie dane
      //QString r;
      int r;
      int licznik=0;
          //r=QString::number(stream.readLine());
          r=stream.readLine().toInt();
      QString t1,t2,t3,t4,t5,t6,t7; // tymczasowe zmienne przechowujące kolejne linie

      for(int i=0;i<100;i++){
      tekst = stream.readLine();
          if (tekst == "Bramkarz") {

              t1 = stream.readLine();
              t2 = stream.readLine();
              t3 = stream.readLine();
              t4 = stream.readLine();
              t5 = stream.readLine();
              t6 = stream.readLine();
              t7 = stream.readLine();
              // tak działa, trzeba było najpierw pobrać dane do zmiennych a potem te zmienne przekazać do obiektu :D
              ka->Dodaj_pilkarza(new Bramkarz(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt()));

              licznik++;
          }
      }

      // umieszczamy je wewnątrz text boxa
      //for(int i=0;i<licznik;i++)
      int y=ka->rozmiar();
      for(int i=0;i<y;i++)
         // ui->pole->setText(ka->zwroc(i)->Pobierz_dane());
      ui->pole->append(ka->zwroc(i)->Pobierz_dane());

      //ui->pole->append(ka->zwroc(1)->Pobierz_dane());
      // ui->pole->setText(ka->zwroc(0)->Pobierz_dane());

      // metoda pobierz dane wyświetla tylko 6 cech bo jest to metoda Piłkarza :D
      // trzeba ją przeciążyć w Pomocniku żeby wyświetlała wszystkie jego cechy

      plik.close();

      poprzedniaSciezka = fileName;
      //k=new Okienko;
      //k->show();

     //connect(this, SIGNAL(clicked()), this, SLOT(Dodaj_pilkarza()));//?
     //Dodaj_pilkarza();
}
void MainWindow::on_pushButton_5_clicked()//wczytanie obrońców z pliku działa
{
    ui->pole->clear();
      // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
      // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
      QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

      QFile plik(fileName);

      // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
      if(!plik.open(QIODevice::ReadWrite | QIODevice::Text))
          return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku

      // czyścimy wcześniej zapełnioną zmienną tekstową
      tekst.clear();

      QTextStream stream(&plik);

      // czytamy wszystkie dane
      //QString r;
      int r;
      int licznik=0;
          //r=QString::number(stream.readLine());
          r=stream.readLine().toInt();
      QString t1,t2,t3,t4,t5,t6,t7; // tymczasowe zmienne przechowujące kolejne linie

      for(int i=0;i<100;i++){
      tekst = stream.readLine();
          if (tekst == "Obronca") {

              t1 = stream.readLine();
              t2 = stream.readLine();
              t3 = stream.readLine();
              t4 = stream.readLine();
              t5 = stream.readLine();
              t6 = stream.readLine();
              t7 = stream.readLine();
              // tak działa, trzeba było najpierw pobrać dane do zmiennych a potem te zmienne przekazać do obiektu :D
              ka->Dodaj_pilkarza(new Bramkarz(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt()));

              licznik++;
          }
      }

      // umieszczamy je wewnątrz text boxa
      //for(int i=0;i<licznik;i++)
      int y=ka->rozmiar();
      for(int i=0;i<y;i++)
         // ui->pole->setText(ka->zwroc(i)->Pobierz_dane());
      ui->pole->append(ka->zwroc(i)->Pobierz_dane());

      //ui->pole->append(ka->zwroc(1)->Pobierz_dane());
      // ui->pole->setText(ka->zwroc(0)->Pobierz_dane());

      // metoda pobierz dane wyświetla tylko 6 cech bo jest to metoda Piłkarza :D
      // trzeba ją przeciążyć w Pomocniku żeby wyświetlała wszystkie jego cechy

      plik.close();

      poprzedniaSciezka = fileName;
      //k=new Okienko;
      //k->show();

     //connect(this, SIGNAL(clicked()), this, SLOT(Dodaj_pilkarza()));//?
     //Dodaj_pilkarza();
}
void MainWindow::on_pushButton_clicked()//wczytanie pomocników z pliku działa
{
ui->pole->clear();
  // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
  // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
  QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

  QFile plik(fileName);

  // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
  if(!plik.open(QIODevice::ReadWrite | QIODevice::Text))
      return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku

  // czyścimy wcześniej zapełnioną zmienną tekstową
  tekst.clear();

  QTextStream stream(&plik);

  // czytamy wszystkie dane
  //QString r;
  int r;
  int licznik=0;
      //r=QString::number(stream.readLine());
      r=stream.readLine().toInt();
  QString t1,t2,t3,t4,t5,t6,t7; // tymczasowe zmienne przechowujące kolejne linie

  for(int i=0;i<100;i++){
  tekst = stream.readLine();
      if (tekst == "Pomocnik") {

          t1 = stream.readLine();
          t2 = stream.readLine();
          t3 = stream.readLine();
          t4 = stream.readLine();
          t5 = stream.readLine();
          t6 = stream.readLine();
          t7 = stream.readLine();
          // tak działa, trzeba było najpierw pobrać dane do zmiennych a potem te zmienne przekazać do obiektu :D
          ka->Dodaj_pilkarza(new Pomocnik(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt()));

          licznik++;
      }
  }

  // umieszczamy je wewnątrz text boxa
  //for(int i=0;i<licznik;i++)
  int y=ka->rozmiar();
  for(int i=0;i<y;i++)
     // ui->pole->setText(ka->zwroc(i)->Pobierz_dane());
  ui->pole->append(ka->zwroc(i)->Pobierz_dane());

  //ui->pole->append(ka->zwroc(1)->Pobierz_dane());
  // ui->pole->setText(ka->zwroc(0)->Pobierz_dane());

  // metoda pobierz dane wyświetla tylko 6 cech bo jest to metoda Piłkarza :D
  // trzeba ją przeciążyć w Pomocniku żeby wyświetlała wszystkie jego cechy

  plik.close();

  poprzedniaSciezka = fileName;
  //k=new Okienko;
  //k->show();

 //connect(this, SIGNAL(clicked()), this, SLOT(Dodaj_pilkarza()));//?
 //Dodaj_pilkarza();
}
void MainWindow::on_pushButton_2_clicked()//wczytanie napastników z pliku działa
{
    ui->pole->clear();
    // QFileDialog::getOpenFileName([rodzic (parent)],[tytuł nagłówka],
    // [ścieżka od której rozpoczyna się wyszukiwanie pliku], [rozszerzenia wyszukiwanych plików])
    QString fileName = QFileDialog::getOpenFileName(this,tr("Otwórz..."), "/home/", tr("Pliki txt (*.txt)"));

    QFile plik(fileName);

    // możemy tylko czytać dane, oraz wczytujemy je jako tekst:
    if(!plik.open(QIODevice::ReadWrite | QIODevice::Text))
        return;			 // jeżeli nie udało się otworzyć pliku: przerwij wczytywanie pliku

    // czyścimy wcześniej zapełnioną zmienną tekstową
    tekst.clear();

    QTextStream stream(&plik);

    // czytamy wszystkie dane
    //QString r;
    int r;
    int licznik=0;
        //r=QString::number(stream.readLine());
        r=stream.readLine().toInt();
    QString t1,t2,t3,t4,t5,t6,t7,t8; // tymczasowe zmienne przechowujące kolejne linie

    for(int i=0;i<100;i++){
    tekst = stream.readLine();
        if (tekst == "Napastnik") {

            t1 = stream.readLine();
            t2 = stream.readLine();
            t3 = stream.readLine();
            t4 = stream.readLine();
            t5 = stream.readLine();
            t6 = stream.readLine();
            t7 = stream.readLine();
            t8 = stream.readLine();
            // tak działa, trzeba było najpierw pobrać dane do zmiennych a potem te zmienne przekazać do obiektu :D
            ka->Dodaj_pilkarza(new Napastnik(t1,t2,t3,t4.toInt(),t5.toInt(),t6.toInt(),t7.toInt(), t8.toInt()));

            licznik++;
        }
    }
int y=ka->rozmiar();
    // umieszczamy je wewnątrz text boxa
    //for(int i=0;i<licznik;i++)
    //for(int i=y;i<licznik;i++)
     //ui->pole->append(ka->zwroc(i)->Pobierz_dane());
     for(int i=0;i<y;i++)
     ui->pole->append(ka->zwroc(i)->Pobierz_dane());
    //ui->pole->append(ka->zwroc(1)->Pobierz_dane());
    // ui->pole->setText(ka->zwroc(0)->Pobierz_dane());

    // metoda pobierz dane wyświetla tylko 6 cech bo jest to metoda Piłkarza :D
    // trzeba ją przeciążyć w Pomocniku żeby wyświetlała wszystkie jego cechy

    plik.close();

    poprzedniaSciezka = fileName;
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_bramkarz_clicked()//dodanie określonego bramkarza do kadry działa
{
  ui->pole->clear();
  ka->Dodaj_pilkarza(new Bramkarz("Artur", "Boruc", "Bramkarz", 22, 36, 70, 82));
  int y=ka->rozmiar();
  for(int i=0;i<y;i++)
  ui->pole->append(ka->zwroc(i)->Pobierz_dane());
}
void MainWindow::on_obronca_clicked()//dodanie określonego obrońcy do kadry działa
{
    ui->pole->clear();
    ka->Dodaj_pilkarza(new Obronca("Bartosz", "Salamon", "Obronca", 21, 25, 65, 70));
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
    ui->pole->append(ka->zwroc(i)->Pobierz_dane());
}
void MainWindow::on_pomocnik_clicked()//dodanie określonego pomocnika do kadry działa
{
  ui->pole->clear();
  ka->Dodaj_pilkarza(new Pomocnik("Bartosz", "Kapustka", "Pomocnik", 15, 20, 76, 85));
  int y=ka->rozmiar();
  for(int i=0;i<y;i++)
  ui->pole->append(ka->zwroc(i)->Pobierz_dane());
}
void MainWindow::on_napastnik_clicked()//dodanie określonego napastnika do kadry działa
{
    ui->pole->clear();
    ka->Dodaj_pilkarza(new Napastnik("Mariusz", "Stępiński", "Napastnik", 17, 21, 70, 74, 69));
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
    ui->pole->append(ka->zwroc(i)->Pobierz_dane());
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_pushButton_3_clicked()//wyswietlenie kadry działa
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
    ui->pole->append(ka->zwroc(i)->Pobierz_dane());
   // ui->pole->clear();
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



///////////////////dodanie własnego zawodnika w EditLine'ach
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_imie_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString a= ui->imie->text();
    //QString b=ui->nazwisko->text();
    //ka->Dodaj_pilkarza(new Pomocnik(a, b, "Pomocnik", 400, 500, 600, 700));
  //   ui->pole->setText(ka->zwroc(0)->Pobierz_dane());
}
void MainWindow::on_nazwisko_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    //QString a= ui->imie->text();
    QString b=ui->nazwisko->text();
    //ka->Dodaj_pilkarza(new Pomocnik(a, b, "Pomocnik", 400, 500, 600, 700));
}
void MainWindow::on_pozycja_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString c= ui->pozycja->text();
}
void MainWindow::on_nr_koszulki_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString d= ui->nr_koszulki->text();
}
void MainWindow::on_wiek_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString e= ui->wiek->text();
}
void MainWindow::on_szybkosc_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString f= ui->szybkosc->text();
}
void MainWindow::on_ustawienie_na_linii_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString g= ui->ustawienie_na_linii->text();
}
void MainWindow::on_glowka_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString h= ui->glowka->text();
}
void MainWindow::on_technika_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString i= ui->technika->text();
}
void MainWindow::on_sila_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString j= ui->sila->text();
}
void MainWindow::on_wykonczenie_cursorPositionChanged(int arg1, int arg2)
{
    ui->pole->clear();
    QString k= ui->wykonczenie->text();
}
///////////////////////////////////tworzenie własnego zawodnika; połączone z powyższymi; działa
void MainWindow::on_bramkarz_gotowe_clicked()
{
    QString a= ui->imie->text();
    QString b=ui->nazwisko->text();
    QString c= ui->pozycja->text();
    QString d= ui->nr_koszulki->text();
    QString e= ui->wiek->text();
    QString f= ui->szybkosc->text();
    QString i= ui->ustawienie_na_linii->text();
    ka->Dodaj_pilkarza(new Bramkarz(a, b, c, d.toInt(), e.toInt(), f.toInt(), i.toInt()));
}
void MainWindow::on_obronca_gotowe_clicked()
{
    QString a= ui->imie->text();
    QString b=ui->nazwisko->text();
    QString c= ui->pozycja->text();
    QString d= ui->nr_koszulki->text();
    QString e= ui->wiek->text();
    QString f= ui->szybkosc->text();
    QString i= ui->glowka->text();
    ka->Dodaj_pilkarza(new Obronca(a, b, c, d.toInt(), e.toInt(), f.toInt(), i.toInt()));
}
void MainWindow::on_gotowe_clicked()//tworzenie własnego pomocnika; połączone z powyższymi; działa
{
    QString a= ui->imie->text();
    QString b=ui->nazwisko->text();
    QString c= ui->pozycja->text();
    QString d= ui->nr_koszulki->text();
    QString e= ui->wiek->text();
    QString f= ui->szybkosc->text();
    QString i= ui->technika->text();
    ka->Dodaj_pilkarza(new Pomocnik(a, b, c, d.toInt(), e.toInt(), f.toInt(), i.toInt()));
}
void MainWindow::on_napastnik_gotowe_clicked()
{
    QString a= ui->imie->text();
    QString b=ui->nazwisko->text();
    QString c= ui->pozycja->text();
    QString d= ui->nr_koszulki->text();
    QString e= ui->wiek->text();
    QString f= ui->szybkosc->text();
    QString i= ui->wykonczenie->text();
    QString j= ui->sila->text();
    ka->Dodaj_pilkarza(new Napastnik(a, b, c, d.toInt(), e.toInt(), f.toInt(), i.toInt(), j.toInt()));
}
////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/// /////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_wyswietl_bramkarzy_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Bramkarz")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
       }
}
void MainWindow::on_wyswietl_obroncow_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Obronca")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
       }
}
void MainWindow::on_wyswiet_pomocnikow_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Pomocnik")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
       }
}
void MainWindow::on_wyswietl_napastnikow_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Napastnik")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
       }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
void MainWindow::on_wzorek_bramkarz_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Bramkarz")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
           double b=ka->Przecietne_umiejetnosci(i);
              ui->pole->append(QString::number(b));continue;
       }
}
void MainWindow::on_pushButton_6_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Obronca")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
           double b=ka->Przecietne_umiejetnosci(i);
              ui->pole->append(QString::number(b));continue;
       }
}
void MainWindow::on_wzorek_pomocnik_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Pomocnik")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
           double b=ka->Przecietne_umiejetnosci(i);
              ui->pole->append(QString::number(b));continue;
       }
}
void MainWindow::on_pushButton_7_clicked()
{
    ui->pole->clear();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++)
       if(ka->oddaj_pozycje(i)=="Napastnik")
       {
           ui->pole->append(ka->zwroc(i)->Pobierz_dane());
           double b=ka->Przecietne_umiejetnosci(i);
              ui->pole->append(QString::number(b));continue;
       }
}
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



































/*void MainWindow::on_lineEdit_cursorPositionChanged(int arg1, int arg2)
{
        ui->pole->clear();
        QString g= ui->lineEdit->text();
}*/

/*void MainWindow::on_pushButton_8_clicked()
{
    QString a= ui->lineEdit->text();
    int y=ka->rozmiar();
    for(int i=0;i<y;i++){
    if(a.toInt()!=i){
        ui->pole->append(ka->zwroc(i)->Pobierz_dane());
    }
    else ka->oddaj_pilkarza_do_usuniecia(i);
    ka->_sklad.erase(i);
}}*/
