#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>

PaintController::PaintController(QObject *parent, PaintView* view)
	: QObject(parent),
	_view(view)
{
}

PaintController::~PaintController()
{
}

void PaintController::onMousePress(const QPoint& pos, const Qt::MouseButtons& buttons)
{
	_line = _view->createLine(QLineF(pos, pos));
}

void PaintController::onMouseMove(const QPoint& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	QLineF line = _line->line();
	line.setP2(pos);
	_line->setLine(line);
}

void PaintController::onMouseRelease(const QPoint& pos, const Qt::MouseButtons& buttons)
{
}
