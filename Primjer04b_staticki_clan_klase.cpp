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
int cklasa::brojac;       // definira statièki èlan klase (mora biti izvan klase)
cklasa objekt,o2;         // dva objekta iz klase cklasa
int main ()
{
      cklasa::brojac=10;  // upotreba statièkog èlana klase izvan klase
      objekt.metoda();    // odnosno pomoæu odgovarajuæe metode
      o2.metoda();
}
