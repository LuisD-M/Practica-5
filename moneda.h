#ifndef MONEDA_H
#define MONEDA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QObject>

class moneda : public QGraphicsItem, public QObject
{
    int w, h, posx, posy;

public:
    moneda(int w, int h, int x, int y);

    float filas, columnas, ancho, alto;                      //Disposicion de la imagen

    QPixmap *pixmap2;
    QRectF boundingRect() const;                            //delimitador de la moneda
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);

};

#endif // MONEDA_H
