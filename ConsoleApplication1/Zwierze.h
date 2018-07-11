#pragma once

#include "Organizm.h"

class Zwierze :
	public Organizm
{

public:

	Zwierze(Swiat&, int, int);
	~Zwierze();

	void mnozenie(int toX, int toY);
	void dzialanie();

protected:

	virtual void ruch(int prz = 1);
};
