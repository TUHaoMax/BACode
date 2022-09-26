#include <iostream>
#include <Python.h>

#include "OP.h"

int main() {
   // std::cout << "Hello, World!" << std::endl;
    std::string key;
    //std::cout << "Hello, World!" << std::endl;
    /*std::string key;
    std::string move;
    std::string checkKey;

@ -40,7 +40,17 @@ int main() {
    std::cout << checkKey << std::endl;


    Py_Finalize();
    Py_Finalize();*/
    OP op=OP();
    op.test();

    std::cout <<  op.getKey("m=1&n=1")<< std::endl;

    std::cout << op.getMove("m=1&n=1")<< std::endl;

    std::cout << op.checkMove("m=1&n=1+d4")<< std::endl;



    return 0;
}