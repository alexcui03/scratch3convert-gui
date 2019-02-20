#include "MainWindow.h"

#include <QFileDialog>
#include <QMessageBox>

#include "scratch3convert/scratch3convert.h"

MainWindow::MainWindow(QWidget *parent) :QMainWindow(parent) {
	this->btn_file = new QPushButton("Select file", this);
	this->btn_file->move(0, 0);
	this->btn_file->resize(100, 50);

	this->label = new QLabel(this);
	this->label->move(100, 0);
	this->label->resize(400, 50);

	this->btn_convert = new QPushButton("Convert", this);
	this->btn_convert->move(500, 0);
	this->btn_convert->resize(100, 50);

	connect(this->btn_file, SIGNAL(clicked()), this, SLOT(btn_file_push()));
	connect(this->btn_convert, SIGNAL(clicked()), this, SLOT(btn_convert_push()));
}

MainWindow::~MainWindow() {

}

void MainWindow::btn_file_push() {
	QFileDialog *dialog = new QFileDialog();
	dialog->setWindowTitle("Choose *.sb3 project");
	dialog->setDirectory(".");
	dialog->setNameFilter("*.sb3");
	dialog->setViewMode(QFileDialog::Detail);
	dialog->show();
	if (dialog->exec()) {
		QString file_name = dialog->selectedFiles().at(0);
		this->label->setText(file_name);
	}
}

void MainWindow::btn_convert_push() {
	int code = sc3convert_convert(this->label->text().toStdString().c_str());
	if (code == SC3CONVERT_SUCCESS) {
		QMessageBox *msgbox = new QMessageBox(this);
		msgbox->setWindowTitle("Message");
		msgbox->setText("Convert Successfully!");
		msgbox->show();
	}
	else {
		char message[256];
		memset(message, 0, 256);
		sprintf_s(message, 256, "Convertion crashed. Exit code: %d.", code);
		QMessageBox *msgbox = new QMessageBox(this);
		msgbox->setWindowTitle("Error");
		msgbox->setText(message);
		msgbox->show();
	}
}
