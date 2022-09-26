#include <iostream>
#include <Windows.h>
#include "HttpRequest.h"
#include <iostream>
#include <Windows.h>

int main(int argc, char** argv) {

        HttpRequest httpReq("127.0.0.1", 5000);

        std::string res = httpReq.HttpGet("");
        std::cout << "send:  "<<res << std::endl;
        Sleep(1000);

        //res = httpReq.HttpPost("/postsomething/", HttpRequest::genJsonString("something", 100));
        //std::cout << res << std::endl;
        return 0;

}
