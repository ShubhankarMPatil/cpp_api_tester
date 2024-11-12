#include "../include/GitHubAPI.h"
#include "../include/curl/curl.h"
#include <iostream>
#include <string>
#include "../lib/nlohmann/json.hpp" // nlohmann JSON library

using json = nlohmann::json;

// Helper function to write cURL response data
size_t WriteCallback(void* contents, size_t size, size_t nmemb, void* userp) {
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

std::string getUserRepositories(const std::string& username) {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    
    if (curl) {
        std::string url = "https://api.github.com/users/" + username + "/repos";
        
        // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Add a User-Agent header (GitHub requires this header)
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "GitHubAPI_Client/1.0");

        // Set the write function to handle the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the cURL request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL Error: " << curl_easy_strerror(res) << std::endl;
        }
        
        // Clean up the cURL handle
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}

// Example function to get repository commits (you can expand as needed)
std::string getRepositoryCommits(const std::string& username, const std::string& repoName) {
    std::string readBuffer;
    CURL* curl = curl_easy_init();
    
    if (curl) {
        std::string url = "https://api.github.com/repos/" + username + "/" + repoName + "/commits";
        
        // Set the URL for the request
        curl_easy_setopt(curl, CURLOPT_URL, url.c_str());

        // Add a User-Agent header (GitHub requires this header)
        curl_easy_setopt(curl, CURLOPT_USERAGENT, "GitHubAPI_Client/1.0");

        // Set the write function to handle the response data
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        // Perform the cURL request
        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "cURL Error: " << curl_easy_strerror(res) << std::endl;
        }
        
        // Clean up the cURL handle
        curl_easy_cleanup(curl);
    }

    return readBuffer;
}


void parseRepositories(const std::string& jsonResponse) {
    try {
        // Parse the JSON response
        json repositories = json::parse(jsonResponse);
        
        // Loop through the repositories and print each repository name
        for (const auto& repo : repositories) {
            std::cout << "Repository Name: " << repo["name"] << std::endl;
            std::cout << "Repository Description: " << repo["description"] << std::endl;
            std::cout << "Repository URL: " << repo["html_url"] << std::endl;
            std::cout << "------" << std::endl;
        }
    } catch (const json::parse_error& e) {
        std::cerr << "JSON Parsing Error: " << e.what() << std::endl;
    }
}