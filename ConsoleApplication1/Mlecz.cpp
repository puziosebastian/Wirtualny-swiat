#include "Mlecz.h"

Mlecz::Mlecz(Swiat& swiat, int x, int y) :
	Roslina(swiat, x, y)
{
	this->symbol = 'M';
}


Mlecz::~Mlecz() {
}

bool Mlecz::specAkcja() {
	this->mnozenie(this->polozenie.x, this->polozenie.y);
	this->mnozenie(this->polozenie.x, this->polozenie.y);
	this->mnozenie(this->polozenie.x, this->polozenie.y);
	return true;
}