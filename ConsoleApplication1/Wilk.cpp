#include "Wilk.h"

Wilk::Wilk(Swiat& swiat, int x, int y) :
	Zwierze(swiat, x, y)
{
	this->sila = 9;
	this->inicjatywa = 5;
	this->symbol = 'W';
}

Wilk::~Wilk() {
}