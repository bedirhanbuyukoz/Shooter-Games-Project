#include "Game.h"
#include <QTimer>
#include <QGraphicsTextItem>
#include <QFont>
#include "Enemy.h"
//#include <QMediaPlayer>
#include <QBrush>
#include <QImage>

Game::Game(QWidget *parent){
    // create the scene
    scene = new QGraphicsScene();
    scene->setSceneRect(0,0,800,600); // make the scene 800x600 instead of infinity by infinity for zombie spawn
    setBackgroundBrush(QBrush(QImage(":/images/bg.png")));

    // make the newly QGraphicsView Widget,
    // it can be used to visualize scenes
    setScene(scene);
    setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    setFixedSize(800,600);

    // create the player
    player = new Player();
    player->setPos(400,500); //  always be in the middle bottom of screen
    //it to be the current focus
    player->setFlag(QGraphicsItem::ItemIsFocusable); // i can for stun in game
    player->setFocus();
    // add the player to the scene
    scene->addItem(player);

    // create the score/health board
    score = new Score();
    scene->addItem(score);
    health = new Health();
    health->setPos(health->x(),health->y()+25);
    scene->addItem(health);

    // spawn enemies
    QTimer * timer = new QTimer();
    QObject::connect(timer,SIGNAL(timeout()),player,SLOT(spawn()));
    timer->start(1000); // enemy oftn  it can levells !!!

    /* play background music
    QMediaPlayer * music = new QMediaPlayer(); //mediaplayer hata
    music->setMedia(QUrl("qrc:/sounds/bgsound.mp3"));
    music->play();
*/
    show();
}
