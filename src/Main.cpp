#include "MainWindow.h"
#include <QApplication>

int main(int argc, char *argv[]) {
	QApplication *app = new QApplication(argc, argv);
	MainWindow *window = new MainWindow();
	window->setWindowTitle("Scratch3Convert - By Alex Cui");
	window->resize(600, 50);
	window->show();
	return app->exec();
}
