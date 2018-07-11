#pragma once

#include "Organizm.h"

class Roslina :
	public Organizm
{
public:

	Roslina(Swiat& swiat, int x, int y);
	~Roslina();

	void mnozenie(int x, int y);
	void dzialanie();
};
