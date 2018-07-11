#include "Roslina.h"

Roslina::Roslina(Swiat& swiat, int x, int y) :
	Organizm(swiat, x, y)
{
	this->inicjatywa = 0;
	this->sila = 0;
}

Roslina::~Roslina() {
}

void Roslina::mnozenie(int toX, int toY) {
	int random = rand() % 15;
	if (random == 0) {
		for (int y = -1; y < 2; y++) {
			for (int x = -1; x < 2; x++) {
				if ((swiat.jesliWolne(toX + x, toY + y)) && swiat.jesliNaPlanszy(toX + x, toY + y)) {
					swiat.ladujOrganizm(toX + x, toY + y, this->symbol);
					return;
				}
			}
		}
		return;
	}
}

void Roslina::dzialanie() {
	if (specAkcja()) {
		return;
	}
	else {
		this->mnozenie(this->polozenie.x, this->polozenie.y);
	}
}