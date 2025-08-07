#include"solution.h"

void Solution::swap(vector<int>::iterator a, vector<int>::reverse_iterator b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

long long Solution::minCost(vector<int>& basket1, vector<int>& basket2) {
	long long res = 0;

	std::sort(basket1.begin(), basket1.end());
	std::sort(basket2.begin(), basket2.end());

	/*vector<int> symmetric_diff;
	std::set_symmetric_difference(
		basket1.begin(), basket1.end(),
		basket2.begin(), basket2.end(),
		std::back_inserter(symmetric_diff));*/

	vector<int> d1;
	std::set_difference(
		basket1.begin(), basket1.end(),
		basket2.begin(), basket2.end(),
		std::back_inserter(d1));

	vector<int> d2;
	std::set_difference(
		basket2.begin(), basket2.end(),
		basket1.begin(), basket1.end(),
		std::back_inserter(d2));

	if (d1.size()!=d2.size()
		|| d1.size() % 2 == 1
		|| d2.size() % 2 == 1)
	{
		return -1;
	}

	auto i1 = d1.begin();
	auto i2 = d2.rbegin();

	while (i1!=d1.end()||i2!=d2.rend())
	{
		if (*i1==*(i1+1)&&*i2==*(i2+1))
		{
			res += std::min(*i1, *i2);
			swap(i1, i2);
			i1 += 2;
			i2 += 2;
		}
		else {
			return -1;
		}
	}

	std::sort(d1.begin(), d1.end());
	std::sort(d2.begin(), d2.end());
	bool is_equal = std::equal(d1.begin(), d1.end(), d2.begin(), d2.end());
	if (is_equal)
	{
		return res;
	}
	return -1;
}


