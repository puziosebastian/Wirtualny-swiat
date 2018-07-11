#include "Jagoda.h"

Jagoda::Jagoda(Swiat& swiat, int x, int y) :
	Roslina(swiat, x, y)
{
	this->sila = 99;
	this->symbol = 'J';
}

Jagoda::~Jagoda() {
}

bool Jagoda::specSpotkanie(Organizm* org) {
	swiat.usunOrganizm(*org);
	return true;
}