// Predložak za rad sa sekvencijalnim datotekama
#include <iostream>
#include <fstream>
using namespace std;
struct tstudent{	// tip zapisa koje sadrži datoteka
	int mat_br;
	char prez_ime[35];
	int g_stu;
};
tstudent student; // varijabla èiji se upisuje/èita u/iz datoteke
fstream dat; // datoteèni objekt
char naziv_datoteke[40]; // fizièko ime datoteke

void unos(char *znakovni_niz)
{
	cin.getline(znakovni_niz, 150);
	if (cin.gcount()==1)
	  	 cin.getline (znakovni_niz,150);
};

void kreiranje_datoteke(){
	cout << "Unesite naziv datoteke u koju cete spremati podatke:";
	cin >> naziv_datoteke;
	dat.open(naziv_datoteke,ios::in | ios::binary);
	if (!dat){	// ako datoteka ne postoji na disku
		dat.open(naziv_datoteke,ios::out | ios::binary); // kreiranje datoteke
		dat.close();dat.clear();
	}
	else{
		cout << "Datoteka " << naziv_datoteke << " vec postoji na disku."<<endl;
		dat.close();dat.clear();}
};

void unos_podataka_u_datoteku(){
	char dalje;
	dat.open(naziv_datoteke,ios::out | ios::ate | ios::in| ios::binary);
	do{
		cout << "Maticni broj:";
		cin >> student.mat_br;
		cout << "Prezime i ime:";
		unos (student.prez_ime); // zbog problema s razmakom
		cout << "Godina studija:";
		cin >> student.g_stu;
		dat.write((char *) &student,sizeof(student));
		cout << "Dalje? (d/n)";
		cin >> dalje;
	} while (dalje=='d');
	dat.close();dat.clear();
};

void ispis_podataka_o_svim_studentima(){
	dat.open(naziv_datoteke,ios::in | ios::binary);
	while (1){
		dat.read((char *) &student,sizeof(student));
		if (dat.eof()) break;
		cout << "Maticni broj: " << student.mat_br << endl;
		cout << "Prezime i ime: " << student.prez_ime << endl;
		cout << "Godina studija: " << student.g_stu << endl;
	}
	dat.close();dat.clear();
};

void ispis_podataka_o_zadanom_studentu(int mb){
	int brojac=0;
	dat.open(naziv_datoteke,ios::in | ios::binary);
	while (1){
		dat.read((char *) &student,sizeof(student));
		if (dat.eof()) break;
		if (student.mat_br==mb){
			cout << "Maticni broj: " << student.mat_br << endl;
			cout << "Prezime i ime: " << student.prez_ime << endl;
			cout << "Godina studija: " << student.g_stu << endl;
			brojac++;
		}
	}
	if (brojac==0)
		cout << "Student s maticnim brojem " << mb << " nije nadjen u datoteci."<<endl;
	dat.close();dat.clear();
};

int main(){
int izbor,mbr;
do{ cout <<"Izaberite :" <<endl<<endl;
	cout <<"1. Kreiranje datoteke"<<endl;
	cout <<"2. Unos podataka u datoteku"<<endl;
	cout <<"3. Ispis svih zapisa iz datoteke"<<endl;
	cout <<"4. Ispis podataka o zadanom studentu"<<endl;
	cout <<"9. Izlaz iz programa"<<endl;
	cin >> izbor;
	switch (izbor){
		case 1:kreiranje_datoteke();break;
		case 2:unos_podataka_u_datoteku();break;
		case 3:ispis_podataka_o_svim_studentima();break;
		case 4:cout << "Maticni broj studenta:"; cin >> mbr;
		            ispis_podataka_o_zadanom_studentu(mbr); break;
  }
 } while (izbor != 9);
return 1;
}
