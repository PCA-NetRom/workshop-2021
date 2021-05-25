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

QPointF Tool::proportionalPos(const QPointF& startPos, const QPointF& endPos)
{
	QPointF posDiff = endPos - startPos;
	float minSideLen = qMin(qAbs(posDiff.x()), qAbs(posDiff.y()));

	QPointF proportionalPos;
	proportionalPos.setX(startPos.x() + (endPos.x() > startPos.x() ? minSideLen : -minSideLen));
	proportionalPos.setY(startPos.y() + (endPos.y() > startPos.y() ? minSideLen : -minSideLen));

	return proportionalPos;
}