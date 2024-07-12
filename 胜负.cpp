#include <windows.h>
#include <stdio.h>
#define BLACK 1
#define WHITE -1
#define EMPTY 0
#define N 5

void win(const char* x, int con)//return who is winner
{
	if (con < 5)con = 0;
	else if(con==5)
	{
		printf("%s赢了", x);
		exit(0);
	}
}

void search(int arr[N][N], int m, int n, const char* x,const int y)//search the next five smile colour chess
{
	int con,t,v;
	t = m, v = n;
	con = 0;
	while (arr[m][n] == y)
	{
		m++;
		con++;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		n++;
		con++;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		con++;
		m++, n++;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		con++;
		m++, n--;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		m--;
		con++;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		n--;
		con++;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		con++;
		m--, n++;
	}
	win(x, con);
	m = t, n = v;
	while (arr[m][n] == y)
	{
		con++;
		m--, n--;
	}
	win(x, con);
	m = t, n = v;
}

void Win_Or_Lose(int arr[N][N],int getMouse)
{
	if (getMouse == BLACK)//get the data from getmouse if it's black
	{
		int i = 0;
		for (i = 0; i < N; i++)
		{
			int j = 0;
			for (j = 0; j < N; j++)//
				if (arr[i][j] == BLACK)//traverse black
				{
						search(arr, i, j, "BLACK", BLACK);//search all directions of this black chess
				}
		}
	}
	else//get the data from getmouse if it's white
	{
		int i;
		for (i = 0; i < N; i++)
		{
			int j;
			for (j = 0; j < N; j++)
				if (arr[i][j] ==WHITE)//traverse white
				{
						search(arr, i, j,"WHITE",WHITE);//search all directions of this white chess
				}
		}
	}
}

/*int main()
{	
	int arr[N][N] = {
					  { 1, 1 , 1 ,1, 1 },
					  { 0,-1 , 0 ,1, 0 }, 
					  { 0, 0 , 1 ,0, 0 },
					  { 0, 1 , 0 ,-1,0 },
					  { 1, 0 , 0 ,0, -1} //debug用小棋盘
					};//将下棋程序写在这
	
	Win_Or_Lose(arr, BLACK);//判别函数
	return 0;
}*/ 
