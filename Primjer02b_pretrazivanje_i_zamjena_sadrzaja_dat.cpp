//Pretraživanje i zamjena sadržaja tekstualne datoteke
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;
void unos(char *znakovni_niz)
{
	cin.getline(znakovni_niz, 150);
	if (cin.gcount()==1)
	  	 cin.getline (znakovni_niz,150);
};
int main(){
  int i,j,duzina,brojac_zamjena=0;
  char naziv_ul[40],naziv_izl[40];
  char trazeni_niz[100],zamjenski_niz[100];
  cout<<"Naziv ulazne datoteke: ";unos(naziv_ul);
  cout<<"Naziv izlazne datoteke: ";unos(naziv_izl);
  cout<<"Trazeni znakovni niz: ";unos(trazeni_niz);
  cout<<"Zamjenski znakovni niz: ";unos(zamjenski_niz);
  fstream dat_ul,dat_izl; // datoteèni objekti
  dat_ul.open (naziv_ul,ios::in);
  dat_izl.open (naziv_izl,ios::out);
  char red[500],zamjenski_red[500];  // red teksta
  while(1){
    zamjenski_red[0]='\0'; // prazan znakovni niz
    dat_ul.getline(red,sizeof(red),'\n');
    if (dat_ul.eof())break;
    int pomak=0;
    for (i=0;i<(int)strlen(red);i++){
      if (red[i+pomak]==trazeni_niz[pomak]){
        pomak++;
        i--;}
      else if (pomak < (int)strlen(trazeni_niz)){
        duzina=strlen(zamjenski_red);
        for (j=0;j<=pomak;j++){
          zamjenski_red[duzina+j]=red[i+j];
          zamjenski_red[duzina+j+1]='\0'; //kraj reda
        }//for
        i+=pomak;
        pomak=0;}
      if (pomak==(int)strlen(trazeni_niz)){
        strcat (zamjenski_red,zamjenski_niz);
        i+=pomak;
        pomak=0;
        brojac_zamjena++;
      }//if
    }// for i
    dat_izl << zamjenski_red << endl;
  }//while (1)
  dat_ul.close();
  dat_izl.close();
  cout << "Broj zamjena: " << brojac_zamjena << endl;
  return 1;
}
