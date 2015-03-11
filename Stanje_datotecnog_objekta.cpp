#include<iostream>
#include<fstream>
using namespace std;
void stanje_dat_objekta(fstream &dat){  //argument tipa fstream mora biti referenca!
  cout << "-----<Stanje datotecnog objekta>-----" << endl;
  if (dat.is_open() == false){
    cout << "Datoteka nije otvorena!" << endl;
    return;
    }

  cout << "Datotecni pokazivac za citanje: " << dat.tellg() << endl;
  cout << "Datotecni pokazivac za upis: " << dat.tellp() << endl;
  if (dat.eof()){
    cout << "Kraj datoteke!" << endl;
  }
  if (dat.good()){
    cout << "Datoteka je spremna za upis/citanje." << endl;
  } else {
    cout << "Datoteka trenutno nije spremna za upis/citanje." << endl;
  }
  cout << "Stanje zastavice pogreske: " << dat.rdstate() << endl;

  int pamti=dat.tellg();
  dat.seekg (0, ios::end); // relativna pozicija u odnosu na kraj datoteke
  cout << "Velicina datoteke (b): " << dat.tellg() << endl;
  dat.seekg(pamti);
};//stanje_dat_objekta

int main(){
  fstream dat,dat2;
  stanje_dat_objekta(dat);
  dat.clear();
  int a = 55;
  dat.open("podaci.dat",ios::out|ios::binary); // kreiranje datoteke
  dat.write((char *)&a,sizeof(a));
  stanje_dat_objekta(dat);
  dat.close();

  dat2.open("tekst.txt",ios::out);
  dat2 << "Ovo se upisuje u datoteku!" << endl;
  stanje_dat_objekta(dat2);
  dat2.close();
  return 0;
}
