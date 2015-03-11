//Telefonski imenik: relativna datoteka
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include "biblioteka_tel_imenik.cc"
using namespace std;
struct timenik{
  int rb_zapisa;
  int tel_broj;
  char prez_ime[35];
  char adresa[50];
};//timenik
fstream dat;
int prost_broj;
int prvi_manji_prost(int x){
  int i,j,prost;
  for (i=x-1;i>1;i--){
    prost = 1; // pretpostavka da je prost broj
    for (j=2;j<=sqrt(i);j++){
      if (i%j==0){prost=0;break;}
    } // for j
    if (prost) return i;
  }//for i
  return 0;
};//prvi_manji_prost
void kreiranje_datoteke(int vd){
  timenik slog;
  int i;
  slog.tel_broj=0;//'prazan' slog
  slog.prez_ime[0]='\0';
  slog.adresa[0]='\0';
  prost_broj=prvi_manji_prost(vd);
  cout << "Prosti broj=" << prost_broj << endl;
  dat.open ("imenik_rel.dat",ios::out|ios::binary);
  for (i=0;i<vd;i++){
    slog.rb_zapisa=i;
    dat.write ((char *)&slog,sizeof(timenik));
  }//for
  dat.close();dat.clear();
};//kreiranje_datoteke
void unos_zapisa_rucno(){
  timenik slog,slog2;
  int rbz; // redni broj zapisa
  cout << "Telefonski broj:";while (!unos_tel(slog.tel_broj));
  cout << "Prezime i ime:";unos(slog.prez_ime);
  cout << "Adresa:";unos(slog.adresa);
  rbz=slog.tel_broj%prost_broj; //Ovo još treba provjeriti!
  dat.open ("imenik_rel.dat",ios::in|ios::out|ios::binary);//U/I datoteka
  dat.seekg(rbz*sizeof(timenik));
  do{ // traženje prve slobodne pozicije
    dat.read((char *)&slog2,sizeof(timenik));
  }while (slog2.tel_broj>0);
  rbz=(dat.tellg()/sizeof(timenik))-1;
  dat.seekp(rbz*sizeof(timenik));
  slog.rb_zapisa=slog2.rb_zapisa;
  dat.write ((char *)&slog,sizeof(timenik));
  dat.close();dat.clear();
};//unos_zapisa_rucno
void ispis_svih_zapisa(){
  timenik slog;
  dat.open ("imenik_rel.dat",ios::in|ios::binary);
  while (1){
    dat.read ((char *)&slog, sizeof(timenik));
    if (dat.eof())break;
    if (slog.tel_broj>0){
      cout << "Zapis br. " << slog.rb_zapisa << endl;
      cout << "Telefonski broj:00"<<slog.tel_broj << endl;
      cout << "Prezime i ime:"<<slog.prez_ime<<endl;
      cout << "Adresa:"<<slog.adresa<<endl;
    }//if
  }//while
  dat.close();dat.clear();
};//ispis_svih_zapisa
void generiranje_zapisa(int broj_zapisa){
  timenik slog,slog2;
  int rbz,i,j;
  dat.open ("imenik_rel.dat",ios::in|ios::out|ios::binary);//U/I datoteka
  for (i=1;i<=broj_zapisa;i++){
    slog.tel_broj=rand()%1000+rand()%1000*1000+1000000;
    // prezime i ime
    slog.prez_ime[0]=char(rand()%26+65);
    for (j=1;j<=6;j++)
      slog.prez_ime[j]=char(rand()%26+97);
    slog.prez_ime[7]=' ';
    slog.prez_ime[8]=char(rand()%26+65);
    for (j=9;j<=16;j++)
      slog.prez_ime[j]=char(rand()%26+97);
    slog.prez_ime[17]='\0';
    // adresa
    slog.adresa[0]=char(rand()%26+65);
    for (j=1;j<=10;j++)
      slog.adresa[j]=char(rand()%26+97);
    slog.adresa[11]=' ';
    slog.adresa[12]=char(rand()%10+48);
    slog.adresa[13]='\0';
    rbz=slog.tel_broj%prost_broj; //Ovo još treba provjeriti!
    dat.seekg(rbz*sizeof(timenik));
    do{ // traženje prve slobodne pozicije
      dat.read((char *)&slog2,sizeof(timenik));
    }while (slog2.tel_broj>0);
    rbz=(dat.tellg()/sizeof(timenik))-1;
    dat.seekp(rbz*sizeof(timenik));
    slog.rb_zapisa=slog2.rb_zapisa;
    dat.write ((char *)&slog,sizeof(timenik));
  }//for
  dat.close();dat.clear();
};//generiranje_zapisa
void pretrazivanje_zapisa(int tel_broj){
  vrijeme_pocetak();
  timenik slog;
  bool nadjen=false;
  int brojac=0,rbz;
  dat.open ("imenik_rel.dat",ios::in|ios::binary);
  rbz=tel_broj%prost_broj; //Ovo još treba provjeriti!
  dat.seekg(rbz*sizeof(timenik));
  do {
    dat.read ((char *)&slog, sizeof(timenik));
    if (dat.eof())break;
    brojac++;
    if (slog.tel_broj==tel_broj){
      nadjen=true;
      cout << "Zapis br. " << slog.rb_zapisa << endl;
      cout << "Telefonski broj:00"<<slog.tel_broj << endl;
      cout << "Prezime i ime:"<<slog.prez_ime<<endl;
      cout << "Adresa:"<<slog.adresa<<endl;
      break;
    }//if
  } while (slog.tel_broj>0);
  dat.close();dat.clear();
  vrijeme_kraj();
  if (!nadjen) cout << "Zapis nije pronadjen!" << endl;
  cout <<"Ukupan broj procitanih zapisa:"<<brojac<<endl;
  cout <<"Vrijeme pretrazivanja:"<<vrijeme_proteklo()<<endl;
};//pretrazivanje_zapisa
int main(){
  int izbor,tel_broj,vd,broj_zapisa;
  do{cout << endl;
    cout << "0. kreiranje datoteke s praznim zapisima i racunanje prostog broja" << endl;
    cout << "1. unos novog zapisa u datoteku (rucno)" << endl;
    cout << "2. ispis zapisa o svim pretplatnicima" << endl;
    cout << "3. generiranje zapisa o pretplatnicima" << endl;
    cout << "4. pretrazivanje zapisa po telefonskom broju" << endl;
    cout << "9. izlaz iz programa" << endl;
    cin >> izbor;
    switch (izbor){
      case 0:
        cout << "Velicina datoteke u broju zapisa:"; cin>>vd;
        vrijeme_pocetak();
        kreiranje_datoteke(vd);
        vrijeme_kraj();
        cout <<"Vrijeme kreiranja datoteke s praznim zapisima:"<<vrijeme_proteklo()<<endl;break;
      break;
      case 1:unos_zapisa_rucno();break;
      case 2:ispis_svih_zapisa();break;
      case 3:
        cout << "Koliko zapisa zelite generirati?"; cin>>broj_zapisa;
        vrijeme_pocetak();
        generiranje_zapisa(broj_zapisa);
        vrijeme_kraj();
        cout <<"Vrijeme generiranja i upisa u datoteku (preko postojecih zapisa!):"<<vrijeme_proteklo()<<endl;break;
      case 4: cout << "Telefonski broj:";while (!unos_tel(tel_broj));
              pretrazivanje_zapisa(tel_broj);break;
    }//switch
  } while (izbor!=9);
	return 1;
}
