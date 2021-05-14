#include "PaintView.h"

#include <QDebug>
#include <QMouseEvent>

static const int	kWindowWidth	= 800;
static const int	kWindowHeight	= 600;

PaintView::PaintView(QWidget *parent)
	: QGraphicsView(parent),
	_pen(QBrush(Qt::black), 1)
{
	initScene();

	this->setMouseTracking(true);
	this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

QGraphicsLineItem* PaintView::createLine(const QLineF& line)
{
	return _scene->addLine(line, _pen);
}

QGraphicsItem* PaintView::itemAt(const QPointF& pos)
{
	return _scene->itemAt(pos, QTransform());
}

void PaintView::onActionLineThicknessTriggered(const QString& lineThickness)
{
	qDebug() << "action Line Thickness triggered: " << lineThickness;
	_pen.setWidth(lineThickness.toInt());
}

void PaintView::onColorSelected(const QColor& color)
{
	qDebug() << "action Color triggered";
	_pen.setColor(color);
}

void PaintView::initScene()
{
	_scene = new QGraphicsScene(this);
	_scene->setSceneRect(QRectF(0, 0, kWindowWidth, kWindowHeight));
	this->setScene(_scene);
	this->centerOn(0, 0);
}

void PaintView::mousePressEvent(QMouseEvent* event)
{
	const QPointF pos = mapToScene(event->pos());
	const Qt::MouseButtons buttons = event->buttons();
	emit mousePress(pos, buttons);
}

void PaintView::mouseMoveEvent(QMouseEvent* event)
{
	const QPointF pos = mapToScene(event->pos());
	const Qt::MouseButtons buttons = event->buttons();
	emit mouseMove(pos, buttons);
}

void PaintView::mouseReleaseEvent(QMouseEvent* event)
{
	const QPointF pos = mapToScene(event->pos());
	const Qt::MouseButtons buttons = event->buttons();
	emit mouseRelease(pos, buttons);
}
