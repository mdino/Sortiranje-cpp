#include <iostream>
int a;  // globalna varijabla a
class cklasa{
  public: int a,b;
  static int c; // vrijednost c se dijeli izmeðu svih objekata klase
  enum {pon,uto,sri,cet,pet,sub,ned}; // pobrojenje
  void metoda(); //prototip metode
};//cklasa                                               
void cklasa::metoda(){  //metoda pripada klasi cklasa
  std::cout << "Metoda izvan tijela klase" << std::endl;
  c=55; // statièki èlan klase
};//metoda
cklasa objekt1,objekt2;
int cklasa::c=5; //posebno se deklarira jer ne pripada svakom objektu pojedinaèno
int main(){
  objekt1.metoda(); // kod poziva nema razlike
  char a; // lokalna varijabla a koja prekriva istoimenu globalnu var.
  a = 'A'; // podrazumijeva se lokalna varijabla
  ::a=55; // ovo je globalna varijabla a
  std::cout << cklasa::ned << std::endl; //pristup èlanu pobrojenja
  std::cout << cklasa::c << std::endl;
  cklasa::c=99;
  std::cout << objekt1.c << std::endl;
  std::cout << objekt2.c << std::endl;
  return 1;
}//main
