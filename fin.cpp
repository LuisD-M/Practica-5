#include "fin.h"
#include <QFont>

fin::fin(QGraphicsItem *parent) : QGraphicsTextItem(parent)
{
    setPlainText(QString("---------- WIN ---------- "));              //Mostrar en pantalla el texto
    setDefaultTextColor(Qt::red);                                                   //color del texto
    setFont(QFont("Comic Sans MS",50));
}
