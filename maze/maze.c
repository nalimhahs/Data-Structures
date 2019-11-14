#include <stdio.h>

#define N 10
#define MAX N *N

typedef struct coordinate
{
    int x;
    int y;
} point;

typedef struct moves
{
    point position;
    int direction;
} move;

move stack[MAX];

int top = -1;

void push(move i)
{
    if (top >= MAX)
    {
        printf("\nOverflow\n");
        return;
    }
    else
    {
        stack[++top] = i;
    }
}

move pop()
{
    if (top < 0)
    {
        printf("\nUnderflow\n");
        return;
    }
    else
    {
        return stack[top--];
    }
}

// int is_intersecting(point p)
// {

// }

int is_valid(point p, int maze[N][N])
{
    if (p.x >= 0 && p.y >= 0 && p.x < N && p.y < N && maze[p.x][p.y] != 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int calc_diff(point start, point end)
{
    int x = end.x - start.x;
    int y = end.y - start.y;

    if (x < 0)
    {
        x *= -1;
    }
    if (y < 0)
    {
        y *= -1;
    }

    return x + y;
}

point *get_possible_moves(point current)
{
    point possible[4];
    possible[0].x = current.x + 1;
    possible[0].y = current.x;

    possible[1].x = current.x;
    possible[1].y = current.y + 1;

    possible[2].x = current.x - 1;
    possible[2].y = current.y;

    possible[3].x = current.x;
    possible[3].y = current.y - 1;

    return possible;
}

point *get_optimized_moves(point current, point end)
{
    point possible_moves[4] = get_possible_moves(current);
    point temp;
    int small;

    // Sorting the possible moves to prioritize the point closest to the end.

    for (int i = 0; i < 4; i++)
    {
        small = i;
        for (int j = i; j < 4; j++)
        {
            if (calc_diff(possible_moves[j], end) < calc_diff(possible_moves[small], end))
            {
                small = j;
            }
        }
        temp = possible_moves[small];
        possible_moves[small] = possible_moves[i];
        possible_moves[i] = temp;
    }

    // Assigning the prev node the least priority

    point prev = stack[top].position;

    if (prev.x == possible_moves[2].x && prev.y == possible_moves[2].y)
    {
        temp = possible_moves[2];
        possible_moves[2] = possible_moves[3];
        possible_moves[3] = temp;
    }

    return possible_moves;
}

int get_next_move(int maze[N][N], point end)
{
    move current = pop();

    if (current.position.x == end.x && current.position.y == end.y)
    {
        push(current);
        return 1;
    }

    move next;
    int i = current.direction;
    point possible_moves[4] = get_optimized_moves(current.position, end);
    while (!is_valid(possible_moves[i], maze) && i < 4)
    {
        i++;
    }
    if (i >= 4)
    {
        return -1;
    }
    if (i == 3)
    {
        current = pop();
        get_next_move(maze, end);
    }
    else
    {
        current.direction = i;
        push(current);
        next.position = possible_moves[i];
        next.direction = 0;
        get_next_move(maze, end);
    }
}

int solve(int maze[N][N], point current, point end)
{
    move initial;
    int status;
    initial.position = current;
    initial.direction = 0;
    push(initial);
    status = get_next_move(maze, end);
    if (status == -1)
    {
        printf("\nMaze cannot be solved!\n");
    }
}

void print_solution(int maze[N][N])
{
    char sol[N][N];
    move current;

    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (maze[i][j])
            {
                sol[i][j] = '0';
            }
            else
            {
                sol[i][j] = '-';
            }
        }
    }

    while (top != -1)
    {
        current = pop();
        sol[current.position.x][current.position.y] = '*';
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            printf("%c ",sol[i][j]);
        }
        printf("\n");
    }
}