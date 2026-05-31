#include <stdio.h>
#include <stdlib.h>

#define BLACK 1
#define WHITE -1
#define EMPTY 0
#define N 15

int inBoard(int row, int col)
{
    return row >= 0 && row < N && col >= 0 && col < N;
}

void win(const char* player)
{
    printf("%s 赢了\n", player);
    exit(0);
}

int countDirection(int board[N][N], int row, int col, int color, int dx, int dy)
{
    int count = 1;

    int r = row + dx;
    int c = col + dy;

    while (inBoard(r, c) && board[r][c] == color)
    {
        count++;
        r += dx;
        c += dy;
    }

    r = row - dx;
    c = col - dy;

    while (inBoard(r, c) && board[r][c] == color)
    {
        count++;
        r -= dx;
        c -= dy;
    }

    return count;
}

void Win_Or_Lose(int board[N][N], int row, int col)
{
    int color = board[row][col];

    if (color == EMPTY)
    {
        return;
    }

    const char* player = color == BLACK ? "BLACK" : "WHITE";

    int directions[4][2] = {
        {1, 0},   // 竖直
        {0, 1},   // 水平
        {1, 1},   // 主对角线
        {1, -1}   // 副对角线
    };

    for (int i = 0; i < 4; i++)
    {
        int count = countDirection(
            board,
            row,
            col,
            color,
            directions[i][0],
            directions[i][1]
        );

        if (count >= 5)
        {
            win(player);
        }
    }
}
