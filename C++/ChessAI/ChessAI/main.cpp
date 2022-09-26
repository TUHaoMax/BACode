#include <iostream>
#include <Python.h>
#include "OP.h"

int main() {
    //std::cout << "Hello, World!" << std::endl;
    /*std::string key;
    std::string move;
    std::string checkKey;

    Py_Initialize();
    //PyRun_SimpleString("print('Hello World_ python')");
   // PyRun_SimpleString("import Op;");
   // PyRun_SimpleString("print (Op.Make_url(\"m=1&n=1\"))");
    PyObject *pModule, *pFunc,*pFunc_1,*pFunc_2;
    PyObject *pArgs,* pArgs_m, *pValue_k, *pValue_m,*pValue_c;

    pModule = PyImport_Import(PyUnicode_FromString("Op"));
    //pModule = PyImport_ImportModule("test");

    pFunc = PyObject_GetAttrString(pModule, (char *)"get_keys");
    pFunc_1= PyObject_GetAttrString(pModule, (char *)"get_Moves");
    pFunc_2= PyObject_GetAttrString(pModule, (char *)"check");
    //pArgs = PyTuple_New(10);
    //PyTuple_SetItem(pArgs, 0, PyBytes_FromString("m=1&n=1"));
    pArgs = PyTuple_Pack(1,PyBytes_FromString("m=1&n=1"));
    pArgs_m = PyTuple_Pack(1,PyBytes_FromString("m=1&n=1+d4"));


    pValue_k = PyObject_CallObject(pFunc, pArgs);
    key= PyBytes_AsString(pValue_k);
    std::cout << key << std::endl;

    pValue_m = PyObject_CallObject(pFunc_1, pArgs);
    move= PyBytes_AsString(pValue_m);
    std::cout << move << std::endl;

    pValue_c = PyObject_CallObject(pFunc_2, pArgs_m);
    checkKey= PyBytes_AsString(pValue_c);
    std::cout << checkKey << std::endl;


    Py_Finalize();*/
    OP op=OP();
    op.test();

    std::cout <<  op.getKey("m=1&n=1")<< std::endl;

    std::cout << op.getMove("m=1&n=1")<< std::endl;

    std::cout << op.checkMove("m=1&n=1+d4")<< std::endl;



    return 0;
}

