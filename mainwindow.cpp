#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow), timer(new QTimer(this))
{
    ui->setupUi(this);
    create_board();
    ui->Board->setStyleSheet("background-color: #1B1B20;");
    connect(timer,SIGNAL(timeout()),this,SLOT(iteration_timer()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_board_size_valueChanged(int value)
{
    game.enlarge_list();
    game.setMax(value);
    max_alive();
    create_board();
    ui->number_of_points->setMaximum(ui->board_size->value()*ui->board_size->value());
}

void MainWindow::on_draw_clicked()
{
  game.initial_state(ui->number_of_points->value());
  create_board();
}


void MainWindow::create_board(){
    scene = new QGraphicsScene(ui->Board);
    ui->Board->setScene(scene);
    QPen blackpen(Qt::darkGray);
    QBrush brush(QColor(90, 208, 184, 150));
    int window_size=400;
    point new_point;
    int cell_size=window_size/game.getMax();
    ui->Board->setMaximumSize(window_size+game.getMax(),window_size+game.getMax());
    ui->Board->setMinimumSize(window_size+game.getMax(),window_size+game.getMax());
    for(int x_size=0; x_size<ui->board_size->value(); x_size++){
        new_point.x = x_size;
        for(int y_size=0; y_size<ui->board_size->value(); y_size++){
            new_point.y=y_size;
            if(game.getIsAlive({new_point.x,new_point.y})){
                square = scene->addRect(cell_size*x_size, cell_size*y_size, cell_size, cell_size, blackpen, brush);
            }
            else{
                square = scene->addRect(cell_size*x_size, cell_size*y_size, cell_size, cell_size, blackpen);
                }
            }
        }

    }


void MainWindow::max_alive(){
    ui->number_of_points->setMaximum(ui->board_size->value()*ui->board_size->value());
}

void MainWindow::on_iteration_clicked()
{
    game.enlarge_list();
    game.Game_Rules();
    game.iteration();
    create_board();
}

void MainWindow::on_start_clicked()
{
    timer->setInterval(500);
    timer->start();
}

void MainWindow::iteration_timer(){
    game.Game_Rules();
    game.iteration();
    create_board();
}

void MainWindow::on_stop_clicked()
{
    timer->stop();
    game.initial_state(0);
    create_board();
}

void MainWindow::on_pause_clicked()
{
    timer->stop();
    create_board();
}

void MainWindow::on_Load_clicked()
{
    path_to_load();
    game.load(path);
    create_board();
    path=nullptr;
}


void MainWindow::on_Save_clicked()
{
    path_to_save();
    game.save(path);
}

void MainWindow::path_to_load()
{
    QString pom = QFileDialog::getOpenFileName(this,"Save", "","Save (*.txt)");
    if(!pom.isEmpty()) path = pom;
}

void MainWindow::path_to_save()
{
    QString pom = QFileDialog::getSaveFileName(this,"Save", "","Save (*.txt)");
    if(!pom.isEmpty()) path = pom;
}


void MainWindow::on_alive_slider_sliderPressed()
{
     ui->number_of_points->setMaximum(ui->board_size->value()*ui->board_size->value());
}



