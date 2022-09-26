//
// Created by tpztp on 01.12.2021.
//

#ifndef ONLINEOPENING_OP_H
#define ONLINEOPENING_OP_H
#include <iostream>
#include <Python.h>

class OP {


public:
    std::string key;
    std::string move;
    std::string checkKey;
    PyObject *pModule, *pFunc,*pFunc_1,*pFunc_2;
    PyObject *pArgs,* pArgs_m, *pValue_k, *pValue_m,*pValue_c;

    OP();
    void test();
    std::string getKey(char *msg);
    std::string getMove(char *msg);
    std::string checkMove(char *msg);
};


#endif //ONLINEOPENING_OP_H
