#ifndef VECTOR_H_
#define VECTOR_H_

#include <stddef.h>
#include <stdbool.h>

typedef struct _pixel
{
  int x;
  int y;
  char color;
} Pixel;

typedef struct _vector
{
  Pixel **matrix;
  size_t capacity;
  size_t size;
} Vector;

void vectorInit(Vector *vec, size_t initialCapacity);
size_t vectorGetSize(Vector *vec);
bool vectorIsEmpty(Vector *vec);
void vectorResize(Vector *vec, size_t newSize);
void vectorPush(Vector *vec, Pixel *pixel);
void vectorSet(Vector *vec, size_t idx, Pixel *pixel);
void *vectorGet(Vector *vec, size_t idx);
void *vectorBack(Vector *vec);
void vectorDelete(Vector *vec, size_t idx);
void vectorPop(Vector *vec);
void vectorFree(Vector *vec);

#endif /* VECTOR_H_ */
