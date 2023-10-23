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
    archivo.close();

    ifstream in("monedas.txt");

    while (getline(in, linea)) {
        stringstream ss(linea);
        string valor;

        if (getline(ss, valor, ',')) wi = stoi(valor);
        if (getline(ss, valor, ',')) hi = stoi(valor);
        if (getline(ss, valor, ',')) xi = stoi(valor);
        if (getline(ss, valor, ',')) yi = stoi(valor);

        monedas.push_back(new moneda(wi,hi,xi,yi));
        scene->addItem(monedas.back());
    }
    in.close();

    ifstream cer("cereza.txt");

    while (getline(cer, linea)) {
        stringstream ss(linea);
        string valor;

        if (getline(ss, valor, ',')) wi = stoi(valor);
        if (getline(ss, valor, ',')) hi = stoi(valor);
        if (getline(ss, valor, ',')) xi = stoi(valor);
        if (getline(ss, valor, ',')) yi = stoi(valor);

        cerezas.push_back(new Cereza(wi,hi,xi,yi));
        scene->addItem(cerezas.back());
    }
    cer.close();

    personaje = new sprite();                           // crear Pacman
    scene->addItem(personaje);                         //Añade a la escena
    personaje->setPos(20,20);                         //Poscicion de la escena

    puntos = new puntaje;                            //añade puntaje
    scene->addItem(puntos);
    puntos->setPos(-160,-20);

    final = new fin;
    final->setPos(-120,270);

}

void MainWindow::keyPressEvent(QKeyEvent *event){

    if(personaje->x() < -20)                                        //Si se sale por la izquierda, inicia en la derecha
        personaje->setPosx(560);

    if(personaje -> x() > 560)                                     //Si se sale por la derecha, inicia en la izquierda
        personaje->setPosx(20);

    for(int i=0; i<monedas.size(); i++){                            //Colision de con las monedas y desaparecen
        if(personaje->collidesWithItem(monedas.at(i))){
            scene->removeItem(monedas.at(i));                         //Eliminar de la escena la moneda
            monedas.removeAt(i);
            puntos->increaseMoneda();
        }
    }

    for(int i=0; i<cerezas.size(); i++){                             //Colision con las cerezas
        if(personaje->collidesWithItem(cerezas.at(i))){
            scene->removeItem(cerezas.at(i));                        //eliminar cereza de la escena
            cerezas.removeAt(i);
            puntos->increaseCereza();
        }
    }

    if(puntos->getpuntaje() == 314){
        scene->removeItem(personaje);
        scene->addItem(final);
    }



    if(event->key()==Qt::Key_W){
        personaje->MoveUp();                                                          // mover sprite hacia arriba
        personaje->setRotation(-90);                                                  // mirar hacia arriba

        for(auto it = muro.begin(); it != muro.end(); it++){                          //recorre la lista de los muros
            if(personaje -> collidesWithItem(*it))                                    //Si las possiciones son iguales
                personaje -> MoveDown();                                              //Mueve al contrario
        }
    }

    else if(event->key()==Qt::Key_S){
        personaje->MoveDown();                                                       //Mover haccia abajo
        personaje->setRotation(90);

        for(auto it = muro.begin(); it != muro.end(); it++){
            if(personaje -> collidesWithItem(*it))
                personaje -> MoveUp();                                              //Mueve al contrario
        }
    }

    else if(event->key()==Qt::Key_A){
        personaje->MoveLeft();                                                         //Mover a la izquierda
        personaje->setRotation(180);

        for(auto it = muro.begin(); it != muro.end(); it++){
            if(personaje -> collidesWithItem(*it))
                personaje -> MoveRight();                                              //Mueve al contrario
        }
    }

    else if(event->key()==Qt::Key_D){
        personaje->MoveRight();                                                     //Mueve a la derecha
        personaje->setRotation(0);

        for(auto it = muro.begin(); it != muro.end(); it++){
            if(personaje -> collidesWithItem(*it))
                personaje -> MoveLeft();                                              //Mueve al contrario
        }
    }
}


MainWindow::~MainWindow(){
    delete ui;
}

