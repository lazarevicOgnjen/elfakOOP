#pragma once
#include "automobil.h"
#include <ostream>

using namespace std;

class Prevoznik {
private:
	int ukupan_kapacitet, trenutno;
	Automobil** flota;

public:
	Prevoznik(int u);
	~Prevoznik();

	void Dodaj(Automobil* a);
	void IzbaciPoKm(int kilometraza);
	void ObavljenaVoznja(char* rg, int duzina);
	int UkupnaKilometraza() const;
	Automobil* NajpovoljnijiAutomobil(int d);
	void VratiNajDuzinuGorivo(Automobil** NajKM, Automobil** NajGorivo);

	bool Uporedi(const char* reg1, const char* reg2);

	void ispisi(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Prevoznik& p);
};