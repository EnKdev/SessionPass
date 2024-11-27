//
// Created by EnKdev on 27.11.2024.
//

#include <iostream>
#include <ostream>

#include "../OtsvCode.h"

void eval(bool isSame) {
    if (isSame) {
        std::cout << "Code check success" << std::endl;
    } else {
        std::cout << "Code check failed" << std::endl;
    }
}

int main(int argc, char* argv[]) {
    auto oc = EnKdev::SessionPass::OtsvCode();
    auto isSame = false;
    auto otsvCode = "";

    std::cout << "TEST1 - Code Check (small) [codeFlag=0]" << std::endl;
    otsvCode = oc.requestOtsvCode(0).c_str();
    std::cout << "Received code (" << otsvCode << "), checking for integrity..." << std::endl;
    isSame = oc.compareOtsvCode(otsvCode, 0);
    eval(isSame);

    std::cout << "------------------" << std::endl;

    std::cout << "TEST2 - Code Check (medium) [codeFlag=1]" << std::endl;
    otsvCode = oc.requestOtsvCode(1).c_str();
    std::cout << "Received code (" << otsvCode << "), checking for integrity..." << std::endl;
    isSame = oc.compareOtsvCode(otsvCode, 1);
    eval(isSame);

    std::cout << "------------------" << std::endl;

    std::cout << "TEST3 - Code Check (large) [codeFlag=2]" << std::endl;
    otsvCode = oc.requestOtsvCode(2).c_str();
    std::cout << "Received code (" << otsvCode << "), checking for integrity..." << std::endl;
    isSame = oc.compareOtsvCode(otsvCode, 2);
    eval(isSame);

    std::cout << "------------------" << std::endl;

    std::cout << "TEST4 - Code Faking" << std::endl;
    std::cout << "Setting otsvCode to abskd" << std::endl;
    otsvCode = "abskd";
    std::cout << "Received code, checking for integrity..." << std::endl;
    isSame = oc.compareOtsvCode(otsvCode, 2);
    eval(isSame);

    std::cout << "------------------" << std::endl;

    std::cout << "TEST5 - Null/Empty string" << std::endl;
    std::cout << "Setting otsvCode to Null/Empty" << std::endl;
    otsvCode = "";
    std::cout << "Received code, checking for integrity..." << std::endl;
    isSame = oc.compareOtsvCode(otsvCode, 2);

    std::cout << "Press any key to conclude the test..." << std::endl;

    std::cin.get();

    return 0;
}