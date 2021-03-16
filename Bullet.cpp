#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game; //  external global object called game

Bullet::Bullet(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){
    // draw graphics
    setPixmap(QPixmap(":/images/bullet.png"));


   //a timer to move() the bullet every so often
    QTimer * timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    // start the timer
    timer->start(30);
}

void Bullet::move(){
    // get a list of all the items currently colliding with this bullet
    QList<QGraphicsItem *> colliding_items = collidingItems();

    // if one of the colliding items is an Enemy, destroy both the bullet and the enemy
    for (int i = 0, n = colliding_items.size(); i < n; ++i){
        if (typeid(*(colliding_items[i])) == typeid(Enemy)){

            // increase the score
            game->score->increase();

            // remove them from the scene
            scene()->removeItem(colliding_items[i]); //null code
            scene()->removeItem(this);

            // delete them from the heap to save memory
            delete colliding_items[i];
            delete this;


            return;
        }
    }

    // if there was no collision with an Enemy, move the bullet forward
    setPos(x(),y()-10);
    // if the bullet is off the screen, destroy it and save memory
    if (pos().y() < 0){
        scene()->removeItem(this);
        delete this;
    }
}
