#include "PaintView.h"

#include <QtGui/QMouseEvent>
#include <QtWidgets/QGraphicsTextItem>

static const int	kWindowWidth	= 800;
static const int	kWindowHeight	= 600;

PaintView::PaintView(QWidget *parent)
	: QGraphicsView(parent)
{
	_scene = new QGraphicsScene(this);
	_scene->setSceneRect(QRectF(0, 0, kWindowWidth, kWindowHeight));

	this->setScene(_scene);
	this->centerOn(0, 0);
	this->raise();
	_previous_text = nullptr;
}

PaintView::~PaintView()
{
}

QGraphicsLineItem* PaintView::createLine(const QLineF& line)
{
	return _scene->addLine(line);
}

void PaintView::mousePressEvent(QMouseEvent* event)
{
	QPoint pos = event->pos();
	this->printMouseCoords(pos);
	Qt::MouseButtons buttons = event->buttons();
	emit mousePress(pos, buttons);
}

void PaintView::mouseMoveEvent(QMouseEvent* event)
{
	QPoint pos = event->pos();
	this->printMouseCoords(pos);
	Qt::MouseButtons buttons = event->buttons();
	emit mouseMove(pos, buttons);
}

void PaintView::mouseReleaseEvent(QMouseEvent* event)
{
	QPoint pos = event->pos();
	Qt::MouseButtons buttons = event->buttons();
	emit mouseRelease(pos, buttons);
}

void PaintView::printMouseCoords(QPoint pos) {
	if (_previous_text != nullptr) {
		_scene->removeItem(_previous_text);
		delete _previous_text;
		_previous_text = nullptr;
	}
	QGraphicsTextItem* mouse_coords = new QGraphicsTextItem(QString::number(pos.x()) + QString(" ") + QString::number(pos.y()), nullptr);
	_scene->addItem(mouse_coords);
	_previous_text = mouse_coords;
}