#pragma once

#include <QtWidgets/QDialog>
#include "ui_QtGuiApplication2.h"
#include "OpenGLWidget.h"
class QtGuiApplication2 : public QDialog
{
	Q_OBJECT

public:
	QtGuiApplication2(QWidget *parent = Q_NULLPTR);

private:
	Ui::QtGuiApplication2Class ui;
	OpenGLWidget* widget = nullptr;
};
