#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) // configurar la interfaz de la ventana principal
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)

{
    ui->setupUi(this);
    QRect Desktop = QApplication::desktop()->screenGeometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = Desktop.width();
    alto=Desktop.height();

    // Crear la escena rectangular utilizando con las coordenadas (0,0) como origen y un tamaño de 540x600
    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setSceneRect(0,0,540,600);
    scene->setBackgroundBrush(QBrush(Qt::black));


    ui->graphicsView->setScene(scene);

    personaje = new sprite();                                    // crear Pacman

    scene->addItem(personaje);
    personaje->setPos(20,20);

}


MainWindow::~MainWindow()
{
    delete ui;
}

