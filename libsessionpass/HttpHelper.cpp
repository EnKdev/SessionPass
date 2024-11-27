//
// Created by EnKdev on 27.11.2024.
//

#include "HttpHelper.h"

#include <curl/curl.h>

std::string EnKdev::SessionPass::HttpHelper::httpPost(const std::string &uri,
    const std::map<std::string, std::string> &pairs) {
    std::string response;

    curl_global_init(CURL_GLOBAL_DEFAULT);

    if (CURL *curl = curl_easy_init()) {
        curl_easy_setopt(curl, CURLOPT_URL, uri.c_str());

        // Preparation - POST fields
        std::string post_fields;

        for (const auto& pair : pairs) {
            if (!post_fields.empty()) {
                post_fields += "&";
            }

            post_fields += curl_easy_escape(curl, pair.first.c_str(), pair.first.length());
            post_fields += "=";
            post_fields += curl_easy_escape(curl, pair.second.c_str(), pair.second.length());
        }

        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, post_fields.c_str());

        // Setup write callback to capture the response from the webserver
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &response);

        CURLcode res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();

    return response;
}

