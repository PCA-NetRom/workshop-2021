#include "PaintController.h"

#include <QtWidgets/QGraphicsLineItem>
#include <QtCore/qdebug.h>

static const QString kSelectTool	= "selectTool";
static const QString kPenTool		= "penTool";
static const QString kLineTool		= "lineTool";
static const QString kRectangleTool = "rectangleTool";
static const QString kEllipseTool	= "ellipseTool";

static const QString kLineThicknessAction	= "lineThicknessAction";
static const QString kColorAction			= "colorAction";

PaintController::PaintController(QObject *parent, PaintView* view)
	: QObject(parent),
	_view(view),
	_selectedTool("")
{
}

void PaintController::onMousePress(const QPointF& pos, const Qt::MouseButtons& buttons)
{
	if (_selectedTool == kLineTool)
		_line = _view->createLine(QLineF(pos, pos));
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

void PaintController::onActionSelectTriggered()
{
	qDebug() << "action Select triggered";
	_selectedTool = kSelectTool;
}

void PaintController::onActionPenTriggered()
{
	qDebug() << "action Pen triggered";
	_selectedTool = kPenTool;
}

void PaintController::onActionLineTriggered()
{
	qDebug() << "action Line triggered";
	_selectedTool = kLineTool;
}

void PaintController::onActionRectangleTriggered()
{
	qDebug() << "action Rectangle triggered";
	_selectedTool = kRectangleTool;
}

void PaintController::onActionEllipseTriggered()
{
	qDebug() << "action Ellipse triggered";
	_selectedTool = kEllipseTool;
}