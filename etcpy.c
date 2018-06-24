#include <Python.h>
#include "etc.h"

/*
 * Implements an example function.
 */
PyDoc_STRVAR(
    etc1_doc,
    "Decode ETC1 format bytes to RGBA bytes.\n\n"
        "Args:\n"
        "    rawdata(bytes): bytes of etc1 image data\n"
        "    width(int): original image's width\n"
        "    height(int): original image's height\n"
        "Return:\n"
        "    image(bytes) : decoded image data"
    );

PyObject *etc1(PyObject *self, PyObject *args, PyObject *kwargs) {
    /* Shared references that do not need Py_DECREF before returning. */
	const char *rawdata;
	int rawdata_len;
    int x = 0;
	int y = 0;

    /* Parse positional and keyword arguments */
    static char* keywords[] = { "rawdata", "width", "height", NULL };
	if (!PyArg_ParseTupleAndKeywords(args, kwargs, "y#ii", keywords, &rawdata, &rawdata_len, &x, &y)) {
        return NULL;
    }

    /* Function implementation starts here */
	uint32_t *image = (uint32_t*)calloc(x * y, sizeof(uint32_t));
	decode_etc1((uint64_t*)rawdata, x, y, image);

	return Py_BuildValue("y#", (char*)image, x * y * sizeof(uint32_t));
}

/*
 * List of functions to add to etcpy in exec_etcpy().
 */
static PyMethodDef etcpy_functions[] = {
    { "decode_etc1", (PyCFunction)etc1, METH_VARARGS | METH_KEYWORDS, etc1_doc },
    { NULL, NULL, 0, NULL } /* marks end of array */
};

/*
 * Initialize etcpy. May be called multiple times, so avoid
 * using static state.
 */
int exec_etcpy(PyObject *module) {
    PyModule_AddFunctions(module, etcpy_functions);

    PyModule_AddStringConstant(module, "__author__", "krepe-suZette");
    PyModule_AddStringConstant(module, "__version__", "0.1.0");
    PyModule_AddIntConstant(module, "year", 2018);

    return 0; /* success */
}

/*
 * Documentation for etcpy.
 */
PyDoc_STRVAR(etcpy_doc, "Decode ETC image data to RGBA string");


static PyModuleDef_Slot etcpy_slots[] = {
    { Py_mod_exec, exec_etcpy },
    { 0, NULL }
};

static PyModuleDef etcpy_def = {
    PyModuleDef_HEAD_INIT,
    "etcpy",
    etcpy_doc,
    0,              /* m_size */
    NULL,           /* m_methods */
    etcpy_slots,
    NULL,           /* m_traverse */
    NULL,           /* m_clear */
    NULL,           /* m_free */
};

PyMODINIT_FUNC PyInit_etcpy() {
    return PyModuleDef_Init(&etcpy_def);
}
