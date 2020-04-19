#include<iostream>
#include<conio.h>
#include<windows.h>

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
};


int main()
{
	Point p(5, 10);
	p.Draw();



	system("pause");
	return 0;
}