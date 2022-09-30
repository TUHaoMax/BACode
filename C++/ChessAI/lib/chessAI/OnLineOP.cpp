//
// Created by htu on 28/09/2022.
//

#include "OnLineOP.h"

OnLineOP::OnLineOP() {
    std::cout << " OP Hello, World! getMove" << std::endl;
    Py_Initialize();
    std::cout << " OP Hello, World! getMove" << std::endl;
    pModule = PyImport_Import(PyUnicode_FromString("Op"));
    std::cout << " OP Hello, World! getMove" << std::endl;
    pFunc = PyObject_GetAttrString(pModule, (char *)"get_keys");

    pFunc_1= PyObject_GetAttrString(pModule, (char *)"get_Moves");
    pFunc_2= PyObject_GetAttrString(pModule, (char *)"check");
    std::cout << " OP Hello, World! getMove" << std::endl;
}

void OnLineOP::test(){
    std::cout << " OP 1!" << std::endl;
}
std::string OnLineOP::getKey(char *msg){
    std::cout << " OP 1 getKey!" << std::endl;
    pArgs = PyTuple_Pack(1, PyBytes_FromString(msg));
    pValue_k = PyObject_CallObject(pFunc, pArgs);
    key= PyBytes_AsString(pValue_k);
    return key;
}

std::string OnLineOP::getMove(char *msg){
    std::cout << " OP 1 getMove!" << std::endl;
    pArgs = PyTuple_Pack(1, PyBytes_FromString(msg));
    pValue_k = PyObject_CallObject(pFunc_1, pArgs);
    key= PyBytes_AsString(pValue_k);
    return key;
}

std::string OnLineOP::checkMove(char *msg){
    pArgs = PyTuple_Pack(1, PyBytes_FromString(msg));
    pValue_k = PyObject_CallObject(pFunc_2, pArgs);
    key= PyBytes_AsString(pValue_k);
    return key;
}