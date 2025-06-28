#pragma once
#include <QTWidgets>
#include "AbstractRepo.h"
#include "service.h"
#include "serviceLista.h"

class InterfataQT : public QWidget{
private:
	AbstractRepo<Locatar>& repo;
	Service& service;
	ServiceLista& serviceLista;

    QWidget* window1;
    QVBoxLayout* mainLayout;
    QHBoxLayout* hbxLayout1, * hbxLayout2;;
    QVBoxLayout* vbxLayout1, * vbxLayout2, * vbxLayout3, * vbxLayout4;
    QLabel* lblTitluColumn1, * lblitluColumn2, * lblTitluColumn3, * lblApLoc, * lblPropLoc, * lblSupLoc, * lblTipLoc;
    QLabel* lblTitluExports;

    QListWidget* lstLoc, * lstLista, * lstTipuri, * lstExports;
    QTableWidget* tblLista;

    QPushButton* btnAdaugaLoc, * btnModificaLoc, * btnStergeLoc, * btnCautaLoc;
    //aici ai ramas
    QPushButton* btnFiltrareTip, * btnFiltrareSuprafata, * btnSortare, * btnUndo, * btnResetListaLocatari;
    QPushButton* btnAdaugaLista, * btnGenereazaLista, * btnGolesteLista, * btnExportaLista;

    QLabel* lbltxtApartamentLocatar, * lbltxtProprietarLocatar, * lbltxtSuprafataLocatar, * lbltxtTipLocatar;

    QFormLayout* frmLocatar;

    QGridLayout* gridLayout1, * gridLayout2;

    QFont font1, font2;

public:
    InterfataQT(AbstractRepo<Locatar>& repoX, Service& serviceX, ServiceLista& serviceListaX):
        repo{repoX},service{serviceX},serviceLista{serviceListaX}{ }

    void runInterfataQT();

    void setUpInterfataQT();
    void connectInterfataQT();
    //void onLocatarSelected();

    void reloadOferte();

    void reloadLocatarFiltrate(vector<Locatar> allLocatari);

    void reloadLista();

    void reloadListaTable();

    void reloadTipuri();

    void reloadExports();

};

