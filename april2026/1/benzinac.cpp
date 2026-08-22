#include "benzinac.h"
#include <ostream>

using namespace std;

Benzinac::Benzinac(char* r, int km, float zr, float pp, float zug) : Automobil(r, km) {
	zap_rezervoara = zr;
	pros_potrosnja = pp;
	zap_utrosenog_goriva = zug;
}

Benzinac::~Benzinac() {

}

void Benzinac::DodajKM(int d) {
	predjeni_km += d;
	zap_utrosenog_goriva += predjeni_km * pros_potrosnja;

}

float Benzinac::MaxKM() const {
	return zap_rezervoara / pros_potrosnja;
}

void Benzinac::ispisi(ostream& os) const {
	Automobil::ispisi(os);

	os << "Zapremina rezervoara: " << zap_rezervoara << endl;
	os << "Prosecna potrosnja: " << pros_potrosnja << endl;
	os << "Zapremina utrosenog goriva: " << zap_utrosenog_goriva << endl;
}