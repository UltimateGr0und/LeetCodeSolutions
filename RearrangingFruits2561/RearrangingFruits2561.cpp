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

TEST_CASE("Common values") {
	Solution sol;
	{
		vector<int> a = { 1 };
		vector<int> b = { 1 };
		REQUIRE(sol.minCost(a,b)==0);
	}
	{
		vector<int> a = { 1,2,3 };
		vector<int> b = { 1,3,2 };
		REQUIRE(sol.minCost(a, b) == 0);
	} {
		vector<int> a = { 1,1,1 };
		vector<int> b = { 2,2,2 };
		REQUIRE(sol.minCost(a, b) == -1);
	}
}

TEST_CASE("Advanced values") {
	Solution sol;
	{
		vector<int> a = { 84,80,43,8,80,88,43,14,100,88 };
		vector<int> b = { 32,32,42,68,68,100,42,84,14,8 };
		REQUIRE(sol.minCost(a, b) == 48);
	}
}