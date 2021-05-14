#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>
#include <QtCore/qdebug.h>

#include "tools/LineTool.h"
#include "tools/SelectTool.h"


PaintController::PaintController(QObject *parent, PaintView* view)
	: QObject(parent),
	_view(view)
{
}

void PaintController::onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	_currentTool->onMousePress(pos);
}

void PaintController::onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	_currentTool->onMouseMove(pos);
}

void PaintController::onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	_currentTool->onMouseRelease(pos);
}

void PaintController::onToolSelected(ToolType type)
{
	switch (type)
	{
	case ToolType::eLine:
		_currentTool = std::make_shared<LineTool>(_view);
		break;
	case ToolType::eSelect:
		_currentTool = std::make_shared<SelectTool>(_view);
		break;
	default:
		break;
	}
}