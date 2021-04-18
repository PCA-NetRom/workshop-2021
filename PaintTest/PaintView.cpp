#include "PaintView.h"

#include <QtGui/QMouseEvent>
#include <string>
static const int	kWindowWidth	= 800;
static const int	kWindowHeight	= 600;
static const QColor kPenColor = QColor(0, 0, 0);
static const int	kPenWidth = 3;

PaintView::PaintView(QWidget *parent)
	: QGraphicsView(parent)
{
	_scene = new QGraphicsScene(this);
	_scene->setSceneRect(QRectF(0, 0, kWindowWidth, kWindowHeight));

	this->setScene(_scene);
	this->centerOn(0, 0);

	_lineButton = new QPushButton("Draw Line", this);
	_drawButton = new QPushButton("Simple Draw", this);
	_penColorButton = new QPushButton("Change Pen Color", this);
	_penWidthButton = new QPushButton("Change Pen Width", this);

	_drawButton->move(QPoint(100, 0));
	_penColorButton->move(QPoint(200, 0));
	_penWidthButton->move(QPoint(325, 0));

	connect(_lineButton, &QPushButton::clicked, this, &PaintView::clickLineButton);
	connect(_drawButton, &QPushButton::clicked, this, &PaintView::clickDrawButton);
	connect(_penColorButton, &QPushButton::clicked, this, &PaintView::clickPenColorButton);
	connect(_penWidthButton, &QPushButton::clicked, this, &PaintView::clickPenWidthButton);

	_penWidthDialog = new QInputDialog(this);
	_penWidthDialog->move(QPoint(150, 150));

	_penColorDialog = new QColorDialog(kPenColor, this);
	_penColorDialog->move(QPoint(150, 150));

	_mousePosLable = new QLabel(parent);
	_mousePosLable->move(QPoint(500, 0));

	_pen = new QPen(kPenColor, kPenWidth);
}

PaintView::~PaintView()
{
}

QGraphicsLineItem* PaintView::createLine(const QLineF& line)
{
	return _scene->addLine(line, getPen());
}

void PaintView::mousePressEvent(QMouseEvent* event)
{
	if (event == nullptr)
		return;

	QPoint pos = event->pos();
	Qt::MouseButtons buttons = event->buttons();
	emit mousePress(pos, buttons);
}

void PaintView::mouseMoveEvent(QMouseEvent* event)
{

	if (event == nullptr)
		return;

	QPoint pos = event->pos();

	_mousePosLable->setText(QString("X : %1, Y : %2").arg(pos.x()).arg(pos.y()));

	Qt::MouseButtons buttons = event->buttons();
	emit mouseMove(pos, buttons);
}

void PaintView::mouseReleaseEvent(QMouseEvent* event)
{
	if (event == nullptr)
		return;

	QPoint pos = event->pos();
	Qt::MouseButtons buttons = event->buttons();
	emit mouseRelease(pos, buttons);
}


QPen PaintView::getPen()
{
	return *_pen;
}


void PaintView::clickLineButton() {
	emit buttonSelect(1);
}

void PaintView::clickDrawButton()
{
	emit buttonSelect(0);
}

void PaintView::clickPenColorButton()
{
	_pen->setColor(_penColorDialog->getColor());
}

void PaintView::clickPenWidthButton()
{
	bool ok = false;

	int newWidth = _penWidthDialog->getInt(this, tr("Pen Width"), tr("Select pen width:"), _pen->width(), 1, 50, 1, &ok);

	if (ok)
	{
		_pen->setWidth(newWidth);
	}
}
