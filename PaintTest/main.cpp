#include "MainWindow.h"

#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
	QApplication app(argc, argv);

	MainWindow window;
	window.show();

	//test 
	
	return app.exec();
}
