#include "hibrid.h"
#include <ostream>

using namespace std;

Hibrid::Hibrid(char* r, int km, float zr, float pp, float zug, int epk) : Benzinac(r, km, zr, pp, zug) {
	elek_pogon_km = epk;
}

Hibrid::~Hibrid() {

}

void Hibrid::DodajKM(int d) {
	predjeni_km += d;
	zap_utrosenog_goriva += (predjeni_km - elek_pogon_km)* pros_potrosnja;
}

float Hibrid::MaxKM() const {
	return (zap_rezervoara / pros_potrosnja) + elek_pogon_km;
}

void Hibrid::ispisi(ostream& os) const {
	Benzinac::ispisi(os);

	os << "Duzina puta u km na elek pogon: " << elek_pogon_km << endl;
}