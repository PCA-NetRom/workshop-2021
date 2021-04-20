#pragma once

#include <QtWidgets/QGraphicsView>

class PaintView : public QGraphicsView
{
	Q_OBJECT
public:
						PaintView(QWidget *parent);
						~PaintView();

	QGraphicsLineItem*	createLine(const QLineF& line);

signals:
	void				mousePress(const QPoint& pos, const Qt::MouseButtons& buttons);
	void				mouseMove(const QPoint& pos, const Qt::MouseButtons& buttons);
	void				mouseRelease(const QPoint& pos, const Qt::MouseButtons& buttons);

private:
	void				mousePressEvent(QMouseEvent* event) override;
	void				mouseMoveEvent(QMouseEvent* event) override;
	void				mouseReleaseEvent(QMouseEvent* event) override;

private:
	QGraphicsScene*	_scene;
};				
