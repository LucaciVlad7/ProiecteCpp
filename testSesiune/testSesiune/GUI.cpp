#include "GUI.h"
#include <QHeaderView>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QLabel>
#include "Exceptii.h"

GUI::GUI(Service& srv, QWidget* parent) : QWidget(parent), service(srv) {
	model = new MelodiiModel(service);
	initGUI();
	connectSignals();
}

void GUI::initGUI() {
    tableView = new QTableView;
    tableView->setModel(model);
    tableView->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    btnRefresh = new QPushButton{ "Refresh" };
    btnUpdate = new QPushButton{ "Update" };
    btnDelete = new QPushButton{ "Delete" };
    txtTitlu = new QLineEdit;
    sliderRank = new QSlider(Qt::Horizontal);
    sliderRank->setMinimum(1);  
    sliderRank->setMaximum(10);

    auto* layout = new QVBoxLayout;
    layout->addWidget(tableView);
    layout->addWidget(new QLabel("Titlu:"));
    layout->addWidget(txtTitlu);
    layout->addWidget(new QLabel("Rank:"));
    layout->addWidget(sliderRank);
    layout->addWidget(btnUpdate);
    layout->addWidget(btnRefresh);
    layout->addWidget(btnDelete);

    setLayout(layout);
}

void GUI::connectSignals() {
    connect(btnRefresh, &QPushButton::clicked, this, &GUI::handleRefresh);
    connect(btnUpdate, &QPushButton::clicked, this, &GUI::handleUpdate);

    connect(tableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
        this, &GUI::incarcaDateInCampuri);

    connect(btnDelete, &QPushButton::clicked, this, &GUI::handleDelete);
}

void GUI::incarcaDateInCampuri(const QModelIndex& index) {
    if (!index.isValid()) return;

    int row = index.row();
    const auto& m = service.sortareRank().at(row);
    txtTitlu->setText(m.getTitlu());
    sliderRank->setValue(m.getRank());
}

void GUI::handleUpdate() {
    auto index = tableView->currentIndex();
    if (!index.isValid()) return;

    int row = index.row();
    const auto& melodie = service.sortareRank().at(row);
    int id = melodie.getId();
    QString nouTitlu = txtTitlu->text();
    int nouRank = sliderRank->value();

    service.modificaTitlu(id, nouTitlu);
    service.modificaRank(id, nouRank);
    model->actualizeaza();
}

void GUI::handleDelete() {
    auto index = tableView->currentIndex();
    if (!index.isValid()) return;

    int row = index.row();
    const auto& melodie = service.sortareRank().at(row);
    int id = melodie.getId();
    try {
        service.stergereMelodie(id);
        model->actualizeaza();
    }
    catch (const RepoError& ex) {
        QMessageBox::warning(this, "Warning", QString::fromStdString(ex.what()));
    }
}


void GUI::handleRefresh() {
    service.sortareRank();
    model->actualizeaza();
}