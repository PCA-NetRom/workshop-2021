#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>
#include <QtCore/qdebug.h>

const QString kLineTool = "lineTool";
const QString kSelectTool = "selectTool";


PaintController::PaintController(QObject *parent, PaintView* view)
	: QObject(parent),
	_view(view),
	_selectedTool("")
{
}

PaintController::~PaintController()
{
}

void PaintController::onActionSelect()
{
	qDebug() << "Action select triggered";
	_selectedTool = kSelectTool;
}

void PaintController::onActionLine()
{
	qDebug() << "Action line triggered";
	_selectedTool = kLineTool;
}

void PaintController::onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (_selectedTool == kLineTool)
	{
		_line = _view->createLine(QLineF(pos, pos));
	}
}

void PaintController::onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (buttons != Qt::MouseButton::LeftButton)
		return;

	if (_selectedTool == kLineTool)
	{
		QLineF line = _line->line();
		line.setP2(pos);
		_line->setLine(line);
	}
}

void PaintController::onMouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons)
{
}
