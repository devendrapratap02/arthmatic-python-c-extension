#include<Python.h>

static PyObject *info(PyObject *self)
{
   return Py_BuildValue("s", "Hello, Welcome to the Arthmatic Library Extensions!!");
}

static PyObject *add(PyObject *self, PyObject *args) {
    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    return Py_BuildValue("i", a + b);
}

static PyObject *subtract(PyObject *self, PyObject *args) {
    int a, b;

    if (!PyArg_ParseTuple(args, "ii", &a, &b)) {
        return NULL;
    }

    return Py_BuildValue("i", a - b);
}

static PyMethodDef arthmatic_funcs[] = {
    {
        "info", 
        (PyCFunction)info,
        METH_NOARGS,
        "A simple Arthmatic C Extension Library"
    },
    {
        "add", 
        (PyCFunction)add,
        METH_VARARGS,
        "A method to perform sum of 2 numbers"
    },
    {
        "subtract", 
        (PyCFunction)subtract,
        METH_VARARGS,
        "A method to perform substraction of 2 numbers"
    },
    {
        NULL
    }
};

static struct PyModuleDef arthmatic_module = {
    PyModuleDef_HEAD_INIT,
    "arthmatic",
    "Python interface for the C library function",
    -1,
    arthmatic_funcs
};

PyMODINIT_FUNC PyInit_arthmatic(void)
{
   return PyModule_Create(&arthmatic_module);
}
