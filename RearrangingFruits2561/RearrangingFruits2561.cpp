#include<iostream>
#include<catch.hpp>
#include"solution.h"



int main(int argc, char* argv[]) {
	int result = Catch::Session().run(argc, argv);
	return result;
}

TEST_CASE("Base") {
	Solution sol;
	{
		vector<int> a = { 4,2,2,2 };
		vector<int> b = { 1,4,1,2 };
		REQUIRE(sol.minCost(a,b)==1);
	}
	{
		vector<int> a = { 2,3,4,1 };
		vector<int> b = { 3,2,5,1 };
		REQUIRE(sol.minCost(a,b)==-1);
	}
}