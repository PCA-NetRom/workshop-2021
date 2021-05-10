#include "MainWindow.h"

#include <QComboBox>
#include <QLabel>
#include <QStatusBar>
#include <QDebug>

MainWindow::MainWindow(QWidget* parent, Qt::WindowFlags flags) :
	QMainWindow(parent, flags)
{
	_ui.setupUi(this);

	initView();
	initController();

	initLeftToolbar();
	initTopToolbar();

	this->adjustSize();
}

void MainWindow::initLeftToolbar()
{
	QActionGroup* tools = new QActionGroup(this);
	tools->addAction(_ui.actionSelect);
	tools->addAction(_ui.actionPen);
	tools->addAction(_ui.actionLine);
	tools->addAction(_ui.actionRectangle);
	tools->addAction(_ui.actionEllipse);

	connect(_ui.actionSelect, SIGNAL(triggered()),
		_view, SLOT(onActionSelectTriggered()));
	connect(_ui.actionPen, &QAction::triggered,
		_controller, &PaintController::onActionPenTriggered);
	connect(_ui.actionLine, SIGNAL(triggered()),
		_controller, SLOT(onActionLineTriggered()));
	connect(_ui.actionRectangle, SIGNAL(triggered()),
		_controller, SLOT(onActionRectangleTriggered()));
	connect(_ui.actionEllipse, SIGNAL(triggered()),
		_controller, SLOT(onActionEllipseTriggered()));

	_ui.actionSelect->setChecked(true);
}

void MainWindow::initTopToolbar()
{
	_topToolBar = new QToolBar(this);
	_topToolBar->setIconSize(QSize(10, 10));
	this->addToolBar(Qt::TopToolBarArea, _topToolBar);

	// Color picker
	_actionColor = new QAction(QIcon(":/MainWindow/res/icons/Transparent.png"), "Color", this);
	_actionColor->setToolTip("Change color of the drawing item");
	_topToolBar->addAction(_actionColor);
	_topToolBar->widgetForAction(_actionColor)->setStyleSheet("background: black");

	_colorDialog = new QColorDialog(this);
	connect(_actionColor, SIGNAL(triggered()),
		_colorDialog, SLOT(open()));
	connect(_colorDialog, &QColorDialog::colorSelected,
		_view, &PaintView::onColorSelected);
	connect(_colorDialog, &QColorDialog::colorSelected,
		this, &MainWindow::onColorSelected);

	_topToolBar->addSeparator();

	// Line thickness
	QComboBox* lineThicknessComboBox = new QComboBox(this);
	lineThicknessComboBox->addItem("1");
	lineThicknessComboBox->addItem("2");
	lineThicknessComboBox->addItem("3");

	connect(lineThicknessComboBox, &QComboBox::currentTextChanged,
		_view, &PaintView::onActionLineThicknessTriggered);

	_topToolBar->addWidget(new QLabel("Line Thickness: ", this));
	_topToolBar->addWidget(lineThicknessComboBox);
}

void MainWindow::onColorSelected(const QColor& color)
{
	_topToolBar->widgetForAction(_actionColor)->setStyleSheet("background: " + color.name());
}

void MainWindow::initView()
{
	_view = new PaintView(this);
	this->setCentralWidget(_view);
}

void MainWindow::initController()
{
	_controller = new PaintController(this, _view);
	connect(_view, SIGNAL(mousePress(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMousePress(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseMove(QPointF, Qt::MouseButtons)),
		this, SLOT(onMouseMove(QPointF, Qt::MouseButtons)));
	connect(_view, SIGNAL(mouseRelease(QPointF, Qt::MouseButtons)),
		_controller, SLOT(onMouseRelease(QPointF, Qt::MouseButtons)));
}

void MainWindow::onMouseMove(const QPointF& pos, const Qt::MouseButtons& /*buttons*/)
{
	QString msg;
	msg.sprintf("%1.0fx%1.0f", pos.x(), pos.y());
	statusBar()->showMessage(msg);
}