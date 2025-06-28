#include "Validator.h"

void Validator::valideaza(const Produs& p) {
	string erori = "";
	if(p.getId()<=0)
		erori+= "Id invalid!\n";
	if (p.getNume() == "")
		erori += "Numele este invalid!\n";
	if (p.getTip() == "")
		erori += "Tipul este invalid!\n";
	if (p.getPret() < 1.0 || p.getPret() > 100.0)
		erori += "Pret invalid!\n";
	if (!erori.empty())
		throw ValidationError(erori);
}