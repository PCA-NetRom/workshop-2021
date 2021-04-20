#include "MainWindow.h"

MainWindow::MainWindow(QWidget* parent, Qt::WindowFlags flags) :
	QMainWindow(parent, flags)
{
	_ui.setupUi(this);

	_view = new PaintView(this);
	this->setCentralWidget(_view);
	this->adjustSize();
	this->setWindowTitle("MyPaintApp");

	_controller = new PaintController(this, _view);
	connect(_view, SIGNAL(mousePress(QPoint, Qt::MouseButtons)),
			_controller, SLOT(onMousePress(QPoint, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPoint, Qt::MouseButtons)),
		_controller, SLOT(onMouseMove(QPoint, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseRelease(QPoint, Qt::MouseButtons)),
		_controller, SLOT(onMouseRelease(QPoint, Qt::MouseButtons)));
	connect(_view, SIGNAL(buttonSelect(std::string)),
		_controller, SLOT(onButtonSelect(std::string)));
	connect(_view, SIGNAL(spaceKeyHeldDown(Qt::Key)),
		_controller, SLOT(onSpaceKeyHeldDown(Qt::Key)));
	connect(_view, SIGNAL(spaceKeyRelease(Qt::Key)),
		_controller, SLOT(onSpaceKeyRelease(Qt::Key)));
}

