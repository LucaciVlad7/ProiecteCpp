#include "Locatar.h"

Locatar::Locatar(unsigned int apartament, string& proprietar, unsigned int suprafata, string& tip) {
	this->apartament = apartament;
	this->proprietar = proprietar;
	this->suprafata = suprafata;
	this->tip = tip;
}

unsigned int Locatar::getApartament() const {
	return this->apartament;
}

unsigned int Locatar::getSuprafata() const {
	return this->suprafata;
}

string Locatar::getProprietar() const {
	return this->proprietar;
}

string Locatar::getTip() const {
	return this->tip;
}

void Locatar::setApartament(const unsigned int apartament) {
	this->apartament = apartament;
}

void Locatar::setSuprafata(const unsigned int suprafata) {
	this->suprafata = suprafata;
}

void Locatar::setProprietar(const string& proprietar) {
	this->proprietar = proprietar;
}

void Locatar::setTip(const string& tip) {
	this->tip = tip;
}

