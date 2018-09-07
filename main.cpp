#include "main.h"

int     main(int argc, char **argv)
{
    QApplication    application(argc, argv);
	Scene			*scene = new Scene(5);
    QGraphicsView   *view = new QGraphicsView(scene);

    scene->setSceneRect(0, 0, 450, 800);
	scene->setFocus();
	scene->createBackGround();
	scene->player = scene->createGameObject(":/playerLeft.png",
						Vector2 (0, scene->roomSize - 1), PLAYER);
	view->show();
	QTimer *timer = new QTimer(scene);
	QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(game()));
	timer->start(100);
    return application.exec();
}
