#ifndef MUROS_H
#define MUROS_H
#include <QGraphicsItem>
#include <QPainter>

class muros : public QGraphicsItem
{
    int posx, posy;              //Posciones del bloque en la pantalla
    int w, h;                    //Tamaño del bloque.

public:
    muros();                    //Constructo por defecto
    muros(int w, int h, int x, int y); //Se sobrecarga el constructor de los muros
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);  //dibujar paredes en la escena
    QRectF boundingRect() const;       //delimita la pared en la escena
};

#endif // MUROS_H
