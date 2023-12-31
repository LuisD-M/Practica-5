#ifndef SPRITE_H
#define SPRITE_H

#include <QObject>
#include <QGraphicsItem>
#include <QTimer>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QKeyEvent>

class sprite : public QObject, public QGraphicsItem
{
    Q_OBJECT
    int r; // radio
    int posx = 20, posy = 20;                                      // posición del pacman en la escena.
    int velocidad=10;

public:
    explicit sprite(QObject *parent = nullptr);

    sprite(int r_, int x, int y);       // Constructor para inicializar el radio r y las posiciones posx e posy del sprite
    QTimer * timer;                                            // Puntero a un QTimer programar actualziacion del sprite
    QPixmap *pixmap;                                        // Puntero a un QPixmap, que representa la imagen del sprite.

    // Para  determinar la posición y el tamaño del sprite en la hoja de sprites
    float filas, columnas, ancho, alto;

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    int getPosx() const;
    void setPosx(int px);
    int getPosy() const;
    void setPosy(int py);

signals:

public slots:
    void Actualizacion();                            // actualización periódica del sprite
    void MoveUp();
    void MoveDown();
    void MoveRight();
    void MoveLeft();
};

#endif // SPRITE_H
