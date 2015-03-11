#include <iostream>
#include "biblioteka_vrijeme.cc"
using namespace std;
cvrijeme prvi,drugi,treci;
int main(){
  int a;
  char b[40];
  float c;
  prvi.pocetak();
  cout << "Unesi cijeli broj:";cin >> a;
  prvi.kraj();
  drugi.pocetak();
  cout << "Unesi rijec:";cin >> b;
  drugi.kraj();
  treci.pocetak();
  cout << "Unesi realni broj:";cin >> c;
  treci.kraj();
  cout << "Trajanje procesa:" << endl;
  cout << "prvi:" << prvi.proteklo() << endl;
  cout << "drugi:" << drugi.proteklo() << endl;
  cout << "treci:" << treci.proteklo() << endl;
}//main
