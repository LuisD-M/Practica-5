#ifndef PUNTAJE_H
#define PUNTAJE_H

#include <QObject>
#include <QGraphicsTextItem>
#include <QGraphicsItem>
#include <QGraphicsScene>


class puntaje : public QGraphicsTextItem
{
public:
    puntaje(QGraphicsItem *parent=nullptr);
    void increaseMoneda();                           //Puntuacion para las monedas
    void increaseCereza();                           //Puntuacion para las cerezas

    int getpuntaje();                               //Obtener puntaje

private:
    int puntuacion;

};

#endif // PUNTAJE_H
