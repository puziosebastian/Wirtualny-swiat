#include "Czlowiek.h"
#include <conio.h>

Czlowiek::Czlowiek(Swiat& swiat, int x, int y) :
	Zwierze(swiat, x, y)
{
	this->czyZywy = 1;
	this->inicjatywa = 4;
	this->sila = 5;
	this->symbol = 'C';
}

Czlowiek::~Czlowiek() {
}

bool Czlowiek::jesliZywy() {
	if (this->czyZywy == 1) {
		return true;
	}

	else {
		return false;
	}
}

void Czlowiek::ruch(int prz) {
	int dx = 0, dy = 0;
	char ruch = _getch();

	if (_kbhit()) {
		ruch = _getch();
	}

	switch (ruch) {
	case 72:
	{
		dx = -1 * prz;
		break;
	}
	case 80:
	{
		dx = 1 * prz;
		break;
	}
	case 77:
	{
		dy = 1 * prz;
		break;
	}
	case 75:
	{
		dy = -1 * prz;
		break;
	}
	}
	if (swiat.jesliNaPlanszy(this->polozenie.x + dx, this->polozenie.y + dy))
	{
		swiat.poruszajSie(this->polozenie.x, this->polozenie.y, this->polozenie.x + dx, this->polozenie.y + dy);
	}
	return;
}