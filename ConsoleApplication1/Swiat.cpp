#include <iostream>
#include <time.h>
#include <conio.h>

#include "Swiat.h"
#include "Organizm.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Czlowiek.h"
#include "Antylopa.h"
#include "Guarana.h"
#include "Jagoda.h"
#include "Lis.h"
#include "Mlecz.h"
#include "Owca.h"
#include "Trawa.h"
#include "Wilk.h"
#include "Zolw.h"

using namespace std;

Swiat::Swiat(int x, int y) {
	this->rozmiarSwiata.x = x;
	this->rozmiarSwiata.y = y;
	this->Organizmy = new Organizm*[x*y];

	for (int i = 0; i < x*y; i++) {
		this->Organizmy[i] = NULL;
	}
}

Swiat::~Swiat() {
	delete[] Organizmy;
}

void Swiat::menuStart() {
	cout << "Witaj w symulatorze wirtualnego swiata!\n\n";
	cout << "Wcisnij dowolny klawisz, aby rozpoczac gre.\n";

	char wybor = _getch();
	if (_kbhit()) {
		wybor = _getch();
	}

	switch (wybor) {
	case('A') :
	{
		this->zacznij();
		break;
	}
	default:
	{
		this->zacznij();
		break;
	}
	}

	system("cls");

	while (this->Postac->jesliZywy())
		this->nowyRuch();
	while (true)
		this->nowyRuch();
}

void Swiat::zacznij() {
	this->Postac = (Czlowiek*)this->ladujOrganizm(0, 0, 'C');
	int random, x, y;

	for (int i = 0; i < 15; i++) {
		random = rand() % 9;
		x = rand() % rozmiarSwiata.x;
		y = rand() % rozmiarSwiata.y;

		if (jesliWolne(x, y)) {
			switch (random) {
			case 0:
			{
				this->ladujOrganizm(x, y, 'A');
				break;
			}
			case 1:
			{
				this->ladujOrganizm(x, y, 'G');
				break;
			}
			case 2:
			{
				this->ladujOrganizm(x, y, 'J');
				break;
			}
			case 3:
			{
				this->ladujOrganizm(x, y, 'L');
				break;
			}
			case 4:
			{
				this->ladujOrganizm(x, y, 'M');
				break;
			}
			case 5:
			{
				this->ladujOrganizm(x, y, 'O');
				break;
			}
			case 6:
			{
				this->ladujOrganizm(x, y, 'T');
				break;
			}
			case 7:
			{
				this->ladujOrganizm(x, y, 'W');
				break;
			}
			case 8:
			{
				this->ladujOrganizm(x, y, 'Z');
				break;
			}
			default:
			{
				break;
			}
			}
		}
	}
	this->rysujSwiat();
}

void Swiat::rysujSwiat() {
	system("cls");
	cout << "Sebastian Puzio 160782\n";

	for (int i = 0; i <= this->rozmiarSwiata.y + 1; i++) {
		cout << "-";
	}
	cout << "\n|";

	for (int j = 0; j < this->rozmiarSwiata.x; j++) {
		for (int k = 0; k < this->rozmiarSwiata.y; k++) {
			if (this->Organizmy[j*(this->rozmiarSwiata.y) + k] == NULL) {
				cout << ".";
			}
			else {
				cout << this->Organizmy[j*(this->rozmiarSwiata.y) + k]->pobierzSymbol();
			}
		}
		cout << "|\n|";
	}
	for (int l = 0; l < this->rozmiarSwiata.y + 1; l++) {
		cout << "-";
	}
}

Organizm* Swiat::ladujOrganizm(int x, int y, char symbol) {

	if (jesliWolne(x, y)) {
		Organizm* poj = NULL;

		switch (symbol) {
		case 'A':
		{
			poj = new Antylopa(*this, x, y);
			break;
		}
		case 'C':
		{
			poj = new Czlowiek(*this, x, y);
			break;
		}
		case 'G':
		{
			poj = new Guarana(*this, x, y);
			break;
		}
		case 'J':
		{
			poj = new Jagoda(*this, x, y);
			break;
		}
		case 'L':
		{
			poj = new Lis(*this, x, y);
			break;
		}
		case 'M':
		{
			poj = new Mlecz(*this, x, y);
			break;
		}
		case 'O':
		{
			poj = new Owca(*this, x, y);
			break;
		}
		case 'T':
		{
			poj = new Trawa(*this, x, y);
			break;
		}
		case 'W':
		{
			poj = new Wilk(*this, x, y);
			break;
		}
		case 'Z':
		{
			poj = new Zolw(*this, x, y);
			break;
		}
		default:
		{
			break;
		}
		}

		this->Organizmy[x*(this->rozmiarSwiata.y) + y] = poj;
		this->inicOrgan[poj->pobierzInic()].push_back(poj);
		return poj;
	}

	else {
		return NULL;
	}
}

void Swiat::nowyRuch() {
	for (int init = 7; init >= 0; init--) {
		for (int wiek = inicOrgan[init].size() - 1; wiek >= 0; wiek--) {
			this->inicOrgan[init][wiek]->dzialanie();
		}
		for (int wiek = inicOrgan[init].size() - 1; wiek >= 0; wiek--) {
			this->inicOrgan[init][wiek]->zwiekszWiek();
		}
	}
	this->rysujSwiat();
}

void Swiat::poruszajSie(int zX, int zY, int doX, int doY) {
	int z = zX*(this->rozmiarSwiata.y) + zY;
	int doxy = doX*(this->rozmiarSwiata.y) + doY;

	if (this->Organizmy[doxy] == NULL) {
		this->zamianaZPustym(zX, zY, doX, doY);
		return;
	}

	else if (this->Organizmy[doxy]->pobierzSymbol() == this->Organizmy[z]->pobierzSymbol()) {
		this->Organizmy[z]->mnozenie(doX, doY);
	}

	else {
		if (this->Organizmy[z]->specSpotkanie(this->Organizmy[doxy])) {
			return;
		}

		else if (this->Organizmy[doxy]->specSpotkanie(this->Organizmy[z])) {
			return;
		}

		else if (this->Organizmy[z]->pobierzSile() >= this->Organizmy[doxy]->pobierzSile()) {
			this->usunOrganizm(*(this->Organizmy[doxy]));
		}
		else {
			this->usunOrganizm(*(this->Organizmy[z]));
		}
		this->zamianaZPustym(zX, zY, doX, doY);
	}
}

void Swiat::zamianaZPustym(int ad1X, int ad1Y, int ad2X, int ad2Y) {
	int adres1 = ad1X*(this->rozmiarSwiata.y) + ad1Y;
	int	adres2 = ad2X*(this->rozmiarSwiata.y) + ad2Y;

	if (this->Organizmy[adres1] != NULL) {
		this->Organizmy[adres1]->ustawPolozenieX(ad2X);
		this->Organizmy[adres1]->ustawPolozenieY(ad2Y);
	}
	if (this->Organizmy[adres2] != NULL) {
		this->Organizmy[adres2]->ustawPolozenieY(ad1Y);
		this->Organizmy[adres2]->ustawPolozenieX(ad1X);
	}
	swap(this->Organizmy[adres1], this->Organizmy[adres2]);
	return;
}

void Swiat::usunOrganizm(Organizm& organizm) {
	int inicjatywa = organizm.pobierzInic();
	for (vector <Organizm*>::iterator i = this->inicOrgan[inicjatywa].begin(); i < this->inicOrgan[inicjatywa].end(); i++) {
		if (*i == &organizm) {
			this->inicOrgan[inicjatywa].erase(i);
			break;
		}
	}
	this->Organizmy[organizm.pobierzPolozenieX()*(this->rozmiarSwiata.y) + organizm.pobierzPolozenieY()] = NULL;
	delete &organizm;
}

bool Swiat::jesliWolne(int x, int y) { 
	if (this->jesliNaPlanszy(x, y)) {
		if (this->Organizmy[x*(this->rozmiarSwiata.y) + y] == NULL) {
			return true;
		}
		else {
			return false;
		}
	}
	else {
		return false;
	}
	
}

bool Swiat::jesliNaPlanszy(int x, int y) {
	if ((x < this->rozmiarSwiata.x) && (x >= 0) && (y >= 0) && (y < this->rozmiarSwiata.y)) {
		return true;
	}
	else {
		return false;
	}
}