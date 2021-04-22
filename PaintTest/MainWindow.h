#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QtWidgets/qcolordialog.h>

#include "PaintView.h"
#include "PaintController.h"
#include "ui_painttest.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
						MainWindow(QWidget* parent = 0, Qt::WindowFlags flags = 0);

public slots:
	void				onColorChanged(const QColor& color);
	void				onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);

private:
	void				initLeftToolBar();
	void				initTopToolBar();

private:
	Ui::PaintTest			_ui;

	PaintView*				_view;
	PaintController*		_controller;

	QColorDialog*			_colorDialog;
	QToolBar*				_topToolBar;
	QAction*				_actionColor;
};

#endif // MAINWINDOW_H
