#include <iostream>
#include <list>
#include<sstream>
#include<catch.hpp>

using namespace std;

bool isMatch(string s, string p) {
    if (p == "*")
        return true;

    auto sIter = s.begin();
    stringstream cutter(p);
    string subP;

    while (!cutter.eof())
    {
        getline(cutter, subP, '*');

        auto subIter = subP.begin();
        while (subIter!=subP.end())
        {
            if (*subIter==*sIter || *subIter=='?')
            {
                subIter++;
            }
            else {
                subIter = subP.begin();
            }

            sIter++;
            if (sIter == s.end())
                return false;
        }

    }

    return sIter==s.end();
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