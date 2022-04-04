#include <stdlib.h>
#include <stdio.h>
#include <Vector.h>

void vectorInit(Vector *vec, size_t initialCapacity)
{
  vec->capacity = initialCapacity;
  vec->size = 0;
  do
  {
    vec->matrix = malloc(sizeof(Pixel *) * vec->capacity);
  } while (!vec->matrix);
}

size_t vectorGetSize(Vector *v)
{
  return v->size;
}

bool vectorIsEmpty(Vector *vec)
{
  return vec->size == 0;
}

void vectorResize(Vector *vec, size_t capacity)
{
  Pixel **matrix = realloc(vec->matrix, sizeof(Pixel *) * capacity);
  if (matrix)
  {
    vec->matrix = matrix;
    vec->capacity = capacity;
  }
  if (vec->size >= capacity)
  {
    vec->size = capacity;
  }
}

void vectorPush(Vector *vec, Pixel *pixel)
{
  if (vec->capacity == vec->size)
  {
    vectorResize(vec, vec->capacity * 2);
  }
  vec->matrix[vec->size] = pixel;
  vec->size++;
}

void vectorSet(Vector *vec, size_t idx, Pixel *pixel)
{
  if (idx < vec->size)
  {
    vec->matrix[idx] = pixel;
  }
}

void *vectorGet(Vector *vec, size_t idx)
{
  if (idx < vec->size)
  {
    return vec->matrix[idx];
  }
  return NULL;
}

void *vectorBack(Vector *vec)
{
  if (0 == vec->size)
  {
    return NULL;
  }
  return vec->matrix[vec->size - 1];
}

void vectorDelete(Vector *vec, size_t idx)
{
  if (idx >= vec->size)
  {
    return;
  }

  vec->matrix[idx] = NULL;

  for (size_t i = idx; i < vec->size - 1; ++i)
  {
    vec->matrix[i] = vec->matrix[i + 1];
    vec->matrix[i + 1] = NULL;
  }
  vec->size--;
}

void vectorPop(Vector *vec)
{
  if (vec->size == 0)
  {
    return;
  }

  vec->size--;
}

void vectorFree(Vector *vec)
{
  if (vec->matrix != NULL)
  {
    free(vec->matrix);
    vec->matrix = NULL;
    vec->size = 0;
    vec->capacity = 0;
  }
}
