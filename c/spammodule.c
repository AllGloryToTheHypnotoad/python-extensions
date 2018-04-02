#include <Python.h>  // defines some pre-processor commands

// static struct PyModuleDef spammodule = {
//     PyModuleDef_HEAD_INIT,
//     "spam",   // name of module
// };
//
// PyMODINIT_FUNC
// PyInit_spam(void) {
//     PyObject* m = PyModule_Create(&spammodule);
//     if (m == NULL) {
//         return NULL;
//     }
//     return m;
// }

static PyObject *SpamError;

PyMODINIT_FUNC
initspam(void)
{
    PyObject *m;

    m = Py_InitModule("spam", SpamMethods);
    if (m == NULL)
        return;

    SpamError = PyErr_NewException("spam.error", NULL, NULL);
    Py_INCREF(SpamError);
    PyModule_AddObject(m, "error", SpamError);
}

static PyObject *
spam_system(PyObject *self, PyObject *args)
{
    const char *command;
    int sts;

    if (!PyArg_ParseTuple(args, "s", &command))
        return NULL;
    sts = system(command);
    if (sts < 0) {
        PyErr_SetString(SpamError, "System command failed");
        return NULL;
    }
    return PyLong_FromLong(sts);
}
