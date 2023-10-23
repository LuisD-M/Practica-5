#include "fantasma.h"

fantasma::fantasma(int w, int h, int x, int y)
{
    this->w = w;
    this->h = h;
    this->posx = x;
    this->posy = y;

    filas=0;
    columnas=0;

    pixmap4 = new QPixmap(":/images/fantasma.jpg");

    timer4 = new QTimer();
    connect(timer4, &QTimer::timeout,, this, &fantasma::mover);          //conecta el timer con la funcion mover
    timer->start(100);                                                   // Ajusta el intervalo del temporizador

    ancho=66;
    alto=99;

    setPos(posx,posy);
    setPos(270,270);
}

QRectF fantasma::boundingRect() const
{
    return QRectF(-ancho/2,-alto/2,ancho,alto);
}

void fantasma::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->drawPixmap(-ancho/2, -alto/2,*pixmap4,columnas,0,ancho,alto);
    setScale(0.29);
}

void fantasma::mover()
{
    int dx = qrand() % 3 - 1;  // Movimiento aleatorio en X (-1, 0, 1)
    int dy = qrand() % 3 - 1;  // Movimiento aleatorio en Y (-1, 0, 1)
}
