#include <iostream>
#include <list>
#include<sstream>
#include<catch.hpp>

using namespace std;

bool isMatch(string s, string p) {
    /*if (p == "*")
        return true;*/

    auto sIter = s.begin();
    stringstream cutter(p);
    string subP;

    while (!cutter.eof())
    {
        getline(cutter, subP, '*');

        auto subIter = subP.begin();
        while (subIter!=subP.end())
        {
            if (sIter == s.end())
                return false;
            if (*subIter==*sIter || *subIter=='?')
            {
                subIter++;
            }
            else {
                subIter = subP.begin();
                if (*subIter == *sIter || *subIter == '?')
                {
                    subIter++;
                }
            }

            sIter++;
        }

    }
    if (p.size()>0)
    if (p.at(p.length() - 1)=='*')
    {
        return true;
    }

    return sIter==s.end()||sIter==s.begin();
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