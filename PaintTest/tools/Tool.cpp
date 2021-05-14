#include "Tool.h"

Tool::Tool(PaintView* view):
	_view(view)
{
}

void Tool::onMousePress(const QPointF& pos)
{
	_startPos = pos;
	_previousPos = pos;
}

void Tool::onMouseMove(const QPointF& pos)
{
	_previousPos = pos;
}

void Tool::onMouseRelease(const QPointF& pos)
{
	_graphicsItem = nullptr;
	_startPos = QPointF();
}
