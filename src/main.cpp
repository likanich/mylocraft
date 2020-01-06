#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QSqlDatabase>
#include "ui/mainwindow.hpp"

int main(int argc, char *argv[]) {

    QApplication app(argc, argv);

    MainWindow window;
    window.show();

    return app.exec();
}
