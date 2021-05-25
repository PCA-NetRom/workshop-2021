#include "EllipseTool.h"

#include <QtGui/QGuiApplication>
#include <QtWidgets/QGraphicsItem>

EllipseTool::EllipseTool(PaintView* view) : 
	Tool(view)
{
}

void EllipseTool::onMousePress(const QPointF& pos)
{
	QRectF ellipse(pos, pos);

	_graphicsItem = _view->createEllipse(ellipse);

	Tool::onMousePress(pos);
}

void EllipseTool::onMouseMove(const QPointF& pos)
{
	QGraphicsEllipseItem* ellipseItem = dynamic_cast<QGraphicsEllipseItem*>(_graphicsItem);
	if (!ellipseItem)
		return;

	QPointF endPos = pos;
	bool shiftPressed = QGuiApplication::keyboardModifiers() == Qt::ShiftModifier;
	if (shiftPressed)
		endPos = proportionalPos(_startPos, endPos);

	QRectF ellipse = QRectF(_startPos, endPos).normalized();
	ellipseItem->setRect(ellipse);

	Tool::onMouseMove(pos);
}
