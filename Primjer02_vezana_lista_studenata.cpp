//Vezana lista objekata
#include <iostream>
using namespace std;
class cstudent{
  private: cstudent *sljedeci;
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
      zadnji = zadnji->sljedeci;       // pronalaženje zadnjeg elementa u listi
    novi = new cstudent;                // alokacija novog elementa liste
    zadnji -> sljedeci = novi;         // povezivanje zadnjeg elementa u listi s novim elementom
    cout << "Maticni broj: "; cin >> novi -> mat_br;
    cout << "Prezime i ime: "; cin >> novi -> prez_ime;
    cout << "Godina studija: "; cin >> novi -> god_stu;
  };//dodaj_element
  void ispisi_sve_elemente(){ // ispis svih elemenata liste
    cstudent *tekuci = this -> sljedeci;  // tekuci se usmjerava na poèetni element za ispis
    while (tekuci){
      cout << "Maticni broj: " << tekuci -> mat_br << endl;
      cout << "Prezime i ime: " << tekuci -> prez_ime << endl;
      cout << "Godina studija: " << tekuci -> god_stu << endl;
      cout << "---------------------" << endl;
      tekuci = tekuci -> sljedeci;   // kretanje kroz listu
    }; // while
  };//ispisi_sve_elemente
  void pretrazi_listu(int mat_br){ //pretraživanje liste prema matiènom broju
    int nadjen=0;
    cstudent *tekuci = this -> sljedeci;  // tekuci se usmjerava na poèetni element za ispis
    while (tekuci){
      if (tekuci -> mat_br == mat_br){
        nadjen=1;
        cout << "Maticni broj: " << tekuci -> mat_br << endl;
        cout << "Prezime i ime: " << tekuci -> prez_ime << endl;
        cout << "Godina studija: " << tekuci -> god_stu << endl;
        cout << "---------------------" << endl;
        break;  // izlaz iz petlje
      };//if
      tekuci = tekuci -> sljedeci;   // kretanje kroz listu
    }; // while
    if (!nadjen) cout<<"Element nije pronadjen u listi!"<<endl;
  };//pretrazi_listu
  void brisi_element(int mat_br){ //brisanje elementa liste prema matiènom broju
    int nadjen=0;
    cstudent *brisi = this -> sljedeci, *prethodni = this;
    while (brisi){
      if (brisi -> mat_br == mat_br){
        nadjen=1;
        prethodni -> sljedeci = brisi -> sljedeci;
        delete brisi;
        break; // izlaz iz petlje
      }; // if
      prethodni = brisi;
      brisi = brisi->sljedeci;
    }; // while
    if (nadjen) cout << "Element je izbrisan iz liste!" << endl;
    else cout << "Element nije pronadjen!" << endl;
  };//brisi element
  void sortiraj_listu(){ //sortiranje liste uzlazno po matiènom broju
    if (this->sljedeci==NULL) return; // izlaz ako je lista prazna
    cstudent *prethodni,*tekuci,*sljedeci;
    int indikator;
    do{
      indikator = 0;
      tekuci=this->sljedeci;
      prethodni=this;
      while (tekuci->sljedeci){
        sljedeci=tekuci->sljedeci;
        if (tekuci->mat_br > sljedeci->mat_br){
           prethodni->sljedeci=sljedeci;
           tekuci->sljedeci=sljedeci->sljedeci;
           sljedeci->sljedeci=tekuci;
           indikator=1;
        }//if
        prethodni=prethodni->sljedeci;
        tekuci=prethodni->sljedeci;
      }//while
    } while (indikator==1);
  }; // sortiraj listu
  cstudent *dealokacija_liste(){ //dealokacija liste
    cstudent *tekuci,*prethodni;
    prethodni=this;
    tekuci=this->sljedeci;
    while (tekuci){
      delete prethodni;
      prethodni=tekuci;
      tekuci=tekuci->sljedeci;
    }//while
    delete prethodni;
    return NULL;
  };//dealokacija_liste
};//class
cstudent *lista;
int main(){
  int izbor, mat_br;
  lista=new cstudent; //alokacija glave liste
  do{
    cout << "1. dodavanje novog elementa na kraj liste" << endl;
    cout << "2. ispis svih elemenata liste" << endl;
    cout << "3. pretrazivanje liste prema maticnom broju" << endl;
    cout << "4. brisanje elementa liste prema maticnom broju" << endl;
    cout << "5. sortiranje liste prema maticnom broju uzlazno" << endl;
    cout << "9. dealokacija liste i izlaz" << endl;
    cin >> izbor;
    switch (izbor){
      case 1:lista->dodaj_element();break;
      case 2:lista->ispisi_sve_elemente();break;
        case 3:
        cout << "Maticni broj: "; cin >> mat_br;
        lista->pretrazi_listu(mat_br);break;
        case 4:
        cout << "Maticni broj: "; cin >> mat_br;
        lista->brisi_element(mat_br);break;
        case 5:lista->sortiraj_listu();break;
        case 9:lista=lista->dealokacija_liste();break;
    };
  } while (izbor!=9);
}//main
