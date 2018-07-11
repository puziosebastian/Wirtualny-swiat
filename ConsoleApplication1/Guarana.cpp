#include "Guarana.h"

Guarana::Guarana(Swiat& swiat, int x, int y) :
	Roslina(swiat, x, y)
{
	this->symbol = 'G';
}

Guarana::~Guarana() {
}

bool Guarana::specSpotkanie(Organizm* org) {
	org->ustawSile(org->pobierzSile() + 3);
	swiat.usunOrganizm(*this);
	return true;
}