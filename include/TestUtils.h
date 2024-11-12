#ifndef TESTUTILS_H
#define TESTUTILS_H

#include <string>

bool assertStatusCode(int actual, int expected);
bool assertNotEmpty(const std::string& responseBody);
void printTestResult(const std::string& testName, bool result);

#endif // TESTUTILS_H
