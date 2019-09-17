#pragma once

#include <QOpenGLWidget>
//#include "ui_OpenGLWidget.h"

class OpenGLWidget : public QOpenGLWidget
{
	Q_OBJECT

public:
	OpenGLWidget(QWidget *parent = Q_NULLPTR);
	~OpenGLWidget();
	void loadGLTexture();
protected:
	void initializeGL()override;
	void paintGL()override;
	void resizeGL(int w, int h)override;
	void timerEvent(QTimerEvent *event)override;
private:
	//Ui::OpenGLWidget ui;
	GLfloat xRot = 0, yRot = 0, zRot = 0;
	GLuint texture[1];
};
