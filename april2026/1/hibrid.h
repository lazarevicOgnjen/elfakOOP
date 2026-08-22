#pragma once
#include "benzinac.h"
#include <ostream>

using namespace std;

class Hibrid : public Benzinac {
private:
	int elek_pogon_km;

public:
	Hibrid(char* r, int km, float zr, float pp, float zug, int epk);
	~Hibrid();

	void DodajKM(int d) override;
	float MaxKM() const override;

	void ispisi(ostream& os) const override;
};