#include "./include/util.hpp"

 string Util :: lowerCaseVersion(const string &word){
    string lowerVersion;
    for(char c : word) lowerVersion.push_back(tolower(c));
    return lowerVersion;
}
