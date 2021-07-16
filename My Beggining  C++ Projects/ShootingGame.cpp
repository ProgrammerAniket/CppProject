#include <iostream>
#include <conio.h>
using namespace std;

enum Dir
{
    STOP = 0,
    LEFT = 1,
    RIGHT = 2,
    DOWN = 3,
    UP = 4,
};

class cShooter
{
    int shooterX;
    int shooterY;
    Dir direction;

public:
    cShooter() {}
    cShooter(int x, int y)
    {
        shooterX = x;
        shooterY = y;
        direction = STOP;
    }
    inline int getshooterX() { return shooterX; }
    inline int getshooterY() { return shooterY; }
    inline int moveshooterRight() { shooterX += 2; }
    inline int moveshooterLeft() { shooterX -= 2; }
    inline int getshooterDirection(Dir direction)
    {
        this->direction = direction;
    }
    void getClassShooter()
    {
        cout << "Shooter Class" << endl;
        cout << getshooterX() << endl;
        cout << getshooterY() << endl;
    }
};

class cBullet
{
    int bulletX;
    int bulletY;
    Dir direction;

public:
    int a = 1;
    cBullet() {}
    void setBullet(int x, int y)
    {
        direction = STOP;
        bulletX = x;
        bulletY = y;
    }
    inline int shoot() { bulletY--; }
    inline int getbulletX() { return bulletX; }
    inline int getbulletY() { return bulletY; }
    inline int movebulletRight() { bulletX += 2; }
    inline int movebulletLeft() { bulletX -= 2; }
    inline int getbulletDirection(Dir direction)
    {
        this->direction = direction;
    }
    void getBullet()
    {
        cout << bulletX << endl;
        cout << bulletY << endl;
    }
};

class cEnemy
{
    int enemyX;
    int enemyY;
    Dir direction;

public:
    cEnemy() {}
    cEnemy(int x, int y)
    {
        enemyX = x;
        enemyY = y;
        direction = STOP;
    }
    inline int getenemyX() { return enemyX; }
    inline int getenemyY() { return enemyY; }
    void changeDirection(Dir d)
    {
        direction = d;
    }
    void RandomDirection()
    {
        direction = (Dir)((rand() % 2) + 1);
    }
    void Move()
    {
        switch (direction)
        {
        case LEFT:
            enemyX++;
            break;

        case RIGHT:
            enemyX--;
            break;

        case UP:
            enemyY--;
            break;

        case DOWN:
            enemyY++;
            break;

        default:
            break;
        }
    }
    inline int getenemyDirection() { return direction; }
    void getClassEnemy()
    {
        cout << "Enemy Class" << endl;
        cout << getenemyX() << endl;
        cout << getenemyY() << endl;
        cout << getenemyDirection() << endl;
    }
};

class cGameManager : public cShooter, public cBullet, public cEnemy
{
    int mapWidth;
    int mapHeight;
    bool quit;
    bool enemyMove;
    char Left, Right, Shoot;
    char bulletStatus;
    int score;
    int life;
    int x, y;
    cShooter *shooter;
    cBullet *bullet;
    cEnemy *enemy;

public:
    cGameManager(int w, int h)
    {
        mapWidth = w;
        mapHeight = h;
        score = 0;
        life = 3;
        enemyMove = false;
        bulletStatus = 'f';
        quit = false;
        Left = 'a', Right = 'd', Shoot = 's';
        shooter = new cShooter(mapWidth / 2, mapHeight - 5);
        bullet = new cBullet[4];
        enemy = new cEnemy(rand() % mapWidth - 1, mapHeight / 5 - 1);
        bullet->setBullet(shooter->getshooterX(), shooter->getshooterY() - 1);
    }
    void getGame()
    {
        cout << mapWidth << endl;
        cout << mapHeight << endl;
        cout << quit << endl;
        cout << shooter->getshooterX() << endl;
        cout << shooter->getshooterY() << endl;
        cout << enemy->getenemyX() << endl;
        cout << enemy->getenemyY() << endl;
    }
    void Draw();
    void Input();
    void Logic();
    void Run();
};

void cGameManager ::Draw()
{
    system("CLS");
    for (int i = 1; i <= mapHeight; i++)
    {
        for (int j = 1; j <= mapWidth; j++)
        {
            if (i == 1 || i == mapHeight || j == 1 || j == mapWidth)
            {
                cout << "#";
            }

            else
            {
                cout << " ";
            }

            if (i == shooter->getshooterY() && j == shooter->getshooterX())
            {
                cout << "O";
            }

            if (i == enemy->getenemyY() && j == enemy->getenemyX())
            {
                cout << "@";
            }

            if (i == bullet->getbulletY() && j == bullet->getbulletX())
            {
                cout << "o";
            }
        }
        cout << endl;
    }
    cout << "Score : " << score << endl;
    cout << "Life " << life << endl;
}

void cGameManager ::Input()
{
    x = getenemyX();
    y = getenemyY();
    if (_kbhit())
    {
        char current = _getch();
        if (current == Left)
        {
            shooter->moveshooterLeft();
            if (bulletStatus == 'f')
            {
                bullet->movebulletLeft();
            }
        }

        if (current == Right)
        {
            shooter->moveshooterRight();
            if (bulletStatus == 'f')
            {
                bullet->movebulletRight();
            }
        }

        if (current == Shoot)
        {
            bulletStatus = 't';
            bullet->shoot();
        }

        if (current == 'x')
        {
            quit = true;
        }
    }
}

void cGameManager ::Logic()
{
    if (enemy->getenemyY() == mapHeight)
    {
        enemy = new cEnemy(mapWidth / 2, mapHeight / 5 - 1);
    }

    if (shooter->getshooterX() == 0 || shooter->getshooterX() == mapWidth)
    {
        shooter = new cShooter(mapWidth / 2, mapHeight - 5);
        bullet->setBullet(shooter->getshooterX(), shooter->getshooterY() - 1);
    }

    if (bulletStatus == 't')
    {
        bullet->shoot();
    }

    if (bullet->getbulletY() == 0)
    {
        bullet->setBullet(shooter->getshooterX(), shooter->getshooterY() - 1);
        bulletStatus = 'f';
    }

    if (bullet->getbulletX() == enemy->getenemyX() && bullet->getbulletY() == enemy->getenemyY() && bulletStatus == 't')
    {
        enemy = new cEnemy(mapWidth / 2, mapHeight / 5 - 1);
        score += 10;
    }

    if (bullet->getbulletX() == enemy->getenemyX() && bullet->getbulletY() == enemy->getenemyY() && bulletStatus == 'f')
    {
        enemy = new cEnemy(mapWidth / 2, mapHeight / 5 - 1);
        life -= 1;
    }

    if (shooter->getshooterX() == enemy->getenemyX() && shooter->getshooterY() == enemy->getenemyY() && bulletStatus == 't')
    {
        enemy = new cEnemy(mapWidth / 2, mapHeight / 5 - 1);
        life -= 1;
    }

    if (life == 0)
    {
        quit = true;
    }
}

void cGameManager ::Run()
{
    while (!quit)
    {
        Draw();
        Input();
        Logic();
        enemy->changeDirection(DOWN);
        enemy->Move();
    }

    if (quit == true)
    {
        int input;
        system("CLS");
        cout << "Game Over!!!" << endl;
        cout << "Do you want to restart the game yes[1] or no[2] " << endl;
        cin >> input;
        switch (input)
        {
        case 1:
            Run();
            break;

        case 2:
            cout << "Thanks for playing the game ";
            _exit(0);
            break;

        default:
            _exit(0);
            break;
        }
    }
}

int main()
{
    system("CLS");
    cGameManager game(120, 30);
    game.Run();
    return 0;
}