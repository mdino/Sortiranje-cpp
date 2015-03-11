//Nasljeðivanje fstream
#include <iostream>
#include <fstream>
#include<cstring>
using namespace std;
class cdatoteka:public fstream{
  public:
  char naziv_datoteke[30]; // fizièko ime datoteke
  void stanje(){
    cout << "-----<Stanje datotecnog objekta>-----" << endl;
    if (this->is_open() == false){
      cout << "Datoteka nije otvorena!" << endl;
      return;
    }
    cout << "Datotecni pokazivac za citanje: " << this->tellg() << endl;
    cout << "Datotecni pokazivac za upis: " << this->tellp() << endl;
    if (this->eof()){
      cout << "Kraj datoteke!" << endl;
    }
    if (this->good()){
      cout << "Datoteka je spremna za upis/citanje." << endl;
    } else {
      cout << "Datoteka trenutno nije spremna za upis/citanje." << endl;
    }
    cout << "Stanje zastavice pogreske: " << this->rdstate() << endl;
  };//stanje_dat_objekta
  int velicina(){
    int vel;
    int pamti=this->tellg();
    this->seekg (0, ios::end); // relativna pozicija u odnosu na kraj datoteke
    vel = (int)this->tellg();
    this->seekg(pamti);
    return vel;
  };//velicina
  void open(char *naziv){ // prekriva postojeæu metodu open!
    this->fstream::open (naziv, ios::in);
    if (!*this){
      cout << "Ne mogu otvoriti datoteku " << naziv << endl;
      cout << "Kreiram novu datoteku!" << endl;
      this->fstream::open (naziv, ios::out);
      this->close();this->clear();
    } else {
      this->close();this->clear();
    }//if
    this->fstream::open (naziv, ios::in|ios::out|ios::binary);
    cout << "Datoteka "<< naziv << " je otvorena za upis i citanje!" << endl;
    strcpy(naziv_datoteke,naziv);
  };//open
};//cdatoteka
int main(){
  cdatoteka dat;
  dat.open((char *)"podaci.dat"); // Modificirani open!
  cout << "Fizicko ime datoteke: " << dat.naziv_datoteke << endl;
  dat.stanje();
  cout << endl;
  cout << "Velicina datoteke = " << dat.velicina() << endl;
  dat.close();dat.clear();
  return 0;
}
