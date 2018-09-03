#include "main.h"
#include <QPushButton>

int    main(int argc, char **argv)
{
    QApplication    application(argc, argv);
    MainWindow      mainWindow;

    mainWindow.show();
    return application.exec();
}

MainWindow::MainWindow()
{
    QWidget     *window = new QWidget;
    QPushButton *button = new QPushButton;
    QImage      image(":/player.png");
    GameObject  *player = new GameObject(image, Vector2(50, 50), 64);
    QIcon       icon(QPixmap::fromImage(image));

    player->display(window);
    player->Move(Vector2(10, 10));
    player->display(window);
    button->setIcon(icon);
    button->setIconSize(QSize(50, 50));
    button->setFixedSize(50, 50);
    button->setFlat(true);
    button->setParent(window);

    setCentralWidget(window);
}

/*

    button.move(50, 100);
*/
