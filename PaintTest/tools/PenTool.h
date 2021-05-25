#ifndef PENTOOL_H
#define PENTOOL_H

#include "Tool.h"

class PenTool : public Tool
{
public:
					PenTool(PaintView* view);

	void			onMousePress(const QPointF& pos) override;
	void			onMouseMove(const QPointF& pos) override;
};

#endif // PENTOOL_H

