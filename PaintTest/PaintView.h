#pragma once
#include <string>
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
	void				buttonSelect(std::string buttonName);
	void				penColorChange(const QColor& color);
	void				penWidthChange(const int& width); 
	void				spaceKeyHeldDown(const Qt::Key& keyPressed);
	void				spaceKeyRelease(const Qt::Key& keyPressed);

private:
	void				mousePressEvent(QMouseEvent* event) override;
	void				mouseMoveEvent(QMouseEvent* event) override;
	void				mouseReleaseEvent(QMouseEvent* event) override;
	void				keyPressEvent(QKeyEvent* event) override;
	void				keyReleaseEvent(QKeyEvent* event) override;
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
