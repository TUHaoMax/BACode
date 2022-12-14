#include "ChessGame.h"
#include "AbstractChessPlayer.h"
#include "ChessAI.h"
#include "HumanChessPlayer.h"
#include "OnLineOP.h"
#include <windows.h>
#include <algorithm>
#include <memory>

using namespace std;
using ChessPlayerPtr = std::shared_ptr<AbstractChessPlayer>;

void ChessGame::gameHandler()
{
    string move="";
    string key="m=1&n=1";
    DWORD t1, t2;
    OnLineOP onLineOp=OnLineOP();


    for (int i = 0; i<7;i++)
    {
        std::cout << "round: " << i + 1 << std::endl;
        t1 = GetTickCount();
        char* Ckey = strcpy(Ckey, key.c_str());
        ;

        move = onLineOp.getMove(Ckey);
        std::cout << "move: " << move << std::endl;

        key = onLineOp.getKey(Ckey);
        std::cout << "key: " << key << std::endl;

        t2 = GetTickCount();

        std::cout << "end round: " << i + 1 << std::endl;
        std::cout << "time = " << ((t2 - t1) * 1.0 / 1000) << std::endl;
        std::cout << "################# " << std::endl;
        std::cout << " " << std::endl;
    }
    /*ChessPlayerPtr whitePlayer = nullptr;
    ChessPlayerPtr blackPlayer = nullptr;
    while(true)
    {
        string userColorChoice = "white";
        cout << "Enter your color(white/black): ";
        getline(cin, userColorChoice);
        transform(userColorChoice.begin(), userColorChoice.end(), userColorChoice.begin(),
                  ::tolower);
        if(userColorChoice.compare("black") == 0)
        {
            whitePlayer = ChessPlayerPtr(new ChessAI(true));
            blackPlayer = ChessPlayerPtr(new HumanChessPlayer(false));
            break;
        }
        else if(userColorChoice.compare("white") == 0)
        {
            blackPlayer = ChessPlayerPtr(new ChessAI(false));
            whitePlayer = ChessPlayerPtr(new HumanChessPlayer(true));
            break;
        }
        else
            cout << "Invalid Input! Try again" << endl;
    }

    bool whitesMove = true;
    string move;
    thc::Move mv;

    while(1)
    {
        printBoardState();
        if(whitesMove)
        {
            do
            {
                move = whitePlayer->chooseMove(board);
                cout << " whitePlayer" <<move<< endl;
            } while(!mv.TerseIn(&board, move.c_str()));
        }
        else
        {
            do
            {
                move = blackPlayer->chooseMove(board);
                cout << " blackPlayer" <<move<< endl;
            } while(!mv.TerseIn(&board, move.c_str()));
        }
        board.PlayMove(mv);
        cout << " PlayMove" << endl;

        thc::TERMINAL evalPosition;
        board.Evaluate(evalPosition); // detect mate
        thc::DRAWTYPE eval_draw;
        board.IsDraw(board.white, eval_draw); // detect draw
        if(eval_draw == thc::DRAWTYPE_50MOVE || eval_draw == thc::DRAWTYPE_REPITITION ||
           eval_draw == thc::DRAWTYPE_INSUFFICIENT_AUTO)
        {
            printBoardState();
            cout << "Final Move: " << move << endl;
            cout << " Draw" << endl;
            break;
        }
        else if(evalPosition == 2 || evalPosition == -2)
        {
            printBoardState();
            cout << "Final Move: " << move << endl;
            cout << "Draw" << endl;
            break;
        }
        else if(evalPosition == 1)
        {
            printBoardState();
            cout << "Final Move: " << move << endl;
            cout << "White won!" << endl;
            break;
        }
        else if(evalPosition == -1)
        {
            printBoardState();
            cout << "Final Move: " << move << endl;
            cout << "Black won!" << endl;
            break;
        }

        whitesMove = !whitesMove;
    }*/
}

// print board
void ChessGame::printBoardState()
{
    int i = 0;
    for(char c : board.squares)
    {
        if(i % 8 == 0 && i != 64)
            cout << "|" << endl
                 << "   +---+---+---+---+---+---+---+---+" << endl
                 << " " << ((64 - i) / 8) << " ";
        cout << "| " << c << " ";
        i++;
    }
    cout << endl << "   +---+---+---+---+---+---+---+---+" << endl;
    cout << "     a   b   c   d   e   f   g   h " << endl;
}
