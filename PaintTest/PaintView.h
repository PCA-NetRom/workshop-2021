#pragma once

#include <QtWidgets/QGraphicsView>

class PaintView : public QGraphicsView
{
	Q_OBJECT
public:
						PaintView(QWidget *parent);

	QGraphicsPathItem*		createPath(const QPainterPath& path);
	QGraphicsLineItem*		createLine(const QLineF& line);
	QGraphicsRectItem*		createRectangle(const QRectF& rectangle);
	QGraphicsEllipseItem*	createEllipse(const QRectF& ellipse);
	QGraphicsItem*			itemAt(const QPointF& pos);

public slots:
	void				onActionLineThicknessTriggered(const QString& lineThickness);
	void				onColorSelected(const QColor& color);

signals:
	void				mousePress(const QPointF& pos, const Qt::MouseButtons& buttons);
	void				mouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);
	void				mouseRelease(const QPointF& pos, const Qt::MouseButtons& buttons);

private:
	void				initScene();

	void				mousePressEvent(QMouseEvent* event) override;
	void				mouseMoveEvent(QMouseEvent* event) override;
	void				mouseReleaseEvent(QMouseEvent* event) override;

private:
	QGraphicsScene*	_scene;

	QPen			_pen;
	QBrush			_brush;
};				
