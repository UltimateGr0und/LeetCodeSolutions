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
	{
		vector<int> a = { 3350,1104,2004,1577,1365,2088,2249,1948,2621,750,31,2004,1749,3365,3350,3843,3365,1656,3168,3106,2820,3557,1095,2446,573,2464,2172,1326,2712,467,1104,1446,1577,53,2492,2638,1200,2997,3454,2492,1926,1452,2712,446,2997,2820,750,2529,3847,656,272,3873,530,1749,1743,251,3847,31,251,515,2858,126,2491 };
		vector<int> b = { 530,1920,2529,2317,1969,2317,1095,2249,2858,2636,3772,53,3106,2638,1267,1926,2882,515,3772,1969,3454,2446,656,2621,1365,1743,3557,1656,3447,446,1098,1446,467,2636,1088,1098,2882,1088,1326,644,3873,3843,3926,1920,2464,2088,205,1200,1267,272,925,925,2172,2491,3168,644,1452,573,1948,3926,205,126,3447 };
		REQUIRE(sol.minCost(a, b) == 837);
	}
}