#include <iostream>
#include <list>
#include<sstream>
#include<catch.hpp>

using namespace std;

bool isEqual(string::iterator first,
    string::iterator firstEnd,
    string::iterator second,
    string::iterator secondEnd) {

    while (first!=firstEnd || second!= secondEnd)
    {
        if (*first!=*second&&*second!='?')
        {
            return false;
        }
        first++;
        second++;
    }
    if (first != firstEnd || second != secondEnd)
    {
        return false;
    }
    return true;

}

bool isEqualStrings(string first, string second) {
    if (first.length() != second.length())
    {
        return false;
    }
    return isEqual(first.begin(), first.end(), second.begin(), second.end());
}

list<string::iterator> findSubStrings(string::iterator dataIter, string::iterator dataEnd, string subString) {
    list<string::iterator> res = {};
    size_t subLength = subString.length();
    auto dataEndPoint = dataEnd -subLength+1;
    while (dataIter!= dataEndPoint)
    {
        if (isEqual(dataIter,dataIter+subLength,subString.begin(), subString.end()))
        {
            res.push_back(dataIter);
        }
        dataIter++;
    }
    return res;
        
}

bool isMatchRecursive(string::iterator dataIter, string::iterator dataEnd, list<string> params) {
    if (params.empty()) {
        return dataIter == dataEnd;
    }
    auto locations = findSubStrings(dataIter, dataEnd, params.front());
    size_t param_size = params.front().size();
    params.pop_front();
    bool res = false;
    for (auto iter : locations)
    {
        res |= isMatchRecursive(iter+param_size,dataEnd,params);
    }
    return res;
}

bool isMatch(string s, string p) {
  
    stringstream cutter(p);
    string subP;
    list<string> params = {};
    size_t params_length = 0;

    if (p.find('*')==string::npos)
    {
        return isEqualStrings(s, p);
    }

    while (!cutter.eof())
    {
        getline(cutter, subP, '*');
        if (subP != "")
        {
            params.push_back(subP);
            params_length += subP.length();
        }
    }

    if (params.empty())
        return true;
    if (params_length>s.length())
        return false;


    return isMatchRecursive(s.begin(), s.end(), params);
}

int main(int argc, char* argv[]) {
    int result = Catch::Session().run(argc, argv);

    return result;
}

TEST_CASE("Basic values") {
    REQUIRE(!isMatch("aa", "a"));
    REQUIRE(isMatch("aa", "*"));
    REQUIRE(!isMatch("cb", "?a"));
}

TEST_CASE("Classic values") {
    REQUIRE(isMatch("abc", "abc"));//4
    REQUIRE(isMatch("a123a456", "a*a*"));
    REQUIRE(isMatch("12aabababc", "*a*ab*abc"));
}
TEST_CASE("Extreme values") {
    REQUIRE(isMatch("", ""));//7
    REQUIRE(isMatch("", "*"));
    REQUIRE(isMatch("a", "?"));
    REQUIRE(isMatch("a", "?*"));//10
    REQUIRE(isMatch("", "****"));
    REQUIRE(isMatch("a*a", "****"));
    REQUIRE(isMatch("aba", "****"));
}
TEST_CASE("Leetcode values") {
    REQUIRE(isMatch("abcabczzzde", "*abc???de*"));
}