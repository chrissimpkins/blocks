/* pyc.h
*    - A Python function wrapper for C++
*  Copyright 2013 Christopher Simpkins.  MIT License
*/

#include <iostream>
#include <string>

#include <Python.h>

using std::cout;
using std::cerr;
using std::endl;
using std::string;

//Declarations
PyObject* get_PyCallable_From_PyModule(const char*, const char*);
template<typename F, typename... Args>
int python_Call(F&, const char*, Args...);

/*
*  Initialize Python
*/

int python_Initialize(){
	Py_Initialize();
	PyObject *sys = PyImport_ImportModule("sys");
	PyObject *path = PyObject_GetAttrString(sys, "path");
	PyList_Append(path, PyString_FromString("."));
	Py_DECREF(sys);
	Py_DECREF(path);
}

/*
*  Get a callable object from a Python module
*/
PyObject* get_PyCallable_From_PyModule(const char* py_modulename, const char* py_callable) {
	PyObject* uni_name = PyUnicode_FromString(py_modulename);
	PyObject* py_module = PyImport_Import(uni_name);
	Py_DECREF(uni_name);
	if (py_module != NULL){
		return PyObject_GetAttrString(py_module, py_callable);
	}
	else {
		PyErr_Print();
		cerr << "Unable to import the Python module" << endl;
		Py_XDECREF(py_module);
		//TO DO : throw exception
	}
}


/*
*  Secure the GIL & call a Python function
*     -- C++ variadic template that permits one or more arguments to be passed
*/
template<typename F, typename... Args>
int python_Call(F& py_func, const char* argtypes, Args... py_args){
	PyObject* args;
	PyObject* kwargs;
	PyObject* result = nullptr;

	/* Secure the GIL */
	PyGILState_STATE state = PyGILState_Ensure();

	/* Confirm that py_func is a callable */
	if (!PyCallable_Check(py_func)){
		cerr << "You did not supply a Python callable as your first argument";
		Py_XDECREF(result);
		PyGILState_Release(state);
	}

	/* Build the argument list for the callable */
	args = Py_BuildValue(argtypes, py_args...);
	//cout << sizeof...(py_args) << endl;
	kwargs = NULL;

	/* Call the function */
	result = PyObject_Call(py_func, args, kwargs);
	Py_DECREF(args);
	Py_XDECREF(kwargs);

	/* Check for Python exceptions */
	if (PyErr_Occurred()){
		PyErr_Print();
		Py_XDECREF(result);
		PyGILState_Release(state);
	}

	/* Verify that the result is the appropriate type */
	//if (!PyFloat_Check(result)){
	//	cerr << "The function did not return the appropriate result type" << endl;
	//	Py_XDECREF(result);
	//	PyGILState_Release(state);
	//}

	/* Create the return value */
	//double retval = PyFloat_AsDouble(result);
	Py_DECREF(result);

	/* Restore GIL state */
	PyGILState_Release(state);
	return 0;
}

/*
*  Close the Python interpreter
*/
int python_Finalize() {
	Py_Finalize();
}


int main2 () {
	/*PyObject* mult_func;
	Py_Initialize();
	PySys_SetPath(".");
	mult_func = get_PyCallable_From_PyModule("multiply", "multiply");
	double x = 3;
	double y = 4;
	double mult_result = py_Call(mult_func, "(dd)", x, y);
	cout << mult_result << endl;
	Py_DECREF(mult_func);
	Py_Finalize();
	return 0;*/
}