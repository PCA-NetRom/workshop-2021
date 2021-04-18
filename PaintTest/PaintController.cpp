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
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_option == 0) {
		_point = pos;
	}
	else if (_option == 1) {
		_line = _view->createLine(QLineF(pos, pos));
	}
}

void PaintController::onMouseMove(const QPoint& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_option == 0) {
		QPoint point = _point;
		_view->createLine(QLineF(_point, pos));
		_point = pos;
	}
	else if (_option == 1) {
		QLineF line = _line->line();
		line.setP2(pos);
		_line->setLine(line);
	}

}

void PaintController::onMouseRelease(const QPoint& pos, const Qt::MouseButtons& buttons)
{
}

void PaintController::onButtonSelect(int id)
{
	this->_option = id;
}