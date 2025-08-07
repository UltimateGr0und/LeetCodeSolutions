#pragma once
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<iterator>
#include<numeric>

using std::vector;
using std::list;

class Solution {
    void swap(vector<int>::iterator a, vector<int>::reverse_iterator b);
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2);
};