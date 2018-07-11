#pragma once

#include "Swiat.h"

class Organizm {
public:

	Organizm(Swiat&, int, int);
	~Organizm();

	char pobierzSymbol();
	int pobierzInic();
	int pobierzWiek();
	int pobierzSile();
	int pobierzPolozenieX();
	int pobierzPolozenieY();

	void zwiekszWiek();
	void ustawSile(int);
	void ustawPolozenieX(int);
	void ustawPolozenieY(int);

	virtual void mnozenie(int x, int y) = 0;
	virtual void dzialanie() = 0;
	virtual bool specSpotkanie(Organizm*) {
		return false;
	}
	virtual bool specAkcja() {
		return false;
	}

protected:

	Swiat& swiat;

	char symbol;
	int inicjatywa;
	int wiek;
	int sila;

	struct Polozenie
	{
		int x;
		int y;
	} polozenie;

};
