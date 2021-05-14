#include "LineTool.h"

#include <QtGui/qguiapplication.h>
#include <QtWidgets/qgraphicsitem.h>

LineTool::LineTool(PaintView* view) : Tool(view)
{
}

void LineTool::onMousePress(const QPointF& pos)
{
	QLineF line(QPointF(0, 0), QPointF(0, 0));
	_graphicsItem = _view->createLine(line);
	Tool::onMousePress(pos);
}

void LineTool::onMouseMove(const QPointF& pos)
{
	QGraphicsLineItem* lineItem = dynamic_cast<QGraphicsLineItem*>(_graphicsItem);
	if (!lineItem)
		return;

	QPointF endPos = pos;
	bool shiftPressed = QGuiApplication::keyboardModifiers() == Qt::ShiftModifier;
	if (shiftPressed)
	{
		QPointF posDif = endPos - _startPos;
		float coordDifference = qAbs(posDif.x()) - qAbs(posDif.y());
		if (coordDifference < 0)
			endPos.setX(_startPos.x());
		else
			endPos.setY(_startPos.y());
	}

	QLineF line(_startPos, endPos);
	lineItem->setLine(line);

	Tool::onMouseMove(pos);
}
