#include "RectangleTool.h"

#include <QtGui/QGuiApplication>
#include <QtWidgets/QGraphicsItem>

RectangleTool::RectangleTool(PaintView* view) : 
	Tool(view)
{
}

void RectangleTool::onMousePress(const QPointF& pos)
{
	QRectF rectangle(pos, pos);

	_graphicsItem = _view->createRectangle(rectangle);

	Tool::onMousePress(pos);
}

void RectangleTool::onMouseMove(const QPointF& pos)
{
	QGraphicsRectItem* rectangleItem = dynamic_cast<QGraphicsRectItem*>(_graphicsItem);
	if (!rectangleItem)
		return;

	QPointF endPos = pos;
	bool shiftPressed = QGuiApplication::keyboardModifiers() == Qt::ShiftModifier;
	if (shiftPressed)
		endPos = proportionalPos(_startPos, endPos);

	QRectF rectangle = QRectF(_startPos, endPos).normalized();
	rectangleItem->setRect(rectangle);

	Tool::onMouseMove(pos);
}
