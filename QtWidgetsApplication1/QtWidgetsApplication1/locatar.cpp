#include "locatar.h"
#include <vector>
#include <string>
#include <sstream>  

using std::vector;
using std::string;
using std::to_string;

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

Locatar Locatar::lineToTElem(const string& line) {
	vector<string> params;
	size_t pos, prevPos = 0;
	while ((pos = line.find(',', prevPos)) != string::npos) {
		params.push_back(line.substr(prevPos, pos - prevPos));
		prevPos = pos + 1;
	}
	params.push_back(line.substr(prevPos));
	return Locatar(std::stoi(params[1]), params[2], std::stoi(params[3]), params[4]);
}

string Locatar::TElemToLine(const Locatar& locatarX) {
	return to_string(locatarX.getApartament()) + "," + locatarX.getProprietar() + "," +
		to_string(locatarX.getSuprafata()) + "," + locatarX.getTip();
}

Locatar::~Locatar() {

}