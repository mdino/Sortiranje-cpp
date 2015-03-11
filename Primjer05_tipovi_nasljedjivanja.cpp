//Tipovi nasljeðivanja
#include <iostream>
using namespace std;
class cosnovna{
public:
	void fpub(){
		cout << "Javna metoda!" << endl;
	};
private:
	void fpriv(){
		cout << "Privatna metoda!" << endl;
	};
protected:
	void fprot(){
		cout << "Zasticena metoda!" << endl;
	};
};//cosnovna

class cpublic : public cosnovna{};

class cipublic : public cpublic{
public:
	void fcpublic(){
		cout << "Poziv naslijedjenih metoda kod javnog nasljedjivanja:"<<endl;
		fpub();
		// fpriv(); // Ovo, naravno, nije moguæe jer se radi o privatnom èlanu!
		fprot();
	};
};
class cprivate : private cosnovna{};

class ciprivate : private cprivate{
public:
	void fcprivate(){
		cout << "Kod privatnog nasljedjivanja nista nije ostalo 'unucima'!" << endl;
		// fpub(); fpriv(); fprot();
	};
};

class cprotected : protected cosnovna{};

class ciprotected : protected cprotected{
public:
	void fcprotected(){
		cout << "Zasticeno nasljedjivanje, kod poziva " << endl;
		cout << "iz izvedene klase nema razlike u " << endl;
		cout << "odnosu na javno nasljedjivanje..." << endl;
		fpub(); 
		//fpriv();
		fprot();
	};
};
cipublic javni; ciprivate privatni; ciprotected zasticeni;

int main(){
	javni.fcpublic();
	privatni.fcprivate();
	zasticeni.fcprotected();
	cout << "Ali kod poziva iz ostalih dijelova programa ima!" << endl;
	javni.fpub();
	//zasticeni.fpub();
	return 1;
}
