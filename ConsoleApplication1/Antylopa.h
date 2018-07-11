#pragma once

#include "Zwierze.h"

class Antylopa :
	public Zwierze
{

public:
	Antylopa(Swiat& swiat, int x, int y);
	~Antylopa();

	bool specSpotkanie(Organizm*);
	bool specAkcja();
};
