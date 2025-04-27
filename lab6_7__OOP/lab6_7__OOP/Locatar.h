#pragma once
#include <string>

using std::string;

class Locatar {
private:
	unsigned int apartament, suprafata;
	string proprietar, tip;

public:
	//Constructor default
	Locatar() : apartament{ 0 }, proprietar{ "" }, suprafata{0}, tip{""} {

	}

	//Constructor pt initializare
	Locatar(unsigned int apartament, string& proprietar, unsigned int suprafata, string& tip);

	//suprascriere "="
	Locatar& operator=(const Locatar& other) {
		if (this != &other) {
			apartament = other.apartament;
			proprietar = other.proprietar;
			suprafata = other.suprafata;
			tip = other.tip;
		}
		return *this;
	}

	//getters
	unsigned int getApartament() const;
	unsigned int getSuprafata() const;
	string getProprietar() const;
	string getTip() const;

	//setters
	void setApartament(const unsigned int apartament);
	void setSuprafata(const unsigned int suprafata);
	void setProprietar(const string& proprietar);
	void setTip(const string& tip);

	//suprascriere "=="
	bool operator==(const Locatar& other) const {
		return this->apartament == other.apartament && 
			this->suprafata == other.suprafata && 
			this->proprietar == other.proprietar && 
			this->tip == other.tip;
	}

	//destructor
	~Locatar() = default;
};