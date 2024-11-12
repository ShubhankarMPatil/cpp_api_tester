#include "../include/TestUtils.h"
#include <iostream>

bool assertStatusCode(int actual, int expected) {
    return actual == expected;
}

bool assertNotEmpty(const std::string& responseBody) {
    return !responseBody.empty();
}

void printTestResult(const std::string& testName, bool result) {
    std::cout << testName << ": " << (result ? "PASSED" : "FAILED") << std::endl;
}
