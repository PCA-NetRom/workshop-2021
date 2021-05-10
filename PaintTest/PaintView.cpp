#include "PaintView.h"

#include <QMouseEvent>

static const int	kWindowWidth	= 800;
static const int	kWindowHeight	= 600;

PaintView::PaintView(QWidget *parent)
	: QGraphicsView(parent)
{
	initScene();

	this->setMouseTracking(true);
	this->setRenderHints(QPainter::Antialiasing | QPainter::SmoothPixmapTransform);
}

QGraphicsLineItem* PaintView::createLine(const QLineF& line)
{
	return _scene->addLine(line);
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
