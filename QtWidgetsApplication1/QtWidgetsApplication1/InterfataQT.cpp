#include "InterfataQT.h"

void InterfataQT::setUpInterfataQT() {
    window1 = new QWidget();
    mainLayout = new QVBoxLayout();
    hbxLayout1 = new QHBoxLayout();
    hbxLayout2 = new QHBoxLayout();
    vbxLayout1 = new QVBoxLayout();
    vbxLayout2 = new QVBoxLayout();
    vbxLayout3 = new QVBoxLayout();
    vbxLayout4 = new QVBoxLayout();
    lblTitluColumn1 = new QLabel();
    lblitluColumn2 = new QLabel();
    lblTitluColumn3 = new QLabel();
    lblTitluExports = new QLabel("Fisiere Exportate");
    lblApLoc = new QLabel("Apartamentul: ");
    lblPropLoc= new QLabel("Proprietarul: ");
    lblSupLoc= new QLabel("Suprafata: ");
    lblTipLoc = new QLabel("Tip; ");
    lstExports = new QListWidget();
    lstLoc = new QListWidget();
    lstLista= new QListWidget();
    lstTipuri= new QListWidget();

    btnAdaugaLoc = new QPushButton("Adauga Locatar");
    btnModificaLoc = new QPushButton("Modifica Locatar");
    btnStergeLoc = new QPushButton("Sterge Locatar");
    btnCautaLoc = new QPushButton("Cauta Locatar");
    btnFiltrareTip = new QPushButton("Filtrare tip");
    btnFiltrareSuprafata = new QPushButton("Filtrare suprafata");
    btnSortare = new QPushButton("Sortare");
    btnUndo = new QPushButton("Undo");
    btnAdaugaLista = new QPushButton("Adauga in Lista");
    btnGenereazaLista = new QPushButton("Genereaza Lista");
    btnGolesteLista = new QPushButton("Goleste Lista");
    btnExportaLista = new QPushButton("Exporta Lista");
    btnResetListaLocatari = new QPushButton("Reseteaza Lista Locatar");

    lbltxtApartamentLocatar = new QLabel();
    lbltxtProprietarLocatar = new QLabel();
    lbltxtSuprafataLocatar = new QLabel();
    lbltxtTipLocatar = new QLabel();
    frmLocatar = new QFormLayout();
    gridLayout1 = new QGridLayout();
    gridLayout2 = new QGridLayout();
    tblLista = new QTableWidget();

    window1->setLayout(mainLayout);
    window1->setWindowTitle("Gestiune Locatari");
    mainLayout->addLayout(hbxLayout1);
    mainLayout->addLayout(hbxLayout2);

    hbxLayout2->addLayout(vbxLayout1);
    lblTitluColumn1->setText("Locatar");
    vbxLayout1->addWidget(lblTitluColumn1);
    lblTitluColumn1->setAlignment(Qt::AlignCenter);

    vbxLayout1->addWidget(lstLoc);

    vbxLayout1->addLayout(gridLayout1);

    gridLayout1->addWidget(btnAdaugaLoc, 0, 0);
    gridLayout1->addWidget(btnModificaLoc, 1, 0);
    gridLayout1->addWidget(btnCautaLoc, 2, 0);
    gridLayout1->addWidget(btnStergeLoc, 3, 0);
    gridLayout1->addWidget(btnFiltrareTip, 0, 1);
    gridLayout1->addWidget(btnFiltrareSuprafata, 1, 1);
    gridLayout1->addWidget(btnSortare, 2, 1);
    gridLayout1->addWidget(btnUndo, 3, 1);

    vbxLayout1->addWidget(btnResetListaLocatari);

    hbxLayout2->addLayout(vbxLayout2);
    lblitluColumn2->setText("Lista");
    vbxLayout2->addWidget(lblitluColumn2);
    lblitluColumn2->setAlignment(Qt::AlignCenter);

    vbxLayout2->addWidget(tblLista);

    vbxLayout2->addWidget(btnAdaugaLista);
    vbxLayout2->addWidget(btnGenereazaLista);
    vbxLayout2->addWidget(btnGolesteLista);
    vbxLayout2->addWidget(btnExportaLista);

    hbxLayout2->addLayout(vbxLayout3);
    lblTitluColumn3->setText("Locatar Selectat");
    vbxLayout3->addWidget(lblTitluColumn3);
    lblTitluColumn3->setAlignment(Qt::AlignCenter);
    vbxLayout3->addLayout(frmLocatar);
    font1.setPointSize(12);
    font1.setBold(true);
    font2.setPointSize(12);
    font2.setBold(false);
    lblApLoc->setFont(font1);
    lblPropLoc->setFont(font1);
    lblSupLoc->setFont(font1);
    lblTipLoc->setFont(font1);
    lbltxtApartamentLocatar->setFont(font2);
    lbltxtProprietarLocatar->setFont(font2);
    lbltxtSuprafataLocatar->setFont(font2);
    lbltxtTipLocatar->setFont(font2);
    frmLocatar->addRow(lblApLoc, lblApLoc);
    frmLocatar->addRow(lblPropLoc, lblPropLoc);
    frmLocatar->addRow(lblSupLoc, lblSupLoc);
    frmLocatar->addRow(lblTipLoc, lblTipLoc);
    vbxLayout3->addStretch();
    vbxLayout3->addWidget(lblTitluExports);
    vbxLayout3->addWidget(lstExports);

    hbxLayout2->addLayout(vbxLayout4);
    vbxLayout4->addWidget(lblTitluExports);
    lblTitluExports->setAlignment(Qt::AlignCenter);
    vbxLayout4->addWidget(lstExports);

    hbxLayout2->setStretchFactor(vbxLayout1, 1);
    hbxLayout2->setStretchFactor(vbxLayout2, 1);
    hbxLayout2->setStretchFactor(vbxLayout3, 1);
    hbxLayout2->setStretchFactor(vbxLayout4, 1);
    window1->resize(800, 600);
    window1->show();
}

void SuccesWindow() {
    auto* succesWindow = new QWidget();
    succesWindow->resize(200, 50);
    succesWindow->setWindowModality(Qt::ApplicationModal);

    auto* layoutsucces = new QVBoxLayout();
    auto* lblSucces = new QLabel("Actiune efectuata cu succes!");
    auto* btnOK = new QPushButton("OK");

    succesWindow->setLayout(layoutsucces);
    layoutsucces->addWidget(lblSucces);
    layoutsucces->addWidget(btnOK);

    QObject::connect(btnOK, &QPushButton::clicked, succesWindow, &QWidget::close);

    succesWindow->show();
}

void ErrorWindow(const string& msg) {
    auto* errorWindow = new QWidget();
    errorWindow->resize(200, 50);
    errorWindow->setWindowModality(Qt::ApplicationModal);

    auto* layouterror = new QVBoxLayout();
    auto* lblError = new QLabel(QString::fromStdString(msg));
    auto* btnOK = new QPushButton("OK");

    errorWindow->setLayout(layouterror);
    layouterror->addWidget(lblError);
    layouterror->addWidget(btnOK);

    QObject::connect(btnOK, &QPushButton::clicked, errorWindow, &QWidget::close);

    errorWindow->show();
}

void InterfataQT::connectInterfataQT() {
    reloadOferte();
    reloadListaTable();
    reloadTipuri();
    reloadExports();

    QObject::connect(lstLoc, &QListWidget::itemClicked, [this](QListWidgetItem* item) {
        if (!item) return;
        string id = item->text().toStdString();
        size_t pos1 = id.find(": ");
        size_t pos2 = id.find(")");
        id = id.substr(pos1 + 1, pos2 - pos1 - 1);
        const Locatar& of = service.serviceCautaLocatar(stoi(id));
        lbltxtApartamentLocatar->setText(QString::number(of.getApartament()));
        lbltxtProprietarLocatar->setText(QString::fromStdString(of.getProprietar()));
        lbltxtSuprafataLocatar->setText(QString::number(of.getSuprafata()));
        lbltxtTipLocatar->setText(QString::fromStdString(of.getTip()));
        });

    QObject::connect(lstExports, &QListWidget::itemClicked, [this](QListWidgetItem* item) {
        QString path = item->data(Qt::UserRole).toString();
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
        });

    QObject::connect(btnAdaugaLoc, &QPushButton::clicked, [this]() {
        auto* adaugaLocatarWindow = new QWidget();
        adaugaLocatarWindow->setWindowModality(Qt::ApplicationModal);
        adaugaLocatarWindow->show();
        adaugaLocatarWindow->resize(500, 200);
        auto* layout = new QVBoxLayout();
        adaugaLocatarWindow->setLayout(layout);
        auto* lblAp = new QLabel("Apartament:");
        auto* lblPr = new QLabel("Pr:");
        auto* lblSup = new QLabel("Sup:");
        auto* lblTip = new QLabel("Tip:");
        auto* editAp = new QLineEdit();
        auto* editPr = new QLineEdit();
        auto* editSup = new QLineEdit();
        auto* editTip = new QLineEdit();
        auto* formLayout = new QFormLayout();
        layout->addLayout(formLayout);
        formLayout->addRow(lblAp, editAp);
        formLayout->addRow(lblPr, editPr);
        formLayout->addRow(lblSup, editSup);
        formLayout->addRow(lblTip, editTip);

        auto* intVal = new QIntValidator(0, 1000, editAp);
        editAp->setValidator(intVal);

        auto* dblVal = new QDoubleValidator(0.0, 10000000.0, 2, editSup);
        dblVal->setNotation(QDoubleValidator::StandardNotation);
        editSup->setValidator(dblVal);

        auto* adaugaBtn = new QPushButton("Adauga Locatar");
        formLayout->addRow(adaugaBtn);
        QObject::connect(adaugaBtn, &QPushButton::clicked,
            [this, editAp, editPr, editSup, editTip, adaugaLocatarWindow]() {
                string ap = editAp->text().toStdString();
                unsigned int value = static_cast<unsigned int>(std::stoul(ap));
                string pr = editPr->text().toStdString();
                string sup = editSup->text().toStdString();
                unsigned int value1 = static_cast<unsigned int>(std::stoul(sup));
                std::string tipStr = editTip->text().toStdString();
                std::string tip = editTip->text().toStdString();
                Locatar loc( value, pr, value1, tip);
                try {
                    this->service.serviceAdaugaLocatar(loc);
                    reloadOferte();
                    reloadTipuri();
                    SuccesWindow();
                    adaugaLocatarWindow->close();
                }
                catch (const RepoError& re) {
                    ErrorWindow(re.getMessage());
                }
                catch (const ValidationError& ve) {
                    ErrorWindow(ve.getMessage());
                }
            });
        });

    QObject::connect(btnStergeLoc, &QPushButton::clicked, [this]() {
        auto* stergeLocatarWindow = new QWidget();
        stergeLocatarWindow->setWindowModality(Qt::ApplicationModal);
        stergeLocatarWindow->resize(500, 50);
        stergeLocatarWindow->show();

        auto* layout = new QVBoxLayout();
        stergeLocatarWindow->setLayout(layout);
        auto* formLayout = new QFormLayout();
        layout->addLayout(formLayout);
        auto* lblId = new QLabel("Ap:");
        auto* ledId = new QLineEdit();
        formLayout->addRow(lblId, ledId);
        auto* btnStergeLocatar = new QPushButton("Sterge Locatar");
        formLayout->addRow(btnStergeLocatar);
        QObject::connect(btnStergeLocatar, &QPushButton::clicked, [this, ledId, stergeLocatarWindow]() {
            try {
                this->service.serviceStergeLocatar(ledId->text().toInt());
                reloadOferte();
                reloadTipuri();
                SuccesWindow();
                stergeLocatarWindow->close();
            }
            catch (const RepoError& re) {
                ErrorWindow(re.getMessage());
            }
            });
        });

    QObject::connect(btnAdaugaLista, &QPushButton::clicked, [this]() {
        string idtxt = lbltxtApartamentLocatar->text().toStdString();

        if (idtxt == "") {
            ErrorWindow("Nu ati selectat o oferta!");
            return;
        }
        int id = stoi(idtxt);
        Locatar locAux = this->service.serviceCautaLocatar(id);
        try {
            this->serviceLista.adaugaLocatarInLista(locAux.getApartament());
            //reloadCos();
            reloadListaTable();
        }
        catch (const RepoError& re) {
            ErrorWindow(re.getMessage());
        }
        });
    QObject::connect(btnGenereazaLista, &QPushButton::clicked, [this]() {
        auto* windowAux = new QWidget();
        windowAux->setWindowModality(Qt::ApplicationModal);
        windowAux->resize(500, 50);
        windowAux->show();

        auto* layout = new QVBoxLayout();
        windowAux->setLayout(layout);
        auto* formLayout = new QFormLayout();
        layout->addLayout(formLayout);
        auto* lblNr = new QLabel("Numar de locatari:");
        auto* ledNr = new QLineEdit();
        formLayout->addRow(lblNr, ledNr);
        auto* btnStergeLoc = new QPushButton("Genereaza Lista");
        formLayout->addRow(btnStergeLoc);
        QObject::connect(btnStergeLoc, &QPushButton::clicked, [this, lblNr, ledNr, windowAux]() {
            try {
                this->serviceLista.genereazaListaAleator(ledNr->text().toInt());
                //reloadCos();
                reloadListaTable();
                windowAux->close();
            }
            catch (const ServiceError& re) {
                ErrorWindow(re.getMessage());
            }
            });
        });

    QObject::connect(btnGolesteLista, &QPushButton::clicked, [this]() {
        this->serviceLista.golesteLista();
        //reloadCos();
        reloadListaTable();
        });

    QObject::connect(btnExportaLista, &QPushButton::clicked, [this]() {
        auto* exportaListaWindow = new QWidget();
        exportaListaWindow->setWindowModality(Qt::ApplicationModal);
        exportaListaWindow->resize(500, 50);
        exportaListaWindow->show();

        auto* layout = new QVBoxLayout();
        exportaListaWindow->setLayout(layout);
        auto* formLayout = new QFormLayout();
        layout->addLayout(formLayout);
        auto* lblFisier = new QLabel("Nume Fisier:");
        auto* ledFisier = new QLineEdit();
        formLayout->addRow(lblFisier, ledFisier);
        auto* btnExportaCosCSV = new QPushButton("Exporta in fisier CSV");
        auto* btnExportaCosHTML = new QPushButton("Exporta in fisier HTML");
        auto* gridL = new QGridLayout();
        layout->addLayout(gridL);
        gridL->addWidget(btnExportaCosCSV, 0, 0);
        gridL->addWidget(btnExportaCosHTML, 0, 1);
        QObject::connect(btnExportaCosCSV, &QPushButton::clicked, [this, ledFisier, exportaListaWindow]() {
            string filename = ledFisier->text().toStdString();
            filename = "../Exports/" + filename + ".csv";
            try {
                this->serviceLista.exportaLista(filename, 1);
                exportaListaWindow->close();
                reloadExports();
                SuccesWindow();
            }
            catch (const ServiceError& se) {
                ErrorWindow(se.getMessage());
            }
            });
        QObject::connect(btnExportaCosHTML, &QPushButton::clicked, [this, ledFisier, exportaListaWindow]() {
            string filename = ledFisier->text().toStdString();
            filename = "../Exports/" + filename + ".html";
            try {
                this->serviceLista.exportaLista(filename, 2);
                exportaListaWindow->close();
                reloadExports();
                SuccesWindow();
            }
            catch (const ServiceError& se) {
                ErrorWindow(se.getMessage());
            }
            });
        });

    QObject::connect(btnResetListaLocatari, &QPushButton::clicked, [this]() {
        reloadOferte();
        });

    QObject::connect(btnFiltrareTip, &QPushButton::clicked, [this]() {
        auto* filtrareWindow = new QWidget();
        filtrareWindow->setWindowModality(Qt::ApplicationModal);
        filtrareWindow->resize(500, 50);
        filtrareWindow->show();

        auto* layout = new QVBoxLayout();
        filtrareWindow->setLayout(layout);
        auto* formLayout = new QFormLayout();
        layout->addLayout(formLayout);
        auto* lblDest = new QLabel("tip:");
        auto* ledDest = new QLineEdit();
        formLayout->addRow(lblDest, ledDest);
        auto* btnFiltrareDest = new QPushButton("Filtreaza");
        formLayout->addRow(btnFiltrareDest);
        QObject::connect(btnFiltrareDest, &QPushButton::clicked, [this, filtrareWindow, ledDest]() {
            try {
                vector<Locatar> aux = this->service.serviceFiltrareDupaTip(ledDest->text().toStdString());
                if (aux.size() == 0) {
                    ErrorWindow("Nu s-au gasit Locatari cu acest tip!");
                    filtrareWindow->close();
                    return;
                }
                reloadLocatarFiltrate(aux);
                //qDebug() << ledDest->text().toStdString();
                SuccesWindow();
                filtrareWindow->close();
            }
            catch (const ServiceError& se) {
                ErrorWindow(se.getMessage());
            }
            });
        });

    QObject::connect(btnFiltrareSuprafata, &QPushButton::clicked, [this]() {
        auto* filtrareWindow = new QWidget();
        filtrareWindow->setWindowModality(Qt::ApplicationModal);
        filtrareWindow->resize(500, 50);
        filtrareWindow->show();

        auto* layout = new QVBoxLayout();
        filtrareWindow->setLayout(layout);
        auto* formLayout = new QFormLayout();
        layout->addLayout(formLayout);
        auto* suprafata = new QLabel("Suprafata:");
        auto* suprafataMin = new QLineEdit();
        auto* dblVal = new QDoubleValidator(0.0, 10000000.0, 2);
        dblVal->setNotation(QDoubleValidator::StandardNotation);
        suprafataMin->setValidator(dblVal);

        formLayout->addRow(suprafata, suprafataMin);
        auto* btnFiltrareDest = new QPushButton("Filtreaza");
        formLayout->addRow(btnFiltrareDest);
        QObject::connect(btnFiltrareDest, &QPushButton::clicked, [this, filtrareWindow, suprafataMin]() {
            try {
                unsigned int Suprafata = suprafataMin->text().toUInt();
                vector<Locatar> aux = this->service.serviceFiltrareDupaSuprafata(Suprafata);
                if (aux.size() == 0) {
                    ErrorWindow("Nu s-au gasit oferte in acest interval de pret!");
                    filtrareWindow->close();
                    return;
                }
                reloadLocatarFiltrate(aux);
                SuccesWindow();
                filtrareWindow->close();
            }
            catch (const ServiceError& se) {
                ErrorWindow(se.getMessage());
            }
            });
        });

    QObject::connect(btnSortare, &QPushButton::clicked, [this]() {
        auto* sortareWindow = new QWidget();
        sortareWindow->setWindowModality(Qt::ApplicationModal);
        sortareWindow->resize(500, 50);
        sortareWindow->show();

        auto* horLayout = new QHBoxLayout();
        auto* verLayout = new QVBoxLayout();
        auto* lbltitlu = new QLabel("Alegeti modul de sortare");
        auto* btnSortarePropr = new QPushButton("Propr");
        auto* btnSortareSuprafata = new QPushButton("Suprafata");
        auto* btnSortareTS = new QPushButton("Tip si Suprafata");
        sortareWindow->setLayout(verLayout);
        verLayout->addWidget(lbltitlu);
        verLayout->addLayout(horLayout);
        horLayout->addWidget(btnSortarePropr);
        horLayout->addWidget(btnSortareSuprafata);
        horLayout->addWidget(btnSortareTS);
        QObject::connect(btnSortarePropr, &QPushButton::clicked, [this, sortareWindow]() {
            this->service.serviceSortareLocatari(1);
            reloadOferte();
            sortareWindow->close();
            });
        QObject::connect(btnSortareSuprafata, &QPushButton::clicked, [this, sortareWindow]() {
            this->service.serviceSortareLocatari(2);
            reloadOferte();
            sortareWindow->close();
            });
        QObject::connect(btnSortareTS, &QPushButton::clicked, [this, sortareWindow]() {
            this->service.serviceSortareLocatari(3);
            reloadOferte();
            sortareWindow->close();
            });
        });

    QObject::connect(btnUndo, &QPushButton::clicked, [this]() {
        try {
            this->service.serviceUndo();
            reloadOferte();
            SuccesWindow();
        }
        catch (const ServiceError& se) {
            ErrorWindow(se.getMessage());
        }
        });
}

void InterfataQT::reloadOferte() {
    lstLoc->clear();
    auto allOferte = this->service.serviceGetAllLocatari();
    //qDebug() << allOferte.size();
    int index = 0;
    for (const auto& oferta : allOferte) {
        index++;
        QString itemText = QString::fromStdString(
            to_string(index) + ". " + std::to_string(oferta.getApartament()) + " (Id: " + to_string(oferta.getApartament()) + ")"
        );
        QListWidgetItem* item = new QListWidgetItem(itemText);
        lstLoc->addItem(item);
    }
}

void InterfataQT::reloadLocatarFiltrate(vector<Locatar> allLocatari) {
    lstLoc->clear();
    int index = 0;
    for (const auto& loc : allLocatari) {
        index++;
        QString itemText = QString::fromStdString(
            to_string(index) + ". " + std::to_string(loc.getApartament()) + " (Id: " + to_string(loc.getApartament()) + ")"
        );
        QListWidgetItem* item = new QListWidgetItem(itemText);
        lstLoc->addItem(item);
    }
}

void InterfataQT::reloadLista() {
    lstLista->clear();
    auto allLoc = this->serviceLista.getLista();
    int index = 0;
    for (const auto& loc : allLoc) {
        index++;
        QString itemText = QString::fromStdString(
            to_string(index) + ". " + std::to_string(loc.getApartament()) + " (Id: " + to_string(loc.getApartament()) + ")"
        );
        QListWidgetItem* item = new QListWidgetItem(itemText);
        lstLista->addItem(item);
    }
}

void InterfataQT::reloadListaTable() {
    tblLista->clearContents();
    tblLista->setColumnCount(6);
    tblLista->setHorizontalHeaderLabels(
        QStringList{ "#","Apartament","Proprietar","Suprafata","Tip" });
    tblLista->setRowCount(this->serviceLista.getLista().size());
    auto allLoc = this->serviceLista.getLista();
    int index = 0;
    for (const auto& loc : allLoc) {
        QString itemTextIndex = QString::fromStdString(to_string(index));
        QTableWidgetItem* itemIndex = new QTableWidgetItem(itemTextIndex);
        tblLista->setItem(index, 0, itemIndex);

        QString itemTextAp = QString::number(loc.getApartament());
        QTableWidgetItem* itemDen = new QTableWidgetItem(itemTextAp);
        tblLista->setItem(index, 2, itemDen);

        QString itemTextPropr = QString::fromStdString(loc.getProprietar());
        QTableWidgetItem* itemDest = new QTableWidgetItem(itemTextPropr);
        tblLista->setItem(index, 1, itemDest);

        QString itemTextSup = QString::number(loc.getSuprafata());
        QTableWidgetItem* itemTip = new QTableWidgetItem(itemTextSup);
        tblLista->setItem(index, 3, itemTip);

        QString itemTextTip = QString::fromStdString(loc.getTip());
        QTableWidgetItem* itemPret = new QTableWidgetItem(itemTextTip);
        tblLista->setItem(index, 4, itemPret);
        index++;
    }
    tblLista->resizeColumnsToContents();
}

void InterfataQT::reloadTipuri() {
    QLayoutItem* item;
    while ((item = hbxLayout1->takeAt(0)) != nullptr) {
        delete item->widget();  // șterge widgetul
        delete item;            // șterge itemul din layout
    }
    map<string, int> tipuriLocatari = this->service.serviceGetTipuri();
    for (const auto& tip : tipuriLocatari) {
        auto* btnTip = new QPushButton(QString::fromStdString(tip.first));
        hbxLayout1->addWidget(btnTip);
    }
}

void InterfataQT::reloadExports() {
    lstExports->clear();
    QString dirpath = QCoreApplication::applicationDirPath() + "/../Exports";
    //qDebug() << dirpath;
    QDir dir(dirpath);
    dir.setFilter(QDir::Files);
    for (auto filename : dir.entryList()) {
        auto* item = new QListWidgetItem(filename);
        lstExports->addItem(item);
        item->setData(Qt::UserRole, dir.absoluteFilePath(filename));
    }
}
void InterfataQT::runInterfataQT() {
    this->setUpInterfataQT();
    this->connectInterfataQT();
}