#include "Game.h"
#include <iostream>
#include <fstream>
#include <QDebug>

using namespace std;


void Game::rewrite_points(){
    point new_point;
    for(int x=0;x<max;x++){
        for( int y=0;y<max;y++){
            new_point={x,y,false};
            point_list.push_back(new_point);
            }
    }
}

void Game::enlarge_list(){
    QVector<point> alive_list;
    for(int i=0;i<point_list.size();i++){
        if (point_list[i].isAlive){
            alive_list.push_back(point_list[i]);
        }
    }
    point_list.clear();
    rewrite_points();
    for(int index=0; index<point_list.size(); index++){
        for(int alive_index=0; alive_index<alive_list.size(); alive_index++){
            if(point_list[index].x==alive_list[alive_index].x && point_list[index].y==alive_list[alive_index].y)
                point_list[index].isAlive=true;
        }
    }
}


void Game::initial_state(int number_of_points){
    point_list.clear();
    rewrite_points();
    srand(time(NULL));
    int random_index=0;
    for(int counter=0; counter<number_of_points; counter++){
        random_index=rand()%point_list.size();
        if(!point_list[random_index].isAlive){
            point_list[random_index].isAlive=true;
        }else{
            counter--;
        }
    }
}

int Game::neighbor_count(vector<int> neighbour,int index, int size){
    int counter=0;
    point pkt;
    point temp;
    pkt=point_list[index];
    for(int index=0; index<size;index++){
        switch(neighbour[index]){
        case 1:
            temp = {pkt.x-1,pkt.y,getIsAlive({pkt.x-1,pkt.y})};
            if(temp.isAlive){counter++;}
            break;
        case 2:
            temp={pkt.x+1,pkt.y,getIsAlive({pkt.x+1,pkt.y})};
            if(temp.isAlive){counter++;}
            break;
        case 3:
            temp={pkt.x,pkt.y-1,getIsAlive({pkt.x,pkt.y-1})};
            if(temp.isAlive){counter++;}
            break;
        case 4:
            temp={pkt.x,pkt.y+1,getIsAlive({pkt.x,pkt.y+1})};
            if(temp.isAlive){counter++;}
            break;
        case 5:
            temp={pkt.x-1,pkt.y+1,getIsAlive({pkt.x-1,pkt.y+1})};
            if(temp.isAlive){counter++;}
            break;
        case 6:
            temp={pkt.x-1,pkt.y-1,getIsAlive({pkt.x-1,pkt.y-1})};
            if(temp.isAlive){counter++;}
            break;
        case 7:
            temp={pkt.x+1,pkt.y+1,getIsAlive({pkt.x+1,pkt.y+1})};
            if(temp.isAlive){counter++;}
            break;
        case 8:
            temp={pkt.x+1,pkt.y-1,getIsAlive({pkt.x+1,pkt.y-1})};
            if(temp.isAlive){counter++;}
            break;
            }
        }
    return counter;
}

int Game::number_neighbours(int point_index){
    int number_of_neighbours=0;
    point pkt;
    int size;
    pkt=point_list[point_index];
    if(pkt.x==min || pkt.x==max || pkt.y==min || pkt.y==max){
        if(pkt.x==min && pkt.y==min){
           size=3;
           vector<int> neighbours(size);
           neighbours[0]=2;
           neighbours[1]=4;
           neighbours[2]=7;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.x==max && pkt.y==min){
           size=3;
           vector<int> neighbours(size);
           neighbours[0]=4;
           neighbours[1]=1;
           neighbours[2]=5;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.x==min && pkt.y==max){
           size=3;
           vector<int> neighbours(size);
           neighbours[0]=3;
           neighbours[1]=2;
           neighbours[2]=8;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.x==max && pkt.y==max){
           size=3;
           vector<int> neighbours(size);
           neighbours[0]=3;
           neighbours[1]=1;
           neighbours[2]=6;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.x==min){
           size=5;
           vector<int> neighbours(size);
           neighbours[0]=4;
           neighbours[1]=3;
           neighbours[2]=7;
           neighbours[3]=2;
           neighbours[4]=8;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.x==max){
           size=5;
           vector<int> neighbours(size);
           neighbours[0]=4;
           neighbours[1]=5;
           neighbours[2]=1;
           neighbours[3]=6;
           neighbours[4]=3;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.y==min){
           size=5;
           vector<int> neighbours(size);
           neighbours[0]=1;
           neighbours[1]=2;
           neighbours[2]=5;
           neighbours[3]=4;
           neighbours[4]=7;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
       }else if(pkt.y==max){
           size=5;
           vector<int> neighbours(size);
           neighbours[0]=2;
           neighbours[1]=1;
           neighbours[2]=6;
           neighbours[3]=3;
           neighbours[4]=8;
           number_of_neighbours=neighbor_count(neighbours, point_index, size);
        }
    }else{
        size=8;
        vector<int> neighbours(size);
        for(int index=0; index<size; index++){
            neighbours[index]=index+1;
            }
        number_of_neighbours+=neighbor_count(neighbours, point_index, size);
        }
    return number_of_neighbours;
}

int Game::getMax(){
    return max;
}

void Game::setMax(int window_size){
    max=window_size;
}

void Game::add(point pkt){
    point_list.push_back(pkt);
}

bool Game::getIsAlive(point pkt){
    bool alive=false;
    for(int index=0; index<point_list.size(); index++){
        if(pkt.x==point_list[index].x && pkt.y==point_list[index].y){
            alive=point_list[index].isAlive;
            }
        }
    return alive;
}

void Game::die(int index){
   point_list[index].isAlive=false;
}

void Game::live(int index){
   point_list[index].isAlive=true;
}

void Game::Game_Rules(){
   for(int i=0;i<point_list.size();i++){
        if(number_neighbours(i)>3 || number_neighbours(i)<2){
            death.push_back(i);
        }else if(number_neighbours(i)==3){
            birth.push_back(i);
        }
   }
}

void Game::iteration(){
    for(int number_of_deaths=0; number_of_deaths<death.size(); number_of_deaths++){
        die(death[number_of_deaths]);
        }
    for(int number_of_alive=0; number_of_alive<birth.size(); number_of_alive++){
        live(birth[number_of_alive]);
        }
    death.clear();
    birth.clear();
}

QList<point> Game::getPoint_list(){
    return point_list;
}

QVector<int> Game::getBirth(){
    return birth;
}

void Game::save(QString path){
    if(!path.isEmpty()){
        std::ofstream file(path.toStdString());
        for(int point_index=0; point_index<point_list.size(); point_index++){
            file <<point_list[point_index].x <<" ";
            file <<point_list[point_index].y <<" ";
            file <<point_list[point_index].isAlive <<endl;
            }
        file.close();
        }
    }

void Game::load(QString path){
    if(!path.isEmpty()){
        point_list.clear();
        int x,y;
        bool isAlive;
        std::ifstream file(path.toStdString());
        for(int i=0;!file.eof();i++){
            file>>x, file>>y, file>>isAlive;
            point_list.push_back({x,y,isAlive});
            }
        file.close();
    }
}
