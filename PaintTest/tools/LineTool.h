#ifndef LINETOOL_H
#define LINETOOL_H

#include "Tool.h"

class LineTool : public Tool
{
public:
	LineTool(PaintView* view);
	void onMousePress(const QPointF& pos) override;
	void onMouseMove(const QPointF& pos) override;
};

#endif