#include<iostream>
#include<conio.h> //console input output
using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x,y; //snake head postion
int fruitX, fruitY; //fruit Position
int score;
enum eDirection { STOP=0, LEFT, RIGHT, UP, DOWN}; //for snake movement
eDirection dir;

void Setup()
{
	gameOver=false;
	dir = STOP;
	x=width/2;
	y=height/2;
	fruitX = rand() % width;
	fruitY = rand() % height;
	score=0;
}

void Draw()
{
	system("clear");
	for(int i=0;i<width+2;i++)cout<<"#";
	cout<<endl;
	
	for(int i=0;i<height;i++)
	{
		for(int j=0;j<width;j++)
		{
			if(j==0)cout<<"#";
			
			if(i==y && j==x)cout<<"O";
			else if(i==fruitY && j==fruitX)cout<<"F";
			else cout<<" ";

			if(j==width-1)cout<<"#";
		}
		cout<<endl;
	}
	for(int i=0;i<width+2;i++)cout<<"#";
	cout<<endl;
	cout<<"Score : "<<score<<endl;
}

void Input()
{
	if(_kbhit()) //it will return positive no ,if any character is pressed
	{
		switch(getch())
		{
			case 'a':
				dir = LEFT;
				break;
			case 'd':
				dir = RIGHT;
				break;
			case 'w':
				dir = UP;
				break;
			case 's':
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
	switch(dir)
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
	if(x >= width || x < 0 || y >= height || y < 0)
	gameOver = true;
	if(x==fruitX && y==fruitY)
	{
		score+=10;
		fruitX = rand() % width;
		fruitY = rand() % height;
	}
}
int main()
{
	Setup();
	while(!gameOver)
	{
		Draw();
		Input();
		Logic();
		//sleep(10);
	}
	return 0;
}
