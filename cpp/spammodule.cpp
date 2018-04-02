#include <Python.h>

static struct PyModuleDef spammodule = {
    PyModuleDef_HEAD_INIT,
    "spam",   /* name of module */
};

PyMODINIT_FUNC
PyInit_spam(void) {
    PyObject* m = PyModule_Create(&spammodule);
    if (m == NULL) {
        return NULL;
    }
    return m;
}
