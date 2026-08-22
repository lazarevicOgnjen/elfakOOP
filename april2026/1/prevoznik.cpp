#include "prevoznik.h"
#include <ostream>

using namespace std;

Prevoznik::Prevoznik(int u) {
	ukupan_kapacitet = u;
	trenutno = 0;
	flota = new Automobil * [ukupan_kapacitet];
}

Prevoznik::~Prevoznik() {
	for (int i = 0; i < trenutno; i++) {
		delete flota[i];
	}
	delete[]flota;
}

void Prevoznik::Dodaj(Automobil* a) {
	if (trenutno < ukupan_kapacitet) {
		flota[trenutno] = a;
		trenutno++;
	}
}

void Prevoznik::IzbaciPoKm(int kilometraza) {
	for (int i = 0; i < trenutno; i++) {
		if (flota[i]->GetPredjeniKM() > kilometraza) { // ako ima
			delete flota[i]; // ocisti mesto
			int k = i; // vidi gde se trenutno nalazimo
			for (int j = k+1; j < trenutno; j++) { // pomeri sve za jedno mesto ulevo
				flota[k] = flota[j];
				k++;
			}
			trenutno--; // sada imamo jedan auto manje
			i--;
		}
	}
}

bool Prevoznik::Uporedi(const char* reg1, const char* reg2) {
	int i = 0;
	while (reg1[i] != '\0' && reg2[i] != '\0') {

		if (reg1[i] != reg2[i]) {
			break;
		}

		i++;
	}

	return reg1[i] == '\0' && reg2[i] == '\0';
}

void Prevoznik::ObavljenaVoznja(char* rg, int duzina) {
	for (int i = 0; i < trenutno; i++) {
		if (Uporedi(flota[i]->GetReg(), rg)) {
			flota[i]->DodajKM(duzina);
		}
	}
}

int Prevoznik::UkupnaKilometraza() const {
	int ukupna_predjena_km = 0;
	for (int i = 0; i < trenutno; i++) {
		ukupna_predjena_km += flota[i]->GetPredjeniKM();
	}
	return ukupna_predjena_km;
}

Automobil* Prevoznik::NajpovoljnijiAutomobil(int d) {
	float x = 0, najboljeX = 0;
	Automobil* najpovoljniji = flota[0];
	for (int i = 1; i < trenutno; i++) {
		x = flota[i]->MaxKM() - d;
		if (x == 0) {
			najpovoljniji = flota[i];
			break;
		}
		else if (x > 0) {
			if (x < najboljeX || najboljeX < 0) {
				najboljeX = x;
				najpovoljniji = flota[i];
			}
		}
	}
	return najpovoljniji;
}

void Prevoznik::VratiNajDuzinuGorivo(Automobil** NajKM, Automobil** NajGorivo) {
	*NajKM = flota[0];
	*NajGorivo = flota[0];
	for (int i = 1; i < trenutno; i++) {
		if ((*NajKM)->GetPredjeniKM() > flota[i]->GetPredjeniKM()) {
			*NajKM = flota[i];
		}
		if ((*NajGorivo)->GetZapreminaGoriva() > flota[i]->GetZapreminaGoriva()) {
			*NajGorivo = flota[i];
		}
	}
}

void Prevoznik::ispisi(ostream& os) const {
	os << "Kapacitet: " << ukupan_kapacitet << endl;
	os << "Trenutan broj vozila: " << trenutno << endl;
	for (int i = 0; i < trenutno; i++) {
		os << "Automobil " << i + 1 << ": " << endl;
		os << *flota[i] << endl;
	}
}

ostream& operator<<(ostream& os, const Prevoznik& p) {
	p.ispisi(os);
	return os;
}