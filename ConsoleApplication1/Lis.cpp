#include "Lis.h"

Lis::Lis(Swiat& swiat, int x, int y) :
	Zwierze(swiat, x, y)
{
	this->sila = 3;
	this->inicjatywa = 7;
	this->symbol = 'L';
}

Lis::~Lis() {
}
