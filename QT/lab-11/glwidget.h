#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QOpenGLWidget>
#include <QOpenGLFunctions>

class GLWidget : public QOpenGLWidget, protected QOpenGLFunctions
{
    Q_OBJECT

public:
    explicit GLWidget(QWidget *parent = nullptr);

protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int w, int h) override;

public slots:
    void moveBall();

private:
    float xBall, yBall;   // Координаты центра шарика
    float dx, dy;         // Шаг движения
    float radius;         // Радиус шарика
};

#endif // GLWIDGET_H