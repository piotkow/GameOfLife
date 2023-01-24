#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPixmap>
#include <QPainter>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <Game.h>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void create_board();
    void max_alive();

private slots:

    void on_board_size_valueChanged(int value);
    void on_draw_clicked();
    void on_iteration_clicked();
    void on_start_clicked();
    void iteration_timer();
    void on_stop_clicked();
    void on_pause_clicked();
    void on_Load_clicked();
    void on_Save_clicked();
    void path_to_load();
    void path_to_save();
    void on_alive_slider_sliderPressed();

private:

    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    QGraphicsRectItem *square;
    Game game;
    QTimer *timer = nullptr;
    QString path;

};

#endif // MAINWINDOW_H
