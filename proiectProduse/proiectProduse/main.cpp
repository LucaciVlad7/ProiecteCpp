#include "proiectProduse.h"
#include <QtWidgets/QApplication>
#include "Teste.h"
#include "Service.h"
#include "Repo.h"
#include "Validator.h"
#include "GUI.h"

int main(int argc, char *argv[])
{
    Teste test = Teste();
    test.testAll();
    QApplication a(argc, argv);
    Repo repo = Repo("teste.txt");
    Validator val = Validator();
    Service serv = Service(repo, val);
    GUI gui = GUI(serv);
    gui.show();
    return a.exec();
}
