//
// Created by htu on 28/09/2022.
//

#ifndef CHESSAI_ONLINEOP_H
#define CHESSAI_ONLINEOP_H
#include <iostream>
#include <Python.h>

class OnLineOP
{
  public:
    std::string key;
    std::string move;
    std::string checkKey;
    PyObject *pModule, *pFunc,*pFunc_1,*pFunc_2;
    PyObject *pArgs,* pArgs_m, *pValue_k, *pValue_m,*pValue_c;

    OnLineOP();
    void test();
    std::string getKey(char *msg);
    std::string getMove(char *msg);
    std::string checkMove(char *msg);
};

#endif // CHESSAI_ONLINEOP_H
