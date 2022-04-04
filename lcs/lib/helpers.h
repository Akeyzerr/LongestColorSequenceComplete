#ifndef __HELPERS_LONGEST_SEQ_H__
#define __HELPERS_LONGEST_SEQ_H__

#include <stdbool.h>
#include <Defines.h>

bool isValidAdjPosition(int startX, int startY, Direction dir, int matrixSize);
bool isValidDirection(int startX, int startY, Direction dir, int matrixSize, char *matrix[matrixSize], char color);
void freeMatrix(char **matrix, int size);
char **loadMatrix(char *filename, int *matrixSize);
void printMatrix(char **m, int x, int y);

#endif /* __HELPERS_LONGEST_SEQ_H__ */