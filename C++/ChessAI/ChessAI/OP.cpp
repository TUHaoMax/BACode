//
// Created by tpztp on 01.12.2021.
//

#include "OP.h"

OP::OP() {
    std::cout << " OP Hello, World!" << std::endl;
    Py_Initialize();
    pModule = PyImport_Import(PyUnicode_FromString("Op"));
    pFunc = PyObject_GetAttrString(pModule, (char *)"get_keys");
    pFunc_1= PyObject_GetAttrString(pModule, (char *)"get_Moves");
    pFunc_2= PyObject_GetAttrString(pModule, (char *)"check");
}

void OP::test(){
    std::cout << " OP 1!" << std::endl;
}
std::string OP::getKey(char *msg){
    pArgs = PyTuple_Pack(1, PyBytes_FromString(msg));
    pValue_k = PyObject_CallObject(pFunc, pArgs);
    key= PyBytes_AsString(pValue_k);
    return key;
}

std::string OP::getMove(char *msg){
    pArgs = PyTuple_Pack(1, PyBytes_FromString(msg));
    pValue_k = PyObject_CallObject(pFunc_1, pArgs);
    key= PyBytes_AsString(pValue_k);
    return key;
}

std::string OP::checkMove(char *msg){
    pArgs = PyTuple_Pack(1, PyBytes_FromString(msg));
    pValue_k = PyObject_CallObject(pFunc_2, pArgs);
    key= PyBytes_AsString(pValue_k);
    return key;
}