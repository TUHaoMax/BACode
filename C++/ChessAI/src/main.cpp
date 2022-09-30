//
// Created by Florian on 30.03.2021.
//

#include "../lib/thc/src/thc.h"
#include "ChessGame.h"
#include "OnLineOP.h"
#include <cstring>
#include <iostream>

using namespace std;

int main(void)
{
    ChessGame game;
    game.gameHandler();

    /*OnLineOP onLineOp=OnLineOP();
    onLineOp.test();

    std::cout <<  onLineOp.getKey("m=1&n=1")<< std::endl;

    std::cout << onLineOp.getMove("m=1&n=1")<< std::endl;

    std::cout << onLineOp.checkMove("m=1&n=1+d4")<< std::endl;
*/
}