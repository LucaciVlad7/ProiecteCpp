#include <iostream>
#include "teste.h"
#include "consola.h"
#include "produseService.h"
#include "produseRepo.h"

int main() {
	test_all();
	ProduseRepo repo;
	ProduseValidator validator;
	ProduseService service{ repo, validator };
	Consola consola(service); 
	consola.start_aplicatie();
	return 0;
}