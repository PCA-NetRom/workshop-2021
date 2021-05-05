#include "MainWindow.h"
#include <QtWidgets/qlabel.h>
#include <QtWidgets/qcombobox.h>
#include <QtWidgets/qstatusbar.h>

MainWindow::MainWindow(QWidget* parent, Qt::WindowFlags flags) :
	QMainWindow(parent, flags)
{
	_ui.setupUi(this);

	_view = new PaintView(this);
	this->setCentralWidget(_view);
	this->adjustSize();

	_controller = new PaintController(this, _view);
	connect(_view, SIGNAL(mousePress(QPointF, Qt::MouseButtons)),
			_controller, SLOT(onMousePress(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		this, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseRelease(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseRelease(QPointF, Qt::MouseButtons)));

	initLeftToolBar();
	initTopToolBar();
}

void MainWindow::initLeftToolBar()
{
	QActionGroup* actionGroup = new QActionGroup(this);
	actionGroup->addAction(_ui.actionSelect);
	actionGroup->addAction(_ui.actionLine);
	_ui.actionSelect->setChecked(true);

	connect(_ui.actionSelect, &QAction::triggered,
		_controller, &PaintController::onActionSelect);
	connect(_ui.actionLine, &QAction::triggered,
		_controller, &PaintController::onActionLine);
}

void MainWindow::initTopToolBar()
{
	_topToolBar = new QToolBar(this);
	addToolBar(Qt::TopToolBarArea, _topToolBar);

	_topToolBar->addWidget(new QLabel("Line thickness: "));

	QComboBox* lineThickness = new QComboBox(this);
	lineThickness->addItem("1");
	lineThickness->addItem("2");
	lineThickness->addItem("3");

	_topToolBar->addWidget(lineThickness);

	connect(lineThickness, &QComboBox::currentTextChanged,
		_view, &PaintView::onLineThickessChanged);

	_actionColor = new QAction(QIcon(":/MainWindow/res/icons/Transparent.png"), "Color", this);
	_actionColor->setToolTip("Change color of the drawing item");

	_topToolBar->addAction(_actionColor);
	_topToolBar->widgetForAction(_actionColor)->setStyleSheet("background: black");

	_colorDialog = new QColorDialog(this);
	connect(_actionColor, SIGNAL(triggered()),
		_colorDialog, SLOT(open()));
	connect(_colorDialog, &QColorDialog::colorSelected,
		_view, &PaintView::onColorChanged);
	connect(_colorDialog, &QColorDialog::colorSelected,
		this, &MainWindow::onColorChanged);

}

void MainWindow::onColorChanged(const QColor& color)
{
	_topToolBar->widgetForAction(_actionColor)->setStyleSheet("background: " + color.name());
}

void MainWindow::onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	QString msg;
	msg.sprintf("%1.0fx%1.0f", pos.x(), pos.y());
	statusBar()->showMessage(msg);
}