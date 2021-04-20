#pragma once

#include <QtCore/QObject>

#include "PaintView.h"

class PaintController : public QObject
{
	Q_OBJECT

public:
					PaintController(QObject *parent, PaintView* view);
					~PaintController();

protected slots:
	void			onMousePress(const QPoint& pos, const Qt::MouseButtons& buttons);
	void			onMouseMove(const QPoint& pos, const Qt::MouseButtons& buttons);
	void			onMouseRelease(const QPoint& pos, const Qt::MouseButtons& buttons);
	void			onButtonSelect(std::string buttonName);
	void			onSpaceKeyHeldDown(const Qt::Key& keyPressed);
	void			onSpaceKeyRelease(const Qt::Key& keyPressed);

private:
	PaintView*			_view;

	QGraphicsLineItem*	_line;

	QPoint _point;

	std::string _option;

	bool _scribbling;
	bool _spaceKeyHeldDown;

};
