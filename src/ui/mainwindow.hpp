#pragma once

#include <QMainWindow>
#include <QLabel>
#include "src/core/database.hpp"

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Database *_db;

private:
    void createUI();

signals:

};
