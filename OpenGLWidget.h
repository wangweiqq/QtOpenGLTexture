#pragma once

#include <QOpenGLWidget>
//#include "ui_OpenGLWidget.h"

class OpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	OpenGLWidget(QWidget *parent = Q_NULLPTR);
	~OpenGLWidget();
protected:
	void initializeGL()override;
	void paintGL()override;
	void resizeGL(int w, int h)override;
	void timerEvent(QTimerEvent *event)override;
private:
	//Ui::OpenGLWidget ui;
	GLfloat xRot, yRot, zRot;
	GLuint texture[1];
};
