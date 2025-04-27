#include <iostream>

#include "mvector.h"
#include "teste.h"
#include "repository.h"
#include "service.h"
#include "ui.h"

int main() {
	runAlltests();
	TestAllVector<mvector<Locatar>>();
	repository repo([](const TElem& loc) -> int { return loc.getApartament(); });
	service serv(repo);
	ui ui(serv, repo);
	ui.runApp();
}