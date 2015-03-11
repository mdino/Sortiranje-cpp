//Vezana lista - primjer zaštiæenog nasljeðivanja
#include <iostream>
using namespace std;
class clista{
  protected: clista *sljedeci;
};//clista
class cstudent:public clista{
  public:
  //atributi
  int mat_br;
  char prez_ime[35];
  int god_stu;
  //metode
  cstudent(){//konstruktor
    sljedeci=NULL;
  };//konstruktor
  void dodaj_element(){ // dodaje element na kraj liste
    cstudent *novi,*zadnji;
    zadnji = this;
    while (zadnji->sljedeci)
      zadnji = (cstudent*)zadnji->sljedeci;       // pronalaženje zadnjeg elementa u listi
    novi = new cstudent;                // alokacija novog elementa liste
    zadnji -> sljedeci = novi;         // povezivanje zadnjeg elementa u listi s novim elementom
    cout << "Maticni broj: "; cin >> novi -> mat_br;
    cout << "Prezime i ime: "; cin >> novi -> prez_ime;
    cout << "Godina studija: "; cin >> novi -> god_stu;
  };//dodaj_element
  void ispisi_sve_elemente(){ // ispis svih elemenata liste
    cstudent *tekuci = (cstudent *)this -> sljedeci;  // tekuci se usmjerava na poèetni element za ispis
    while (tekuci){
      cout << "Maticni broj: " << tekuci -> mat_br << endl;
      cout << "Prezime i ime: " << tekuci -> prez_ime << endl;
      cout << "Godina studija: " << tekuci -> god_stu << endl;
      cout << "---------------------" << endl;
      tekuci = (cstudent *)tekuci -> sljedeci;   // kretanje kroz listu
    }; // while
  };//ispisi_sve_elemente
};//cstudent
cstudent *lista;
int main(){
  int izbor;
  lista=new cstudent; //alokacija glave liste
  do{
    cout << "1. dodavanje novog elementa na kraj liste" << endl;
    cout << "2. ispis svih elemenata liste" << endl;
    cout << "9. izlaz" << endl;
    cin >> izbor;
    switch (izbor){
      case 1:lista->dodaj_element();break;
      case 2:lista->ispisi_sve_elemente();break;
    };
  } while (izbor!=9);
}//main
