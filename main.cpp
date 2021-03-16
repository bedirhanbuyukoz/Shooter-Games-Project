#include <QApplication>
#include "Game.h"




//-QMediaPlayer, setMedia(), QUrl, play()


Game * game;

int main(int argc, char *argv[]){
    QApplication a(argc, argv);

    game = new Game();
    game->show();

    return a.exec();
}
