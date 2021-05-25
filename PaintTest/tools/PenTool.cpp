#include "PenTool.h"

#include <QtWidgets/QGraphicsItem>

PenTool::PenTool(PaintView* view) : 
	Tool(view)
{
}

void PenTool::onMousePress(const QPointF& pos)
{
	Tool::onMousePress(pos);

	QPainterPath path(_startPos);		// TODO: Causes problem, starts from (0, 0)
	path.moveTo(pos);

	_graphicsItem = _view->createPath(path);
}

void PenTool::onMouseMove(const QPointF& pos)
{
	QGraphicsPathItem* pathItem = dynamic_cast<QGraphicsPathItem*>(_graphicsItem);
	if (!pathItem)
		return;

	QPainterPath path = pathItem->path();
	path.lineTo(pos);
	pathItem->setPath(path);

	Tool::onMouseMove(pos);
}
