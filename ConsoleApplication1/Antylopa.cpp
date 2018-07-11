#include "Antylopa.h"

Antylopa::Antylopa(Swiat& swiat, int x, int y) :
	Zwierze(swiat, x, y)
{
	this->sila = 4;
	this->inicjatywa = 4;
	this->symbol = 'A';
}

Antylopa::~Antylopa() {
}

bool Antylopa::specSpotkanie(Organizm* org) {
	int random = rand() % 2;
	if (random == 0)
	{
		for (int x = -1; x < 2; x++)
		{
			for (int y = -1; y < 2; y++)
			{
				if (swiat.jesliWolne(x, y))
				{
					swiat.zamianaZPustym(this->polozenie.x, this->polozenie.y, this->polozenie.x + x, this->polozenie.y + y);
				}
			}
		}
		return true;
	}
	return false;
}

bool Antylopa::specAkcja() {
	this->ruch(2);
	return true;
}