#include "Organizm.h"

Organizm::Organizm(Swiat& swiat, int x, int y) :
	swiat(swiat)
{
	this->polozenie.x = x;
	this->polozenie.y = y;
	this->wiek = 0;
}

Organizm::~Organizm() {
}

char Organizm::pobierzSymbol() {
	return this->symbol;
}

int Organizm::pobierzInic() {
	return this->inicjatywa;
}

int Organizm::pobierzWiek() {
	return this->wiek;
}

int Organizm::pobierzSile() {
	return this->sila;
}

int Organizm::pobierzPolozenieX() {
	return this->polozenie.x;
}

int Organizm::pobierzPolozenieY() {
	return this->polozenie.y;
}

void Organizm::zwiekszWiek() {
	this->wiek++;
}

void Organizm::ustawSile(int sila1) {
	this->sila = sila1;
	return;
}

void Organizm::ustawPolozenieX(int x) {
	this->polozenie.x = x;
	return;
}

void Organizm::ustawPolozenieY(int y) {
	this->polozenie.y = y;
	return;
}