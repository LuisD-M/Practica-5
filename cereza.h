#ifndef CEREZA_H
#define CEREZA_H

#include <QGraphicsItem>
#include <QPainter>
#include <QPixmap>
#include <QObject>

class Cereza  : public QGraphicsItem, public QObject
{
    int w, h, posx, posy;

public:
    Cereza(int w, int h, int x, int y);

    float filas, columnas, ancho, alto;                      //Disposicion de la imagen

    QPixmap *pixmap3;
    QRectF boundingRect() const;                            //delimitador de la moneda
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // CEREZA_H
