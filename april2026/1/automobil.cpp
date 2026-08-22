#include "automobil.h"
#include <ostream>

using namespace std;

Automobil::Automobil(char* r, int km) {
	predjeni_km = km;
	int duzina = 0,i = 0;
	while (r[duzina] != 0) {
		duzina++;
	}
	reg_oznaka = new char[duzina+1];
	while (i < duzina) {
		reg_oznaka[i] = r[i];
		i++;
	}
	reg_oznaka[duzina] = '\0';
}

Automobil::~Automobil() {
	delete []reg_oznaka;
}

void Automobil::ispisi(ostream& os) const {
	os << "Registarska oznaka: " << reg_oznaka << endl;
	os << "Broj predjenih km: " << predjeni_km << endl;
}

ostream& operator<<(ostream& os, const Automobil& a) {
	a.ispisi(os);
	return os;
}