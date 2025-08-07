#pragma once
#include<vector>
#include<functional>
#include<algorithm>
#include<iterator>

using std::vector;

class Solution {
    std::function<void(size_t a, size_t b)> swap;
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2);
};