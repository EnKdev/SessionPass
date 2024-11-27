//
// Created by EnKdev on 27.11.2024.
//

#include "OtsvCode.h"
#include "HttpHelper.h"

#include <map>


std::string EnKdev::SessionPass::OtsvCode::requestOtsvCode(int codeFlag) {
    std::map<std::string, std::string> pairs = {
        {"cf", std::to_string(codeFlag)}
    };

    std::string res = HttpHelper::httpPost("https://enkdev.xyz/cdn/php/sessionpass/generateOtsvCode.php", pairs);
    return res;
}

bool EnKdev::SessionPass::OtsvCode::compareOtsvCode(const std::string &otsvCode, int codeFlag) {
    bool isSame = false;

    if (!otsvCode.empty()) {
        std::map<std::string, std::string> pairs = {
            {"code", otsvCode},
            {"cf", std::to_string(codeFlag)}
        };

        std::string res = HttpHelper::httpPost("https://enkdev.xyz/cdn/php/sessionpass/compareCode.php", pairs);

        if (res == "true") {
            isSame = true;
        }
    } else {
        std::cout << "otsvCode is null, can't check." << std::endl;
    }

    return isSame;
}
