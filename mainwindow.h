#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QKeyEvent>
#include <QList>
#include <QObject>
#include <QTimer>
#include <QPixmap>
#include <QRect>
#include <QDesktopWidget>
#include <QDebug>
#include "sprite.h"
#include "muros.h"
#include "moneda.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void keyPressEvent(QKeyEvent * event);

private slots:
private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    sprite *personaje;
    QTimer *timer;
    QList<muros *> muro;
    QList<moneda *> monedas;
    float x,y,ancho,alto;

};
#endif // MAINWINDOW_H
