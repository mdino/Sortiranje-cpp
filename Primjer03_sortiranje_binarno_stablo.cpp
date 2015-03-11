// Sortiranje polja pomoæu binarnog stabla
#include <iostream>
#include <stdlib.h>
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
int main(){
  int izbor,broj_el;
  telement *stablo;
  int *polje1;// ulazno polje
  int *polje2;// izlazno polje
  stablo = new telement;  // korijen stabla
  stablo->lijevo=NULL;
  stablo->desno=NULL;
	cout << "Broj elemenata polja:";
  cin >> broj_el;
  polje1=new int[broj_el]; // alokacija polja
  polje2=new int[broj_el];
  do{
    indeks=0;
		cout << "Hocete li:"<<endl<<endl;
		cout << "1. Ispuni ulazno polje (polje1)" << endl;
		cout << "2. Prepisi ulazno polje u stablo"<<endl;
		cout << "3. Sortiranje uz pomoc stabla uzlazno"<<endl;
		cout << "4. Sortiranje uz pomoc stabla silazno"<<endl;
		cout << "5. Ispis izlaznog polja"<<endl;
		cout << "9. Izlaz"<<endl<<endl;
		cin >> izbor;
		switch(izbor){
			case 1:puni_polje(polje1,broj_el);cout <<"Ispunjeno!"<<endl;break;
			case 2:puni(stablo,polje1,broj_el);cout <<"Upisano u stablo!"<<endl;break;
			case 3:sort(stablo,polje2);break;
			case 4:sort(stablo,polje2,2);break;
			case 5:ispis(polje2,broj_el);cout << endl;break;
		};
  } while(izbor!=9);
    dealokacija (stablo);
    delete [] polje1;
    delete [] polje2;
  return 1;

}//main
