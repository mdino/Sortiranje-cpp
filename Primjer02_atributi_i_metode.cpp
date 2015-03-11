#include <iostream>
#include <cstring>
using namespace std;
class cprobna{
  public: //Obavezno, jer se podrazumijeva pristup private!
  int atribut;
  void metoda(){
    cout << "metoda" << endl;
  };//metoda
};//cprobna
cprobna objekt1,objekt2;
int main(){
  cout << sizeof(objekt1) << endl; // 4 = sizeof(int)    
  objekt1.atribut=10;
  memcpy (&objekt2,&objekt1,sizeof(cprobna));
  cout << objekt2.atribut << endl;
  return 1;
}//main
