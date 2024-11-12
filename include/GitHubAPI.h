#ifndef GITHUBAPI_H
#define GITHUBAPI_H

#include <string>

std::string getUserRepositories(const std::string& username);
std::string getRepositoryCommits(const std::string& username, const std::string& repo);
void parseRepositories(const std::string& jsonResponse);  // Declare parseRepositories here


#endif // GITHUBAPI_H
