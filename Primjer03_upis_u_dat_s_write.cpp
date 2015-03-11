//Èitanje datoteke s fiksnom velièinom sloga pomoæu metode read
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
	char jos='d';
	fstream dat ("podaci.dat",ios::out | ios::binary);
	while ((jos=='d')||(jos=='D')){
		cout << "Maticni broj: "; cin >> slog.mat_br;
		cout << "Prezime i ime : "; cin >> slog.prez_ime;
		cout << "Godina upisa : "; cin >> slog.g_upisa;
		dat.write ((char *) &slog,sizeof(slog));
		cout <<"Hocete li jos upisivati (d/n) ? ";
		cin >> jos;
	};
	dat.close();dat.clear();
	return 1;
}
