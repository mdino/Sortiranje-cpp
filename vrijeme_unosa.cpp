//Vrijeme unosa cjelobrojne varijable
#include <iostream>
#include "biblioteka_tel_imenik.cc"
using namespace std;
int main(){
  int a;
  vrijeme_pocetak();
  cout << "Unesite cijeli broj: "; cin >> a;
  vrijeme_kraj();
  cout << "Proteklo vrijeme za unos: " << vrijeme_proteklo() << endl;
  return 1;
}
