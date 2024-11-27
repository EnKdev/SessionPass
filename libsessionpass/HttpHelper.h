//
// Created by EnKdev on 27.11.2024.
//

#ifndef HTTPHELPER_H
#define HTTPHELPER_H

#include <string>
#include <iostream>
#include <map>

namespace EnKdev::SessionPass {
    /**
     * @class HttpHelper
     * @brief Provides mechanisms to send POST requests with a payload to a server.
     */
    class HttpHelper {
    public:
        /**
         * Sends an HTTP POST request with a given payload to a server.
         *
         * @param uri The target URL where the POST request should be sent to.
         * @param pairs The payload of the POST request.
         *
         * @return A string containing the server's response.
         */
        static std::string httpPost(const std::string& uri, const std::map<std::string, std::string>& pairs);

    private:
        static size_t writeCallback(void* contents, size_t size, size_t nmemb, std::string* userp) {
            size_t totalSize = size * nmemb;
            userp->append(static_cast<char*>(contents), totalSize);

            return totalSize;
        }
    };
}

#endif //HTTPHELPER_H
