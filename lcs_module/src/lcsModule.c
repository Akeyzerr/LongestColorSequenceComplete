#include <Python.h>
#include <Defines.h>
#include <helpers.h>
#include <runDFS.h>

int lcs(char *filename)
{
  int topPathLen = 0;

  int canvasSize = 0;
  char **canvas = loadMatrix(filename, &canvasSize);

  if (NULL != canvas)
  {
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
    freeMatrix(canvas, canvasSize);
  }
  return topPathLen;
}

static PyObject *py_lcs(PyObject *self, PyObject *args)
{
  char *filename = NULL;
  if (!PyArg_ParseTuple(args, "s", &filename))
  {
    return NULL;
  }
  int result = lcs(filename);

  return PyLong_FromLong(result);
}

static PyMethodDef lcsMethods[] = {
    {"longes_color_sequence", py_lcs, METH_VARARGS,
     "Given a grid with different colors in a different cell, each color represented by a different char (R, G, B) returns the largest connected component on the grid."},
    {NULL, NULL, 0, NULL}};

static struct PyModuleDef lonColSeq = {
    PyModuleDef_HEAD_INIT,
    "LongestColorSequence",
    "Given a grid with different colors in a different cell, each color represented by a different char (R, G, B) returns the largest connected component on the grid.",
    -1,
    lcsMethods};

PyMODINIT_FUNC PyInit_LonColSeq(void)
{
  return PyModule_Create(&lonColSeq);
};

int main(int argc, char *argv[])
{
  wchar_t *program = Py_DecodeLocale(argv[0], NULL);
  if (program == NULL)
  {
    fprintf(stderr, "Fatal error: cannot decode argv[0]\n");
    exit(1);
  }

  /* Add a built-in module, before Py_Initialize */
  if (PyImport_AppendInittab("LCS Module", PyInit_LonColSeq) == -1)
  {
    fprintf(stderr, "Error: could not extend in-built modules table\n");
    exit(1);
  }

  /* Pass argv[0] to the Python interpreter */
  Py_SetProgramName(program);

  /* Initialize the Python interpreter.  Required.
     If this step fails, it will be a fatal error. */
  Py_Initialize();

  /* Optionally import the module; alternatively,
     import can be deferred until the embedded script
     imports it. */
  PyObject *pmodule = PyImport_ImportModule("lonColSeq");
  if (!pmodule)
  {
    PyErr_Print();
    fprintf(stderr, "Error: could not import module 'Longes Color Sequence'\n");
  }
  
  PyMem_RawFree(program);
  return 0;
}