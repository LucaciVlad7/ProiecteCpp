#include "gui.h"
#include <QHeaderView>
#include <QFormLayout>
#include <QLineEdit>
#include <QMessageBox>
#include <QLabel>

GUI::GUI(Service& srv) : service{ srv } {
    initGUI();
    loadData();
}

void GUI::initGUI() {
    auto* layout = new QVBoxLayout(this);

    table = new QTableView;
    model = new MyTableModel;
    table->setModel(model);
    table->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
    layout->addWidget(table);

    auto* formLayout = new QFormLayout;
    txtId = new QLineEdit;
    txtNume = new QLineEdit;
    txtTip = new QLineEdit;
    txtPret = new QLineEdit;

    formLayout->addRow("ID:", txtId);
    formLayout->addRow("Nume:", txtNume);
    formLayout->addRow("Tip:", txtTip);
    formLayout->addRow("Preț:", txtPret);

    layout->addLayout(formLayout);

    btnAdauga = new QPushButton("Adaugă produs");
    layout->addWidget(btnAdauga);

    auto* sliderLayout = new QHBoxLayout;
    lblSliderVal = new QLabel("Filtru preț <= 100");

    sliderFiltru = new QSlider(Qt::Horizontal);
    sliderFiltru->setRange(1, 100);
    sliderFiltru->setValue(100);

    sliderLayout->addWidget(lblSliderVal);
    sliderLayout->addWidget(sliderFiltru);
    layout->addLayout(sliderLayout);

    setLayout(layout);
    initConnect();
}

void GUI::loadData() {
    model->setProduse(service.exportSortat());
}

void GUI::initConnect() {
    QObject::connect(btnAdauga, &QPushButton::clicked, [&]() {
        QString errors;

        bool okId, okPret;
        int id = txtId->text().toInt(&okId);
        QString nume = txtNume->text();
        QString tip = txtTip->text();
        double pret = txtPret->text().toDouble(&okPret);

        if (!okId || id < 0) errors += "ID invalid.\n";
        if (nume.trimmed().isEmpty()) errors += "Numele nu poate fi vid.\n";
        if (!okPret || pret < 1.0 || pret > 100.0) errors += "Prețul trebuie să fie între 1.0 și 100.0.\n";

        if (!errors.isEmpty()) {
            QMessageBox::warning(this, "Date invalide", errors);
            return;
        }

        try {
            service.adaugaServ(Produs(id, nume, tip, pret));
            loadData();
        }
        catch (const std::exception& ex) {
            QMessageBox::warning(this, "Eroare", QString::fromStdString(ex.what()));
        }
        });

    QObject::connect(sliderFiltru, &QSlider::valueChanged, [this](int val) {
        lblSliderVal->setText("Filtru preț <= " + QString::number(val));
        model->setLimitaPret(val);
        });
}