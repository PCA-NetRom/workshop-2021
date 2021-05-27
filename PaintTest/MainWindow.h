#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>
#include <QColorDialog.h>

#include "PaintView.h"
#include "PaintController.h"
#include "ui_painttest.h"

#include "tools/Tool.h"

class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
				MainWindow(QWidget* parent = 0, Qt::WindowFlags flags = 0);

protected slots:
	void		onMouseMove(const QPointF& pos, const Qt::MouseButtons& buttons);
	void		onColorSelected(const QColor& color);
	void		onToolSelected(const ToolType type);

private slots:
	void		clearScene();
	void		saveScene();
	void		openScene();

private:
	void		initView();
	void		initController();

	void		initLeftToolbar();
	void		initTopToolbar();

private:
	Ui::PaintTest		_ui;

	PaintView*			_view;
	PaintController*	_controller;

	QToolBar*			_topToolBar;
	QColorDialog*		_colorDialog;
	QAction*			_actionColor;
};

#endif // MAINWINDOW_H
