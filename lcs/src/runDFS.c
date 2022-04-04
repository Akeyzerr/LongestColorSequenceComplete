#include <stdlib.h>

#include <runDFS.h>
#include <Vector.h>
#include <Defines.h>
#include <helpers.h>

static void addPixelToStack(int x, int y, Vector *stack, char **matrix, char color)
{
    Pixel *px = malloc(sizeof(Pixel));
    px->x = x;
    px->y = y;
    px->color = color;
    vectorPush(stack, px);
    matrix[x][y] = 'x';
    return;
}

static void pushValidAdjToStack(int x, int y, Vector *stack, char **matrix, int matrixSize, char color)
{
    for (Direction dir = LEFT; dir <= DOWN; dir++)
    {
        if (isValidDirection(x, y, dir, matrixSize, matrix, color))
        {
            addPixelToStack(x + DIRECTION[dir][X], y + DIRECTION[dir][Y], stack, matrix, color);
        }
    }
}

int runDFS(int x, int y, char **matrix, int matrixSize)
{
    int potential = 1;
    char color = matrix[x][y];
    Vector stack;
    vectorInit(&stack, matrixSize);

    matrix[x][y] = 'x';
    pushValidAdjToStack(x, y, &stack, matrix, matrixSize, color);

    while (stack.size > 0)
    {
        Pixel *px = vectorBack(&stack);
        vectorPop(&stack);
        potential++;
        pushValidAdjToStack(px->x, px->y, &stack, matrix, matrixSize, color);
    }

    vectorFree(&stack);
    return potential;
}
