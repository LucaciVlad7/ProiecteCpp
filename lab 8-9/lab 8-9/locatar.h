#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <string>

using std::string;
using std::move;

class Locatar {
private:
	string proprietar, tip;
	unsigned int apartament, suprafata;
public:
	Locatar(const unsigned int apartamentX, string proprietarX,const unsigned int suprafataX, string tipX):
		apartament{move(apartamentX)},proprietar{move(proprietarX)},suprafata{move(suprafataX)},tip{move(tipX)}{ }

	Locatar(const Locatar& locatarX):
		apartament{locatarX.getApartament()},proprietar{locatarX.getProprietar()},suprafata{locatarX.getSuprafata()},tip{locatarX.getTip()}{ }

	Locatar& operator=(const Locatar& locatarX) = default;

	bool operator==(const Locatar& other) const {
		return apartament == other.apartament &&
			proprietar == other.proprietar &&
			suprafata == other.suprafata &&
			tip == other.tip;
	}

	//getters
	[[nodiscard]] unsigned int getApartament() const;
	[[nodiscard]] unsigned int getSuprafata() const;
	[[nodiscard]] string getProprietar() const;
	[[nodiscard]] string getTip() const;

	//setters
	void setApartament(const unsigned int apartament);
	void setSuprafata(const unsigned int suprafata);
	void setProprietar(const string& proprietar);
	void setTip(const string& tip);

	static Locatar lineToTElem(const string& line);

	static string TElemToLine(const Locatar& locatarX);

	~Locatar();
};