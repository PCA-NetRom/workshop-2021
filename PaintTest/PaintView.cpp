#include "PaintView.h"

#include <QtGui/QMouseEvent>
#include <QtCore/qdebug.h>
#include <QtGui/qbrush.h>

static const int	kWindowWidth	= 800;
static const int	kWindowHeight	= 600;

PaintView::PaintView(QWidget *parent)
	: QGraphicsView(parent),
	_pen(QBrush(Qt::black), 1)
{
	setMouseTracking(true);

	_scene = new QGraphicsScene(this);
	_scene->setSceneRect(QRectF(0, 0, kWindowWidth, kWindowHeight));

	this->setRenderHint(QPainter::Antialiasing);
	this->setRenderHint(QPainter::HighQualityAntialiasing);

	this->setScene(_scene);
	this->centerOn(0, 0);
}

PaintView::~PaintView()
{
}

QGraphicsLineItem* PaintView::createLine(const QLineF& line)
{
	return _scene->addLine(line, _pen);
}

void PaintView::mousePressEvent(QMouseEvent* event)
{
	QPointF pos = mapToScene(event->pos());
	Qt::MouseButtons buttons = event->buttons();
	emit mousePress(pos, buttons);
}

void PaintView::mouseMoveEvent(QMouseEvent* event)
{
	QPointF pos = mapToScene(event->pos());
	Qt::MouseButtons buttons = event->buttons();
	emit mouseMove(pos, buttons);
}

void PaintView::mouseReleaseEvent(QMouseEvent* event)
{
	QPointF pos = mapToScene(event->pos());
	Qt::MouseButtons buttons = event->buttons();
	emit mouseRelease(pos, buttons);
}

void PaintView::onLineThickessChanged(const QString& lineThickness)
{
	qDebug() << "Line thickess changed " + lineThickness;
	_pen.setWidth(lineThickness.toInt());
}

void PaintView::onColorChanged(const QColor& color)
{
	qDebug() << "Color changed" << color.name();
	_pen.setColor(color);
}