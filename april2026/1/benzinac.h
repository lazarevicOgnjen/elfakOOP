#pragma once
#include "automobil.h"
#include <ostream>

using namespace std;

class Benzinac : public Automobil {
protected:
	float zap_rezervoara;
	float pros_potrosnja;
	float zap_utrosenog_goriva;

public:
	Benzinac(char* r, int km, float zr, float pp, float zug);
	~Benzinac();

	void DodajKM(int d) override;
	float MaxKM() const override;

	float GetZapreminaGoriva() const override {
		return zap_utrosenog_goriva;
	}

	void ispisi(ostream& os) const override;

};