#include "teste.h"
#include "locatar.h"
#include "Repository.h"
#include "filerepository.h"
#include "service.h"
#include "serviceLista.h"
#include "consola.h"


int main() {
	Teste::testAll();
	FileRepository<Locatar> repofile{ "file.txt" };
	Service service{ repofile };
	ServiceLista serviceLista{ repofile };
	Consola consola{ repofile,service,serviceLista };
	consola.runConsola();
	return 0;
}