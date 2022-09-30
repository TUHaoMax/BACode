#include <iostream>
#include <Python.h>
#include "OP.h"


int main() {

    OP op=OP();
    op.test();

    std::cout <<  op.getKey("m=1&n=1")<< std::endl;

    std::cout << op.getMove("m=1&n=1")<< std::endl;

    std::cout << op.checkMove("m=1&n=1+d4")<< std::endl;



    return 0;
}

