#pragma once

#include <QtWidgets/QGraphicsView>
#include <QtWidgets/qpushbutton.h>
#include <QtWidgets/qcolordialog.h>
#include <QtWidgets/qinputdialog.h>
#include <QtWidgets/qlabel.h>


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
	void				buttonSelect(int id);
	void				penColorChange(const QColor& color);
	void				penWidthChange(const int& width); 
private:
	void				mousePressEvent(QMouseEvent* event) override;
	void				mouseMoveEvent(QMouseEvent* event) override;
	void				mouseReleaseEvent(QMouseEvent* event) override;
	QPen 				getPen();

public slots:
	void  clickLineButton();
	void  clickDrawButton();

	void  clickPenColorButton();
	void  clickPenWidthButton();


private:
	QGraphicsScene* _scene;

	QPushButton* _lineButton;
	QPushButton* _drawButton;
	QPushButton* _penColorButton;
	QPushButton* _penWidthButton;

	QColorDialog* _penColorDialog;
	QInputDialog* _penWidthDialog;

	QLabel* _mousePosLable;

	QPen* _pen;



};				
