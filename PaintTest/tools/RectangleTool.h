#ifndef RECTANGLETOOL_H
#define RECTANGLETOOL_H

#include "Tool.h"

class RectangleTool : public Tool
{
public:
					RectangleTool(PaintView* view);

	void			onMousePress(const QPointF& pos) override;
	void			onMouseMove(const QPointF& pos) override;
};

#endif // RECTANGLETOOL_H

