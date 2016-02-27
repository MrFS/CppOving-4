#include <iostream>
#include <cstring>
#include <sstream>
#include <string>

#include <vector>


using namespace std;

struct Vare {
	int VareID;
	string name;
	int vareBeholdning;
	double varePris;
	int grense;
	int kapasitet = grense * 4;

	Vare() {}

	Vare(const string& name, double pris, int ID, int lagerGrense, int beholdning) :

		name(name),

		varePris(pris),

		grense(lagerGrense),

		vareBeholdning(beholdning),

		//kapasitet(lagerKapasitet),

		VareID(ID) { }


};

ostream& operator<<(ostream& out, const Vare& Vare) {
	
		int last4 = Vare.VareID % 10000;
	
		int exch = Vare.VareID / 10000; 
	
		cout << "ID: " << Vare.VareID << ", Navn: " << Vare.name << "\t"

			 << "Varebeholdning: " << Vare.vareBeholdning << "\t"
			 << "Pris pr. enhet: " << Vare.varePris << "\t"
			 << "Lagerkapasitet: " << Vare.kapasitet << "\n";
	
		return out;
	
}


int main() {

	vector<Vare> varer;
						//NAVN    | PRIS |ID |GRENSE |ANT PÅ LAGER
	varer.push_back(Vare("Eple"    , 15, 1337, 30, 23));
	varer.push_back(Vare("Banan"   , 22, 1339, 30, 10));
	varer.push_back(Vare("Appelsin", 20, 1338, 30, 50));
	

	char valg;

	cout << "VAREBEHOLDNING I BUTIKK \n";
	cout << "   <A> Se varebeholdning \n";
	cout << "   <B> Bestill Vare \n";
	cout << "   <C> Avslutt \n";
	cout << "--------------------------- \n";

	cin >> valg;

	toupper(valg);

	while (1){
		switch (valg) {
		case 'A':

			cout << " <A> VAREBEHOLDNING \n";

			for (size_t i = 0; i < varer.size(); i++) {
				cout << varer[i] << endl;
			}

			cin >> valg;


			break;
		case 'B':

			cout << " <B> BESTILL VARE \n";
			
			for each (Vare var in varer)
			{
				if (var.vareBeholdning < var.grense) {
					cout << "ID: " << var.VareID << "\t"
					     << "Navn: " << var.name << "\t"
						 << "Ant. Enheter: " << (var.kapasitet  - var.vareBeholdning) << "\t"
						 << "Pris pr. enhet: " << var.varePris << "\t"
						 << "Total Pris: " << var.varePris * (var.kapasitet - var.vareBeholdning) << "\n";

				}
				else
				{
					cout << "Vare " << var.name << " trenger ikke å bestilles." << "\t" 
						 << "Beholdning: " << var.vareBeholdning << endl;
				}
			}
			
			cin >> valg;

			break;
		case 'C':
			exit(0);
			break;
		}

		
	}

	cin.get();
	
	return 0;
}
