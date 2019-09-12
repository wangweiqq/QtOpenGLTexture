#include "OpenGLWidget.h"
#include <gl/GLU.h>
OpenGLWidget::OpenGLWidget(QWidget *parent)
	: QOpenGLWidget(parent)
{
	//ui.setupUi(this);
}

OpenGLWidget::~OpenGLWidget()
{
}
void OpenGLWidget::initializeGL() {
	//GL_FLAT;
	glShadeModel(GL_SMOOTH);
	//背景白色
	glClearColor(0, 0, 0, 1);
	glClearDepth(1.0);
	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LEQUAL);
	glHint(GL_PERSPECTIVE_CORRECTION_HINT,GL_NICEST);
}
struct Vertex3f {
	GLfloat x, y, z;
};
void OpenGLWidget::paintGL() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glLoadIdentity();
	
	glTranslatef(0, 0, -10);
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
	glColor3f(1.0, 0.0, 0.0);
	//后面
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();

	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 1.0, 0.0);
	//前面
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 0.0, 1.0);
	//左面
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, -1.0, -1.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0, 1.0, 0.0);
	//右面
	glVertex3f(1.0, 1.0, 1.0);
	glVertex3f(1.0, -1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, -1.0, -1.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(1.0, 0.0, 1.0);
	//上面
	glVertex3f(-1.0, 1.0, -1.0);
	glVertex3f(-1.0, 1.0, 1.0);
	glVertex3f(1.0, 1.0, -1.0);
	glVertex3f(1.0, 1.0, 1.0);
	glEnd();
	glBegin(GL_TRIANGLE_STRIP);
	glColor3f(0.0, 1.0, 1.0);
	//底面
	glVertex3f(-1.0, -1.0, -1.0);
	glVertex3f(-1.0, -1.0, 1.0);
	glVertex3f(1.0, -1.0, -1.0);
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
	gluPerspective(45, (GLdouble)w / h,0, 100);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}