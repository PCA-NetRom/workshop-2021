#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>
#include <QtCore/qdebug.h>

#include "tools/LineTool.h"
#include "tools/SelectTool.h"
#include "tools/EllipseTool.h"
#include "tools/PenTool.h"
#include "tools/RectangleTool.h"


PaintController::PaintController(QObject *parent, PaintView* view)
	: QObject(parent),
	_view(view)
{
}

void PaintController::onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_currentTool)
		_currentTool->onMousePress(pos);
}

void PaintController::onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_currentTool)
		_currentTool->onMouseMove(pos);
}

void PaintController::onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (_currentTool)
		_currentTool->onMouseRelease(pos);
}

void PaintController::onToolSelected(ToolType type)
{
	switch (type)
	{
	case ToolType::ePen:
		_currentTool = std::make_shared<PenTool>(_view);
		break;
	case ToolType::eLine:
		_currentTool = std::make_shared<LineTool>(_view);
		break;
	case ToolType::eRectangle:
		_currentTool = std::make_shared<RectangleTool>(_view);
		break;
	case ToolType::eEllipse:
		_currentTool = std::make_shared<EllipseTool>(_view);
		break;
	case ToolType::eSelect:
		_currentTool = std::make_shared<SelectTool>(_view);
		break;
	default:
		// TODO: Log error
		break;
	}
}