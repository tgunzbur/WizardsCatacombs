#include "main.h"

int     main(int argc, char **argv)
{
    QApplication    application(argc, argv);
	Scene			*scene = new Scene();
    QGraphicsView   *view = new QGraphicsView(scene);

    scene->setSceneRect(0, 0, 450, 800);
	scene->setFocus();
	scene->createPlayer(Vector2 (0, ROOMSIZE - 1));
	scene->createCharacter(SKELETON, Vector2 (0, 0));
	scene->createBackGround();
	view->show();
	QTimer *timer = new QTimer(scene);
	QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(Update()));
	timer->start(17);
	return application.exec();
}
