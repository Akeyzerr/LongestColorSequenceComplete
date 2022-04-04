#include <stdio.h>
#include <stdlib.h>
#include <helpers.h>

int DIRECTION[4][2] = {
    {0, -1},
    {-1, 0},
    {0, 1},
    {1, 0},
};

bool isValidAdjPosition(int startX, int startY, Direction dir, int matrixSize)
{
  return ((startX + DIRECTION[dir][X] >= 0) &&
          (startX + DIRECTION[dir][X] < matrixSize) &&
          (startY + DIRECTION[dir][Y] >= 0) &&
          (startY + DIRECTION[dir][Y] < matrixSize))
             ? true
             : false;
}

bool isValidDirection(int startX, int startY, Direction dir, int matrixSize, char *matrix[matrixSize], char color)
{
  if ((isValidAdjPosition(startX, startY, dir, matrixSize)))
  {
    return (matrix
                [startX + DIRECTION[dir][X]]
                [startY + DIRECTION[dir][Y]] == color)
               ? true
               : false;
  }
  return false;
}

void freeMatrix(char **matrix, int size)
{
  for (int i = 0; i < size; i++)
  {
    free(matrix[i]);
  }
  free(matrix);
}

char **loadMatrix(char *filename, int *matrixSize)
{
  int sizeX = 0, sizeY = 0;
  FILE *testInput = NULL;
  char **matrix = NULL;

  testInput = fopen(filename, "r");
  if (NULL == testInput)
  {
    perror("Filename not found.\n");
    return NULL;
  }

  fscanf(testInput, "%d %d ", &sizeX, &sizeY); // mind the expected input format
  matrix = (char **)malloc(sizeY * sizeof(char *));

  for (int i = 0; i < sizeX; i++)
  {
    (*matrixSize)++;
    // printf("%d == %d?\n", *matrixSize, sizeX);
  }

  for (int i = 0; i < sizeX; i++)
  {
    matrix[i] = (char *)malloc(sizeX * sizeof(char));
  }

  for (int k = 0; k < sizeX; k++)
  {
    for (int v = 0; v < sizeY; v++)
    {
      fscanf(testInput, "%c ", &matrix[k][v]);
    }
  }
  return matrix;
}

void printMatrix(char **m, int x, int y)
{
  for (int i = 0; i < x; i++)
  {
    for (int j = 0; j < y; j++)
    {
      printf("%c ", m[i][j]);
    }
    printf("\n");
  }
}
