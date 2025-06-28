#include "QtWidgetsApplication1.h"
#include <QtWidgets/QApplication>
#include "FileRepository.h"
#include "teste.h"
#include "service.h"
#include "serviceLista.h"
#include "InterfataQT.h"

int main(int argc, char *argv[])
{
    Teste::testAll();
    QApplication a(argc, argv);
    FileRepository<Locatar> repoLocatar{ "lab10-11.txt" };
    ServiceLista serviceLista{ repoLocatar };
    Service service{ repoLocatar };
    InterfataQT qtgui{repoLocatar,service,serviceLista};
    qtgui.runInterfataQT();
    return a.exec();
}
