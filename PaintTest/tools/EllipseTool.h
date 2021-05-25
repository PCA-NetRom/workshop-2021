#ifndef ELLIPSETOOL_H
#define ELLIPSETOOL_H

#include "Tool.h"

class EllipseTool : public Tool
{
public:
					EllipseTool(PaintView* view);

	void			onMousePress(const QPointF& pos) override;
	void			onMouseMove(const QPointF& pos) override;
};

#endif // ELLIPSETOOL_H

