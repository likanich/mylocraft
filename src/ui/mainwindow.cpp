#include "mainwindow.hpp"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    resize(640, 480);
    setWindowTitle("Мыловарня");

    _db = new Database();
    _db->connectToDataBase();

    createUI();
}

MainWindow::~MainWindow()
{
    delete _db;
}

void MainWindow::createUI()
{
    QLabel * label = new QLabel("NO!");
    label->setAlignment(Qt::AlignVCenter | Qt::AlignHCenter);
    setCentralWidget(label);
}
