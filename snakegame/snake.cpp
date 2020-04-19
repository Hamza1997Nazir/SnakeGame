#include<iostream>
#include<conio.h>
#include<windows.h>
#include<dos.h>
#include<time.h>


#define MAXSNAKESIZE 100

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

void gotoxy(int x, int y)
{
	CursorPosition.X = x;
	CursorPosition.Y = y;
	SetConsoleCursorPosition(console, CursorPosition);
}

class Point {
private:
	int x;
	int y;
public:

	Point()
	{
		x = 10;
		y = 10;
	}
	Point(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	void setPoint(int x, int y)
	{
		this->x = x;
		this->y = y;
	}
	int GetX()
	{
		return x;
	}
	int GetY()
	{
		return y;
	}
	void MoveUp()
	{
		y--;
	}
	void MoveDown()
	{
		y++;
	}
	void MoveRight()
	{
		x++;
	}
	void MoveLeft()
	{
		x--;
	}
	void Draw()
	{
		gotoxy(x, y);
		cout << "#";
	}
	void Erase()
	{
		gotoxy(x, y);
		cout << " ";
	}
	void Debug()
	{
		cout << "(" << x << "," << y << ")";
	}
	void CopyPosition(Point *p)
	{
		p->x = x;
		p->y = y;
	}
};
class Snake {
private:
	Point* cell[MAXSNAKESIZE];
	int size;
	int direction;
	Point fruit;
public:

	Snake()
	{
		size = 1;
		cell[0] = new Point(25, 25);
		for (int i = 1; i < MAXSNAKESIZE; i++)
		{
			cell[i] = NULL;
		}
	}
	
	fruit.setPoint(srand() % 50, srand() % 50);
	void AddCell(int x, int y)
	{
		cell[size++] = new Point(x, y);
	}

	void TurnUp() {
		direction = 'w';
	}
	void TurnDown() {
		direction = 's';
	}
	void TurnLeft() {
		direction = 'a';
	}
	void TurnRight() {
		direction = 'd';
	}
	void Move()
	{
		system("cls");
		for (int i = size - 1; i > ; i--)
		{
			cell[i-1]->CopyPosition(cell[i]); // copy the snake body ahead
		}

		switch (direction) {
		case 'w':
			cell[0]->MoveUp();
			break;
		case 's':
			cell[0]->MoveDown();
			break;
		case'a':
			cell[0]->MoveLeft();
			break;
		case'd':
			cell[0]->MoveRight();
			break;
		}

		if (fruit.GetX == cell[0]->GetX && fruit.GetY == cell[0]->GetY)
		{
			AddCell(0, 0);
			fruit.setPoint(srand() % 50, srand() % 50);
		}

		for (int i = 0; i < size; i++)
		{
			cell[i]->Draw();
		}
		fruit.Draw();
		Sleep(100);
	}
};

int main()
{

	srand((unsigned)time(NULL));


	Snake snake;
	char op = 'l';

	while (op != 'e')
	{
		if (_kbhit()) {
			op = _getch();
		}

		switch (op) {
		case'w':
		case'W':
			snake.TurnUp();
			break;
		case's':
		case'S':
			snake.TurnDown();
			break;
		case'a':
		case'A':
			snake.TurnLeft();
			break;
		case'd':
		case'D':
			snake.TurnDown();
			break;
		}
		snake.Move();
	}


	system("pause");
	return 0;
}