#include "../include/GitHubAPI.h"
#include "../include/TestUtils.h"
#include <iostream>
#include "../lib/nlohmann/json.hpp"  // Include the nlohmann json header

using json = nlohmann::json;

std::string response;

void testGetUserRepositories() {
    std::string username;
    std::cin >> username;
    response = getUserRepositories(username);
    
    bool notEmpty = assertNotEmpty(response);
    printTestResult("Get User Repositories Not Empty", notEmpty);

    // Parse and check if JSON data structure is as expected
    auto jsonResponse = json::parse(response);
    bool isArray = jsonResponse.is_array();
    printTestResult("Get User Repositories JSON Array", isArray);
}

int main() {
    std::cout << "Running GitHub API Tests...\n";
    testGetUserRepositories();
    parseRepositories(response);
        // Add more test cases as needed

    return 0;
}
