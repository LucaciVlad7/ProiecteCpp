#pragma once
#include <QWidget>
#include "Service.h"
#include <QTableView>
#include <QPushButton>
#include <QSlider>
#include <QLineEdit>
#include "MelodiiModel.h"

class GUI:public QWidget{
	Q_OBJECT
private:
	Service& service;
	MelodiiModel* model;
	QTableView* tableView;
	QPushButton* btnRefresh;
	QPushButton* btnUpdate;
	QSlider* sliderRank;
	QLineEdit* txtTitlu;
	QPushButton* btnDelete;


	void initGUI();
	void connectSignals();
public:
	GUI(Service& srv, QWidget* parent = nullptr);
	void handleRefresh();
	void handleUpdate();
	void handleDelete();
	void incarcaDateInCampuri(const QModelIndex& index);
};

