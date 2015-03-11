#include <iostream>
using namespace std;
class cpravokutnik {
    public: int x1,y1,x2,y2;//javni èlanovi klase=dostupni izvan klase
    private: int sirina, visina;//privatni èlanovi=dostupni unutar klase
    public:
	int povrsina (){//javni èlan klase
    visina = y2 - y1;
    sirina = x2 - x1;
		return sirina * visina;
	};//povrsina
};//cpravokutnik
cpravokutnik p1,p2,*kvadrat; // objekti iz klase cpravokutnik
int main(){
  p1.x1=50;p1.y1=50;p1.x2=150,p1.y2=100; // javni èlanovi objekta p1
  cout << "Povrsina pravokutnika p1: " << p1.povrsina() << endl;

  p2.x1=100;p2.y1=100;p2.x2=150,p2.y2=200;
  cout << "Povrsina pravokutnika p2: " << p2.povrsina() << endl;

  kvadrat=new cpravokutnik; // dinamièka alokacija objekta

  kvadrat->x1=150;kvadrat->y1=150;kvadrat->x2=200;kvadrat->y2=200;
  cout << "Povrsina kvadrata: " << kvadrat->povrsina() << endl;
  //p1.sirina=10;p1.visina=20; // Privatni èlanovi nisu dostupni izvan klase!

  delete kvadrat; // dealokacija objekta
  return 1;
}//main
