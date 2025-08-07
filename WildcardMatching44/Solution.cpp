#include"solution.h"

long long Solution::minCost(vector<int>& basket1, vector<int>& basket2) {
	this->swap = [&basket1,&basket2](size_t a, size_t b) {
		int temp = basket1.at(a);
		basket1.at(a) = basket1.at(b);
		basket2.at(b) = temp;
		};

	std::sort(basket1.begin(), basket1.end());
	std::sort(basket2.begin(), basket2.end());

	vector<int> symmetric_diff;
	std::set_symmetric_difference(
		basket1.begin(), basket1.end(),
		basket2.begin(), basket2.end(),
		std::back_inserter(symmetric_diff));



	return 1;
}


