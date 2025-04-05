#pragma once
#include <string>
#include <vector>
#include "produse.h"

using std::vector;
using std::string;
using std::ostream;

class ValidateException {
	vector<string> errors;
public:
	ValidateException(const vector<string>& errors) : errors{ errors } {}

	friend ostream& operator<<(ostream& out, const ValidateException& ex);
};

ostream& operator<<(ostream& out, const ValidateException& ex);

class ProduseValidator {
public:
	void validate(const Produs& p);
};
