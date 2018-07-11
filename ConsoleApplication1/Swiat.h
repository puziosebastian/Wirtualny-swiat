#pragma once
#include <vector>

class Organizm;
class Czlowiek;

using namespace std;

class Swiat {
public:

	Swiat(int, int);
	~Swiat();

	void menuStart();
	void zacznij();
	void rysujSwiat();
	Organizm* ladujOrganizm(int x, int y, char symbol);
	void nowyRuch();
	void poruszajSie(int zX, int zY, int doX, int doY);
	void Swiat::zamianaZPustym(int ad1X, int ad1Y, int ad2X, int ad2Y);
	void usunOrganizm(Organizm&);
	bool jesliWolne(int x, int y);
	bool jesliNaPlanszy(int x, int y);

private:

	Czlowiek* Postac;
	Organizm** Organizmy;

	struct RozmiarSwiata
	{
		int x;
		int y;
	} rozmiarSwiata;

	vector <Organizm*> inicOrgan[8];
};
