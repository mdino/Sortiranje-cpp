// Binarno stablo
#include <iostream>
using namespace std;
struct telement{
  int broj;
  telement *lijevo,*desno;
};//struct

void dodaj_element_u_stablo(telement *stablo, int broj){
  telement *zadnji,*novi;
  int dalje=1;
	zadnji=stablo;
	do{
		if (broj>zadnji->broj){
			if (zadnji->desno!=NULL){zadnji=zadnji->desno;} //prijelaz na desni pod�vor
		else{ // dodavanje desnog pod�vora
			novi=new telement;
			zadnji->desno=novi;
			novi->broj=broj;
			novi->lijevo=NULL;
			novi->desno=NULL;
			dalje=0;
			}//if
		}//if
		else{//broj<=zadnji->broj
			if (zadnji->lijevo!=NULL){zadnji=zadnji->lijevo;} //prijelaz na lijevi pod�vor
		else{ // dodavanje lijevog pod�vora
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
void sort_uzlazno(telement *stablo){
  static telement *korijen=stablo;
	if (stablo==NULL) return;// sidro rekurzije; omogu�uje izlaz
		sort_uzlazno (stablo->lijevo);
	if (stablo!=korijen) cout<<stablo->broj<<", ";
		sort_uzlazno (stablo->desno);
};//sort_uzlazno
telement *trazi(telement *stablo, int broj){//vra�a adresu �vora ili NULL
  telement *tekuci=stablo;
  while (tekuci){
    if ((tekuci->broj==broj)&&(tekuci!=stablo))break;
    if (broj>tekuci->broj)
      tekuci=tekuci->desno;
    else
      tekuci=tekuci->lijevo;
  };//while
  return tekuci;
};// trazi

int main(){
  int izbor,broj;
  telement *stablo = new telement;
  stablo->lijevo=NULL;
  stablo->desno=NULL;
  do{
    cout << "1. dodavanje cvora u binarno stablo" << endl;
    cout << "2. ispis cvorova u uzlaznom redoslijedu" << endl;
    cout << "3. pretrazivanje binarnog stabla" << endl;
    cout << "9. izlaz iz programa" << endl;
    cin >> izbor;
    switch (izbor){
      case 1: cout << "Broj = ";
              cin >> broj;
              dodaj_element_u_stablo(stablo,broj);break;
      case 2: sort_uzlazno(stablo);
              cout << "kraj!" << endl;break;
      case 3: cout << "Broj = ";
              cin >> broj;
              if(trazi(stablo,broj))
                cout << "Broj je nadjen na adresi " << (int)trazi(stablo,broj) << endl;
              else
                cout << "Broj nije nadjen u stablu!" << endl;
              ;break;
      case 9: break;
    }//switch
  } while(izbor!=9);
  return 1;

}//main
