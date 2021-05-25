#ifndef TOOL_H
#define TOOL_H

#include "PaintView.h"

enum class ToolType
{
	ePen,
	eLine,
	eRectangle,
	eEllipse,
	eSelect
};

class Tool
{
public:
					Tool(PaintView* view);

	virtual void	onMousePress(const QPointF& pos);
	virtual void	onMouseMove(const QPointF& pos);
	virtual void	onMouseRelease(const QPointF& pos);

protected:
	QPointF			proportionalPos(const QPointF& startPos, const QPointF& endPos);

protected:
	PaintView*		_view;
	QGraphicsItem*	_graphicsItem;

	QPointF			_startPos;
	QPointF			_previousPos;
};

#endif