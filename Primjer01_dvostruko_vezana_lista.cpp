// Dvostruko vezana lista
#include <iostream>
using namespace std;
struct telement{
  int broj;
  telement *sljedeci;
  telement *prethodni;
};//struct
void dodaj_element_na_kraj(telement *lista){
  telement *novi,*zadnji;
  zadnji = lista;
  while (zadnji->sljedeci)   //traženje zadnjeg elementa u listi
    zadnji=zadnji->sljedeci;
  novi = new telement;
  novi->prethodni=zadnji;
  novi->sljedeci=NULL;
  zadnji->sljedeci=novi;
  cout << "Broj = ";
  cin >> novi -> broj;
};//dodaj_element_na_kraj
void dodaj_element_na_pocetak(telement *lista){
  if (!lista->sljedeci){ // provjera da lista nije prazna
    dodaj_element_na_kraj(lista);
    return;
  };
  telement *novi,*sljedeci;
  sljedeci = lista->sljedeci;
  novi = new telement;
  novi->prethodni=lista;  //povezivanje novog
  novi->sljedeci=sljedeci;
  lista->sljedeci=novi; //stari 'prihvaæaju' novog
  sljedeci->prethodni=novi;
  cout << "Broj = ";
  cin >> novi -> broj;
};//dodaj_element_na_kraj
void ispis_od_pocetka(telement *lista){
  telement *tekuci = lista->sljedeci;
  while (tekuci){
    cout << tekuci -> broj << ", ";
    tekuci = tekuci -> sljedeci;
  };//while
  cout << "NULL" << endl;
};//ispis_od_pocetka
void ispis_od_kraja(telement *lista){
  telement *tekuci = lista->sljedeci;
  while (tekuci->sljedeci)
    tekuci = tekuci -> sljedeci; // traženje zadnjeg elementa u listi
  while (tekuci!=lista){
    cout << tekuci -> broj << ", ";
    tekuci = tekuci -> prethodni;
  };//while
  cout << "glava" << endl;
};//ispis_od_kraja
telement *dealokacija_liste(telement *lista){ //dealokacija liste
  telement *tekuci,*prethodni;
  prethodni=lista;
  tekuci=lista->sljedeci;
  while (tekuci){
    delete prethodni;
    prethodni=tekuci;
    tekuci=tekuci->sljedeci;
  }//while
  delete prethodni;
  return NULL;
};//dealokacija_liste
int main(){
  int izbor;
  telement *lista = new telement; // alokacija glave liste
  lista -> sljedeci = NULL;
  lista -> prethodni = NULL;
  do{
    cout << "1. dodavanje elementa na kraj liste" << endl;
    cout << "2. dodavanje elementa na pocetak liste" << endl;
    cout << "3. ispis svih elemenata liste od pocetka" << endl;
    cout << "4. ispis svih elemenata liste od kraja" << endl;
    cout << "9. dealokacija liste i izlaz iz programa" << endl;
    cin >> izbor;
    switch (izbor){
      case 1: dodaj_element_na_kraj(lista);break;
      case 2: dodaj_element_na_pocetak(lista);break;
      case 3: ispis_od_pocetka(lista);break;
      case 4: ispis_od_kraja(lista);break;
      case 9:lista=dealokacija_liste(lista);break;
    }//switch
  } while(izbor!=9);
  return 1;
}// main
