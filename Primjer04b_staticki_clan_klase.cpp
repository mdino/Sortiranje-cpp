#include <iostream>
using namespace std;

class cklasa
{
public:
  static int brojac;
  void metoda(){
    cout << brojac << endl;
  }
};
int cklasa::brojac;       // definira stati�ki �lan klase (mora biti izvan klase)
cklasa objekt,o2;         // dva objekta iz klase cklasa
int main ()
{
      cklasa::brojac=10;  // upotreba stati�kog �lana klase izvan klase
      objekt.metoda();    // odnosno pomo�u odgovaraju�e metode
      o2.metoda();
}
