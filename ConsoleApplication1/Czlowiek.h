#pragma once

#include "Zwierze.h"

class Czlowiek :
	public Zwierze
{

public:

	Czlowiek(Swiat& swiat, int x, int y);
	~Czlowiek();

	bool jesliZywy();
	void ruch(int);

private:

	bool czyZywy;
};
