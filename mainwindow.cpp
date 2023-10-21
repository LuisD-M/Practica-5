#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) // configurar la interfaz de la ventana principal


{
    ui->setupUi(this);
    QRect Desktop = QApplication::desktop()->screenGeometry();
    x = Desktop.x();
    y = Desktop.y();
    ancho = Desktop.width();
    alto=Desktop.height();


    scene = new QGraphicsScene(x,y,ancho,alto);
    scene->setSceneRect(0,0,540,600);                    //Se crea la ventana de escena con tamaño 540X600
    scene->setBackgroundBrush(QBrush(Qt::black));       //Pone fondo de la escena negro


    ui->graphicsView->setScene(scene);

    personaje = new sprite();                           // crear Pacman
    scene->addItem(personaje);                         //Añade a la escena
    personaje->setPos(20,20);                         //Poscicion de la escena

    int wi, hi, xi, yi;                               //leen los parametros dde cada bloque
    string linea;

    ifstream archivo("muros.txt");

    while (getline(archivo, linea)) {
        stringstream ss(linea);
        string valor;

        if (getline(ss, valor, ',')) wi = stoi(valor);
        if (getline(ss, valor, ',')) hi = stoi(valor);
        if (getline(ss, valor, ',')) xi = stoi(valor);
        if (getline(ss, valor, ',')) yi = stoi(valor);

        muro.push_back(new muros(wi,hi,xi,yi));
        scene->addItem(muro.back());
    }
}

void MainWindow::keyPressEvent(QKeyEvent *event){

    if(event->key()==Qt::Key_W){
        personaje->MoveUp();                  // mover sprite hacia arriba
        personaje->setRotation(270);          // mirar hacia arriba
        //qDebug()<<personaje->y();
    }

    else if(event->key()==Qt::Key_S){
        personaje->MoveDown();
        personaje->setRotation(90);
    }

    else if(event->key()==Qt::Key_A){
        personaje->MoveLeft();
        personaje->setRotation(180);
    }

    else if(event->key()==Qt::Key_D){
        personaje->MoveRight();
        personaje->setRotation(0);

    }
}





MainWindow::~MainWindow(){
    delete ui;
}

