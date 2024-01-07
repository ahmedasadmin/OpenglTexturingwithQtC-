#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)

{

    setSurfaceType(QWindow::OpenGLSurface);
    QSurfaceFormat format;
    format.setProfile(QSurfaceFormat::CompatibilityProfile);
    format.setVersion(2, 8);
    setFormat(format);


    context = new QOpenGLContext;
    context->setFormat(format);
    context->create();
    context->makeCurrent(this);
    openGLFunctions = context->functions();

    QTimer *timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this,
           SLOT(updateAnimation()));
    timer->start(100);
    rotation = 0;

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::initializeGL()
{
    // enable z-buffer depth Test
    glEnable(GL_DEPTH_TEST);
    // enable texturing
    glEnable(GL_TEXTURE_2D);
    QImage image("brick");
    QImage texture = QGLWidget::convertToGLFormat(image);
    glGenTextures(1, &texID[0]);
    glBindTexture(GL_TEXTURE_2D, texID[0]);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, texture.width(), texture.height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, texture.bits());

    resizeGL(this->width(), this->height());
}

void MainWindow::resizeGL(int w, int h)
{
    // Set the viewport
    glViewport(0, 0, w, h);
    qreal aspectRatio = qreal(w) / qreal(h);
    // Initialize Projection Matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

//    glOrtho(-1 * aspectRatio, 1 * aspectRatio, -1, 1, 1, -1);
    gluPerspective(75, aspectRatio, 0.1, 400000000);

    // Initialize Model View
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void MainWindow::paintGL()
{
    // Initialize clear color (cornflower blue)
//    glClearColor(0.39f, 0.85f, 0.93f, 1.f);
//    glClear(GL_COLOR_BUFFER_BIT);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // gl render quad
//    glBegin(GL_QUADS);
//    glVertex2f(-0.5f, -0.5f);
//    glVertex2f(0.5f, -0.5f);
//    glVertex2f(0.5f, 0.5f);
//    glVertex2f(-0.5f, 0.5f);
//    glEnd();

//    glBegin(GL_QUADS);
//    glColor3f(1.f, 0.f, 0.f); glVertex2f(-0.8f, -0.8f);
//    glColor3f(1.f, 1.f, 0.f); glVertex2f(0.3f, -0.8f);
//    glColor3f(0.f, 1.f, 0.f); glVertex2f(0.3f, 0.3f);
//    glColor3f(0.f, 0.f, 1.f); glVertex2f(-0.8f, 0.3f);
//    glEnd();

//    glBegin(GL_TRIANGLES);
//    glColor3f(1.f, 0.f, 0.f); glVertex2f(-0.4f, -0.4f);
//    glColor3f(0.f, 1.f, 0.f); glVertex2f(0.8f, -0.1f);
//    glColor3f(0.f, 0.f, 1.f); glVertex2f(-0.1f, 0.8f);
//    glEnd();

    // Reset model view..


    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();


    // Transformations
    glTranslatef(0.0, 0.0, -3.0);
    glRotatef(rotation, 1.0, 1.0, 1.0);
//    //FRONT
//    glBegin(GL_POLYGON);
//    glColor3f(0.0, 0.0, 0.0);
//    glVertex3f(0.5, -0.5, -0.5); glVertex3f(0.5, 0.5, -0.5);
//    glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);
//    glEnd();

//    //BACK
//    glBegin(GL_POLYGON);
//    glColor3f(0.0, 0.1, 0.0);
//    glVertex3f(0.5, -0.5, 0.5); glVertex3f(0.5, 0.5, 0.5);
//    glVertex3f(-0.5, 0.5, 0.5); glVertex3f(-0.5, -0.5, 0.5);
//    glEnd();
//    // RIGHT
//    glBegin(GL_POLYGON);
//    glColor3f(1.0, 0.0, 1.0);
//    glVertex3f(0.5, -0.5, -0.5); glVertex3f(0.5, 0.5, -0.5);
//    glVertex3f(0.5, 0.5, 0.5); glVertex3f(0.5, -0.5, 0.5);
//    glEnd();
//    // LEFT
//    glBegin(GL_POLYGON);
//    glColor3f(1.0, 1.0, 0.0);
//    glVertex3f(-0.5, -0.5, 0.5); glVertex3f(-0.5, 0.5, 0.5);
//    glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, -0.5, -0.5);
//    glEnd();

//    // TOP
//    glBegin(GL_POLYGON);
//    glColor3f(0.0, 0.0, 1.0);
//    glVertex3f(0.5, 0.5, 0.5); glVertex3f(0.5, 0.5, -0.5);
//    glVertex3f(-0.5, 0.5, -0.5); glVertex3f(-0.5, 0.5, 0.5);
//    glEnd();

//    //BOTTOM
//    glBegin(GL_POLYGON);
//    glColor3f(1.0, 0.0, 0.0);
//    glVertex3f(0.5, -0.5, -0.5); glVertex3f(0.5, -0.5, 0.5);
//    glVertex3f(-0.5, -0.5, 0.5); glVertex3f(-0.5, -0.5, -0.5);
//    glEnd();


    glEnable(GL_TEXTURE_2D);
    glBindTexture(GL_TEXTURE_2D, texID[0]);
    // FRONT
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();

    // BACK
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, -0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, -0.5, 0.5);
    glEnd();
    // RIGHT
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(0.5, -0.5, -0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, -0.5, 0.5);
    glEnd();
    // LEFT
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, 0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    // TOP
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(1.0f, 0.0f); glVertex3f(0.5, 0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, 0.5, -0.5);
    glTexCoord2f(0.0f, 0.0f); glVertex3f(-0.5, 0.5, 0.5);
    glEnd();
    // Red side - BOTTOM
    glBegin(GL_POLYGON);
    glColor3f(1.0, 1.0, 1.0);
    glTexCoord2f(0.0f, 0.0f); glVertex3f( 0.5, -0.5, -0.5);
    glTexCoord2f(1.0f, 0.0f); glVertex3f( 0.5, -0.5, 0.5);
    glTexCoord2f(1.0f, 1.0f); glVertex3f(-0.5, -0.5, 0.5);
    glTexCoord2f(0.0f, 1.0f); glVertex3f(-0.5, -0.5, -0.5);
    glEnd();
    glDisable(GL_TEXTURE_2D);

    glFlush();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    resizeGL(this->width(), this->height());
    this->update();
}

void MainWindow::PaintEvent(QPaintEvent *event)
{
    paintGL();
}

void MainWindow::updateAnimation()
{
    rotation += 10;
    this->update();
}






