// Sortiranje polja pomoæu binarnog stabla
#include <iostream>
#include <stdlib.h>
#include "biblioteka_vrijeme.cc"
using namespace std;
struct telement{
  int broj;
  telement *lijevo,*desno;
};//struct
int indeks;
void puni_polje(int *polje, int broj_el){
	int i,broj;
	for (i=0;i<broj_el;i++){
			broj=rand()%1000;
			polje[i]=broj;
	}
};//puni_polje
void dodaj_element_u_stablo(telement *stablo, int broj){
  telement *zadnji,*novi;
  int dalje=1;
	zadnji=stablo;
	do{
		if (broj>zadnji->broj){
			if (zadnji->desno!=NULL){zadnji=zadnji->desno;}
		else{
			novi=new telement;
			zadnji->desno=novi;
			novi->broj=broj;
			novi->lijevo=NULL;
			novi->desno=NULL;
			dalje=0;
			}//if
		}//if
		else{//broj<=zadnji->broj
			if (zadnji->lijevo!=NULL){zadnji=zadnji->lijevo;}
		else{
			novi=new telement;
			zadnji->lijevo=novi;
			novi->broj=broj;
			novi->lijevo=NULL;
			novi->desno=NULL;
			dalje=0;
			}//if
		}
	}while (dalje==1);
};// dodaj_element_u_stablo
void puni(telement *stablo,int *polje, int broj_el){
	int i;
	for (i=0;i<broj_el;i++){
		dodaj_element_u_stablo(stablo,polje[i]);
	}// for
}; // puni
void sort(telement *stablo,int *polje,int redoslijed=1){
  static telement *korijen=stablo;
	if (stablo==NULL) {return;}// sidro rekurzije; omoguæuje izlaz
	switch (redoslijed){
	case 1:
		sort (stablo->lijevo,polje);
		if (stablo!=korijen) polje[indeks++]=stablo->broj;
		sort (stablo->desno,polje);break;
	case 2:
		sort (stablo->desno,polje,2);
		if (stablo!=korijen) polje[indeks++]=stablo->broj;
		sort (stablo->lijevo,polje,2);break;
	}//switch
};// sort
void ispis(int *polje, int broj_el){
	int i;
	for (i=0;i<broj_el;i++){
		cout <<polje[i]<<",";
	}
};//ispis
void dealokacija(telement *stablo){//rekurzivna funkcija
  if (stablo->lijevo)dealokacija(stablo->lijevo);
  if (stablo->desno)dealokacija(stablo->desno);
  delete stablo;
  return;
};// dealokacija
void bubble_sort(int *polje, int broj_el){
	int i,j,pom;
	for (j=0;j<broj_el-1;j++)
  	for (i=0;i<broj_el-1;i++){
      if (polje[i]>polje[i+1]){
        pom=polje[i];
        polje[i]=polje[i+1];
        polje[i+1]=pom;
      }//if
    };
};//bubble_sort
int main(){
  int izbor,broj_el;
  telement *stablo;
  int *polje;
  stablo = new telement;  // korijen stabla
  stablo->lijevo=NULL;
  stablo->desno=NULL;
	cout << "Broj elemenata polja:";
  cin >> broj_el;
  polje=new int[broj_el]; // alokacija polja
  do{
    indeks=0;
		cout << "Hocete li:"<<endl<<endl;
		cout << "1. Ispuni polje" << endl;
		cout << "2. Prepisi polje u stablo, sortiraj uzlazno, dealociraj stablo"<<endl;
		cout << "3. Prepisi polje u stablo, sortiraj silazno, dealociraj stablo"<<endl;
		cout << "4. Sortiranje polja metodom Bubble sort"<<endl;
		cout << "5. Ispis izlaznog polja"<<endl;
		cout << "9. Izlaz"<<endl<<endl;
		cin >> izbor;
		switch(izbor){
			case 1:puni_polje(polje,broj_el);cout <<"Ispunjeno!"<<endl;break;
			case 2:vrijeme_pocetak();
             puni(stablo,polje,broj_el);
             sort(stablo,polje);
             dealokacija(stablo);
             stablo=new telement; stablo->lijevo=NULL; stablo->desno=NULL;//novi korijen stabla
             vrijeme_kraj();
             cout <<"Sortirano za "<<vrijeme_proteklo()<<endl;
             break;
			case 3:vrijeme_pocetak();
             puni(stablo,polje,broj_el);
             vrijeme_kraj();
             cout <<"Punjenje stabla za "<<vrijeme_proteklo()<<endl;
             vrijeme_pocetak();
             sort(stablo,polje,2);
             vrijeme_kraj();
             cout <<"Prijepis stabla u polje (silazni redoslijed) za "<<vrijeme_proteklo()<<endl;
             vrijeme_pocetak();
             dealokacija(stablo);
             vrijeme_kraj();
             cout <<"Dealokacija stabla za "<<vrijeme_proteklo()<<endl;
             stablo=new telement; stablo->lijevo=NULL; stablo->desno=NULL;//novi korijen stabla
             break;
			case 4:vrijeme_pocetak();
             bubble_sort(polje,broj_el);
             vrijeme_kraj();
             cout <<"Sortirano za "<<vrijeme_proteklo()<<endl;break;
			case 5:ispis(polje,broj_el);cout << endl;break;
		};
  } while(izbor!=9);
    delete [] polje;
  return 1;

}//main
