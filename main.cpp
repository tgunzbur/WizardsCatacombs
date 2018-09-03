#include "main.h"

int    main(int argc, char **argv)
{
    QApplication application(argc, argv);

    QWidget window;
    window.setFixedSize(200, 200);
    QLabel  label;
    QImage  image(":/player.png");
    image = image.scaled(100, 100, Qt::KeepAspectRatio);
    QPixmap pixMap = QPixmap::fromImage(image);
    label.setPixmap(pixMap);
    label.setGeometry(50, 50, image.size().width(), image.size().height());
    label.setParent(&window);
    window.show();
    return application.exec();
}
