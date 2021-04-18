#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtWidgets/QMainWindow>

#include "PaintView.h"
#include "PaintController.h"
#include "ui_painttest.h"
#include <QtGui/QMouseEvent>
#include <QtWidgets/QFileDialog>
#include <QtWidgets/QColorDialog>
#include <QtWidgets/QInputDialog>
#include <QtWidgets/QMessageBox>



class MainWindow : public QMainWindow
{
	Q_OBJECT
public:
							MainWindow(QWidget* parent = 0, Qt::WindowFlags flags = 0);


private:
	Ui::PaintTest			_ui;

	PaintView*				_view;
	PaintController*		_controller;


};

#endif // MAINWINDOW_H
