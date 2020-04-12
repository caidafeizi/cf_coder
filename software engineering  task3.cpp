#include<stdio.h>
#include<conio.h>
#include<windows.h>

#define height 11
#define width 13

//手动输入地图
int map[height][width] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,4,4,0,4,4,0,0,0,1},
	{1,0,3,4,3,3,4,3,3,4,3,0,1},
	{1,0,0,4,3,0,3,0,3,4,0,0,1},
	{1,0,0,0,4,3,2,3,4,0,0,0,1},
	{1,0,0,0,3,4,3,4,3,0,0,0,1},
	{1,0,0,0,0,0,4,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1}
};


//0 代表空格
//1 代表围墙	▓
//2 代表小人	⊙	
//3 代表箱子	■
//4 代表白五角星	☆
//6 代表人和白五角星重合	〇
//7 代表箱子和五角星重合	★


//画图函数
bool  Endgame()
{
	bool flag = true;
	for (int i = 0; i < height; i++)
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 4)
				return false;
		}
	return true;
}

void  Drawing()
{
	for (int i = 0; i < height;i++)
	{
		for (int j = 0;j < width;j++)
		{
			switch (map[i][j])
			{
			case 0: printf("  "); break;
			case 1: printf("▓"); break;
			case 2: printf("⊙"); break;
			case 3: printf("■"); break;
			case 4: printf("☆"); break;
			case 6: printf("〇"); break;
			case 7: printf("★"); break;
			}
		}
		printf("\n");
	}
	if(Endgame())
		printf("恭喜你通关了！小心心送给你！");
}

void Position(int &col, int &row)
{
	bool flag = false;
	for (int i = 0; i < height; i++)
	{
		if (flag)
			break;
		for (int j = 0; j < width; j++)
		{
			if (map[i][j] == 2 || map[i][j] == 6)
			{
				col = i;
				row = j;
				flag = true;
				break;
			}
		}
	}
}



void  Pushbox()
{
	int col , row ;
	Position(col, row );
	char mob = _getch(); //使用_getch()函数接收键盘输入操作。
	switch (mob)
	{
	case 'W':
	case 'w':
	case 72:
		if (map[col - 1][row] == 0 || map[col - 1][row] == 4 || map[col - 1][row] == 3 || map[col-1][row] == 7)
		{
			if (map[col - 1][row] == 0 || map[col - 1][row] == 4)
			{
				map[col - 1][row] += 2;
				map[col][row] -= 2;
			}
			else if (map[col - 1][row] == 3 || map[col - 1][row] == 7)
				if (map[col - 2][row] == 0 || map[col - 2][row] == 4)
				{
					map[col][row] -= 2;
					map[col - 2][row] += 3;
					map[col - 1][row] -= 1;
				}
		}
		break;
	case 'S':
	case 's':
	case 80:
		if (map[col + 1][row] == 0 || map[col + 1][row] == 4 || map[col + 1][row] == 3 || map[col + 1][row] == 7)
		{
			if (map[col + 1][row] == 0 || map[col + 1][row] == 4)
			{
				map[col + 1][row] += 2;
				map[col][row] -= 2;
			}
			else if (map[col + 1][row] == 3 || map[col + 1][row] == 7)
				if (map[col + 2][row] == 0 || map[col + 2][row] == 4)
				{
					map[col][row] -= 2;
					map[col + 2][row] += 3;
					map[col + 1][row] -= 1;
				}
		}
		break;
	case 'A':
	case 'a':
	case 75:
		if (map[col][row - 1] == 0 || map[col][row - 1] == 4 || map[col][row - 1] == 3 || map[col][row - 1] == 7)
		{
			if (map[col][row - 1] == 0 || map[col][row - 1] == 4)
			{
				map[col][row - 1] += 2;
				map[col][row] -= 2;

			}
			else if (map[col][row - 1] == 3 || map[col][row - 1] == 7)
				if (map[col][row - 2] == 0 || map[col][row - 2] == 4)
				{
					map[col][row] -= 2;
					map[col][row - 2] += 3;
					map[col][row - 1] -= 1;
				}
		}
		break;
	case 'D':
	case 'd':
	case 77:
		if (map[col][row + 1] == 0 || map[col][row + 1] == 4 || map[col][row + 1] == 3 || map[col][row + 1] == 7)
		{
			if (map[col][row + 1] == 0 || map[col][row + 1] == 4)
			{
				map[col][row] -= 2;
				map[col][row + 1] += 2;
			}
			else if (map[col][row + 1] == 3 || map[col][row + 1] == 7)
				if (map[col][row + 2] == 0 || map[col][row + 2] == 4)
				{
					map[col][row] -= 2;
					map[col][row + 2] += 3;
					map[col][row + 1] -= 1;
				}
		}
		break;
	default:
		break;
	}	
}



void  main() {
	while (1)
	{
		system("cls"); //清屏
		Drawing();
		Pushbox();
	}
	system("pause");
}
