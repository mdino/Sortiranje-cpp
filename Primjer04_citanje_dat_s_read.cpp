//Upis podataka u datoteku s fiknom velièinom sloga pomoæu metode write
#include <iostream>
#include <fstream>
using namespace std;
struct tslog{
		int mat_br;
		char prez_ime[35];
		int g_upisa;
};
int main(){
	tslog slog;
	fstream dat ("podaci.dat",ios::in | ios::binary);
	while (1){
		dat.read ((char *) &slog,sizeof(slog));
		if (dat.eof()) break;
		cout << "Matièni broj : " << slog.mat_br << endl;
		cout << "Prezime i ime : " << slog.prez_ime << endl;
		cout << "Godina upisa : " << slog.g_upisa << endl;
	};
	dat.close();dat.clear();
	return 1;
}
