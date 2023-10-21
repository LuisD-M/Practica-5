#include "cereza.h"

Cereza::Cereza(int w, int h, int x, int y)
{
    this->w = w;
    this->h = h;
    this->posx = x;
    this->posy = y;

    filas=0;
    columnas=0;

    pixmap3 = new QPixmap(":/images/Cereza.png");

    ancho=101;
    alto=110;

    setPos(posx,posy);
}

QRectF Cereza::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void Cereza::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap3,columnas,filas,ancho,alto);
    setScale(0.21);
}
