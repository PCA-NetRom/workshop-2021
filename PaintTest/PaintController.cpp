#define _USE_MATH_DEFINES
#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>

#include <cmath>
#include <iostream>


PaintController::PaintController(QObject *parent, PaintView* view)
	: QObject(parent),
	_view(view)
{
	_option = "none";
	_scribbling = false;
	_spaceKeyHeldDown = false;
}

PaintController::~PaintController()
{
}

void PaintController::onMousePress(const QPoint& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;


	if (_option == "DrawButton") {
		_point = pos;
	}
	else if (_option == "LineButton") {
		_line = _view->createLine(QLineF(pos, pos));
	}
}

int get_slope(QPointF p1, QPointF p2)
{
	if (p1.x() == p2.x())
	{
		return 90;
	}

	double tanx = (p2.y() - p1.y()) / (double)(p2.x() - p1.x());
	double s = atan(tanx);
	s = (180 / M_PI) * s;
	return s;
}


void PaintController::onMouseMove(const QPoint& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	_scribbling = true;

	if (_option == "DrawButton") {
		_view->createLine(QLineF(_point, pos));
		_point = pos;
	}
	else if (_option == "LineButton" && _spaceKeyHeldDown)
	{

		int slope = get_slope(_line->line().p1(), pos);


		if ( (slope >= 0 && slope <= 90))
		{
			QLineF line = _line->line();
			line.setP2(QPoint(pos.x(), line.p1().y()));
			_line->setLine(line);
		}
		else
		{
			QLineF line = _line->line();
			line.setP2(QPoint(line.p1().x(), pos.y()));
			_line->setLine(line);
		}

	}
	else if (_option == "LineButton") {
		QLineF line = _line->line();
		line.setP2(pos);
		_line->setLine(line);
	}

}

void PaintController::onMouseRelease(const QPoint& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (buttons == Qt::MouseButton::LeftButton && _scribbling == true)
	{
		_scribbling = false;
	}
}

void PaintController::onButtonSelect(std::string buttonName)
{
	this->_option = buttonName;
}

void PaintController::onSpaceKeyHeldDown(const Qt::Key& keyPressed)
{
	if (keyPressed == Qt::Key_Space)
	{
		_spaceKeyHeldDown = true;
	}

}

void PaintController::onSpaceKeyRelease(const Qt::Key& keyPressed)
{
	if (keyPressed == Qt::Key_Space)
	{
		_spaceKeyHeldDown = false;
	}

}