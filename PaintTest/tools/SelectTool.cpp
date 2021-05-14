#include "SelectTool.h"
#include <QtWidgets/qgraphicsitem.h>

SelectTool::SelectTool(PaintView* view) :
	Tool(view)
{
}

void SelectTool::onMousePress(const QPointF& pos)
{
	_graphicsItem = _view->itemAt(pos);

	Tool::onMousePress(pos);
}

void SelectTool::onMouseMove(const QPointF& pos)
{
	QPointF posDifference = pos - _previousPos;

	if (_graphicsItem)
		_graphicsItem->moveBy(posDifference.x(), posDifference.y());

	Tool::onMouseMove(pos);
}
