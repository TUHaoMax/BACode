
#include <iostream>
#include <cpr/cpr.h>
#include "CommunicationTest.h"
#include <windows.h>

int main(int argc, char** argv) {


    std::string move = "";
    std::string key = "m=1&n=1";
    DWORD t1, t2;

    CommunicationTest com = CommunicationTest("http://127.0.0.1:5000/");

    for (int i = 0; i < 7; i++) {
        std::cout << "round: " << i + 1 << std::endl;
        t1 = GetTickCount();

        move = com.Send("get_Move", key);
        std::cout << move << std::endl;

        key = com.Send("get_Key", key);
        std::cout << key << std::endl;

        t2 = GetTickCount();
        
        std::cout << "end round: " << i + 1 << std::endl;
        std::cout << "time = " << ((t2 - t1) * 1.0 / 1000) << std::endl;
        std::cout << "################# " << std::endl;
        std::cout << " " << std::endl;
    }
    return 0;
}