#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPushButton>
#include <QLabel>

class MainWindow : public QMainWindow {
	Q_OBJECT
public:
	explicit MainWindow(QWidget *parent = nullptr);
	~MainWindow();
public slots:
	void btn_file_push();
	void btn_convert_push();
private:
	QPushButton *btn_file;
	QPushButton *btn_convert;
	QLabel *label;
};

#endif // MAINWINDOW_H
