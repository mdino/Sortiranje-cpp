//Upis u tekstualnu datoteku
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	fstream dat;
	dat.open("tekst.txt",ios::out);
	dat << "Ovo se upisuje u tekstualnu datoteku." << endl;
	dat << "I ovo (u drugi red)" << endl;
	int i = 150;
	dat << i << endl;
	dat.close();dat.clear();
	return 1;
}
