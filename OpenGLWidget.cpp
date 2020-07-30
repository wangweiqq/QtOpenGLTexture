#include "OpenGLWidget.h"
#include <gl/GLU.h>
#include <QDebug>
#include <math.h>
#include <QGLWidget>
//#define _USE_MATH_DEFINES
OpenGLWidget::OpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	//ui.setupUi(this);
}

OpenGLWidget::~OpenGLWidget()
{
}
void OpenGLWidget::timerEvent(QTimerEvent *event)
{
	xRot += 0.3;
	yRot += 0.2;
	zRot += 0.4;
	this->update();
}
void OpenGLWidget::loadGLTexture() {
	QImage tex, buf;
	if (!buf.load("./NeHe.bmp")) {
		QImage dummy(128, 128, QImage::Format_RGB32);
		dummy.fill(Qt::green);
		buf = dummy;
	}
	tex = QGLWidget::convertToGLFormat(buf);
	glGenTextures(1, &texture[0]);
	glBindTexture(GL_TEXTURE_2D, texture[0]);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, tex.width(), tex.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, tex.bits());
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, GL_LINEAR);
}
void OpenGLWidget::initializeGL() {
	loadGLTexture();
	glEnable(GL_TEXTURE_2D);
	//GL_FLAT;
	glShadeModel(GL_SMOOTH);
	//背景白色
	glClearColor(0, 0, 0, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
	this->startTimer(20);
}
struct Vertex3f {
	GLfloat x, y, z;
};
void OpenGLWidget::paintGL() {
	qDebug() << QString("paintGL xRot = %1,yRot = %2,zRot = %3").arg(xRot).arg(yRot).arg(zRot);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);	
	glLoadIdentity();
	
	glBindTexture(GL_TEXTURE_2D, texture[0]);

	glTranslatef(0, 0, -5);
	glRotatef(xRot, 1.0, 0.0, 0.0);
	glRotatef(yRot, 0.0, 1.0, 0.0);
	glRotatef(zRot, 0.0, 0.0, 1.0);
	glEnableClientState(GL_VERTEX_ARRAY);
	//注意描点要逆时针(起始点为直角边，第3点为斜边)
	/*Vertex3f vertices[] = {
		{1.0,1.0,-1.0},
		{-1.0,1.0,-1.0},
		{1.0,-1.0,-1.0},
		{-1.0,-1.0,-1.0}
	};
	glVertexPointer(3, GL_FLOAT, 0, vertices);
	glDrawArrays(GL_TRIANGLE_STRIP, 0,  sizeof(vertices)/sizeof(vertices[0]));*/
	
	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(1.0, 0.0, 0.0);
	//后面
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(0.0, 1.0, 0.0);
	//前面
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);	
	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);	
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(0.0, 0.0, 1.0);
	//左面
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(1.0, 1.0, 0.0);
	//右面
	glTexCoord2f(0.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(1.0, 0.0, 1.0);
	//上面
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, 1.0, 1.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	//glColor3f(0.0, 1.0, 1.0);
	//底面
	glTexCoord2f(0.0, 1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glTexCoord2f(0.0, 0.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glTexCoord2f(1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glTexCoord2f(1.0, 0.0);
	glVertex3f(1.0, -1.0, 1.0);
	glEnd();
}
void OpenGLWidget::resizeGL(int w, int h) {
	if (h == 0) {
		h = 1;
	}
	glViewport(0, 0, w, h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, (GLdouble)w / h,0.1, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}