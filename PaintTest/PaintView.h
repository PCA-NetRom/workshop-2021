#pragma once

#include <QtWidgets/QGraphicsView>
#include <QtGui/qpen.h>
#include <QtGui/qcolor.h>

class PaintView : public QGraphicsView
{
	Q_OBJECT
public:
						PaintView(QWidget *parent);
						~PaintView();

	QGraphicsLineItem*	createLine(const QLineF& line);

signals:
	void				mousePress(const QPointF& pos, const Qt::MouseButtons& buttons);
	void				mouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);
	void				mouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons);

public slots:
	void				onLineThickessChanged(const QString& lineThickness);
	void				onColorChanged(const QColor& color);

private:
	void				mousePressEvent(QMouseEvent* event) override;
	void				mouseMoveEvent(QMouseEvent* event) override;
	void				mouseReleaseEvent(QMouseEvent* event) override;

private:
	QGraphicsScene*	_scene;
	QPen			_pen;
};				
