//Èitanje tekstualne datoteke
#include <iostream>
#include <fstream>
using namespace std;
int main(){
	char red[80];
	fstream dat;
	dat.open("tekst.txt",ios::in);
	while(1){
	   dat.getline (red,sizeof(red),'\n');	// èitanje reda iz datoteke
	   if (dat.eof()) break;
	   cout << red << endl;
	};
	dat.close();dat.clear();
  return 1;
}
