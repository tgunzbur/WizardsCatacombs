#include "main.h"

using namespace std;

int    main()
{
    Character monster("Gnork", 12, 50, 20,  Vector2 (2, 3));
    Character player("Billy", 20, 100, 50, Vector2(5, 5));

    player.changeHealth(-20);
    player.print();
    monster.print();
    return (0);
}
