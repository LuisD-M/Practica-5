#include "moneda.h"

moneda::moneda(int w, int h, int x, int y)
{
    this->w = w;
    this->h = h;
    this->posx = x;
    this->posy = y;

    filas=0;
    columnas=0;

    pixmap2 = new QPixmap(":/images/Coin.png");

    ancho=70;
    alto=62;

    setPos(posx,posy);
}

QRectF moneda::boundingRect() const
{
    return QRectF(-ancho/2, -alto/2, ancho, alto);
}

void moneda::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap2,columnas,filas,ancho,alto);
    setScale(0.13);
}
