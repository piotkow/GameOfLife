#ifndef GAME_H
#define GAME_H
#include <random>
#include <QList>
#include <QFileDialog>
using namespace std;

struct point{
 int x;
 int y;
 bool isAlive;
};

class Game{

private:
    int min=0, max=10;
    QList<point> point_list;
    QVector<int> birth;
    QVector<int> death;

public:
    void initial_state(int number_of_points);
    void Game_Rules();
    int number_neighbours(int index_punktu);
    int neighbor_count(vector<int> sasiad, int index, int size);
    void live(int index);
    void die(int index);
    void rewrite_points();
    void setMax(int rozmiar_okna);
    int getMax();
    void add(point pkt);
    bool getIsAlive(point pkt);
    QList<point> getPoint_list();
    void iteration();
    QVector<int> getBirth();
    void save(QString sciezka);
    void load(QString sciezka);
    void enlarge_list();

};


#endif // GAME_H
