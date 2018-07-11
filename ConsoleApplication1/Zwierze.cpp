#include "Zwierze.h"

Zwierze::Zwierze(Swiat& swiat, int x, int y) :
	Organizm(swiat, x, y)
{
}

Zwierze::~Zwierze() {
}

void Zwierze::mnozenie(int toX, int toY) {
	for (int x = -1; x < 2; x++) {
		for (int y = -1; y < 2; y++) {
			if ((swiat.jesliWolne(toX + x, toY + y))&& swiat.jesliNaPlanszy(toX + x, toY + y)) {
				swiat.ladujOrganizm(toX + x, toY + y, this->symbol);
				return;
			}
		}
	}
}

void Zwierze::dzialanie() {
	if (specAkcja()) {
		return;
	}
	this->ruch();
}

void Zwierze::ruch(int prz) {
	int dx, dy;
	do {
		dx = rand() % 3 - 1;
		dy = rand() % 3 - 1;
	} while (!swiat.jesliWolne(this->polozenie.x + dx, this->polozenie.y + dy) || (dy == 0 && dx == 0));
	swiat.poruszajSie(this->polozenie.x, this->polozenie.y, this->polozenie.x + dx, this->polozenie.y + dy);
	return;
}