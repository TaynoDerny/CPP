#include "glwidget.h"
#include <QtOpenGL>
#include <cmath>

GLWidget::GLWidget(QWidget *parent) : QOpenGLWidget(parent)
{
    xBall = 0.0f;
    yBall = 0.0f;
    dx = 0.02f;    // Скорость по X
    dy = 0.03f;    // Скорость по Y
    radius = 0.15f;
}

void GLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f); // Темно-серый фон
    glShadeModel(GL_SMOOTH);
}

void GLWidget::resizeGL(int w, int h)
{
    if (h == 0) h = 1;
    glViewport(0, 0, w, h);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-1.0f, 1.0f, -1.0f, 1.0f, -1.0f, 1.0f);
    glMatrixMode(GL_MODELVIEW);
}

void GLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glLoadIdentity();

    glBegin(GL_LINE_LOOP);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(-1.0f, -1.0f);
    glVertex2f( 1.0f, -1.0f);
    glVertex2f( 1.0f,  1.0f);
    glVertex2f(-1.0f,  1.0f);
    glEnd();

    // Отрисовка шарика
    glTranslatef(xBall, yBall, 0.0f);

    glBegin(GL_TRIANGLE_FAN); // Рисуем круг веером
    glColor3f(1.0f, 0.0f, 0.0f); // Красный шарик
    glVertex2f(0.0f, 0.0f);      // Центр
    int numSegments = 100;
    for (int i = 0; i <= numSegments; i++) {
        float angle = 2.0f * 3.14159f * float(i) / float(numSegments);
        float x = radius * cosf(angle);
        float y = radius * sinf(angle);
        glVertex2f(x, y);
    }
    glEnd();
}

void GLWidget::moveBall()
{
    xBall += dx;
    yBall += dy;

    if (xBall + radius > 1.0f || xBall - radius < -1.0f)
        dx = -dx;

    if (yBall + radius > 1.0f || yBall - radius < -1.0f)
        dy = -dy;

    update(); // Перерисовываем кадр
}