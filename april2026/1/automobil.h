#pragma once
#include <ostream>

using namespace std;

class Automobil {
protected:
	char* reg_oznaka;
	int predjeni_km;

public:
	Automobil(char* r, int km);
	virtual ~Automobil();

	int GetPredjeniKM() const {
		return predjeni_km;
	}

	const char* GetReg() const {
		return reg_oznaka;
	}

	virtual void DodajKM(int d) = 0;
	virtual float MaxKM() const = 0;
	virtual float GetZapreminaGoriva() const = 0;

	virtual void ispisi(ostream& os) const;
	friend ostream& operator<<(ostream& os, const Automobil& a);
};