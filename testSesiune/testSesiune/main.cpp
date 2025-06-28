#include "testSesiune.h"
#include <QtWidgets/QApplication>
#include "Teste.h"
#include "Service.h"
#include "Repo.h"
#include "GUI.h"
/*
tabel sortat dupa rank cu toate atributele si melodii cu acelasi rank
modif rank
delete
desen
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Teste test = Teste();
    test.testeAll();
    Repo repo = Repo("melodii.txt");
    Service serv(repo);
    GUI gui(serv);
    gui.show();
    testSesiune w;
    return a.exec();
}