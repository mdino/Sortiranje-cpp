#include <iostream>
using namespace std;

class cvozilo{		// definira ono što je zajednièko za sva vozila
public:
	int godiste, tezina, snaga_motora, max_brzina;
	void ispis(){
		cout << "Vozilo : " << endl;
		cout << "Godiste : " << godiste << endl;
	};
};

class cautomobil : public cvozilo{	//klasa cautomobil nasljeðuje klasu cvozilo
};
class ckamion : public cvozilo{		//klasa ckamion nasljeðuje klasu cvozilo
public:
	int nosivost;
	void ispis(){					// funkcijski èlan ispis je redefiniran
		cout << "Kamion : " << endl;
		cout << "Godiste : " << godiste << endl;
		cout << "Nosivost : " << nosivost << endl;
	};
};

class cautobus : public cvozilo{	//klasa cautobus nasljeðuje klasu cvozilo
public:
	int broj_sjedala;
};

cvozilo *vozilo; cautomobil *automobil; ckamion *kamion; cautobus *autobus;

int main (){
	vozilo=new cvozilo;
	automobil=new cautomobil;
	kamion=new ckamion;
	autobus=new cautobus;

	vozilo->godiste=1990;
	vozilo->ispis();

	automobil->godiste=1995;		// atribut godiste je nasljeðen od klase cvozilo,
	automobil->ispis();			// kao i metoda ispis.

	kamion->godiste=1996;
	kamion->nosivost=5000;		// atribut nosivost specifièan je za klasu ckamion
	kamion->ispis();			// metoda ispis je redefinirana u klasi ckamion
  return 1;
}
