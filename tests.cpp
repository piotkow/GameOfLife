#include "tests.h"
#include <QDebug>
#include <QTextStream>
#include <iostream>
#include <Game.h>
using namespace std;

void neighbours_test(){
    Game game;
    point p;
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            if(y==2 && (x==1 || x==0)){
                p={x,y,true};
                game.add((p));
            }
            else{
                p={x,y,false};
                game.add((p));
                }
        }
    }
    if(game.number_neighbours(4)==2){
        qDebug()<<"OK";
    }
    else{
        qDebug()<<"FAIL";
    }
}

void rules_test(){
    Game game;
    point p;
    for(int x=0; x<3; x++){
        for(int y=0; y<3; y++){
            if((x==1 && y==1) || (x==2 && y==2) || (x==0 && y==2)){
                p={x,y,true};
                game.add((p));
            }
            else{
                p={x,y,false};
                game.add((p));
            }
        }
    }
    game.Game_Rules();
    game.iteration();
    QList<point> test_list=game.getPoint_list();
    if(test_list[4].isAlive && test_list[5].isAlive
            && !test_list[0].isAlive && !test_list[1].isAlive
            && !test_list[2].isAlive && !test_list[3].isAlive
            && !test_list[6].isAlive && !test_list[7].isAlive
            && !test_list[8].isAlive){
        qDebug()<<"OK";
    }
    else{
        qDebug()<<"FAIL";
    }
}
