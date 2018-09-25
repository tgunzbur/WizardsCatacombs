#include "main.h"

int     main(int argc, char **argv)
{
    QApplication    application(argc, argv);
	Scene			*scene = new Scene();
    QGraphicsView   *view = new QGraphicsView(scene);

	srand(unsigned (time(nullptr)));
	scene->setSceneRect(0, 0, 450, 800);
	scene->setFocus();
	scene->createPlayer(Vector2 (0, ROOMSIZE - 1));
	scene->createCharacter(SKELETON, Vector2 (0, 0));
	scene->createBackGround();
	view->show();
	QTimer *timer = new QTimer(scene);
	QObject::connect(timer, SIGNAL(timeout()), scene, SLOT(Update()));
	timer->start(1);
	return application.exec();
}

const char	*imageName(std::string name, directionId direction)
{
	if (direction == UP)
		name = ":/" + name + "Up.png";
	else if (direction == DOWN)
		name = ":/" + name + "Down.png";
	else if (direction == LEFT)
		name = ":/" + name + "Left.png";
	else if (direction == RIGHT)
		name = ":/" + name + "Right.png";
	return (name.c_str());
}
