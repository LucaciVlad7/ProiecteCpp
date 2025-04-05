#include "validator.h"
#include <assert.h>
#include <sstream>

void ProduseValidator::validate(const Produs& p) {
	vector<string> errors;
	if (p.getId() < 0) {
		errors.push_back("Id invalid\n");
	}
	if (p.getTip().size() == 0) {
		errors.push_back("Tip invalid\n");
	}
	if (p.getProducator().size() == 0) {
		errors.push_back("Producator invalid\n");
	}
	if (p.getModel().size() == 0) {
		errors.push_back("Model invalid\n");
	}
	if (p.getPret() < 0) {
		errors.push_back("Pret invalid\n");
	}
	if (p.getCantitate() < 0) {
		errors.push_back("Cantitate invalida\n");
	}
	if (errors.size() > 0) {
		throw ValidateException(errors);
	}
}

ostream& operator<<(ostream& out, const ValidateException& ex) {
	for (const string& error : ex.errors) {
		out << error;
	}
	return out;
}