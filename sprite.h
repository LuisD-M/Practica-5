#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>

class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int r; // radio
    int posx = 20, posy = 20; // posición del sprite en la escena.
    int velocidad = 10;       // velocidad de movimiento del sprite

public:
    explicit sprite(QObject *parent = nullptr);

    sprite(int r_, int x, int y); // Constructor para inicializar el radio r y las posiciones posx e posy del sprite
    QTimer * timer;  // Puntero a un QTimer programar actualziacion del sprite
    QPixmap *pixmap; // Puntero a un QPixmap, que representa la imagen del sprite.

    // métodos getter y setter para acceder y modificar radio, px y py sprite.
   /* int getR() const;
    void setR(int radio);
    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);*/

    // Para  determinar la posición y el tamaño del sprite en la hoja de sprites
    float filas, columnas, ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

signals:

public slots:
    void Actualizacion(); // actualización periódica del sprite
};

#endif // SPRITE_H
