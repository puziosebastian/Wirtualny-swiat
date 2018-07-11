#include "Zolw.h"


Zolw::Zolw(Swiat& swiat, int x, int y) :
	Zwierze(swiat, x, y)
{
	this->sila = 2;
	this->inicjatywa = 1;
	this->symbol = 'Z';
}


Zolw::~Zolw() {
}

bool Zolw::specSpotkanie(Organizm* org) {
	if (org->pobierzSile() < 5) {
		return true;
	}
	return false;
}

bool Zolw::specAkcja() {
	if (rand() % 4 == 0) {
		return true;
	}
	return true;
}