#include <iostream>
#include <cstdlib>
#include <unistd.h>
#include <string>
#include <conio.h>
#include <time.h>
#include <iostream>
#include <fstream>
#include "AiBrain.h"
using namespace std;

bool gameOver;
const int width = 62;
const int height = 22;
int x, y, fruitX, fruitY, score;
int const maxTail = 200;
int tailX[maxTail], tailY[maxTail];
int nTail = 0;
enum eDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
eDirection dir;

void Setup()
{
    srand (time(NULL));
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    fruitX = 1 + rand() % (width - 2);
    fruitY = 1 + rand() % (height - 2);
    score = 0;
    nTail = 10;
    system("color 0f");
}
void Draw()
{
    string drawString = "";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || i == 0 || j == width - 1 || i == height - 1)
                drawString = drawString + "#";
            else
            {
                if (i == y && j == x)
                    drawString = drawString + "O";
                else if (i == fruitY && j == fruitX)
                    drawString = drawString + "F";
                else
                {
                    bool drawTail = false;
                    string tempString;
                    for (int k = 0; k < nTail; k++)
                    {
                        if (tailX[k] == j && tailY[k] == i)
                        {
                            tempString = "o";
                            drawTail = true;
                        }
                    }
                    if (!drawTail)
                        tempString = " ";

                    drawString = drawString + tempString;
                }
            }
        }
        drawString = drawString + "\n";
    }
    drawString = drawString + "Score: ";

    system("cls");
    cout << endl << drawString << score << " x: " << x << " y: " << y;
}
void Input()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'd':
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w':
            if (dir != DOWN)
                dir = UP;
            break;
        case 's':
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
void Logic()
{
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i = 1; i < nTail; i++)
    {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    //transport the snake if it goes offscreen
    if (x == width - 1)
        x = 0 + 1;
    if (x == 0)
        x = width - 2;
    if (y == height - 1)
        y = 0 + 1;
    if (y == 0)
        y = height - 2;

    for (int i = 0; i < nTail; i++)
    {
        if (tailX[i] == x && tailY[i] == y && dir != STOP)
        {
            Setup();
            break;
        }
    }

    if (x == fruitX && y == fruitY)
    {
        score += 10;
        fruitX = 1 + rand() % (width - 2);
        fruitY = 1 + rand() % (height - 2);
        nTail++;
        if (nTail >= 201)
        {
            nTail = 200;
        }
    }
}

int main()
{
    AiBrain brain;
    Setup();
    while (!gameOver)
    {
        Draw();
        usleep(60000-30000/(score/100+1));
        Input();
        Logic();
    }
    cout << endl << "GAME OVER";
    return 0;
}
