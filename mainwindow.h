#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QOpenGLWindow>
#include <QSurfaceFormat>
#include <QtOpenGL>
#include <GL/glu.h>
#include <QTimer>
#include <QGLWidget>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QOpenGLWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QOpenGLContext* context;
    QOpenGLFunctions* openGLFunctions;
    float rotation;
    GLuint texID[1];
protected:
    virtual void initializeGL();
    virtual void resizeGL(int w, int h);
    virtual void paintGL();
    void resizeEvent (QResizeEvent *event);
    void PaintEvent(QPaintEvent *event);
public slots:
    void updateAnimation();

};
#endif // MAINWINDOW_H
