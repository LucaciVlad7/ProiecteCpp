#include "validator.h"

string validator::validatorLocatar(const Locatar& locatar) {
	string erori = "";
	if (locatar.getApartament() <= 0)
		erori += "Numarul apartamentului invalid\n";
	if (locatar.getProprietar().empty())
		erori += "Numele proprietarului nu poate fi vid\n";
	if (locatar.getSuprafata() <= 0)
		erori += "Suprafata trebuie sa fie numar pozitiv\n";
	if(locatar.getTip().empty())
		erori+= "Tipul nu poate fi vid\n";
	return erori;
}