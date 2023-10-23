#include "puntaje.h"
#include <QFont>


puntaje::puntaje(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    puntuacion = 0;                                                                    //puntaje inicial en cero
    setPlainText(QString("Puntaje: ") + QString::number(puntuacion));              //Mostrar en pantalla el texto
    setDefaultTextColor(Qt::red);                                                   //color del texto
    setFont(QFont("Comic Sans MS",13));                                            //Tipo de letra y tamaño
}

void puntaje::increaseMoneda()
{
    puntuacion++;                                                                   //moneda 1 punto
    setPlainText(QString("Puntaje: ") + QString::number(puntuacion));               //Actualizar la puntuacion
}

void puntaje::increaseCereza()
{
    puntuacion +=5;
    setPlainText(QString("Puntaje: ") + QString::number(puntuacion));
}


int puntaje::getpuntaje()
{
    return puntuacion;
}
