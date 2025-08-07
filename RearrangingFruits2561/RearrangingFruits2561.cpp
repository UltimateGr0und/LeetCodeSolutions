#include<iostream>
#include<catch.hpp>
#include"solution.h"



int main(int argc, char* argv[]) {
	int result = Catch::Session().run(argc, argv);
	return result;
}

TEST_CASE("Base") {
	Solution test;
	REQUIRE(true);
}