#include <Python.h>
#include <Defines.h>
#include <helpers.h>
#include <runDFS.h>

int main(int argc, char **argv)
{
  if (argc > 1)
  {

    for (int file = 1; file < argc; file++) // read multiple files
    {
      printf("%s\n", argv[file]);
      int canvasSize = 0;
      char **canvas = loadMatrix(argv[file], &canvasSize);

      if (NULL != canvas)
      {
        int topPathLen = 0;
        int potentialLen = 0;

        for (int i = 0; i < canvasSize; i++)
        {
          for (int j = 0; j < canvasSize; j++)
          {
            if (canvas[i][j] == 'x')
            {
              continue;
            }
            potentialLen = runDFS(i, j, canvas, canvasSize);
            topPathLen = potentialLen > topPathLen ? potentialLen : topPathLen;
          }
        }

        printf("%d\n", topPathLen);
        freeMatrix(canvas, canvasSize);
      }
    }
  }
  return EXIT_SUCCESS;
}